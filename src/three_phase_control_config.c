#include "three_phase_control_config.h"
#include "timer.h"
#include "gpio.h"

/******************************************************************************
 * Three-Phase Control Configuration Source file
 * 
 * This library is responsible to configure the GPIO and PWM parameters to generate a sync 
 * three phase PWM signal 
 ******************************************************************************/

/// @brief Array of three phase channels for each UPHASE, VPHASE, and WPHASE
const three_phase_channels_t PhaseChannels = {

    .ch = {TIM_CHANNEL_1, TIM_CHANNEL_2, TIM_CHANNEL_3},

};

        /// @brief GPIO configuration for UPHASE (Phase U) output
        gpio_config_t GPIO_UPHASE = {

        .port = GPIOE,
        .pin = 9,
        .mode = GPIO_MODE_AF,
        .type = GPIO_OUTPUT_TYPE_PUSH_PULL,
        .speed = GPIO_OUTPUT_SPEED_HIGH,
        .pull = GPIO_NO_PULL,
        .af = GPIO_AF1,

    };
        /// @brief GPIO configuration for UPHASE_N (Phase U complementary) output
        gpio_config_t GPIO_UPHASE_N = {

        .port = GPIOE,
        .pin = 8,
        .mode = GPIO_MODE_AF,
        .type = GPIO_OUTPUT_TYPE_PUSH_PULL,
        .speed = GPIO_OUTPUT_SPEED_HIGH,
        .pull = GPIO_NO_PULL,
        .af = GPIO_AF1,

    };
        /// @brief GPIO configuration for VPHASE (Phase V) output
        gpio_config_t GPIO_VPHASE = {

        .port = GPIOE,
        .pin = 11,
        .mode = GPIO_MODE_AF,
        .type = GPIO_OUTPUT_TYPE_PUSH_PULL,
        .speed = GPIO_OUTPUT_SPEED_HIGH,
        .pull = GPIO_NO_PULL,
        .af = GPIO_AF1,

    };
        /// @brief GPIO configuration for VPHASE_N (Phase V complementary) output
        gpio_config_t GPIO_VPHASE_N = {

        .port = GPIOE,
        .pin = 10,
        .mode = GPIO_MODE_AF,
        .type = GPIO_OUTPUT_TYPE_PUSH_PULL,
        .speed = GPIO_OUTPUT_SPEED_HIGH,
        .pull = GPIO_NO_PULL,
        .af = GPIO_AF1,

    };
        /// @brief GPIO configuration for WPHASE (Phase W) output
        gpio_config_t GPIO_WPHASE = {

        .port = GPIOE,
        .pin = 13,
        .mode = GPIO_MODE_AF,
        .type = GPIO_OUTPUT_TYPE_PUSH_PULL,
        .speed = GPIO_OUTPUT_SPEED_HIGH,
        .pull = GPIO_NO_PULL,
        .af = GPIO_AF1,

    };
        /// @brief GPIO configuration for WPHASE_N (Phase W complementary) output
        gpio_config_t GPIO_WPHASE_N = {

        .port = GPIOE,
        .pin = 12,
        .mode = GPIO_MODE_AF,
        .type = GPIO_OUTPUT_TYPE_PUSH_PULL,
        .speed = GPIO_OUTPUT_SPEED_HIGH,
        .pull = GPIO_NO_PULL,
        .af = GPIO_AF1,

    };
    /// @brief PWM handle for the three phase signals
    TIM_Handle_t PHASES_PWM_HANDLE = {

    .timer = TIM1,
    .base = {
        .timer_mode = TIMER_CENTER_ALIGNED_MODE_1,
        //.counter_direction = TIMER_UPCOUNTER_MODE,
        .prescaler = 0, //168MHz
        .period = 3360-1, //168MHz/3360 = 25kHz for center aligned mode
        .slave_mode = SLAVE_MODE_DISABLE,
        .enable_update_interrupt = true, //Enable update interrupt for TIM1_UP_TIM10_IRQn
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
            .compare = 3360*0.5, //50% duty cycle
        },
        .channel[TIM_CHANNEL_2] = {
            .cc_mode = CC_OUTPUT_MODE,
            .oc_mode = OC_PWM1_MODE,
            .oc_preload_enable = true,
            .oc_fast_enable = false,
            .cc_output_polarity = CC_OUTPUT_POLARITY_HIGH,
            .cc_output_enable = CC_OUTPUT_ENABLE,
            .cc_complementary_output_enable = CC_OUTPUT_DISABLED,
            .compare = 6720*0.5, //50% duty cycle
        },
        .channel[TIM_CHANNEL_3] = {
            .cc_mode = CC_OUTPUT_MODE,
            .oc_mode = OC_PWM1_MODE,
            .oc_preload_enable = true,
            .oc_fast_enable = false,
            .cc_output_polarity = CC_OUTPUT_POLARITY_HIGH,
            .cc_output_enable = CC_OUTPUT_ENABLE,
            .cc_complementary_output_enable = CC_OUTPUT_DISABLED,
            .compare = 6720*0.25, //50% duty cycle
        },
    },
    .bdtr = {
        .MOE = false,
        .AOE = false,
        .BKP = false,
        .BKE = false,
        .OSSR = false,
        .OSSI = false,
        .DTG = 0x00,
    },
};