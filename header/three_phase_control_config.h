#ifndef THREE_PHASE_CONTROL_CONFIG_H
#define THREE_PHASE_CONTROL_CONFIG_H
#include "gpio.h"
#include "timer.h"

typedef struct three_phase_channels{

    TIM_Channel_t ch[3];
    
} three_phase_channels_t;


extern gpio_config_t GPIO_UPHASE;
extern gpio_config_t GPIO_UPHASE_N;
extern gpio_config_t GPIO_VPHASE;
extern gpio_config_t GPIO_VPHASE_N;
extern gpio_config_t GPIO_WPHASE;
extern gpio_config_t GPIO_WPHASE_N;
extern TIM_Handle_t PHASES_PWM_HANDLE;
extern const three_phase_channels_t PhaseChannels;

#endif // THREE_PHASE_CONTROL_CONFIG_H