/*
 * codes _to_try_sensors.h
 *
 *  Created on: Dec 19, 2024
 *      Author: amany_Elsedawy
 */
//this file only have the codes i try by it each sensor before use in main program
#ifndef CODES__TO_TRY_SENSORS_H_
#define CODES__TO_TRY_SENSORS_H_




/*
 * main.c
 *
 *  Created on: Dec 12, 2024
 *      Author: amany_Elsedawy
 */
/*
//Code to try ultrasonic
#define F_CPU 8000000UL
#include<util/delay.h>
#include "STD_TYPE.h"
#include "BIT_MAC_FUC.h"
//MCALL
#include"MDIO_Interface.h"
#include"MGIE_Interface.h"
#include"MTimer1_Interface.h"
#include"Ultrasonic_Interface.h"
//HALL
#include"HLCD_Interface.h"


int main(void){

MDIO_Init();
HLCD_void_Init();
MGIE_enable_GI();
MTMR1_voidInit();
Ultrasonic_INIT();

while(1){
	 Ultrasonic_INIT();
 if(DistanceReadyFlag == DATA_READY){
	 DistanceReadyFlag=DATA_NOT_READY;

     u16 Local_u16Distance=Ultrasonic_ReturnDistance();

     if(Local_u16Distance<20){
         // turn red led
    	     MDIO_u8SetPinValue(MDIO_PORTB,MDIO_PIN_0,MDIO_PinHigh);
    	     HLCD_SetCursor(1,0);
    	  	 HLCD_voidLcdWriteNumber(Local_u16Distance);

       }else{
           // turn green led

      	      MDIO_u8SetPinValue(MDIO_PORTB,MDIO_PIN_1,MDIO_PinHigh);
      	      HLCD_SetCursor(2,0);
      	      HLCD_voidLcdWriteNumber(Local_u16Distance);

}
           _delay_ms(500);
    	   MDIO_u8SetPinValue(MDIO_PORTB, MDIO_PIN_0, MDIO_PinLow);
    	   MDIO_u8SetPinValue(MDIO_PORTB, MDIO_PIN_1, MDIO_PinLow);
    	   HLCD_CLEAR();
   }
}


return 0;
}
*/




/*
//code try  IR sensor by interrupt
#define F_CPU 8000000UL
#include<util/delay.h>
#include "STD_TYPE.h"
#include "BIT_MAC_FUC.h"
//MCALL
#include"MDIO_Interface.h"
#include"MGIE_Interface.h"
#include"MEXTI_Interface.h"
//#include"Ultrasonic_Interface.h"
//HALL
//#include"HLCD_Interface.h"
void  try_IR1(void);
void  try_IR2(void);
int main(){


	MDIO_Init();
		//set call back ofEXINT0
		MEXTI_u8SetBack(MEXTI_INT0,&try_IR1);
		MEXTI_u8SetBack(MEXTI_INT1,&try_IR2);
		//enable forFalling Edge to detect Black line
		MEXTI_u8Enable(MEXTI_INT0,MEXTI_Falling_Edg);
        MEXTI_u8Enable(MEXTI_INT1,MEXTI_Falling_Edg);

        MGIE_enable_GI();


while(1){


}



return 0;
}
//function to test IR sensor 1
void  try_IR1(void){
//try red led
	MDIO_u8SetPinValue(MDIO_PORTB,MDIO_PIN_0,MDIO_PinHigh);

	_delay_ms(500);
	MDIO_u8SetPinValue(MDIO_PORTB,MDIO_PIN_0,MDIO_PinLow);

}

//function to test IR sensor 2
void  try_IR2(void){
//turn green led
	MDIO_u8SetPinValue(MDIO_PORTB,MDIO_PIN_1,MDIO_PinHigh);

	_delay_ms(1000);
	MDIO_u8SetPinValue(MDIO_PORTB,MDIO_PIN_1,MDIO_PinLow);

}


*/
/*

//Code to try Bloouth module
#define F_CPU 8000000UL
#include<util/delay.h>


//LIB

#include"STD_TYPE.h"
#include"BIT_MAC_FUC.h"
//MCALL
#include"MDIO_Interface.h"
#include"UART_Interface.h"


int main(){
	 u8 receivedByte;
	MDIO_Init();
	MUART_voidInit();


	while(1){

		 receivedByte = MUART_voidRecieveByte();

		        // Check if the received byte is 'F' to control the LED
		        if (receivedByte == 'F') {
		            MDIO_u8SetPinValue(MDIO_PORTA, MDIO_PIN_7, MDIO_PinHigh); // Turn LED ON
		        }  else if (receivedByte == 'W') {
		            MDIO_u8SetPinValue(MDIO_PORTA, MDIO_PIN_6, MDIO_PinHigh); // Turn LED2 ON
		            MDIO_u8SetPinValue(MDIO_PORTA, MDIO_PIN_7, MDIO_PinLow);  // Turn LED1 OFF
		        }else{
		        	        MDIO_u8SetPinValue(MDIO_PORTA, MDIO_PIN_7, MDIO_PinLow); // Turn LED1 OFF
		        	        MDIO_u8SetPinValue(MDIO_PORTA, MDIO_PIN_6, MDIO_PinLow); // Turn LED2 OFF
		        }


	}
	return 0 ;
}

*/
/*

//last
//code to control Autonomous mode by interrupt
#define F_CPU 8000000UL
#include<util/delay.h>
//Library layer
#include "STD_TYPE.h"
#include "BIT_MAC_FUC.h"
//MCALL Layer
#include"MDIO_Interface.h"
#include"MGIE_Interface.h"
#include"MEXTI_Interface.h"
#include"MTimer1_Interface.h"
#include"MTimer_Interface.h"

//HALL Layer
#include"Ultrasonic_Interface.h"
#include"MOTORS_INTERFACE.h"
#include"HLCD_Interface.h"

//Prototype of function
void car_turn_right(void);
void car_turn_left(void);
void car_Foward(void);
void car_stop(void);
//void car_search(void);  // Function to search about line if car lost it



//volatile u8 left_detected = 0;
//volatile u8 right_detected = 0;

int main(void){

MDIO_Init();//error in this line
HLCD_void_Init();
MTMR0_voidInit();
MTMR2_voidInit();
MTMR1_voidInit();
Ultrasonic_INIT();

// Set Call backs Function for Interrupts
//Left IR sensor on INT1  ||   Right IR sensor on INT0
   MEXTI_u8SetBack(MEXTI_INT0, &car_turn_right);  // INT0 -> Right Turn//for rightIR
   MEXTI_u8SetBack(MEXTI_INT1, &car_turn_left);   // INT1 -> Left Turn//for left IR

   // Enable External Interrupts
   MEXTI_u8Enable(MEXTI_INT0, MEXTI_Falling_Edg);  // Falling edge for INT0
   MEXTI_u8Enable(MEXTI_INT1, MEXTI_Falling_Edg);  // Falling edge for INT1
    MGIE_enable_GI();

    //Start move Car forward
    _delay_ms(4000);
	Motor_SetSpeed(139,118);
    car_Foward();
while(1){
	 Ultrasonic_INIT();
 if(DistanceReadyFlag == DATA_READY){
	 DistanceReadyFlag=DATA_NOT_READY;
// call function return distance in cm
     u16 Local_u16Distance=Ultrasonic_ReturnDistance();

     if(Local_u16Distance<20){

    	  car_stop();
    	  //for LCD
    	 //HLCD_CLEAR();
         // HLCD_SetCursor(2,0);
          //HLCD_WriteStirng((const u8*)"obstacle_here");

       }else{
           //move car forward
    	      car_Foward();

   }

 }
}


return 0;
}
void car_turn_right(void){
  Motor_SetSpeed( 179  , 158 );
  Motor_SetDirection(MOTOR_TURN_RIGHT);
  _delay_ms(170);
  //right_detected=1;

}
void car_turn_left(void){

   Motor_SetSpeed( 179, 158);
   Motor_SetDirection(MOTOR_TURN_LEFT);
	 _delay_ms(170);
    //left_detected=1;
}
void car_Foward(void){
	Motor_SetSpeed(159,138);
	Motor_SetDirection(MOTOR_FORWARD);
}
void car_stop(void){
	Motor_SetSpeed(0,0);
	Motor_SetDirection(MOTOR_STOP);
}
 */

/*
//code to control Autonomous mode by Polling
#define F_CPU 8000000UL
#include<util/delay.h>
//Library layer
#include "STD_TYPE.h"
#include "BIT_MAC_FUC.h"
//MCALL Layer
#include"MDIO_Interface.h"
#include"MGIE_Interface.h"
//#include"MEXTI_Interface.h"
#include"MTimer1_Interface.h"
#include"MTimer_Interface.h"

//HALL Layer
#include"Ultrasonic_Interface.h"
#include"MOTORS_INTERFACE.h"
#include"HLCD_Interface.h"

//Prototype of function
void car_turn_right(void);
void car_turn_left(void);
void car_Foward(void);
void car_stop(void);
//void car_search(void);  // Function to search about line if car lost it



//volatile u8 left_detected = 0;
//volatile u8 right_detected = 0;
u8 Right_Sensor;
u8 Left_Sensor;
int main(void){

MDIO_Init();//error in this line
HLCD_void_Init();
MTMR0_voidInit();
MTMR2_voidInit();
MTMR1_voidInit();
Ultrasonic_INIT();
MGIE_enable_GI();
//
    //Start move Car forward
    car_Foward();
while(1){

	 Ultrasonic_INIT();
 if(DistanceReadyFlag == DATA_READY){
	 DistanceReadyFlag=DATA_NOT_READY;
// call function return distance in cm
     u16 Local_u16Distance=Ultrasonic_ReturnDistance();

     if(Local_u16Distance<20){

    	   car_stop();


    }   else if((MDIO_u8GetPinValue(MDIO_PORTC,MDIO_PIN_3,&Right_Sensor)==1)&&(MDIO_u8GetPinValue(MDIO_PORTC,MDIO_PIN_4,&Left_Sensor)==1))
       {
           //move car forward
    	      car_Foward();


  }       else if((MDIO_u8GetPinValue(MDIO_PORTC,MDIO_PIN_3,&Right_Sensor)==0)&&(MDIO_u8GetPinValue(MDIO_PORTC,MDIO_PIN_4,&Left_Sensor)==1))
   {
       //move car right to return to white surface
	        car_turn_right();



   }        else if((MDIO_u8GetPinValue(MDIO_PORTC,MDIO_PIN_3,&Right_Sensor)==1)&&(MDIO_u8GetPinValue(MDIO_PORTC,MDIO_PIN_4,&Left_Sensor)==0))
{
    //move car Left to return to white surface
	           car_turn_left();


}

 }
}


return 0;
}
void car_turn_right(void){
	 Motor_SetSpeed( 159, 138);

  Motor_SetDirection(MOTOR_TURN_RIGHT);
  //right_detected=1;

}
void car_turn_left(void){
	 Motor_SetSpeed( 159, 138);

	Motor_SetDirection(MOTOR_TURN_LEFT);
    //left_detected=1;
}
void car_Foward(void){
	Motor_SetSpeed(139,118);

	Motor_SetDirection(MOTOR_FORWARD);
}
void car_stop(void){
	Motor_SetSpeed(0,0);
	Motor_SetDirection(MOTOR_STOP);
}
*/

#endif /* CODES__TO_TRY_SENSORS_H_ */
