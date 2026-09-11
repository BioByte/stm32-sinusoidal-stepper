#ifndef SWAVE_H
#define SWAVE_H

/******************************************************************************
 * Sine Wave library Header file
 *
 * Provides basic Sine Wave functionality.
 *
 * This library is responsible only for configuring the sine wave parameters.
 ******************************************************************************/

#include "stm32f4xx.h"

/// @brief Initializes the sine wave generator 
/// @param  
void SWave_init(void);

/// @brief Sets the frequency of the sine wave
/// @param motor_frequency 
void SWave_SetFrequency(uint32_t motor_frequency);

#endif /* SWAVE_H */