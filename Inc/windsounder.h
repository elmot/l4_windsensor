//
// Created by elmot on 7/5/16.
//

#ifndef F3_WINDSENSOR_WINDSOUNDER_H_H
#define F3_WINDSENSOR_WINDSOUNDER_H_H

#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include "stm32l4xx_hal.h"

#define TRANSMIT_VALUE_1 0x10
#define TRANSMIT_VALUE_2 0x20
#define TRANSMIT_VALUE_3 0x40

#define DETECT_CH_1 ADC_CHANNEL_1
#define DETECT_CH_2 ADC_CHANNEL_2
#define DETECT_CH_3 ADC_CHANNEL_6

#define SAMPLES 5000
#define MEASURABLE_HEAD 1400
#define MEASURABLE_TAIL 200
#define MEASURABLE (MEASURABLE_HEAD + MEASURABLE_TAIL)
#define MAX_FIND_RANGE 150

typedef struct {
    uint8_t data[MEASURABLE];
} SIGNAL;

void runMeasurement(uint8_t transmitValue, uint32_t detectChannel, short *signal);

void normalizeTo(SIGNAL *signal, int16_t pInt[3000]);

extern int findBestShift(SIGNAL * forwSignal, SIGNAL * backSignal);

#endif //F3_WINDSENSOR_WINDSOUNDER_H_H
