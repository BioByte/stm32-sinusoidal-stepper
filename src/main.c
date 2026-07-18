#include "stm32f4xx.h"
#include "system_clock.h"
#include "system_time.h"
#include <stdbool.h>
#include "gpio.h"

int main (void){

    InitSystemClock();
    InitSystemTime();

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