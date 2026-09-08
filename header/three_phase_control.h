#ifndef THREE_PHASE_CONTROL_H
#define THREE_PHASE_CONTROL_H
#include <stdint.h>
#include "timer.h"
typedef enum motor_phases{
    UPHASE,
    VPHASE,
    WPHASE
} motor_phases_t;

void ThreePhaseControl_Init(void);
void ThreePhaseControl_UpdatePhase(motor_phases_t phase, uint16_t compare);
void ThreePhaseControl_Start(void);
void ThreePhaseControl_Stop(void);
void ThreePhaseControl_MasterOutputEnable(void);
void ThreePhaseControl_MasterOutputDisable(void);
void ThreePhaseControl_RegisterCallback(TIM_Callback_t callback);
uint32_t ThreePhaseControl_getPWMFrequency(void);

#endif // THREE_PHASE_CONTROL_H