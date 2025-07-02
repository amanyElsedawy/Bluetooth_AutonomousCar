/*
 * Ultrasonic_Program.c
 *
 *  Created on: Dec 12, 2024
 *  Author: amany_Elsedawy
 */

#define F_CPU 8000000UL
#include<util/delay.h>

#include "STD_TYPE.h"
#include "BIT_MAC_FUC.h"
//MCALL
#include"MTimer1_Interface.h"
#include"Ultrasonic_Interface.h"
#include"Ultrasonic_Config.h"

void  Ultrasonic_INIT(void){

  MDIO_u8SetPinValue(TRIG_Port,TRIG_Pin,MDIO_PinHigh);
  _delay_us(10); // 10 microseconds

  MDIO_u8SetPinValue(TRIG_Port,TRIG_Pin,MDIO_PinLow);


}


//complete this function based on driver
u16 Ultrasonic_ReturnDistance(void){
	 u16 Local_u16TimeOfECHO = MTMR1_u16GetOnperiod();//on period is period from sensor to block and back
    // Speed of sound = 343 m/s = 34300 cm/s
   // Distance = (Time * Speed) / 2
  // Each timer tick is 1 µs with a prescaler of 8 at 8 MHz
    u16 Local_u16Distance = (Local_u16TimeOfECHO * 34300UL) / (2 * 1000000UL); // Convert time to cm
    return Local_u16Distance;
}


