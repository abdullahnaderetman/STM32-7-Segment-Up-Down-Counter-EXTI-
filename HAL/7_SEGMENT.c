/*
 * 7_SEGMENT.c
 *
 *  Created on: Aug 28, 2025
 *      Author: abdal
 */

#include"7_SEGMENT.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/SYSTICK/SYSTICK_int.h"
#include "../../MCAL/RCC/RCC_int.h"

u8 error_flag=0;



void Segment_int(void)
{
	MRCC_vInit();
	MRCC_vEnableClk(RCC_AHB1, RCC_GPIOA);
for(u8 i =0 ;i<7;i++){
	GPIOx_PinConfig_t MYPIN={
			GPIO_PORTA,
			i,
			GPIO_MODE_OUTPUT,
			GPIO_OT_PUSHPULL,
			GPIO_SPEED_HIGH,
			GPIO_NO_PULL
	};
	GPIOx_PinConfig_t * mypin=&MYPIN;
		 MGPIO_vPinInit(mypin);}



}
void segment_show(u8 number)
{
	switch (number)
	{
	case 0:
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_A, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_B, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_C, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_D, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_E, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_F, GPIO_HIGH);
		break;
	case 1:
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_B, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_C, GPIO_HIGH);
			break;
	case 2:
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_A, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_B, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_G, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_E, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_D, GPIO_HIGH);
			break;
	case 3:
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_A, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_B, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_C, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_G, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_D, GPIO_HIGH);
			break;
	case 4:
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_B, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_C, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_G, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_F, GPIO_HIGH);
			break;
	case 5:
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_A, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_F, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_G, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_C, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_D, GPIO_HIGH);
			break;
	case 6:
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_A, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_G, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_C, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_D, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_E, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_F, GPIO_HIGH);
			break;
	case 7:
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_A, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_B, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_C, GPIO_HIGH);
			break;
	case 8:
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_A, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_B, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_G, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_C, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_D, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_E, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_F, GPIO_HIGH);
			break;
	case 9:
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_A, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_B, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_G, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_C, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_D, GPIO_HIGH);
		MGPIO_vSetPinValue(GPIO_PORTA, SEGMENT_F, GPIO_HIGH);

			break;
	default:
			error_flag=1;
	}
}
void Segment_Disable(void)
{
	for(u8 i=0;i<7;i++)
	{
		MGPIO_vSetPinValue(GPIO_PORTA, i, GPIO_LOW);

	}
}




