/*
 * RCC_int.h
 *
 *  Created on: Aug 14, 2025
 *      Author: Nada Mamdouh
 *      Version: 0.1
 */

#ifndef MCAL_RCC_RCC_INT_H_
#define MCAL_RCC_RCC_INT_H_


/* Buses */
#define RCC_AHB1	0
#define RCC_AHB2	1
#define RCC_APB1	2
#define RCC_APB2	3

/* ------- Peripherals --------*/
// Bus : RCC_AHB1
#define RCC_GPIOA	0
#define RCC_GPIOB	1

void MRCC_vInit(void);
void MRCC_vEnableClk(u8 A_u8BusID, u8 A_u8PeripheralID);
void MRCC_vDisableClk(u8 A_u8BusID, u8 A_u8PeripheralID);

#endif /* MCAL_RCC_RCC_INT_H_ */
