
/*
 * main.c
 *
 *  Created on: Dec 12, 2024
 *  Author: Amany_Elsedawy & Rofida_Adham
 *   version:10
 *project Description:
 *   Two driving modes for the car: manual and autonomous.
 *  1.Manual mode:
 *    controlled via Bluetooth commands over UART taken from user.
 *    Commands include forward, backward, left, right, stop, forward right,forward left,back right and back left.
 *  2.Autonomous mode :
 *    car move in algorithm line following uses ultrasonic sensor for obstacle detection.
 *    Stops if obstacle < 20 cm, otherwise moves forward.
 *    and use of  2IR Sensors controlled by  external interrupts
 *    for left and right turns when line detect
 * - Motors controlled by speed and direction settings.
 * - Global interrupts enabled for handling sensor interrupts and UART.
 * - Modes can be switched dynamically via Bluetooth commands.
 *
 */

#define F_CPU 8000000UL
#include <util/delay.h>

// Library layer
#include "STD_TYPE.h"
#include "BIT_MAC_FUC.h"

// MCAL Layer
#include "MDIO_Interface.h"
#include "MGIE_Interface.h"
#include "MEXTI_Interface.h"
#include "MTimer1_Interface.h"
#include "MTimer0&2_Interface.h"
#include "UART_Interface.h"

// HAL Layer
#include "Ultrasonic_Interface.h"
#include "MOTORS_INTERFACE.h"
#include "HLCD_Interface.h"

// Prototypes of functions
void car_turn_right(void);
void car_turn_left(void);
void car_forward(void);

void car_stop(void);

volatile u8 manual_mode = 0; // Global  flag variable to modes

int main(void) {
    u8 receivedByte;

    // Initialize all modules
    MDIO_Init();
    HLCD_void_Init();
    MUART_voidInit();
    MTMR0_voidInit();
    MTMR2_voidInit();
    MTMR1_voidInit();
    Ultrasonic_INIT();

    // Enable global interrupt
    MGIE_enable_GI();

    // Set Callbacks for interrupts
    MEXTI_u8SetBack(MEXTI_INT0, &car_turn_right); // INT0 -> Right Turn//for Right sensor
    MEXTI_u8SetBack(MEXTI_INT1, &car_turn_left);  // INT1 -> Left Turn//for Left sensor
    car_stop();
    while (1) {
        // Check for Bluetooth commands
        receivedByte = MUART_voidRecieveByte();

        if (receivedByte == 'W') {
            // Switch to manual mode
            manual_mode = 1;
            MEXTI_u8DISEnable(MEXTI_INT0);
            MEXTI_u8DISEnable(MEXTI_INT1);
        } else if (receivedByte == 'U') {
            // Switch to autonomous mode
            manual_mode = 0;
            MEXTI_u8Enable(MEXTI_INT0, MEXTI_Falling_Edg);//falling edge as if sensor see black line output0
            MEXTI_u8Enable(MEXTI_INT1, MEXTI_Falling_Edg);
            car_forward(); // Start moving forward in autonomous mode
        }

        if (manual_mode) {
            // Manual mode control
        	switch (receivedByte) {
        	            case 'F':
        	                Motor_SetSpeed(179, 158);
        	                Motor_SetDirection(MOTOR_FORWARD);  // Move Forward
        	                break;
        	            case 'B':
        	                Motor_SetSpeed(179, 158);
        	                Motor_SetDirection(MOTOR_BACKWARD);  // Move Backward
        	                break;
        	            case 'L':
        	                Motor_SetSpeed(MOTOR_DEFAULT_SPEED, MOTOR_DEFAULT_SPEED);
        	                Motor_SetDirection(MOTOR_TURN_LEFT);  // Turn Left
        	                break;
        	            case 'R':
        	                Motor_SetSpeed(MOTOR_DEFAULT_SPEED, MOTOR_DEFAULT_SPEED);
        	                Motor_SetDirection(MOTOR_TURN_RIGHT);  // Turn Right
        	                break;
        	            case 'G':
        	                Motor_SetSpeed(MOTOR_DEFAULT_SPEED,MOTOR_Half_Speed);
        	                Motor_SetDirection(MOTOR_FORWARD_LEFT);  // Move Forward-Left
        	                break;
        	             case 'I':
        	            	Motor_SetSpeed(MOTOR_Half_Speed,MOTOR_DEFAULT_SPEED);

        	                Motor_SetDirection(MOTOR_FORWARD_RIGHT); // Move Forward-Right
        	            	break;
        	             case 'H':
        	            	 Motor_SetSpeed(MOTOR_DEFAULT_SPEED,MOTOR_Half_Speed);
        	            	 Motor_SetDirection(MOTOR_BACKWARD_LEFT); // Move Backward-Left
        	            	 break;
        	             case 'J':
        	            	Motor_SetSpeed(MOTOR_Half_Speed,MOTOR_DEFAULT_SPEED);

        	            	Motor_SetDirection(MOTOR_BACKWARD_RIGHT);// Move Backward-Right
        	            	break;
        	            case 'S':
        	                Motor_SetSpeed(0, 0);
        	                Motor_SetDirection(MOTOR_STOP);  // Stop
        	                break;

        	        }


        } else {
            // Autonomous mode logic
            Ultrasonic_INIT();//as apply voltage onTRIG pin for 10 microseconds

            if (DistanceReadyFlag == DATA_READY) {
                DistanceReadyFlag = DATA_NOT_READY;
                u16 Local_u16Distance = Ultrasonic_ReturnDistance();

                if (Local_u16Distance < 20) {
                    car_stop();

                } else {
                    car_forward();

                }
            }
        }
    }

    return 0;
}

void car_turn_right(void) {
    if (!manual_mode) { // Execute only in autonomous mode
    	  Motor_SetSpeed(179, 158);
        Motor_SetDirection(MOTOR_TURN_RIGHT);
        _delay_ms(170);

    }
}

void car_turn_left(void) {
    if (!manual_mode) { // Execute only in autonomous mode
    	  Motor_SetSpeed(179, 158);
        Motor_SetDirection(MOTOR_TURN_LEFT);
        _delay_ms(170);

    }
}

void car_forward(void) {
	 Motor_SetSpeed(159, 138);
    Motor_SetDirection(MOTOR_FORWARD);
}


void car_stop(void) {
	 Motor_SetSpeed(0,0);
    Motor_SetDirection(MOTOR_STOP);
}
/* Change in  motors speeds because real motors have slight speed differences,
 causing uneven movement. This was balanced by experimentally tuning speeds.*/

