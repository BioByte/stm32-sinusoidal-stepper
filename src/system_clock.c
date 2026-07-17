#include "system_clock.h"
#include "stm32f4xx.h"

void InitSystemClock(void){

    // 1. Enable HSE and wait for it to stabilize
    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & RCC_CR_HSERDY));

    // 2. Enable Power Control clock and configure voltage regulator and wait for it to stabilize
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    PWR->CR |= PWR_CR_VOS; // Scale 1 mode (default for 168MHz)
    while (!(PWR->CSR & PWR_CSR_VOSRDY));
    
    // 3. Configure Flash Latency
    // 168MHz requires 5 wait states
    FLASH->ACR &= ~FLASH_ACR_LATENCY;
    FLASH->ACR =
      FLASH_ACR_ICEN |
      FLASH_ACR_DCEN |
      FLASH_ACR_PRFTEN |
      FLASH_ACR_LATENCY_5WS;

    // 4. Configure Prescalers
    // AHB = 1, APB1 = 4 (Max 42MHz), APB2 = 2 (Max 84MHz)
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV4;
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;
   
    // 5. Configure the Main PLL
    // Example for 8MHz HSE: PLLM = 8, PLLN = 336, PLLP = 2 (SYSCLK = 168 MHz)
    RCC->PLLCFGR = (8 << RCC_PLLCFGR_PLLM_Pos) | 
                   (336 << RCC_PLLCFGR_PLLN_Pos) | 
                   (0 << RCC_PLLCFGR_PLLP_Pos) | // 0 means PLLP = 2
                   (RCC_PLLCFGR_PLLSRC_HSE);

    // 6. Enable the PLL and wait for it to stabilize
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));

    // 7. Select PLL as system clock source and wait for it to stabilize
    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

    SystemCoreClockUpdate();
    
}

