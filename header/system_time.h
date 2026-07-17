#include "stm32f4xx.h"

typedef uint32_t time_ms_t;

void InitSystemTime(void);

uint32_t getTime_ms(void);

void SysTick_Handler(void);