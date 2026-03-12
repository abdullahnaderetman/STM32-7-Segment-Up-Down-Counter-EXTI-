/*
 * SYSTICK_prg.c
 *
 *  Created on: Aug 21, 2025
 *      Author: Nada Mamdouh
 *      Version: 0.2
 */
#include  "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "SYSTICK_int.h"
#include "SYSTICK_prv.h"
#include "SYSTICK_cfg.h"

static void(*G_xFptr)(void) = NULL;
static u8 G_u8SingleFlag = 0;

void MSYSTICK_vInit(MSYSTICK_Config_t *A_xCfg)
{
	/* Stop Systick Counter */
	CLR_BIT(SYSTICK->CTRL, ENABLE);

	/*Interrupt enable/disable */
	if(A_xCfg->InterruptEnable == INT_ENABLE)
	{
		SET_BIT(SYSTICK->CTRL, TICKINT);
	}else
	{
		CLR_BIT(SYSTICK->CTRL, TICKINT);
	}

	/*Clock source AHB or AHB/8 */
	if(A_xCfg->CLK_SRC == CLK_SRC_AHB)
	{
		SET_BIT(SYSTICK->CTRL, CLKSOURCE);
	}else if(A_xCfg->CLK_SRC == CLK_SRC_AHB_8)
	{
		CLR_BIT(SYSTICK->CTRL, CLKSOURCE);
	}

}

void MSYSTICK_vStartTimer(u32 A_u32LoadValue)
{
	/* Load Timer with a value */
	SYSTICK->LOAD = A_u32LoadValue - 1;

	/* Reset Timer */
	SYSTICK->VAL = 0;

	/* Start Timer */
	SET_BIT(SYSTICK->CTRL, ENABLE);
}
void MSYSTICK_vStopTimer(void)
{
	/* Stop Systick Counter */
	CLR_BIT(SYSTICK->CTRL, ENABLE);
}

void MSYSTICK_vSetDelay_ms(f64 A_u32Delay_ms)
{
	// in case clksrc = 25Mhz/8
	u32 L_u32Ticks = (u32)(A_u32Delay_ms * 3125.0);

	/* Reset Timer */
	SYSTICK->VAL = 0;
	if((L_u32Ticks >= 0x00000001) && (L_u32Ticks < 0x00FFFFFF))
	{
		MSYSTICK_vStartTimer(L_u32Ticks);

		// wait till timer flag is raised
		while(GET_BIT(SYSTICK->CTRL, COUNTFLAG) == 0)
			;
		MSYSTICK_vStopTimer();
	}

}
void MSYSTICK_vSetDelay_us(u32 A_u32Delay_us)
{
	// in case clksrc = 25Mhz/8
	u32 L_u32Ticks = (u32)(A_u32Delay_us * 3.125);

	/* Reset Timer */
	SYSTICK->VAL = 0;
	if((L_u32Ticks >= 0x00000001) && (L_u32Ticks < 0x00FFFFFF))
	{
		MSYSTICK_vStartTimer(L_u32Ticks);

		// wait till timer flag is raised
		while(GET_BIT(SYSTICK->CTRL, COUNTFLAG) == 0)
			;
		MSYSTICK_vStopTimer();
	}
}
u32 MSYSTICK_u32GetElapsedTime_SingleShot(void)
{
	return (SYSTICK->LOAD) - (SYSTICK->VAL);
}
u32 MSYSTICK_u32GetRemainingTime_SingleShot(void)
{
	return (SYSTICK->VAL);
}

void MSYSTICK_vSetInterval_Single(u32 A_u32Delay_ms, void(*A_xFptr)(void))
{
	G_u8SingleFlag = 1;

	u32 L_u32Ticks = A_u32Delay_ms * 3125;

	G_xFptr = A_xFptr;

	/* Reset Timer */
	SYSTICK->VAL = 0;

	if((L_u32Ticks >= 0x00000001) && (L_u32Ticks < 0x00FFFFFF))
	{
		MSYSTICK_vStartTimer(L_u32Ticks);
	}


}
void MSYSTICK_vSetInterval_Multi(u32 A_u32Delay_ms, void(*A_xFptr)(void))
{
	G_u8SingleFlag = 0;
	u32 L_u32Ticks = A_u32Delay_ms * 3125;

	G_xFptr = A_xFptr;

	/* Reset Timer */
	SYSTICK->VAL = 0;

	if((L_u32Ticks >= 0x00000001) && (L_u32Ticks < 0x00FFFFFF))
	{
		MSYSTICK_vStartTimer(L_u32Ticks);
	}
}

void SysTick_Handler(void)
{
	if(G_xFptr != NULL)
	{
		G_xFptr();

	}
	if(G_u8SingleFlag == 1)
	{
		MSYSTICK_vStopTimer();
	}

}
