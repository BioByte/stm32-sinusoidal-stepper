#include "stm32f4xx.h"
#include "system_clock.h"
#include "system_time.h"
#include <stdbool.h>
#include "gpio.h"
#include "timer.h"

int main (void){

/* Código abaixo para testar o System Clock e System Time */
    InitSystemClock();
    InitSystemTime();

/*Teste de PWM*/

TIM_Handle_t tim1_handle = {

    .timer = TIM1,
    .base = {
        .timer_mode = TIMER_EDGE_ALIGNED_MODE,
        .counter_direction = TIMER_UPCOUNTER_MODE,
        .prescaler = 0, //84MHz
        .period = 3360-1, //84MHz/3360 = 25kHz
        .slave_mode = SLAVE_MODE_DISABLE,
    },
    .channels = {
        .channel[TIM_CHANNEL_1] = {
            .cc_mode = CC_OUTPUT_MODE,
            .oc_mode = OC_PWM1_MODE,
            .oc_preload_enable = true,
            .oc_fast_enable = false,
            .cc_output_polarity = CC_OUTPUT_POLARITY_HIGH,
            .cc_output_enable = CC_OUTPUT_ENABLE,
            .cc_complementary_output_enable = CC_OUTPUT_DISABLED,
            .compare = 1680, //50% duty cycle
        },
    },
    .bdtr = {
        .MOE = true,
        .AOE = false,
        .BKP = false,
        .BKE = false,
        .OSSR = false,
        .OSSI = false,
        .DTG = 0x00,
    },
};

    gpio_config_t GPIO_PWM1 = {

        .port = GPIOE,
        .pin = 9,
        .mode = GPIO_MODE_AF,
        .type = GPIO_OUTPUT_TYPE_PUSH_PULL,
        .speed = GPIO_OUTPUT_SPEED_HIGH,
        .pull = GPIO_NO_PULL,
        .af = GPIO_AF1,

    };

    GPIO_EnableClock(&GPIO_PWM1);
    GPIO_Init(&GPIO_PWM1);
    TIM_HWClockEnable(&tim1_handle);
    TIM_BaseInit(&tim1_handle);
    TIM_OCInit(&tim1_handle, TIM_CHANNEL_1);
    TIM_BDTRInit(&tim1_handle);
    TIM_Start(&tim1_handle);

/* Código abaixo para testar os LEDs */

    time_ms_t current_time = 0, timeout = 0, getSystemTimer_ms = 0;

    timeout = 1000;

    gpio_config_t LED1 = {

        .port = GPIOA,
        .pin = 6,
        .mode = GPIO_MODE_OUTPUT,
        .type = GPIO_OUTPUT_TYPE_OPEN_DRAIN,
        .speed = GPIO_OUTPUT_SPEED_MEDIUM,
        .pull = GPIO_NO_PULL,

    };

        gpio_config_t LED2 = {

        .port = GPIOA,
        .pin = 7,
        .mode = GPIO_MODE_OUTPUT,
        .type = GPIO_OUTPUT_TYPE_OPEN_DRAIN,
        .speed = GPIO_OUTPUT_SPEED_MEDIUM,
        .pull = GPIO_NO_PULL,

    };

    GPIO_EnableClock(&LED1);

    GPIO_Init(&LED1);
    GPIO_Init(&LED2);

    GPIO_SetPin(&LED1);
    GPIO_ResetPin(&LED2);

    while (1)
    {
        getSystemTimer_ms = getTime_ms();
        if((getSystemTimer_ms - current_time)>=timeout){

            current_time = getSystemTimer_ms;
            GPIO_TogglePin(&LED1);
            GPIO_TogglePin(&LED2);
        }
    }
    
    return 0;
}