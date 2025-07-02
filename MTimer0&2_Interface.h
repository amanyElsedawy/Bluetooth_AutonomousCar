
#ifndef  MTimer0_Interface_H
#define  MTimer0_Interface_H


// Function Prototypes for timer0
void MTMR0_voidInit(void);
u8 MTMR0_u8SetCallBack(void(*Copy_pf)(void));
u8 MTMR0_u8SetCallBackCTCMode(void(*Copy_pf)(void));
void MTMR0_voidSetOCR0Value(u8 Copy_u8OCR0value);
//timer0 modes
#define   normal_mode          0
#define   CTC_mode             1
#define   PWM_mode_Fast        2
#define   PWM_mode_phase       3
#define   Normal_counter_mode  4


// Timer2 Modes
#define TIMER2_NORMAL_MODE             0
#define TIMER2_CTC_MODE                1
#define TIMER2_PWM_FAST_MODE           2
#define TIMER2_PWM_PHASE_CORRECT_MODE  3

// Function Prototypes for timer2
void MTMR2_voidInit(void);
void MTMR2_voidSetOCR2Value(u8 Copy_u8OCR2Value);
u8 MTMR2_u8SetCallBack(void (*Copy_pf)(void));
u8 MTMR2_u8SetCallBackCTCMode(void (*Copy_pf)(void));
#endif
