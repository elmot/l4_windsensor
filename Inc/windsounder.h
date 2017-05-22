//
// Created by elmot on 7/5/16.
//

#ifndef F3_WINDSENSOR_WINDSOUNDER_H_H
#define F3_WINDSENSOR_WINDSOUNDER_H_H

#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <arm_math.h>
#include "stm32l4xx_hal.h"
#include "ADC.h"
#include "TIM1.h"
#include "TIM2.h"
#include "DMA1.h"
#include "DMA2.h"
#include "GPIOA.h"
#include "GPIOB.h"

#define MEASURE_SKIP_HEAD 3800
#define MEASURES 3000

#define SAMPLES (MEASURES + MEASURE_SKIP_HEAD)

typedef enum {
    CH_AB,
    CH_BA,
    CH_CD,
    CH_DC
} TRANSMIT_CHANNEL ;


static const double ms_per_tick = 0.04;
static char *const CALIBRED_SIGN = "CALIBRED";
extern bool sendDetails;

#define CONVOLUTION_LEN 2000
#define CONVOLUTION_START  (MEASURES - CONVOLUTION_LEN / 2)

void runMeasurement(TRANSMIT_CHANNEL channel, q15_t *signal);

void transmitFrame(const char *name, const q15_t *outRange, size_t len);

int findAndSendCorrelation(char *name, q15_t *calibRange, q15_t *measureRange);

void calcSendWind(int dAB, int dBA, int dCD, int dDC);

void oneTrip(char *name, TRANSMIT_CHANNEL channel, q15_t *outRange, bool rev);

void calibrate();

void performMeasurement();

void checkCalibrated();

void uartTransmit(const char *str);

#endif //F3_WINDSENSOR_WINDSOUNDER_H_H
