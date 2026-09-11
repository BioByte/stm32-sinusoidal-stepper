#ifndef SYSTEM_CLOCK_H
#define SYSTEM_CLOCK_H

/******************************************************************************
 * System Clock library Header file
 *
 * Init System Clock for 168MHz, AHB 168Mhz, APB1 42MHz, APB2 84MHz
 * 
 * This library is responsible only for configuring the system clock registers.
 ******************************************************************************/

#include <stdint.h>

/// @brief Initializes the system clock
/// @param  
void InitSystemClock(void);

/// @brief Gets the current system clock frequency
/// @param  
/// @return Current system clock frequency in Hz
uint32_t GetSystemClock(void);

#endif // SYSTEM_CLOCK_H