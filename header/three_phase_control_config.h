#ifndef THREE_PHASE_CONTROL_CONFIG_H
#define THREE_PHASE_CONTROL_CONFIG_H

/******************************************************************************
 * Three-Phase Control Configuration Header file
 * 
 * This library is responsible to configure the GPIO and PWM parameters to generate a sync 
 * three phase PWM signal 
 ******************************************************************************/

#include "gpio.h"
#include "timer.h"

/// @brief Structure to hold configure the three phase channels
typedef struct three_phase_channels{

    TIM_Channel_t ch[3];
    
} three_phase_channels_t;

/// @brief GPIO configuration for UPHASE (Phase U) output
extern gpio_config_t GPIO_UPHASE;

/// @brief GPIO configuration for UPHASE_N (Phase U complementary) output
extern gpio_config_t GPIO_UPHASE_N;

/// @brief GPIO configuration for VPHASE (Phase V) output
extern gpio_config_t GPIO_VPHASE;

/// @brief GPIO configuration for VPHASE_N (Phase V complementary) output
extern gpio_config_t GPIO_VPHASE_N;

/// @brief GPIO configuration for WPHASE (Phase W) output
extern gpio_config_t GPIO_WPHASE;

/// @brief GPIO configuration for WPHASE_N (Phase W complementary) output
extern gpio_config_t GPIO_WPHASE_N;

/// @brief PWM handle for the three phase signals
extern TIM_Handle_t PHASES_PWM_HANDLE;

/// @brief Array of three phase channels
extern const three_phase_channels_t PhaseChannels;

#endif // THREE_PHASE_CONTROL_CONFIG_H