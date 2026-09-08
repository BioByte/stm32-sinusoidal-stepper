#ifndef SWAVE_H
#define SWAVE_H
#include "stm32f4xx.h"

void SWave_init(void);

void SWave_SetMotorFrequency(uint32_t motor_frequency);

#endif /* SWAVE_H */