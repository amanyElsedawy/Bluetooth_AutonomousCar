#ifndef MOTORS_CONFIG_H
#define MOTORS_CONFIG_H


// MOTOR ID
#define MOTOR_A    0
#define MOTOR_B    1
// Motor A Pins
#define MOTOR_A_IN1_PORT   MDIO_PORTA
#define MOTOR_A_IN1_PIN    MDIO_PIN_0
#define MOTOR_A_IN2_PORT   MDIO_PORTA
#define MOTOR_A_IN2_PIN    MDIO_PIN_1

// Motor B Control Pins
#define MOTOR_B_IN3_PORT   MDIO_PORTA
#define MOTOR_B_IN3_PIN    MDIO_PIN_2
#define MOTOR_B_IN4_PORT   MDIO_PORTA
#define MOTOR_B_IN4_PIN    MDIO_PIN_3

// PWM Pins for Speed Control
#define MOTOR_A_PWM_PIN   PB3  // OC0
#define MOTOR_B_PWM_PIN   PD7  // OC2





#endif
