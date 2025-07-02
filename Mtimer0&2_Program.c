
//Lib  Layer

#include "STD_TYPE.h"
#include "BIT_MAC_FUC.h"
#include "MTimer0&2_Config.h"
#include "MTimer0&2_Interface.h"
#include "MTimer0&2_Private.h"




static void(*MTMR0_pf)(void)=NULL;
static void(*MTMR0_pfCtcmode)(void)=NULL;
volatile u16 Global_u16OverflowCount = 0;  // 16-bit variable to track overflow
static void (*MTMR2_pf)(void) = NULL;
static void (*MTMR2_pfCTCMode)(void) = NULL;
volatile u16 Global_u16OverflowCount1 = 0;  // 16-bit variable to track overflow


void MTMR0_voidInit(void){
//set timer 0 mode->normal mode
#if Timer_mode == normal_mode
    CLR_BIT(private_TCCR0,6);
	CLR_BIT(private_TCCR0,3);
//enable normal mode interrput
SET_BIT(private_TIMSK,0);
//set pre load value
private_TCNT0=192;
//start timer by select prescaler timer
CLR_BIT(private_TCCR0,0);
CLR_BIT(private_TCCR0,2);
SET_BIT(private_TCCR0,1);

//CtC mode
//timer0->ctc mode
#elif Timer_mode == CTC_mode
CLR_BIT(private_TCCR0,6);
SET_BIT(private_TCCR0,3);
//enable compare match intterput

SET_BIT(private_TIMSK,1);
//set compare match regigter
private_OCR0=99;
//start timer by select prescaler timer
CLR_BIT(private_TCCR0,0);
CLR_BIT(private_TCCR0,2);
SET_BIT(private_TCCR0,1);
//PWM MODE
//timer0->PWM mode
#elif  Timer_mode == PWM_mode_Fast
SET_BIT(private_TCCR0,6);
SET_BIT(private_TCCR0,3);
//set hardware pin oc0->non_inverted mode
SET_BIT(private_TCCR0,5);
CLR_BIT(private_TCCR0,4);
//set duty_cycle
private_OCR0=0;
//start timer by select prescaler timer
CLR_BIT(private_TCCR0,0);
CLR_BIT(private_TCCR0,2);
SET_BIT(private_TCCR0,1);

//PWM_mode_phase
#elif  Timer_mode == PWM_mode_phase
SET_BIT(private_TCCR0,6);
CLR_BIT(private_TCCR0,3);
//set hardware pin oc0->non_inverted mode
SET_BIT(private_TCCR0,5);
CLR_BIT(private_TCCR0,4);
//set duty_cycle
private_OCR0=0;
//start timer by select prescaler timer
CLR_BIT(private_TCCR0,0);
CLR_BIT(private_TCCR0,2);
SET_BIT(private_TCCR0,1);


//COUNTER in NORMAL mode

#elif  Timer_mode == Normal_counter_mode
private_TCNT0=0;
//counter on normal mode
     CLR_BIT(private_TCCR0,6);
	CLR_BIT(private_TCCR0,3);

	//enable normal mode interrupt
	SET_BIT(private_TIMSK,0);

//init  timer as counter
    CLR_BIT(private_TCCR0,0);
	SET_BIT(private_TCCR0,1);
	SET_BIT(private_TCCR0,2);


#endif
}


void MTMR0_voidSetOCR0Value(u8 Copy_u8OCR0value){

	private_OCR0= Copy_u8OCR0value;


}


u8 MTMR0_u8SetCallBack(void(*Copy_pf)(void)){

u8 Local_u8ErrorState=STD_TYPE_NOK;
if(Copy_pf!=NULL){
	 Local_u8ErrorState=STD_TYPE_OK;
	 //set call back function
	 MTMR0_pf=Copy_pf;


}

return  Local_u8ErrorState;

}
u8 MTMR0_u8SetCallBackCTCMode(void(*Copy_pf)(void)){


	u8 Local_u8ErrorState=STD_TYPE_NOK;
	if(Copy_pf!=NULL){
		 Local_u8ErrorState=STD_TYPE_OK;
		 //set call back function
		 MTMR0_pfCtcmode=Copy_pf;


	}

	return  Local_u8ErrorState;



}
// Normal Mode ISR (Overflow Interrupt)
//ISR for tomer0 ovf
#if Timer_mode == normal_mode
void __vector_11(void) __attribute__((signal));

void __vector_11(void){

static u16 Local_u16Counter=0;
  Local_u16Counter++;

if( Local_u16Counter==3907){

//set timer counter with preload value
  private_TCNT0=192;
//action
   if(MTMR0_pf!=NULL){
      MTMR0_pf();
}
   //clear counter
   Local_u16Counter=0;

}
}
#endif

//ISR forNORMAL_COUNTER mode
#if Timer_mode ==Normal_counter_mode
void __vector_11(void) __attribute__((signal));

void __vector_11(void){
	 Global_u16OverflowCount++;

}
#endif
// CTC Mode ISR (Compare Match Interrupt)
//ISR for tomer0 compare match
#if Timer_mode == CTC_mode
void __vector_10(void) __attribute__((signal));

void __vector_10(void){

	static u16 Local_u16Counter=0;
	  Local_u16Counter++;
	if(Local_u16Counter==10000){
		if(MTMR0_pfCtcmode!=NULL){

			MTMR0_pfCtcmode();

}
//clear counter
	 Local_u16Counter=0;
}

}
#endif

void MTMR2_voidInit(void) {
#if Timer2_mode == MTIMER2_NORMAL_MODE
    // Normal mode: WGM21 = 0, WGM20 = 0
    CLR_BIT(private_TCCR2, 6);
    CLR_BIT(private_TCCR2, 3);
    // Enable overflow interrupt
    SET_BIT(private_TIMSK, 6);
    // Pre-load value
    private_TCNT2 = 0;
    // Start timer with prescaler = 64
    CLR_BIT(private_TCCR2, 0);
    CLR_BIT(private_TCCR2, 2);
    SET_BIT(private_TCCR2, 1);

#elif Timer2_mode == MTIMER2_CTC_MODE
    // CTC mode: WGM21 = 1, WGM20 = 0
    SET_BIT(private_TCCR2, 6);
    CLR_BIT(private_TCCR2, 3);
    // Enable compare match interrupt
    SET_BIT(private_TIMSK, 7);
    // Set compare match register
    private_OCR2 = 99;
    // Start timer with prescaler = 64
    CLR_BIT(private_TCCR2, 0);
    CLR_BIT(private_TCCR2, 2);
    SET_BIT(private_TCCR2, 1);

#elif Timer2_mode == MTIMER2_PWM_MODE_FAST
    // Fast PWM mode: WGM21 = 1, WGM20 = 1
    SET_BIT(private_TCCR2, 6);
    SET_BIT(private_TCCR2, 3);
    // Set OC2 pin to non-inverted mode
    CLR_BIT(private_TCCR2, 4);
    SET_BIT(private_TCCR2, 5);
    // Set duty cycle
    private_OCR2 = 0;
    // Start timer with prescaler = 64
    CLR_BIT(private_TCCR2, 0);
    CLR_BIT(private_TCCR2, 2);
    SET_BIT(private_TCCR2, 1);

#elif Timer2_mode == MTIMER2_PWM_MODE_PHASE
    // Phase Correct PWM mode: WGM21 = 0, WGM20 = 1
    CLR_BIT(private_TCCR2, 6);
    SET_BIT(private_TCCR2, 3);
    // Set OC2 pin to non-inverted mode
    CLR_BIT(private_TCCR2, 4);
    SET_BIT(private_TCCR2, 5);
    // Set duty cycle
    private_OCR2 = 0;
    // Start timer with prescaler = 64
    CLR_BIT(private_TCCR2, 0);
    CLR_BIT(private_TCCR2, 2);
    SET_BIT(private_TCCR2, 1);

#elif Timer2_mode == MTIMER2_COUNTER_MODE
    // Counter mode: Normal mode
    CLR_BIT(private_TCCR2, 6);
    CLR_BIT(private_TCCR2, 3);
    // Enable overflow interrupt
    SET_BIT(private_TIMSK, 6);
    // Pre-load counter value
    private_TCNT2 = 0;
    // Counter mode, external clock
    SET_BIT(private_TCCR2, 2);
    CLR_BIT(private_TCCR2, 0);
    SET_BIT(private_TCCR2, 1);

#endif
}

void MTMR2_voidSetOCR2Value(u8 Copy_u8OCR2Value) {
    private_OCR2 = Copy_u8OCR2Value;
}

u8 MTMR2_u8SetCallBack(void (*Copy_pf)(void)) {
    u8 Local_u8ErrorState = STD_TYPE_NOK;
    if (Copy_pf != NULL) {
        Local_u8ErrorState = STD_TYPE_OK;
        MTMR2_pf = Copy_pf;
    }
    return Local_u8ErrorState;
}

u8 MTMR2_u8SetCallBackCTCMode(void (*Copy_pf)(void)) {
    u8 Local_u8ErrorState = STD_TYPE_NOK;
    if (Copy_pf != NULL) {
        Local_u8ErrorState = STD_TYPE_OK;
        MTMR2_pfCTCMode = Copy_pf;
    }
    return Local_u8ErrorState;
}

// ISR for Timer2 Overflow
#if Timer2_mode == MTIMER2_NORMAL_MODE
void __vector_5(void) __attribute__((signal));
void __vector_5(void) {
    if (MTMR2_pf != NULL) {
        MTMR2_pf();
    }
}
#endif

// ISR for Timer2 Compare Match
#if Timer2_mode == MTIMER2_CTC_MODE
void __vector_4(void) __attribute__((signal));
void __vector_4(void)  {
    if (MTMR2_pfCTCMode != NULL) {
    	MTMR2_pfCTCMode();
    }
}
#endif

