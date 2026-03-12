/*
 * GPIO_prg.c
 *
 *  Created on: Aug 17, 2025
 *      Author: Nada Mamdouh
 *      Version: 0.4
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GPIO_int.h"
#include "GPIO_prv.h"
#include "GPIO_cfg.h"

/*Forbidden
 * PortA = A13, A14, A15
 * PortB = B4, B3
 * */
void MGPIO_vSetMode(u8 A_u8PortID, u8 A_u8PinNum, u8 A_u8Mode)
{
	if( (A_u8PortID == GPIO_PORTA)&& (A_u8PinNum == 13|| A_u8PinNum == 14|| A_u8PinNum == 15))
	{

	}else if ((A_u8PortID == GPIO_PORTB)&& (A_u8PinNum == 3|| A_u8PinNum == 4)){


	}else{

		switch(A_u8PortID)
		{
		case GPIO_PORTA:
			GPIOA->MODER &= ~(0b11<<(A_u8PinNum*2));
			GPIOA->MODER |= (A_u8Mode<<(A_u8PinNum*2));
			break;
		case GPIO_PORTB:
			GPIOB->MODER &= ~(0b11<<(A_u8PinNum*2));
			GPIOB->MODER |= (A_u8Mode<<(A_u8PinNum*2));
			break;
		case GPIO_PORTC:
			GPIOC->MODER &= ~(0b11<<(A_u8PinNum*2));
			GPIOC->MODER |= (A_u8Mode<<(A_u8PinNum*2));
			break;
		}
	}
}
void MGPIO_vSetOutputType(u8 A_u8PortID, u8 A_u8PinNum, u8 A_u8OutputType)
{
	if( (A_u8PortID == GPIO_PORTA)&& (A_u8PinNum == 13|| A_u8PinNum == 14|| A_u8PinNum == 15))
	{

	}else if ((A_u8PortID == GPIO_PORTB)&& (A_u8PinNum == 3|| A_u8PinNum == 4)){


	}else{
		if(A_u8OutputType == GPIO_OT_PUSHPULL )
		{
			switch(A_u8PortID)
			{
			case GPIO_PORTA:
				CLR_BIT(GPIOA -> OTYPER, A_u8PinNum);
				break;
			case GPIO_PORTB:
				CLR_BIT(GPIOB -> OTYPER, A_u8PinNum);
				break;
			case GPIO_PORTC:
				CLR_BIT(GPIOC -> OTYPER, A_u8PinNum);
				break;
			}
		}else if(A_u8OutputType == GPIO_OT_OPENDREAIN )
		{
			switch(A_u8PortID)
			{
			case GPIO_PORTA:
				SET_BIT(GPIOA -> OTYPER, A_u8PinNum);
				break;
			case GPIO_PORTB:
				SET_BIT(GPIOB -> OTYPER, A_u8PinNum);
				break;
			case GPIO_PORTC:
				SET_BIT(GPIOC -> OTYPER, A_u8PinNum);
				break;
			}
		}
	}
}
void MGPIO_vSetOutputSpeed(u8 A_u8PortID, u8 A_u8PinNum, u8 A_u8OutputSpeed)
{
	if( (A_u8PortID == GPIO_PORTA)&& (A_u8PinNum == 13|| A_u8PinNum == 14|| A_u8PinNum == 15))
	{

	}else if ((A_u8PortID == GPIO_PORTB)&& (A_u8PinNum == 3|| A_u8PinNum == 4)){


	}else{
		switch(A_u8PortID)
		{
		case GPIO_PORTA:
			GPIOA->OSPEEDR &= ~(0b11<<(A_u8PinNum*2));
			GPIOA->OSPEEDR |= (A_u8OutputSpeed<<(A_u8PinNum*2));
			break;
		case GPIO_PORTB:
			GPIOB->OSPEEDR &= ~(0b11<<(A_u8PinNum*2));
			GPIOB->OSPEEDR |= (A_u8OutputSpeed<<(A_u8PinNum*2));
			break;
		case GPIO_PORTC:
			GPIOC->OSPEEDR &= ~(0b11<<(A_u8PinNum*2));
			GPIOC->OSPEEDR |= (A_u8OutputSpeed<<(A_u8PinNum*2));
			break;
		}
	}
}
void MGPIO_vSetPULLType(u8 A_u8PortID, u8 A_u8PinNum, u8 A_u8PushPull)
{
	if( (A_u8PortID == GPIO_PORTA)&& (A_u8PinNum == 13|| A_u8PinNum == 14|| A_u8PinNum == 15))
	{

	}else if ((A_u8PortID == GPIO_PORTB)&& (A_u8PinNum == 3|| A_u8PinNum == 4)){


	}else{
		switch(A_u8PortID)
		{
		case GPIO_PORTA:
			GPIOA->PUPDR &= ~(0b11<<(A_u8PinNum*2));
			GPIOA->PUPDR |= (A_u8PushPull<<(A_u8PinNum*2));
			break;
		case GPIO_PORTB:
			GPIOB->PUPDR &= ~(0b11<<(A_u8PinNum*2));
			GPIOB->PUPDR |= (A_u8PushPull<<(A_u8PinNum*2));
			break;
		case GPIO_PORTC:
			GPIOC->PUPDR &= ~(0b11<<(A_u8PinNum*2));
			GPIOC->PUPDR |= (A_u8PushPull<<(A_u8PinNum*2));
			break;
		}
	}
}
void MGPIO_vSetPinValue(u8 A_u8PortID, u8 A_u8PinNum, u8 A_u8Value)
{
	if( (A_u8PortID == GPIO_PORTA)&& (A_u8PinNum == 13|| A_u8PinNum == 14|| A_u8PinNum == 15))
	{

	}else if ((A_u8PortID == GPIO_PORTB)&& (A_u8PinNum == 3|| A_u8PinNum == 4)){


	}else{
		if (A_u8Value == GPIO_HIGH)
		{
			switch(A_u8PortID)
			{
			case GPIO_PORTA:
				SET_BIT(GPIOA -> ODR, A_u8PinNum);
				break;
			case GPIO_PORTB:
				SET_BIT(GPIOB -> ODR, A_u8PinNum);
				break;
			case GPIO_PORTC:
				SET_BIT(GPIOC -> ODR, A_u8PinNum);
				break;
			}
		}else if(A_u8Value == GPIO_LOW)
		{
			switch(A_u8PortID)
			{
			case GPIO_PORTA:
				CLR_BIT(GPIOA -> ODR, A_u8PinNum);
				break;
			case GPIO_PORTB:
				CLR_BIT(GPIOB -> ODR, A_u8PinNum);
				break;
			case GPIO_PORTC:
				CLR_BIT(GPIOC -> ODR, A_u8PinNum);
				break;
			}
		}
	}

}
u8 MGPIO_u8GetPinValue(u8 A_u8PortID, u8 A_u8PinNum)
{
	u8 L_u8Value = 0;
	if( (A_u8PortID == GPIO_PORTA)&& (A_u8PinNum == 13|| A_u8PinNum == 14|| A_u8PinNum == 15))
	{

	}else if ((A_u8PortID == GPIO_PORTB)&& (A_u8PinNum == 3|| A_u8PinNum == 4)){


	}else{
		switch(A_u8PortID)
		{
		case GPIO_PORTA:
			L_u8Value = GET_BIT(GPIOA -> IDR, A_u8PinNum);
			break;
		case GPIO_PORTB:
			L_u8Value = GET_BIT(GPIOB -> IDR, A_u8PinNum);
			break;
		case GPIO_PORTC:
			L_u8Value = GET_BIT(GPIOC -> IDR, A_u8PinNum);
			break;
		}
	}
	return L_u8Value;

}

void MGPIO_vPinInit(GPIOx_PinConfig_t* A_xPinCfg)
{
	MGPIO_vSetMode(A_xPinCfg->Port, A_xPinCfg->Pin, A_xPinCfg->Mode);
	MGPIO_vSetOutputType(A_xPinCfg->Port, A_xPinCfg->Pin, A_xPinCfg->OutputType);
	MGPIO_vSetOutputSpeed(A_xPinCfg->Port, A_xPinCfg->Pin, A_xPinCfg->Speed);
	MGPIO_vSetPULLType(A_xPinCfg->Port, A_xPinCfg->Pin, A_xPinCfg->PullType);
	/* TODO: Alternate function */
	MGPIO_vSetAlt(A_xPinCfg->Port, A_xPinCfg->Pin,A_xPinCfg->Altfunc);
}

void MGPIO_vSetAlt(u8 A_u8PortID, u8 A_u8PinNum, u8 A_u8AFx)
{
	if(A_u8PinNum < 8)
	{
		switch(A_u8PortID)
		{
		case GPIO_PORTA:
			GPIOA->AFRL &= ~(0b1111<<(A_u8PinNum*4));
			GPIOA->AFRL |= (A_u8AFx<<(A_u8PinNum*4));
			break;
		case GPIO_PORTB:
			GPIOB->AFRL &= ~(0b1111<<(A_u8PinNum*4));
			GPIOB->AFRL |= (A_u8AFx<<(A_u8PinNum*4));
			break;
		case GPIO_PORTC:
			GPIOC->AFRL &= ~(0b1111<<(A_u8PinNum*4));
			GPIOC->AFRL |= (A_u8AFx<<(A_u8PinNum*4));
			break;
		default:
			break;
		}
	}else if((A_u8PinNum>=8) && (A_u8PinNum<16) )
	{
		switch(A_u8PortID)
		{
		case GPIO_PORTA:
			GPIOA->AFRH &= ~(0b1111<<((A_u8PinNum-8)*4));
			GPIOA->AFRH |= (A_u8AFx<<((A_u8PinNum-8)*4));
			break;
		case GPIO_PORTB:
			GPIOB->AFRH &= ~(0b1111<<((A_u8PinNum-8)*4));
			GPIOB->AFRH |= (A_u8AFx<<((A_u8PinNum-8)*4));
			break;
		case GPIO_PORTC:
			GPIOC->AFRH &= ~(0b1111<<((A_u8PinNum-8)*4));
			GPIOC->AFRH |= (A_u8AFx<<((A_u8PinNum-8)*4));
			break;
		default:
			break;
		}
	}
}
void MGPIO_TogPinValue(u8 A_u8PortID, u8 A_u8PinNum)
{
	switch(A_u8PortID)
	{
	case GPIO_PORTA:
		TOG_BIT(GPIOA -> ODR, A_u8PinNum);
		break;
	case GPIO_PORTB:
		TOG_BIT(GPIOB -> ODR, A_u8PinNum);
		break;
	case GPIO_PORTC:
		TOG_BIT(GPIOC -> ODR, A_u8PinNum);
		break;
	}
}
void MGPIO_vSetPinValueAtomic(u8 A_u8PortID, u8 A_u8PinNum, u8 A_u8Value)
{
	if( (A_u8PortID == GPIO_PORTA)&& (A_u8PinNum == 13|| A_u8PinNum == 14|| A_u8PinNum == 15))
	{

	}else if ((A_u8PortID == GPIO_PORTB)&& (A_u8PinNum == 3|| A_u8PinNum == 4)){


	}else{
		if (A_u8Value == GPIO_HIGH)
		{
			switch (A_u8PortID)
			{
			case GPIO_PORTA:
				GPIOA->BSRR = 1<<(A_u8PinNum);
				break;
			case GPIO_PORTB:
				GPIOB->BSRR = 1<<(A_u8PinNum);
				break;
			case GPIO_PORTC:
				GPIOC->BSRR = 1<<(A_u8PinNum);
				break;
			default:
				break;

			}
		}else if(A_u8Value == GPIO_LOW)
		{

			switch (A_u8PortID)
			{
			case GPIO_PORTA:
				GPIOA->BSRR = 1<<(A_u8PinNum+16);
				break;
			case GPIO_PORTB:
				GPIOB->BSRR = 1<<(A_u8PinNum+16);
				break;
			case GPIO_PORTC:
				GPIOC->BSRR = 1<<(A_u8PinNum+16);
				break;
			default:
				break;

			}
		}

	}

}


