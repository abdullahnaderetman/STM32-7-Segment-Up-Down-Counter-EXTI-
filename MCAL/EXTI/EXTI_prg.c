#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "EXTI_int.h"
#include "EXTI_prv.h"
#include "EXTI_cfg.h"

static void (*G_Fptr[16])(void) = {NULL};

//void MEXTI_vInit(EXTI_Cng_t* A_xCfg)
//{
//	if(A_xCfg != NULL)
//	{
//		/* Configure GPIO port source for EXTI line */
//		MEXTI_vSetPort(A_xCfg->LineNo, A_xCfg->PortNo);
//
//		/* Enable EXTI and set trigger type */
//		MEXTI_vEnableINT(A_xCfg->LineNo, A_xCfg->PortNo, A_xCfg->Trigger_t);
//	}
//
//	/* Clear all pending flags */
//	EXTI->PR = 0xFFFFFFFF;
//}

void MEXTI_vEnableINT(u8 A_u8LineNo, u8 A_u8PortNo, u8 A_u8Trigger_t)
{
	/* Clear all pending flags */
	EXTI->PR = 0xFFFFFFFF;

	if(A_u8LineNo < 16){
		/* Configure GPIO port source for EXTI line */
		MEXTI_vSetPort(A_u8LineNo, A_u8PortNo);

		/* Enable EXTI */
		SET_BIT(EXTI->IMR, A_u8LineNo);

		/* Set Trigger Type */
		MEXTI_vSetTrigger(A_u8LineNo, A_u8Trigger_t);


	}
}

void MEXTI_vDisableINT(u8 A_u8LineNo)
{
	if(A_u8LineNo < 16){
		/* Disable EXTI */
		CLR_BIT(EXTI->IMR, A_u8LineNo);
	}
}

void MEXTI_vSetTrigger(u8 A_u8LineNo, u8 A_u8Trigger_t)
{
	if(A_u8LineNo < 16){
		/* Set Trigger Type */
		switch(A_u8Trigger_t)
		{
		case EXTI_RISING_EDGE:
			SET_BIT(EXTI->RTSR, A_u8LineNo);
			CLR_BIT(EXTI->FTSR, A_u8LineNo);
			break;
		case EXTI_FALLING_EDGE:
			CLR_BIT(EXTI->RTSR, A_u8LineNo);
			SET_BIT(EXTI->FTSR, A_u8LineNo);
			break;
		case EXTI_ONCHANGE_EDGE:
			SET_BIT(EXTI->RTSR, A_u8LineNo);
			SET_BIT(EXTI->FTSR, A_u8LineNo);
			break;
		}
	}
}

void MEXTI_vSetPort(u8 A_u8LineNo, u8 A_u8PortNo)
{
	if(A_u8LineNo < 16 && A_u8PortNo <= EXTI_PORTH){
		u8 reg_index = A_u8LineNo / 4;		/* Determine which EXTICR register to use (0-3) */
		u8 bit_position = (A_u8LineNo % 4) * 4;	/* Determine bit position within the register */

		/* Clear the 4-bit field first */
		SYSCFG->EXTICR[reg_index] &= ~(0xFU << bit_position);

		/* Set the new port configuration */
		SYSCFG->EXTICR[reg_index] |= (A_u8PortNo << bit_position);
	}
}

void MEXTI_vSoftwareINT (u8 A_u8LineNo)
{
	if(A_u8LineNo < 16){
		SET_BIT(EXTI->SWIER, A_u8LineNo);
	}
}

void MEXTI_vSetCallBack(void(*A_xFptr)(void), u8 A_u8LineNo)
{
	if(A_u8LineNo < 16){
		G_Fptr[A_u8LineNo] = A_xFptr;
	}
}

/* EXTI Interrupt Handlers (keep your existing handlers) */
void EXTI0_IRQHandler(void)
{
	if(G_Fptr[EXTI_LINE0] != NULL)
	{
		G_Fptr[EXTI_LINE0]();
	}
	SET_BIT(EXTI->PR, EXTI_LINE0);
}

void EXTI1_IRQHandler(void)
{
	if(G_Fptr[EXTI_LINE1] != NULL)
	{
		G_Fptr[EXTI_LINE1]();
	}
	SET_BIT(EXTI->PR, EXTI_LINE1);
}

void EXTI9_5_IRQHandler(void)
{
	u8 line;
	for(line = EXTI_LINE5; line <= EXTI_LINE9; line++)
	{
		if(GET_BIT(EXTI->PR, line) && (G_Fptr[line] != NULL))
		{
			G_Fptr[line]();
			SET_BIT(EXTI->PR, line);
		}
	}
}

/* Add handlers for other EXTI lines as needed */
void EXTI15_10_IRQHandler(void)
{
	u8 line;
	for(line = EXTI_LINE10; line <= EXTI_LINE15; line++)
	{
		if(GET_BIT(EXTI->PR, line) && (G_Fptr[line] != NULL))
		{
			G_Fptr[line]();
			SET_BIT(EXTI->PR, line);
		}
	}
}
