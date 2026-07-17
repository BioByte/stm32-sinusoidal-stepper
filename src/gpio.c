#include "gpio.h"
#include "stm32f4xx.h"
#include "stdbool.h"


void GPIO_Init(const gpio_config_t *config){

    config->port->MODER &= ~(3U << (config->pin * 2U));
    config->port->MODER |= ((uint32_t)config->mode << (config->pin * 2U));

    config->port->OTYPER &= ~(1U << config->pin);
    config->port->OTYPER |= ((uint32_t)config->type << config->pin);

    config->port->OSPEEDR &= ~(3U << (config->pin * 2U));
    config->port->OSPEEDR |= ((uint32_t)config->speed << (config->pin * 2U));

    config->port->PUPDR &= ~(3U << (config->pin * 2U));
    config->port->PUPDR |= ((uint32_t)config->pull << (config->pin * 2U));

    if(config->mode == GPIO_MODE_AF){
        uint32_t index = config->pin / 8U;
        uint32_t shift = (config->pin % 8U) * 4U;

        config->port->AFR[index] &= ~(0xFU << shift);
        config->port->AFR[index] |= ((uint32_t)config->af << shift);

    }

}

void GPIO_EnableClock(const gpio_config_t *config){

    if(config->port == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    else if(config->port == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    else if(config->port == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    else if(config->port == GPIOD) RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    else if(config->port == GPIOE) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
    else if(config->port == GPIOF) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
    else if(config->port == GPIOG) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
    else if(config->port == GPIOH) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;

    (void)RCC->AHB1ENR;
}

void GPIO_SetPin(const gpio_config_t *config){

    config->port->BSRR = (1U << config->pin);
        
}

bool GPIO_ReadPin(const gpio_config_t *config){

    return (config->port->IDR & (1U << config->pin));

}
void GPIO_ResetPin(const gpio_config_t *config){

    config->port->BSRR = (1U << (config->pin + 16U));

}

void GPIO_WritePin(const gpio_config_t *config, bool state){

    if(state){
        GPIO_SetPin(config);
    }
    else{
        GPIO_ResetPin(config);
    }
}