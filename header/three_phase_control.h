
typedef enum motor_phases{
    UPHASE,
    VPHASE,
    WPHASE
} motor_phases_t;

typedef struct three_phase_channels{

    TIM_Channel_t ch[3];
    
} three_phase_channels_t;

void ThreePhaseControl_Init(void);
void ThreePhaseControl_UpdatePhase(motor_phases_t phase, uint16_t compare);
void ThreePhaseControl_Start(void);
void ThreePhaseControl_Stop(void);
void ThreePhaseControl_MasterOutputEnable(void);
void ThreePhaseControl_MasterOutputDisable(void);
