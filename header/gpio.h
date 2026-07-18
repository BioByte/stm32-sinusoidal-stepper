/******************************************************************************
 * GPIO driver library Header file
 *
 * Provides basic GPIO configuration and pin control.
 *
 * This library is responsible only for configuring the GPIO registers.
 * Peripheral-specific configuration (UART,SPI, I2C, TIM, etc.) 
 * must be handled by the corresponding driver.
 ******************************************************************************/

#include "stm32f4xx.h"
#include "stdbool.h"

/// @brief typedef enum for GPIO Mode config
typedef enum{

    GPIO_MODE_INPUT,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_AF,
    GPIO_MODE_ANALOG

}gpio_mode_t;

/// @brief typedef enum for GPIO Push Pull/Open Drain config
typedef enum{

    GPIO_OUTPUT_TYPE_PUSH_PULL,
    GPIO_OUTPUT_TYPE_OPEN_DRAIN
    
}gpio_output_type_t;

/// @brief typedef enum for GPIO Speed config
typedef enum{

    GPIO_OUTPUT_SPEED_LOW,
    GPIO_OUTPUT_SPEED_MEDIUM,
    GPIO_OUTPUT_SPEED_HIGH,
    GPIO_OUTPUT_SPEED_VERY_HIGH
    
}gpio_output_speed_type_t;

/// @brief typedef enum for GPIO Pull Up/Down config
typedef enum{

    GPIO_NO_PULL,
    GPIO_PULLUP,
    GPIO_PULLDOWN,
    
}gpio_pull_type_t;

/// @brief typedef enum for GPIO AF config
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

/// @brief GPIO configuration structure.
typedef struct
{   
    GPIO_TypeDef *port; //GPIO port (GPIOA, GPIOB, ..., GPIOH)
    uint8_t pin; //GPIO pin number (0 to 15)
    gpio_mode_t mode; // GPIO mode (Input, Output, Alternate Function or Analog)
    gpio_output_type_t type; //Output type (Push-Pull or Open-Drain)
    gpio_output_speed_type_t speed; //Output speed
    gpio_pull_type_t pull; //Pull configuration (None, Pull-Up or Pull-Down)
    gpio_af_type_t af; //Alternate Function selection (used only in AF mode)
}gpio_config_t;

void GPIO_Init(const gpio_config_t *config);
void GPIO_EnableClock(const gpio_config_t *config);
void GPIO_SetPin(const gpio_config_t *config);
bool GPIO_ReadPin(const gpio_config_t *config);
void GPIO_ResetPin(const gpio_config_t *config);
void GPIO_WritePin(const gpio_config_t *config, bool state);
void GPIO_TogglePin(const gpio_config_t *config);