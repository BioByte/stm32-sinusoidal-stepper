#include "stm32f4xx.h"

typedef struct
{   
    GPIO_TypeDef *port;
    uint8_t pin;
    gpio_mode_t mode;
    gpio_output_type_t type;
    gpio_output_speed_type_t speed;
    gpio_pull_type_t pull;
    gpio_af_type_t af;
}gpio_config_t;

typedef enum{

    GPIO_MODE_INPUT,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_AF,
    GPIO_MODE_ANALOG

}gpio_mode_t;

typedef enum{

    GPIO_OUTPUT_TYPE_PUSH_PULL,
    GPIO_OUTPUT_TYPE_OPEN_DRAIN
    
}gpio_output_type_t;

typedef enum{

    GPIO_OUTPUT_SPEED_LOW,
    GPIO_OUTPUT_SPEED_MEDIUM,
    GPIO_OUTPUT_SPEED_HIGH,
    GPIO_OUTPUT_SPEED_VERY_HIGH
    
}gpio_output_speed_type_t;

typedef enum{

    GPIO_NO_PULL,
    GPIO_PULLUP,
    GPIO_PULLDOWN,
    
}gpio_pull_type_t;

typedef enum{

    GPIO_AF0,
    GPIO_AF1,
    GPIO_AF2,
    GPIO_AF3,
    GPIO_AF4,
    GPIO_AF5,
    GPIO_AF6,
    GPIO_AF7,
    GPIO_AF8,
    GPIO_AF9,
    GPIO_AF10,
    GPIO_AF11,
    GPIO_AF12,
    GPIO_AF13,
    GPIO_AF14,
    GPIO_AF15,

}gpio_af_type_t;
