/*
 * MTimer1_Private.h
 *
 *  Created on: Dec 12, 2024
 *      Author: amany_Elsedawy
 */

#ifndef MTIMER1_PRIVATE_H_
#define MTIMER1_PRIVATE_H_


//timer 1 register

#define private_TCCR1A             *((volatile u8*)0x4F)

#define private_TCCR1B            *((volatile u8*)0x4E)

#define private_u16_TCNT1         *((volatile u16*)0x4C)

#define private_u16_OCR1A         *((volatile u16*)0x4A)

#define private_u16_OCR1B         *((volatile u16*)0x48)

#define private_u16_ICR1          *((volatile u16*)0x46)

#define private_TIMSK          *((volatile u8*)0x59)

#endif /* MTIMER1_PRIVATE_H_ */
