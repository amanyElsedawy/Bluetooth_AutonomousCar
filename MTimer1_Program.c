/*
 * MTimer1_Program.c
 *
 *  Created on: Dec 12, 2024
 *      Author:amany_Elsedawy
 */



//Lib  Layer

#include "STD_TYPE.h"
#include "BIT_MAC_FUC.h"
//MCALL
#include"MTimer1_Interface.h"
#include"MTimer1_Private.h"
#include"MTimer1_Config.h"
//timer1
volatile u8 DistanceReadyFlag=DATA_NOT_READY;
static u16  MTMR_u16Tonperiod;
static u16  MTMR_u16Toffperiod;
void MTMR1_voidInit(void){

 //servo motor
 ///select timer1 mode=14
#if Timer1_Mode==PWM_FAST
SET_BIT(private_TCCR1A  ,1);
CLR_BIT(private_TCCR1A  ,0);


SET_BIT(private_TCCR1B  ,4);
SET_BIT(private_TCCR1B  ,3);
//set OC1A pin->non verted mode
SET_BIT(private_TCCR1A,7);
CLR_BIT(private_TCCR1A,6);
//set max value in ICR1  as mode of mode 14
private_u16_ICR1=19999;
//set OCR1A to make server motor go to angle zero
private_u16_OCR1A=1499;
//set timer1 by set prescaler value=8
CLR_BIT(private_TCCR1B,2);
CLR_BIT(private_TCCR1B,0);

SET_BIT(private_TCCR1B,1);
//on pin 5 portD*/

#elif Timer1_Mode==NORMAL_Mode
	//set timer 1 on normal mode
	CLR_BIT(private_TCCR1A  ,1);
	CLR_BIT(private_TCCR1A  ,0);
    CLR_BIT(private_TCCR1B  ,4);
	CLR_BIT(private_TCCR1B  ,3);
//timer1 hardware Configuration
//enable ICU unit
//set trigger source to be  in rising edge
#if Timer1==ICU_INIT
     SET_BIT(private_TCCR1B,6);
//enable interput of ICU
    SET_BIT(private_TIMSK,5);
	//set timer1 by set prescaler value=8
	CLR_BIT(private_TCCR1B,2);
	CLR_BIT(private_TCCR1B,0);
    SET_BIT(private_TCCR1B,1);
#endif


#endif
}


//ISR->ICU

#define Raising_Edg   0
#define Falling_Edg   1
void __vector_6(void) __attribute__((signal));

void __vector_6(void){
	// Set the flag to indicate new distance is ready
	 DistanceReadyFlag = DATA_READY;
	static u16 Local_u16pervoiusCounter;
	static u8 Local_u8flag=Raising_Edg;

	u16 Local_u16CurrentCounter=private_u16_ICR1;

	if(Local_u8flag==Raising_Edg){
		MTMR_u16Toffperiod=Local_u16CurrentCounter-Local_u16pervoiusCounter;

		//change  pit to falling edge
		CLR_BIT(private_TCCR1B,6);
		//update flag
		Local_u8flag=Falling_Edg;



	}else{
		MTMR_u16Tonperiod=Local_u16CurrentCounter-Local_u16pervoiusCounter;



		//change  pit to falling edge
		     SET_BIT(private_TCCR1B,6);
		//update flag
		     Local_u8flag=Raising_Edg;

	}
	Local_u16pervoiusCounter=Local_u16CurrentCounter;

}



u16  MTMR1_u16GetOnperiod(void){

return MTMR_u16Tonperiod;



}
u16  MTMR1_u16GetTotalperiod(void){


	return  ( MTMR_u16Tonperiod+MTMR_u16Toffperiod);
}
