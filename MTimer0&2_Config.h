
#ifndef MTimer0_CONFIG_H
#define MTimer0_CONFIG_H

//configure timer0 modes
//normal_mode,  CTC_mode ,  PWM_mode_Fast,PWM_mode_phase
#define   normal_mode            0
#define   CTC_mode               1
#define   PWM_mode_Fast          2
#define   PWM_mode_phase         3
#define   Normal_counter_mode    4

//access the mode
#define  Timer_mode       PWM_mode_Fast


// Configure Timer2 Mode
// MTIMER2_NORMAL_MODE, MTIMER2_CTC_MODE, MTIMER2_PWM_MODE_FAST, MTIMER2_PWM_MODE_PHASE, MTIMER2_COUNTER_MODE
#define   MTIMER2_NORMAL_MODE          0
#define   MTIMER2_CTC_MODE             1
#define   MTIMER2_PWM_MODE_FAST        2
#define   MTIMER2_PWM_MODE_PHASE       3
#define   MTIMER2_COUNTER_MODE         4

//access the mode
#define Timer2_mode     MTIMER2_PWM_MODE_FAST



#endif
