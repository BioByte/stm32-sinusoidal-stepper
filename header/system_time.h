#ifndef SYSTEM_TIME_H
#define SYSTEM_TIME_H

/******************************************************************************
 * System Time library Header file
 *
 * Provides 1ms systick timer
 * 
 * This library is responsible only for configuring the systick timer registers.
 * The time period can be configured changing the SysTick Load register counter
 ******************************************************************************/

#include "stm32f4xx.h"

/// @brief Typedef for time in milliseconds
typedef uint32_t time_ms_t;

/// @brief Initializes the system time
/// @param  
void InitSystemTime(void);

/// @brief Gets the current time in milliseconds
/// @param  
/// @return Current time in milliseconds
uint32_t getTime_ms(void);

/// @brief System tick interrupt handler
/// @param  
void SysTick_Handler(void);

#endif // SYSTEM_TIME_HS