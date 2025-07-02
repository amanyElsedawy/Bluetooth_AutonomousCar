#ifndef MOTORS_INTERFCE_H
#define MOTORS_INTERFCE_H

// Directions
#define MOTOR_FORWARD          0
#define MOTOR_BACKWARD         1
#define MOTOR_FORWARD_LEFT     2
#define MOTOR_FORWARD_RIGHT    3
#define MOTOR_BACKWARD_LEFT    4
#define MOTOR_BACKWARD_RIGHT   5
#define MOTOR_TURN_RIGHT       6
#define MOTOR_TURN_LEFT        7
#define MOTOR_STOP             8
//Automonous Case
#define MOTOR_RightSmooth      9
#define MOTOR_LeftSmooth       10


//Speed of motor
#define  MOTOR_querter_Speed          64       //50% Duty Cycle
#define  MOTOR_Half_Speed             128      //50% Duty Cycle
#define  MOTOR_DEFAULT_SPEED          179     //70% Duty Cycle
#define  MOTOR_MAX_SPEED          255     //100% Duty Cycle

// Motor Control prototypes
void Motor_Init(void);
void Motor_SetDirection(u8 Direction);
void Motor_SetSpeed(u8 SpeedA,u8 SpeedB );








#endif
