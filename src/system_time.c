/******************************************************************************
 * System Time library
 *
 * Provides 1ms systick timer
 * The time period can be configured changing the SysTick Load register counter
 ******************************************************************************/

#include "stm32f4xx.h"
#include "system_time.h"

/// @brief tick counter 1ms period
static volatile time_ms_t tick = 0;

/// @brief Initialize Systick Timer 
void InitSystemTime(void){

        //Loads the counter for 1ms period
        SysTick->LOAD = (SystemCoreClock / 1000) -1;

        //Reset the counter
        SysTick->VAL = 0;

        SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | //Processor clock 
                        SysTick_CTRL_TICKINT_Msk   | //Enable SysTick Interruption
                        SysTick_CTRL_ENABLE_Msk;    //Enable counter
}

/// @brief Return time 1ms step 
/// @return tick elapsed time
time_ms_t getTime_ms(void){

    return tick;

}

/// @brief SysTick interruption Handler 
void SysTick_Handler(void){

    tick++;

}