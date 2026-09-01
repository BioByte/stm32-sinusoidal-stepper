#include "three_phase_control_config.h"


void ThreePhaseControl_Init(void){

    GPIO_EnableClock(&GPIO_UPHASE);

    GPIO_Init(&GPIO_UPHASE);
    GPIO_Init(&GPIO_VPHASE);
    GPIO_Init(&GPIO_WPHASE);

    TIM_HWClockEnable(&pwm_handle);
    TIM_BaseInit(&pwm_handle);

    TIM_OCInit(&pwm_handle, PhaseChannels.ch[UPHASE]);
    TIM_OCInit(&pwm_handle, PhaseChannels.ch[VPHASE]);
    TIM_OCInit(&pwm_handle, PhaseChannels.ch[WPHASE]);

    TIM_BDTRInit(&pwm_handle);
    ThreePhaseControl_MasterOutputEnable();
    TIM_Start(&pwm_handle);

}

void ThreePhaseControl_UpdatePhase(enum motor_phases phase, uint16_t compare){

    pwm_handle.channels.channel[PhaseChannels.ch[phase]].compare = compare;
    TIM_UpdateCompare(&pwm_handle, PhaseChannels.ch[phase], compare);

}

void ThreePhaseControl_Start(void){

    TIM_Start(&pwm_handle);

}

void ThreePhaseControl_Stop(void){

    TIM_Stop(&pwm_handle);

}

void ThreePhaseControl_MasterOutputEnable(void){

    pwm_handle.bdtr.MOE = true;
    TIM_MasterOCEnable(&pwm_handle);

}

void ThreePhaseControl_MasterOutputDisable(void){

    pwm_handle.bdtr.MOE = false;
    TIM_MasterOCDisable(&pwm_handle);

}
