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

#define SAMPLES 10000
#define MEASURABLE_HEAD 1400
#define MEASURABLE_TAIL 200
#define MEASURABLE (MEASURABLE_HEAD + MEASURABLE_TAIL)
#define MAX_FIND_RANGE 150

typedef enum {
    CH_A,
    CH_B,
    CH_C,
    CH_D
} TRANSMIT_CHANNEL ;
typedef struct {
    uint8_t data[MEASURABLE];
} SIGNAL;

void runMeasurement(TRANSMIT_CHANNEL channel, short *signal);

void normalizeTo(SIGNAL *signal, int16_t pInt[3000]);

extern int findBestShift(SIGNAL * forwSignal, SIGNAL * backSignal);

#endif //F3_WINDSENSOR_WINDSOUNDER_H_H
