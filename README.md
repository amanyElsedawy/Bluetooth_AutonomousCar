#  Bluetooth & Line-Following Autonomous Car

This project demonstrates a dual-mode smart car built using the **ATmega32** microcontroller. The car can operate in two modes:

##  Modes of Operation

### 1. Manual Mode (Bluetooth Controlled)
- The car is controlled by the user via a **Bluetooth module (HC-05/06)** using UART communication.
- A mobile app or serial terminal sends specific character commands to control:
  - Forward, Backward
  - Left, Right
  - Forward-Left, Forward-Right
  - Backward-Left, Backward-Right
  - Stop

### 2. Autonomous Mode (Line Following)
- The car uses **IR sensors** connected to external interrupts (INT0 and INT1) to detect black lines.
- When a line is detected, the car adjusts direction to stay on track.
- An **ultrasonic sensor** is used to avoid obstacles:
  - If an obstacle is detected within a certain range, the car stops.

##  Peripherals Used

- **Motors**: Controlled via PWM for speed and direction (Timer0 & Timer2)
- **UART**: For Bluetooth communication
- **External Interrupts**: IR line-following sensors
- **Timer1 (PWM)**: Used for generating PWM signals for motor control
- **Ultrasonic Sensor (HC-SR04)**: For obstacle detection
- **LCD**: Optional for debugging

##  Features

- Real-time mode switching between manual and autonomous.
- Balanced motor speeds to overcome hardware inconsistencies.
- Modular, clean driver architecture using layered MCAL and HAL.

##  Authors

- Amany Elsedawy  
- Rofida Adham
