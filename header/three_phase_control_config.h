#include "gpio.h"
#include "timer.h"
#include "three_phase_control.h"


static const three_phase_channels_t PhaseChannels = {

    .ch = {TIM_CHANNEL_1, TIM_CHANNEL_2, TIM_CHANNEL_3},

};

        gpio_config_t GPIO_UPHASE = {

        .port = GPIOE,
        .pin = 9,
        .mode = GPIO_MODE_AF,
        .type = GPIO_OUTPUT_TYPE_PUSH_PULL,
        .speed = GPIO_OUTPUT_SPEED_HIGH,
        .pull = GPIO_NO_PULL,
        .af = GPIO_AF1,

    };

        gpio_config_t GPIO_UPHASE_N = {

        .port = GPIOE,
        .pin = 8,
        .mode = GPIO_MODE_AF,
        .type = GPIO_OUTPUT_TYPE_PUSH_PULL,
        .speed = GPIO_OUTPUT_SPEED_HIGH,
        .pull = GPIO_NO_PULL,
        .af = GPIO_AF1,

    };

        gpio_config_t GPIO_VPHASE = {

        .port = GPIOE,
        .pin = 11,
        .mode = GPIO_MODE_AF,
        .type = GPIO_OUTPUT_TYPE_PUSH_PULL,
        .speed = GPIO_OUTPUT_SPEED_HIGH,
        .pull = GPIO_NO_PULL,
        .af = GPIO_AF1,

    };

        gpio_config_t GPIO_VPHASE_N = {

        .port = GPIOE,
        .pin = 10,
        .mode = GPIO_MODE_AF,
        .type = GPIO_OUTPUT_TYPE_PUSH_PULL,
        .speed = GPIO_OUTPUT_SPEED_HIGH,
        .pull = GPIO_NO_PULL,
        .af = GPIO_AF1,

    };

        gpio_config_t GPIO_WPHASE = {

        .port = GPIOE,
        .pin = 13,
        .mode = GPIO_MODE_AF,
        .type = GPIO_OUTPUT_TYPE_PUSH_PULL,
        .speed = GPIO_OUTPUT_SPEED_HIGH,
        .pull = GPIO_NO_PULL,
        .af = GPIO_AF1,

    };

        gpio_config_t GPIO_WPHASE_N = {

        .port = GPIOE,
        .pin = 12,
        .mode = GPIO_MODE_AF,
        .type = GPIO_OUTPUT_TYPE_PUSH_PULL,
        .speed = GPIO_OUTPUT_SPEED_HIGH,
        .pull = GPIO_NO_PULL,
        .af = GPIO_AF1,

    };

    TIM_Handle_t pwm_handle = {

    .timer = TIM1,
    .base = {
        .timer_mode = TIMER_EDGE_ALIGNED_MODE,
        .counter_direction = TIMER_UPCOUNTER_MODE,
        .prescaler = 0, //168MHz
        .period = 6720-1, //168MHz/6720 = 25kHz
        .slave_mode = SLAVE_MODE_DISABLE,
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
            .compare = 6720*0.75, //50% duty cycle
        },
        .channel[TIM_CHANNEL_2] = {
            .cc_mode = CC_OUTPUT_MODE,
            .oc_mode = OC_PWM1_MODE,
            .oc_preload_enable = true,
            .oc_fast_enable = false,
            .cc_output_polarity = CC_OUTPUT_POLARITY_HIGH,
            .cc_output_enable = CC_OUTPUT_ENABLE,
            .cc_complementary_output_enable = CC_OUTPUT_DISABLED,
            .compare = 6720*0.75, //50% duty cycle
        },
        .channel[TIM_CHANNEL_3] = {
            .cc_mode = CC_OUTPUT_MODE,
            .oc_mode = OC_PWM1_MODE,
            .oc_preload_enable = true,
            .oc_fast_enable = false,
            .cc_output_polarity = CC_OUTPUT_POLARITY_HIGH,
            .cc_output_enable = CC_OUTPUT_ENABLE,
            .cc_complementary_output_enable = CC_OUTPUT_DISABLED,
            .compare = 6720*0.75, //50% duty cycle
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

