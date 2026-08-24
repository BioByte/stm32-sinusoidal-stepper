#include "stm32f407xx.h"
#include "timer.h"


void TIM_HWClockEnable(const TIM_Handle_t *tim_handle){

    if(tim_handle->timer == TIM1){

        RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

    }
    else if (tim_handle->timer == TIM2){

        RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    }
    else if (tim_handle->timer == TIM3){

        RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

    }
    else if (tim_handle->timer == TIM4){

        RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

    }
    else if (tim_handle->timer == TIM5){

        RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;

    }
    else if (tim_handle->timer == TIM8){

        RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;

    }

}

void TIM_BaseInit(const TIM_Handle_t *tim_handle){

        tim_handle->timer->CR1 &= ~(TIM_CR1_CMS_Msk | TIM_CR1_DIR_Msk);
        tim_handle->timer->SMCR &= ~(TIM_SMCR_SMS_Msk);
        
    
        tim_handle->timer->CR1 |= (tim_handle->base.timer_mode << TIM_CR1_CMS_Pos) | (tim_handle->base.counter_direction << TIM_CR1_DIR_Pos);
        tim_handle->timer->PSC = tim_handle->base.prescaler;
        tim_handle->timer->ARR = tim_handle->base.period;
        tim_handle->timer->SMCR |= tim_handle->base.slave_mode << TIM_SMCR_SMS_Pos;

}

void TIM_OCInit(const TIM_Handle_t *tim_handle, TIM_Channel_t channel){

    switch (channel)
        {
        case TIM_CHANNEL_1:

                tim_handle->timer->CCMR1 &= ~(TIM_CCMR1_CC1S_Msk | 
                                            TIM_CCMR1_OC1M_Msk  | 
                                            TIM_CCMR1_OC1PE_Msk | 
                                            TIM_CCMR1_OC1FE_Msk);
                tim_handle->timer->CCER &= ~(TIM_CCER_CC1P_Msk | 
                                            TIM_CCER_CC1E_Msk | 
                                            TIM_CCER_CC1NP_Msk | 
                                            TIM_CCER_CC1NE_Msk);

                tim_handle->timer->CCMR1 |= (tim_handle->channels.channel[channel].cc_mode << TIM_CCMR1_CC1S_Pos);
                tim_handle->timer->CCMR1 |= (tim_handle->channels.channel[channel].oc_mode << TIM_CCMR1_OC1M_Pos);
                tim_handle->timer->CCMR1 |= (tim_handle->channels.channel[channel].oc_preload_enable << TIM_CCMR1_OC1PE_Pos);
                tim_handle->timer->CCMR1 |= (tim_handle->channels.channel[channel].oc_fast_enable << TIM_CCMR1_OC1FE_Pos);
                tim_handle->timer->CCER |= (tim_handle->channels.channel[channel].cc_output_polarity << TIM_CCER_CC1P_Pos) | (tim_handle->channels.channel[channel].cc_output_enable << TIM_CCER_CC1E_Pos);
                tim_handle->timer->CCER |= (tim_handle->channels.channel[channel].cc_complementary_output_polarity << TIM_CCER_CC1NP_Pos) | (tim_handle->channels.channel[channel].cc_complementary_output_enable << TIM_CCER_CC1NE_Pos);

                tim_handle->timer->CCR1 = tim_handle->channels.channel[channel].compare;

            break;
        case TIM_CHANNEL_2:
                tim_handle->timer->CCMR1 &= ~(TIM_CCMR1_CC2S_Msk | 
                                            TIM_CCMR1_OC2M_Msk  | 
                                            TIM_CCMR1_OC2PE_Msk | 
                                            TIM_CCMR1_OC2FE_Msk);
                tim_handle->timer->CCER &= ~(TIM_CCER_CC2P_Msk | 
                                            TIM_CCER_CC2E_Msk |
                                            TIM_CCER_CC2NP_Msk |
                                            TIM_CCER_CC2NE_Msk);    
                
                tim_handle->timer->CCMR1 |= (tim_handle->channels.channel[channel].cc_mode << TIM_CCMR1_CC2S_Pos);
                tim_handle->timer->CCMR1 |= (tim_handle->channels.channel[channel].oc_mode << TIM_CCMR1_OC2M_Pos);
                tim_handle->timer->CCMR1 |= (tim_handle->channels.channel[channel].oc_preload_enable << TIM_CCMR1_OC2PE_Pos);
                tim_handle->timer->CCMR1 |= (tim_handle->channels.channel[channel].oc_fast_enable << TIM_CCMR1_OC2FE_Pos);
                tim_handle->timer->CCER |= (tim_handle->channels.channel[channel].cc_output_polarity << TIM_CCER_CC2P_Pos) | (tim_handle->channels.channel[channel].cc_output_enable << TIM_CCER_CC2E_Pos);
                tim_handle->timer->CCER |= (tim_handle->channels.channel[channel].cc_complementary_output_polarity << TIM_CCER_CC2NP_Pos) | (tim_handle->channels.channel[channel].cc_complementary_output_enable << TIM_CCER_CC2NE_Pos);

                tim_handle->timer->CCR2 = tim_handle->channels.channel[channel].compare;

            break;
        case TIM_CHANNEL_3:
                tim_handle->timer->CCMR2 &= ~(TIM_CCMR2_CC3S_Msk | 
                                            TIM_CCMR2_OC3M_Msk  | 
                                            TIM_CCMR2_OC3PE_Msk | 
                                            TIM_CCMR2_OC3FE_Msk);
                tim_handle->timer->CCER &= ~(TIM_CCER_CC3P_Msk | 
                                            TIM_CCER_CC3E_Msk |
                                            TIM_CCER_CC3NP_Msk |
                                            TIM_CCER_CC3NE_Msk);    

                tim_handle->timer->CCMR2 |= (tim_handle->channels.channel[channel].cc_mode << TIM_CCMR2_CC3S_Pos);
                tim_handle->timer->CCMR2 |= (tim_handle->channels.channel[channel].oc_mode << TIM_CCMR2_OC3M_Pos);
                tim_handle->timer->CCMR2 |= (tim_handle->channels.channel[channel].oc_preload_enable << TIM_CCMR2_OC3PE_Pos);
                tim_handle->timer->CCMR2 |= (tim_handle->channels.channel[channel].oc_fast_enable << TIM_CCMR2_OC3FE_Pos);
                tim_handle->timer->CCER |= (tim_handle->channels.channel[channel].cc_output_polarity << TIM_CCER_CC3P_Pos) | (tim_handle->channels.channel[channel].cc_output_enable << TIM_CCER_CC3E_Pos);
                tim_handle->timer->CCER |= (tim_handle->channels.channel[channel].cc_complementary_output_polarity << TIM_CCER_CC3NP_Pos) | (tim_handle->channels.channel[channel].cc_complementary_output_enable << TIM_CCER_CC3NE_Pos);

                tim_handle->timer->CCR3 = tim_handle->channels.channel[channel].compare;

            break;  
        case TIM_CHANNEL_4:
                tim_handle->timer->CCMR2 &= ~(TIM_CCMR2_CC4S_Msk | 
                                            TIM_CCMR2_OC4M_Msk  | 
                                            TIM_CCMR2_OC4PE_Msk | 
                                            TIM_CCMR2_OC4FE_Msk);
                tim_handle->timer->CCER &= ~(TIM_CCER_CC4P_Msk | 
                                            TIM_CCER_CC4E_Msk);    

                tim_handle->timer->CCMR2 |= (tim_handle->channels.channel[channel].cc_mode << TIM_CCMR2_CC4S_Pos);
                tim_handle->timer->CCMR2 |= (tim_handle->channels.channel[channel].oc_mode << TIM_CCMR2_OC4M_Pos);
                tim_handle->timer->CCMR2 |= (tim_handle->channels.channel[channel].oc_preload_enable << TIM_CCMR2_OC4PE_Pos);
                tim_handle->timer->CCMR2 |= (tim_handle->channels.channel[channel].oc_fast_enable << TIM_CCMR2_OC4FE_Pos);
                tim_handle->timer->CCER |= (tim_handle->channels.channel[channel].cc_output_polarity << TIM_CCER_CC4P_Pos) | (tim_handle->channels.channel[channel].cc_output_enable << TIM_CCER_CC4E_Pos);

                tim_handle->timer->CCR4 = tim_handle->channels.channel[channel].compare;

                break;
        
        default:
            break;
    }
}

void TIM_BDTRInit(const TIM_Handle_t *tim_handle){

    tim_handle->timer->BDTR &= ~(TIM_BDTR_MOE_Msk | 
                                TIM_BDTR_AOE_Msk | 
                                TIM_BDTR_BKP_Msk | 
                                TIM_BDTR_BKE_Msk | 
                                TIM_BDTR_OSSR_Msk | 
                                TIM_BDTR_OSSI_Msk | 
                                TIM_BDTR_DTG_Msk);

    tim_handle->timer->BDTR |= (tim_handle->bdtr.MOE << TIM_BDTR_MOE_Pos) |
                               (tim_handle->bdtr.AOE << TIM_BDTR_AOE_Pos) |
                               (tim_handle->bdtr.BKP << TIM_BDTR_BKP_Pos) |
                               (tim_handle->bdtr.BKE << TIM_BDTR_BKE_Pos) |
                               (tim_handle->bdtr.OSSR << TIM_BDTR_OSSR_Pos) |
                               (tim_handle->bdtr.OSSI << TIM_BDTR_OSSI_Pos) |
                               (tim_handle->bdtr.DTG << TIM_BDTR_DTG_Pos);

}

void TIM_Start(const TIM_Handle_t *tim_handle){

    tim_handle->timer->CR1 |= TIM_CR1_CEN_Msk;

}

void TIM_Stop(const TIM_Handle_t *tim_handle){

    tim_handle->timer->CR1 &= ~TIM_CR1_CEN_Msk;

}

void TIM_UpdateCompare(const TIM_Handle_t *tim_handle, TIM_Channel_t channel, uint16_t compare){

    switch(channel){
        case TIM_CHANNEL_1:
            tim_handle->timer->CCR1 = compare;
            break;
        case TIM_CHANNEL_2:
            tim_handle->timer->CCR2 = compare;
            break;
        case TIM_CHANNEL_3:
            tim_handle->timer->CCR3 = compare;
            break;
        case TIM_CHANNEL_4:
            tim_handle->timer->CCR4 = compare;
            break;
        default:
            break;
    }

}

void TIM_MasterOCEnable(const TIM_Handle_t *tim_handle){

    tim_handle->timer->BDTR |= TIM_BDTR_MOE_Msk;

}

void TIM_MasterOCDisable(const TIM_Handle_t *tim_handle){

    tim_handle->timer->BDTR &= ~TIM_BDTR_MOE_Msk;

}
