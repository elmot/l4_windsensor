
#include <stm32l4xx_hal.h>
#include <arm_math.h>
#include "windsounder.h"


extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_tim2_up;
extern DMA_HandleTypeDef hdma_adc1;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;


#define PH_A CODE_P_Pin
#define PH_B CODE_M_Pin
static const uint16_t send_pattern[] = {
        PH_A, PH_B, PH_A, PH_B, PH_A, PH_B, PH_A, PH_B, PH_A, PH_B, //-1
        PH_B, PH_A, PH_B, PH_A, PH_B, PH_A, PH_B, PH_A, PH_B, PH_A, //1
        PH_A, PH_B, PH_A, PH_B, PH_A, PH_B, PH_A, PH_B, PH_A, PH_B, //-1
        PH_A, PH_B, PH_A, PH_B, PH_A, PH_B, PH_A, PH_B, PH_A, PH_B, //-1
        PH_B, PH_A, PH_B, PH_A, PH_B, PH_A, PH_B, PH_A, PH_B, PH_A, //1
        PH_B, PH_A, PH_B, PH_A, PH_B, PH_A, PH_B, PH_A, PH_B, PH_A, //1
        PH_B, PH_A, PH_B, PH_A, PH_B, PH_A, PH_B, PH_A, PH_B, PH_A, //1
};
#define send_sequence send_pattern

q15_t values[SAMPLES];
q15_t *mRange = &values[MEASURE_SKIP_HEAD];//todo remove if not needed
q15_t vRange[MEASURES];

struct {
    q15_t rangeAB[MEASURES]__attribute__ ((aligned (8)));
    q15_t rangeBA[MEASURES]__attribute__ ((aligned (8)));
    q15_t rangeCD[MEASURES]__attribute__ ((aligned (8)));
    q15_t rangeDC[MEASURES]__attribute__ ((aligned (8)));
    char sign[8] __attribute__ ((aligned (32)));
    char span[FLASH_PAGE_SIZE - (4 * 2 * MEASURES + 8) % FLASH_PAGE_SIZE];
} calibr __attribute__ ((section (".rodata"), aligned (FLASH_PAGE_SIZE)));


void runMeasurement(TRANSMIT_CHANNEL channel, q15_t *signal) {

  ADC_ChannelConfTypeDef sConfig;

  /**Configure Regular Channel
  */
  HAL_GPIO_WritePin(EN_A_GPIO_Port, EN_A_Pin | EN_B_Pin | EN_C_Pin | EN_D_Pin, GPIO_PIN_RESET);
  switch (channel) {
    case CH_AB:
      sConfig.Channel = ADC_CHANNEL_11;
      HAL_GPIO_WritePin(EN_A_GPIO_Port, EN_A_Pin, GPIO_PIN_SET);
      break;
    case CH_BA:
      sConfig.Channel = ADC_CHANNEL_12;
      HAL_GPIO_WritePin(EN_B_GPIO_Port, EN_B_Pin, GPIO_PIN_SET);
      break;
    case CH_CD:
      sConfig.Channel = ADC_CHANNEL_9;
      HAL_GPIO_WritePin(EN_C_GPIO_Port, EN_C_Pin, GPIO_PIN_SET);
      break;
    case CH_DC:
      sConfig.Channel = ADC_CHANNEL_10;
      HAL_GPIO_WritePin(EN_D_GPIO_Port, EN_D_Pin, GPIO_PIN_SET);
      break;
  }
  sConfig.Rank = 1;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.SamplingTime = ADC_SAMPLETIME_2CYCLE_5;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
    Error_Handler();
  }
  HAL_DMA_Start(&hdma_tim2_up, (uint32_t) send_sequence, (uint32_t) &CODE_M_GPIO_Port->ODR,
                sizeof send_sequence / sizeof send_sequence[0]);
  HAL_ADC_Start_DMA(&hadc1, (uint32_t *) signal, SAMPLES);
  HAL_TIM_Base_Start(&htim1);
  HAL_SuspendTick();
  HAL_DMA_PollForTransfer(&hdma_tim2_up, HAL_DMA_FULL_TRANSFER, 2000);
  while (HAL_DMA_GetState(&hdma_adc1) != HAL_DMA_STATE_READY)__WFI();
  HAL_TIM_Base_Stop(&htim1);
  __HAL_TIM_SET_COUNTER(&htim2, 0);
  HAL_ADC_Stop_DMA(&hadc1);
  HAL_ResumeTick();
}

bool rangeTest = false;// todo remove



void oneTrip(char *name, TRANSMIT_CHANNEL channel, q15_t *outRange, bool rev) {
  runMeasurement(channel, values);

  q15_t avg;
  arm_mean_q15(mRange, MEASURES, &avg);
  if (rev) {
    for (int i = 0; i < MEASURES; i++) {
      vRange[i] = mRange[MEASURES - i - 1] - avg;
    }
  } else {
    arm_offset_q15(mRange, -avg, vRange, MEASURES);
  }
  transmitFrame(name, vRange, MEASURES);
  if (outRange != NULL) {
    uint32_t dstAddress = (uint32_t) outRange;
    uint64_t *src = (uint64_t *) vRange;
    int counter = MEASURES / 4;  // 8 bytes at the time
    for (int i = 0; i < counter; i++, dstAddress += 8, src++) {
      if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, dstAddress, *src) != HAL_OK) {
        _Error_Handler(__FILE__ ": Flashing failed", __LINE__);
      }
    }
    if (memcmp(vRange, outRange, MEASURES * 2) != 0) {
      _Error_Handler(__FILE__ ": Flash check failed", __LINE__);
    }

  }
}

int findAndSendCorrelation(char *name, q15_t *calibRange, q15_t *measureRange) {
//  static q15_t compare[2 * MEASURES - 1];
//  static q15_t temp_calib[MEASURES];
//  arm_copy_q15(calibRange, temp_calib, MEASURES);
//
//  arm_conv_partial_fast_q15(calibRange, MEASURES , measureRange, MEASURES, compare,
//                            CONVOLUTION_START, CONVOLUTION_LEN);
//  arm_conv_partial_fast_q15(temp_calib, MEASURES , measureRange, MEASURES, compare,
//                            CONVOLUTION_START, CONVOLUTION_LEN);
  q15_t max, min;
  uint32_t maxIndex, minIndex;
//  arm_max_q15(&compare[CONVOLUTION_START], CONVOLUTION_LEN, &max, &maxIndex);
//  arm_min_q15(&compare[CONVOLUTION_START], CONVOLUTION_LEN, &min, &minIndex);
//  transmitFrame(name, &compare[CONVOLUTION_START], CONVOLUTION_LEN);
  return CONVOLUTION_START +  (int)(max > -min ? maxIndex : minIndex);
}

void calibrate() {
  sendDetails = true;
  HAL_FLASH_Unlock();
  FLASH_EraseInitTypeDef eraser = {
            FLASH_TYPEERASE_PAGES,
            FLASH_BANK_BOTH,
            (((uint32_t) &calibr) - FLASH_BASE) / FLASH_PAGE_SIZE,
            sizeof calibr / FLASH_PAGE_SIZE
    };
  uint32_t pageError;
  HAL_FLASHEx_Erase(&eraser, &pageError);
  if (pageError != -1) _Error_Handler(__FILE__ ": Erase error", __LINE__);

  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
  HAL_Delay(700);
  oneTrip("CH_AB", CH_AB, calibr.rangeAB,true);
  HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);

  oneTrip("CH_BA", CH_BA, calibr.rangeBA,true);
  HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
  oneTrip("CH_CD", CH_CD, calibr.rangeCD,true);
  HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
  oneTrip("CH_DC", CH_DC, calibr.rangeDC,true);
  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);

  HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, (uint32_t) calibr.sign, *(uint64_t *) CALIBRED_SIGN);
  HAL_FLASH_Lock();
  for (int i = 0; i <= 5; i++) {
      HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
      HAL_Delay(600);
      HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
      HAL_Delay(200);
    }
}

int dAB = -1, dBA = -1, dCD = -1, dDC = -1;

void performMeasurement() {
  oneTrip("CH_AB", CH_AB, NULL, false);//todo test for differenr amplitude and huge shift
  dAB = findAndSendCorrelation("CORR_AB", calibr.rangeAB, vRange);
  oneTrip("CH_BA", CH_BA, NULL,false);
  dBA = findAndSendCorrelation("CORR_BA", calibr.rangeBA, vRange);
  calcSendWind(dAB, dBA, dCD, dDC);

  rangeTest = true;
  oneTrip("CH_CD", CH_CD, NULL,false);
  rangeTest = false;
  dCD = findAndSendCorrelation("CORR_CD", calibr.rangeCD, vRange);
  oneTrip("CH_DC", CH_DC, NULL,false);
  dDC = findAndSendCorrelation("CORR_DC", calibr.rangeDC, vRange);
  calcSendWind(dAB, dBA, dCD, dDC);
}

void checkCalibrated() {
  if (strncmp(CALIBRED_SIGN, calibr.sign, 8) != 0) {
    _Error_Handler(__FILE__ ": uncalibrated", __LINE__);
  }
}

void appendCheckSum(char *buff) {
  int checkSum = 0, ind = 1;
  for (; buff[ind] != 0; ind++) {
    checkSum ^= buff[ind];
  }
  sprintf(&buff[ind], "*%02x\r\n", checkSum);
}

void calcSendWind(int dAB, int dBA, int dCD, int dDC) {
/*
  $–MWV, Acoustic Wind Sensor

  COLUMN	NAME	        DESCRIPTION	                                                  EXAMPLE
1	        Sentence        Identifier	Acoustic Wind Sensor	                          $WIMWV
2	        Wind Direction	Wind Direction in degrees	                                  154.3
3	        Direction       Reference	Wind Direction Reference, R = Relative, T = True  R
4	        Wind Speed	    Wind Speed	                                                  16.4
5	        Speed Units	    Wind Speed Units, K = km/hr, M = m/sec, N = kt	              K
6	        Sensor Status	Sensor Status, A = Valid, V = Void	                          A
7	        Checksum	    2-byte XOR sum of data to check for transmission errors	      *0A


          1  2  3  4  5  6  7  8 9
         |  |  |  |  |  |  |  | |
 $--VWR,x.x,a,x.x,N,x.x,M,x.x,K*hh<CR><LF>
Field Number:

Wind direction magnitude in degrees

Wind direction Left/Right of bow

Speed

N = Knots

Speed

M = Meters Per Second

Speed

K = Kilometers Per Hour

Checksum
*/
  if (dAB < 0 || dBA < 0 || dCD < 0 || dDC < 0) return;
  static uint32_t time = 0;
  char buff[100];
  int dY = dDC - dCD;
  int dX = dAB - dBA;
  double speed = sqrt(dX * dX + dY * dY) * ms_per_tick;
  double angle;
  if (speed < 0.1) {
    angle = 0;
  } else {
    angle = atan2(dY, dX) * 180.0 / PI;
    if (angle < 0) angle += 360;
  }

  sprintf(buff, "MSG:%d:%d | %d:%d | %4.1f deg : %5.2f m/s | dT: %d ms\r\n", dAB, dBA, dCD, dDC,
          angle, speed,
          (int) (HAL_GetTick() - time));
  uartTransmit(buff);

  sprintf(buff, "$WIMWV,%1.1f,R,%1.1f,M,A", angle, speed);
  appendCheckSum(buff);
  uartTransmit(buff);
  time = HAL_GetTick();
}

