#ifndef THREE_PHASE_CONTROL_H
#define THREE_PHASE_CONTROL_H

/******************************************************************************
 * Three-Phase Control Header file
 *
 * This library is responsible to control the PWM duty and Output Compare states
 * 
 ******************************************************************************/

#include <stdint.h>
#include "timer.h"

/// @brief Enum for motor phases
typedef enum motor_phases{
    UPHASE,
    VPHASE,
    WPHASE
} motor_phases_t;

/// @brief Initializes the three-phase control
/// @param  
void ThreePhaseControl_Init(void);

/// @brief Updates the PWM compare value for a specific phase
/// @param phase 
/// @param compare 
void ThreePhaseControl_UpdatePhase(motor_phases_t phase, uint16_t compare);

/// @brief Starts the three-phase control
/// @param  
void ThreePhaseControl_Start(void);

/// @brief Stops the three-phase control
/// @param  
void ThreePhaseControl_Stop(void);

/// @brief Enables the master output
/// @param  
void ThreePhaseControl_MasterOutputEnable(void);

/// @brief Disables the master output
/// @param  
void ThreePhaseControl_MasterOutputDisable(void);

/// @brief Registers a callback function for PWM events
/// @param callback 
void ThreePhaseControl_RegisterCallback(TIM_Callback_t callback);

/// @brief Gets the PWM frequency
/// @param  
/// @return PWM frequency in Hz
uint32_t ThreePhaseControl_getPWMFrequency(void);

#endif // THREE_PHASE_CONTROL_H