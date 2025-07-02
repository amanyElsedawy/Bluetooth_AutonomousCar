
#ifndef MTimer0_Private_H
#define MTimer0_Private_H
//if you want to turn counter mode
//extern volatile u16 Global_u16OverflowCount;
#define private_TCCR0          *((volatile u8*)0x53)
#define private_TCNT0          *((volatile u8*)0x52)

#define private_TIMSK          *((volatile u8*)0x59)
#define private_TIFR           *((volatile u8*)0x58)
#define private_OCR0          *((volatile u8*)0x5C)

// Timer/Counter2 Registers
#define private_TCCR2         *((volatile u8*)0x45)
#define private_TCNT2         *((volatile u8*)0x44)
#define private_OCR2          *((volatile u8*)0x43)
#define private_TIMSK         *((volatile u8*)0x59)
#define private_TIFR          *((volatile u8*)0x58)
#endif
