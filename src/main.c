#include "stm32f4xx.h"

int main (void){

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    //Clean MODER register for PA6 and PA7
    GPIOA->MODER &= ~(3 << (6 * 2));
    GPIOA->MODER &= ~(3 << (7 * 2));

    //Set PA6 and PA7 as output mode
    GPIOA->MODER |= (1 << (6 * 2));
    GPIOA->MODER |= (1 << (7 * 2)); 

    //Reset PA6 and PA7 pins
    GPIOA->OTYPER &= ~(1 << 6);    
    GPIOA->OTYPER &= ~(1 << 7);

    //Set PA6 and PA7 as open drain pins
    GPIOA->OTYPER |= 1 << 6;    
    GPIOA->OTYPER |= 1 << 7;

    //Reset PA6 and PA7 speed register and set them to medium speed
    GPIOA->OSPEEDR &= ~(3 << (6 * 2));
    GPIOA->OSPEEDR &= ~(3 << (7 * 2));
    GPIOA->OSPEEDR |= (1 << (6 * 2));
    GPIOA->OSPEEDR |= (1 << (7 * 2));

    //No pull-up/pull-down for PA6 and PA7
    GPIOA->PUPDR &= ~(3 << (6 * 2));
    GPIOA->PUPDR &= ~(3 << (7 * 2));

    //Reset PA6 and PA7 to enable the NMOS
    //As the PA6 and PA7 are configured as open drain, when set 1 in BSRR register, the output
    //leaves the port as high impedance. When reseting the port, the internal NMOS is enabled
    //and drives the pin to the GND, turning on the PA6 and PA7 LEDs
    GPIOA->BSRR = (0x01 << (6 + 16));
    GPIOA->BSRR = (0x01 << (7 + 16));

    GPIOA->BSRR = (0x01 << (7));

    
    return 0;
}