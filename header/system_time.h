/******************************************************************************
 * System Time library Header file
 *
 * Provides 1ms systick timer
 * The time period can be configured changing the SysTick Load register counter
 ******************************************************************************/

#include "stm32f4xx.h"

typedef uint32_t time_ms_t;

void InitSystemTime(void);
uint32_t getTime_ms(void);
void SysTick_Handler(void);