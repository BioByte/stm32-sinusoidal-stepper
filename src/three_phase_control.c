#include "three_phase_control.h"
#include "three_phase_control_config.h"


void ThreePhaseControl_Init(void){

    GPIO_EnableClock(&GPIO_UPHASE);

    GPIO_Init(&GPIO_UPHASE);
    GPIO_Init(&GPIO_VPHASE);
    GPIO_Init(&GPIO_WPHASE);

    TIM_HWClockEnable(&PHASES_PWM_HANDLE);
    TIM_BaseInit(&PHASES_PWM_HANDLE);

    TIM_OCInit(&PHASES_PWM_HANDLE, PhaseChannels.ch[UPHASE]);
    TIM_OCInit(&PHASES_PWM_HANDLE, PhaseChannels.ch[VPHASE]);
    TIM_OCInit(&PHASES_PWM_HANDLE, PhaseChannels.ch[WPHASE]);

    TIM_BDTRInit(&PHASES_PWM_HANDLE);
    ThreePhaseControl_MasterOutputEnable();
    NVIC_SetPriority(TIM1_UP_TIM10_IRQn, 2);
    NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
    //TIM_Start(&PHASES_PWM_HANDLE);

}

void ThreePhaseControl_UpdatePhase(enum motor_phases phase, uint16_t compare){

    PHASES_PWM_HANDLE.channels.channel[PhaseChannels.ch[phase]].compare = compare;
    TIM_UpdateCompare(&PHASES_PWM_HANDLE, PhaseChannels.ch[phase], compare);

}

void ThreePhaseControl_Start(void){

    TIM_Start(&PHASES_PWM_HANDLE);

}

void ThreePhaseControl_Stop(void){

    TIM_Stop(&PHASES_PWM_HANDLE);

}

void ThreePhaseControl_MasterOutputEnable(void){

    PHASES_PWM_HANDLE.bdtr.MOE = true;
    TIM_MasterOCEnable(&PHASES_PWM_HANDLE);

}

void ThreePhaseControl_MasterOutputDisable(void){

    PHASES_PWM_HANDLE.bdtr.MOE = false;
    TIM_MasterOCDisable(&PHASES_PWM_HANDLE);

}

uint32_t ThreePhaseControl_getPWMFrequency(void){

    return TIM_GetPWMFrequency(&PHASES_PWM_HANDLE);

}

void ThreePhaseControl_RegisterCallback(TIM_Callback_t callback){

    TIM_CallbackRegister(callback);

}
