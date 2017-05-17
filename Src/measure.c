//
// Created by elmot on 7/5/16.
//

#include <stm32l4xx_hal.h>
#include "windsounder.h"
#include "main.h"

/*
  static const uint8_t buffer[] = {0, 0xff, 0, 0xff, 0, 0xff, 0, 0xff, 0, 0xff, 0, 0xff , 0, 0xff , 0, 0xff , 0, 0xff , 0, 0xff,0,
                                   0, 0xff, 0, 0xff, 0, 0xff, 0, 0xff, 0, 0xff , 0, 0xff , 0, 0xff , 0, 0xff, 0
  };
*/
/*
static const uint8_t send_pattern[] = {0, 0xff, 0, 0xff, 0, 0xff, 0, 0xff, //-1
                                       0xff, 0, 0xff, 0, 0xff, 0, 0xff, 0, //1
                                       0, 0xff, 0, 0xff, 0, 0xff, 0, 0xff, //-1
                                       0, 0xff, 0, 0xff, 0, 0xff, 0, 0xff, //-1
                                       0xff, 0, 0xff, 0, 0xff, 0, 0xff, 0, //1
                                       0xff, 0, 0xff, 0, 0xff, 0, 0xff, 0, //1
                                       0xff, 0, 0xff, 0, 0xff, 0, 0xff, 0, //1
};

*/

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


void runMeasurement(TRANSMIT_CHANNEL channel, int16_t *signal) {

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


void normalizeTo(SIGNAL *signal, int16_t srcValues[3000]) {
  int min = 100000;
  int minPos = 0;
  int max = -1;
  int maxPos = 0;

  for (int i = 0; i < SAMPLES; ++i) {
    int16_t v = srcValues[i];
    if (v < min) {
      minPos = i;
      min = v;
    } else if (v > max) {
      maxPos = i;
      max = v;
    }
  }
  int keyPoint = (minPos + maxPos) / 2 - MEASURABLE_HEAD;
  if (keyPoint < 0) keyPoint = 0;

  int sum = 0;
  for (int i = 0; i < MEASURABLE; ++i) {
    sum += srcValues[i + keyPoint];
  }
  int avg = sum / MEASURABLE;

  double multiplier = 250.0 / (max - min);

  for (int i = 0; i < MEASURABLE; ++i) {

    int16_t v = srcValues[i + keyPoint];
    if (v > avg) {
      signal->data[i] = (uint8_t) ((v - avg) * multiplier);
    } else {
      signal->data[i] = (uint8_t) ((avg - v) * multiplier);
    }
  }
}


int findBestShift(SIGNAL *forwSignal, SIGNAL *backSignal) {
  int shift;
  long minSqDiff = 0x7FFFFFFF;
  int bestShift = 0;

  for (shift = -MAX_FIND_RANGE; shift <= 0; shift++) {
    long sqDiff = 0;
    for (int j = 0; j < MEASURABLE - MAX_FIND_RANGE; j++) {
      int v = forwSignal->data[j] - backSignal->data[j - shift];
      sqDiff += v * v;
    }
    if (sqDiff < minSqDiff) {
      minSqDiff = sqDiff;
      bestShift = shift;
    }
  }
  for (shift = 1; shift < MAX_FIND_RANGE; shift++) {
    long sqDiff = 0;
    for (int j = 0; j < MEASURABLE - MAX_FIND_RANGE; j++) {
      int v = forwSignal->data[j + shift] - backSignal->data[j];
      sqDiff += v * v;
    }
    if (sqDiff < minSqDiff) {
      minSqDiff = sqDiff;
      bestShift = shift;
    }
  }

  return bestShift;
}
