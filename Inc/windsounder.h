//
// Created by elmot on 7/5/16.
//

#ifndef F3_WINDSENSOR_WINDSOUNDER_H_H
#define F3_WINDSENSOR_WINDSOUNDER_H_H

#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include "stm32l4xx_hal.h"
#include "ADC.h"
#include "TIM1.h"
#include "TIM2.h"
#include "DMA1.h"
#include "DMA2.h"
#include "GPIOA.h"
#include "GPIOB.h"

#define MEASURE_SKIP_HEAD 3200
#define MEASURES 2000

#define SAMPLES (MEASURES + MEASURE_SKIP_HEAD)

typedef enum {
    CH_AB,
    CH_BA,
    CH_CD,
    CH_DC
} TRANSMIT_CHANNEL ;

void runMeasurement(TRANSMIT_CHANNEL channel, short *signal);

#endif //F3_WINDSENSOR_WINDSOUNDER_H_H
