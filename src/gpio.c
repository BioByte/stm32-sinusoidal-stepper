/******************************************************************************
 * GPIO driver library
 *
 * Provides basic GPIO configuration and pin control.
 *
 * This library is responsible only for configuring the GPIO registers.
 * Peripheral-specific configuration (UART,SPI, I2C, TIM, etc.) 
 * must be handled by the corresponding driver.
 ******************************************************************************/

#include "gpio.h"
#include "stm32f4xx.h"
#include "stdbool.h"

/// @brief Initialize a GPIO pin
/// @param config Pointer to the GPIO configuration structure

void GPIO_Init(const gpio_config_t *config){

    // Clear the mode bits and configure the selected pin mode
    config->port->MODER &= ~(3U << (config->pin * 2U));
    config->port->MODER |= ((uint32_t)config->mode << (config->pin * 2U));

    // Clear the type bits and configure the selected pin type
    config->port->OTYPER &= ~(1U << config->pin);
    config->port->OTYPER |= ((uint32_t)config->type << config->pin);

    // Clear the speed bits and configure the selected pin speed
    config->port->OSPEEDR &= ~(3U << (config->pin * 2U));
    config->port->OSPEEDR |= ((uint32_t)config->speed << (config->pin * 2U));

    // Clear the pull-up/down bits and configure the selected pin pull-up/down
    config->port->PUPDR &= ~(3U << (config->pin * 2U));
    config->port->PUPDR |= ((uint32_t)config->pull << (config->pin * 2U));

    // Configure the Alternate Function (AF) registers when required
    if(config->mode == GPIO_MODE_AF){
        uint32_t index = config->pin / 8U;// AFR[0] controls pins 0-7, AFR[1] controls pins 8-15
        uint32_t shift = (config->pin % 8U) * 4U;

        config->port->AFR[index] &= ~(0xFU << shift);
        config->port->AFR[index] |= ((uint32_t)config->af << shift);

    }

}

/// @brief Enable clock for each GPIO port peripheral
/// @param config Pointer to the GPIO configuration structure
void GPIO_EnableClock(const gpio_config_t *config){

    if(config->port == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    else if(config->port == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    else if(config->port == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    else if(config->port == GPIOD) RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    else if(config->port == GPIOE) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
    else if(config->port == GPIOF) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
    else if(config->port == GPIOG) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
    else if(config->port == GPIOH) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;

    // Read back to ensure the write has completed
    (void)RCC->AHB1ENR;
}

/// @brief Set the selected GPIO pin using the BSRR register
/// @param config Pointer to the GPIO configuration structure
void GPIO_SetPin(const gpio_config_t *config){

    config->port->BSRR = (1U << config->pin);
        
}

/// @brief Read the selected GPIO pin state from the IDR register
/// @param config Pointer to the GPIO configuration structure
/// @return Return the boolean value read
bool GPIO_ReadPin(const gpio_config_t *config){

    return (config->port->IDR & (1U << config->pin));

}

/// @brief Reset the selected GPIO pin using the BSRR register
/// @param config Pointer to the GPIO configuration structure
void GPIO_ResetPin(const gpio_config_t *config){

    config->port->BSRR = (1U << (config->pin + 16U));

}

/// @brief Set or reset the selected GPIO pin
/// @param config Pointer to the GPIO configuration structure
/// @param state  true = High, false = Low
void GPIO_WritePin(const gpio_config_t *config, bool state){

    if(state){
        GPIO_SetPin(config);
    }
    else{
        GPIO_ResetPin(config);
    }
}

/// @brief Toggle the selected GPIO pin state
/// @param config Pointer to the GPIO configuration structure
/// @note This operation performs a read-modify-write on the ODR register
///       and is therefore not atomic
void GPIO_TogglePin(const gpio_config_t *config){

    config->port->ODR ^= (1U << config->pin);

}