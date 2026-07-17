#include "stm32f4xx.h"
#include "system_time.h"

static volatile time_ms_t tick = 0;

void InitSystemTime(void){

        SysTick->LOAD = (SystemCoreClock / 1000) -1;

        SysTick->VAL = 0;

        SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                        SysTick_CTRL_TICKINT_Msk   |
                        SysTick_CTRL_ENABLE_Msk;
}

time_ms_t getTime_ms(void){

    return tick;

}

void SysTick_Handler(void){

    tick++;

}