//
// Created by elmot on 7/5/16.
//

#include "windsounder.h"

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

void Error_Handler(void);

static const uint16_t send_pattern[] = {
        1, 2, 1, 2, 1, 2, 1, 2, 1, 2, //-1
        2, 1, 2, 1, 2, 1, 2, 1, 2, 1, //1
        1, 2, 1, 2, 1, 2, 1, 2, 1, 2, //-1
        1, 2, 1, 2, 1, 2, 1, 2, 1, 2, //-1
        2, 1, 2, 1, 2, 1, 2, 1, 2, 1, //1
        2, 1, 2, 1, 2, 1, 2, 1, 2, 1, //1
        2, 1, 2, 1, 2, 1, 2, 1, 2, 1, //1
};
#define send_sequence send_pattern


void runMeasurement(uint8_t transmitValue, uint32_t detectChannel, int16_t *signal) {

/*
  static uint8_t send_sequence[sizeof send_pattern];
  for (int i = 0; i < sizeof send_sequence; ++i) {
    send_sequence[i] = send_pattern[i] ? transmitValue : (uint8_t) 0;
  }
*/

  ADC_ChannelConfTypeDef sConfig;

  /**Configure Regular Channel
  */
  sConfig.Channel = detectChannel;
  sConfig.Rank = 1;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.SamplingTime = ADC_SAMPLETIME_2CYCLE_5;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
    Error_Handler();
  }
  HAL_DMA_Start(&hdma_tim2_up, (uint32_t) send_sequence, (uint32_t) &GPIOC->ODR,
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