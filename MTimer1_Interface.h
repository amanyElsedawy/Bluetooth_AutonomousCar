/*
 * MTimer1_Interface.h
 *
 *  Created on: Dec 12, 2024
 *      Author:amany_Elsedawy
 */

#ifndef MTIMER1_INTERFACE_H_
#define MTIMER1_INTERFACE_H_
extern volatile u8 DistanceReadyFlag;
void MTMR1_voidInit(void);

u16  MTMR1_u16GetOnperiod(void);
u16  MTMR1_u16GetTotalperiod(void);

#endif /* MTIMER1_INTERFACE_H_ */
