#include "stm32f407xx.h"
#include "stdbool.h"


/// @brief Center-aligned mode selection. Set CMS bits in TIMx_CR1 register
typedef enum timer_mode{

    TIMER_EDGE_ALIGNED_MODE,
    TIMER_CENTER_ALIGNED_MODE_1,
    TIMER_CENTER_ALIGNED_MODE_2,
    TIMER_CENTER_ALIGNED_MODE_3,

}timer_mode_t;

/// @brief Counter direction. Set DIR bits in TIMx_CR1 register
typedef enum timer_counter_direction{

    TIMER_UPCOUNTER_MODE,
    TIMER_DOWNCOUNTER_MODE,

}timer_counter_direction_mode_t;

/// @brief Select an external signal for clock reference. Set SMS bits in TIMx_SMCR
typedef enum slave_mode{

    SLAVE_MODE_DISABLE,
    ENCODER_MODE_1,
    ENCODER_MODE_2,
    ENCODER_MODE_3,
    RESET_MODE,
    GATED_MODE,
    TRIGGER_MODE,
    EXTERNAL_CLOCK_MODE_1,

}slave_mode_t;

/// @brief Compare/Capture selection, define de channel direction (I/O). Set CCxS bits in TIMx_CCMRx
typedef enum cc_config_mode{

    CC_OUTPUT_MODE,
    CC_INPUT_MODE1,
    CC_INPUT_MODE2,
    CC_INPUT_MODE3,

}cc_config_mode_t;

/// @brief Select the polarity by writing the CCxP and CCxNP bits in TIMx_CCER register
typedef enum cc_output_polarity_config_mode{

    CC_OUTPUT_POLARITY_HIGH,
    CC_OUTPUT_POLARITY_LOW,

}cc_output_polarity_config_mode_t;

/// @brief Enable the compare capture signal, writing CCxE and CCxNE bits in TIMx_CCER register
typedef enum cc_output_enable{

    CC_OUTPUT_DISABLED,
    CC_OUTPUT_ENABLE,

}cc_output_enable_t;

/// @brief Select the output compare mode. Set OCxM bits in TIMx_CCMRx bits
typedef enum oc_config_mode{

    OC_FROZEN_MODE,
    OC_ACTIVE_LEVEL_ON_MATCH_MODE,
    OC_INACTIVE_LEVEL_ON_MATCH_MODE,
    OC_TOGGLE_MODE,
    OC_FORCE_INACTIVE_LEVEL_MODE,
    OC_FORCE_ACTIVE_LEVEL_MODE,
    OC_PWM1_MODE,
    OC_PWM2_MODE,

}oc_config_mode_t;


typedef struct TIM_Base_Config{

    timer_mode_t timer_mode;
    slave_mode_t slave_mode;
    timer_counter_direction_mode_t counter_direction;
    uint16_t prescaler; //The counter clock frequency (fCK_PSC / (PSC[15:0] + 1)) TIMx_PSC register
    uint16_t period; //TIMx_ARR register;

}TIM_Base_Config_t;

typedef struct TIM_OC_Config{

    cc_config_mode_t cc_mode;
    oc_config_mode_t  oc_mode;
    bool oc_preload_enable;
        //0: Preload register on TIMx_CCR1 disabled. TIMx_CCR1 can be written at anytime, the
        //new value is taken in account immediately.
        //1: Preload register on TIMx_CCR1 enabled. Read/Write operations access the preload
        //register. TIMx_CCR1 preload value is loaded in the active register at each update event.
    bool oc_fast_enable;//used to accelerate the effect of an event on the trigger in input on the CC output
    cc_output_polarity_config_mode_t cc_output_polarity;
    cc_output_polarity_config_mode_t cc_complementary_output_polarity;
    cc_output_enable_t cc_output_enable;
    cc_output_enable_t cc_complementary_output_enable;
    uint16_t compare; //TIMx_CCRx register;

}TIM_OC_Config_t;

/// @brief Break and Dead Time register, TIMx_BDTR
typedef struct TIM_BDTR_Config{

    bool MOE; //Main Output Enable
    bool AOE; //Automatic Output Enable
    bool BKP; //Break Polarity
    bool BKE; //Break Enable
    bool OSSR; //Off-state selection for Run Mode
    bool OSSI; //Off-state selection for Idle Mode
    uint8_t DTG; //Dead-Time generator Setup

}TIM_BDTR_Config_t; 

typedef enum TIM_Channel{

    TIM_CHANNEL_1,
    TIM_CHANNEL_2,
    TIM_CHANNEL_3,
    TIM_CHANNEL_4,

}TIM_Channel_t;


typedef struct TIM_OC_Channel_Config{

    TIM_OC_Config_t channel[4];

}TIM_OC_Channel_Config_t;


typedef struct TIM_Handle{

    TIM_TypeDef *timer;
    
    TIM_Base_Config_t base;

    TIM_OC_Channel_Config_t channels;

    TIM_BDTR_Config_t bdtr;

}TIM_Handle_t;

void TIM_HWClockEnable(const TIM_Handle_t *tim_handle);

void TIM_BaseInit(const TIM_Handle_t *tim_handle);

void TIM_OCInit(const TIM_Handle_t *tim_handle, TIM_Channel_t channel);

void TIM_BDTRInit(const TIM_Handle_t *tim_handle);

void TIM_Start(const TIM_Handle_t *tim_handle);

void TIM_Stop(const TIM_Handle_t *tim_handle);

void TIM_UpdateCompare(const TIM_Handle_t *tim_handle, TIM_Channel_t channel, uint16_t compare);

void TIM_MasterOCEnable(const TIM_Handle_t *tim_handle);

void TIM_MasterOCDisable(const TIM_Handle_t *tim_handle);

