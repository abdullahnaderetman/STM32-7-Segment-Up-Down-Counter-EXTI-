#include"LIB/BIT_MATH.h"
#include"LIB/STD_TYPES.h"
#include"MCAL/GPIO/GPIO_int.h"
#include"MCAL/EXTI/EXTI_int.h"
#include"MCAL/GPIO/GPIO_cfg.h"
#include"MCAL/SYSTICK/SYSTICK_int.h"
#include"MCAL/RCC/RCC_int.h"
#include"HAL/7_SEGMENT/7_SEGMENT.h"
#include"MCAL/NVIC/NVIC_int.h"
#include"MCAL/SYSCFG/SYSCFG_int.h"
#include"MCAL/EXTI/EXTI_int.h"

#define BOUNCING_DELAY 350

volatile static u8 counter=0;

void increase(void)
{
	MEXTI_vDisableINT(EXTI_LINE0);
	MSYSTICK_vSetDelay_ms(BOUNCING_DELAY);
	counter++;
	if(counter>=10)
	{
		counter=0;
	}
	segment_show(counter);
	MSYSTICK_vSetDelay_ms(BOUNCING_DELAY);
	MEXTI_vEnableINT(EXTI_LINE0, EXTI_FALLING_EDGE);

}

void decrease(void)
{
	MEXTI_vDisableINT(EXTI_LINE1);
	MSYSTICK_vSetDelay_ms(BOUNCING_DELAY);
	counter--;
	if(counter == 255)
	{
		counter = 9;
	}
	segment_show(counter);
	MSYSTICK_vSetDelay_ms(BOUNCING_DELAY);
	MEXTI_vEnableINT(EXTI_LINE1, EXTI_FALLING_EDGE);

}



int main(int argc, char* argv[])
{

	//Enable Clocks
	MRCC_vInit();
	MRCC_vEnableClk(RCC_AHB1, RCC_GPIOB);
	MRCC_vEnableClk(RCC_AHB1, RCC_GPIOA);

	Segment_int();
	segment_show(0);


	MRCC_vEnableClk(RCC_APB2,14);

	//PB0 INPUT
	MGPIO_vSetMode(GPIO_PORTB, GPIO_PIN0, GPIO_MODE_INPUT);
	MGPIO_vSetPULLType(GPIO_PORTB, GPIO_PIN0, GPIO_PULL_UP);

	//PB0 INPUT
	MGPIO_vSetMode(GPIO_PORTB, GPIO_PIN1, GPIO_MODE_INPUT);
	MGPIO_vSetPULLType(GPIO_PORTB, GPIO_PIN1, GPIO_PULL_UP);


	//initializing EXTI
	EXTI_Cng_t increase_pin={
			EXTI_LINE0, EXTI_FALLING_EDGE
	};
	MEXTI_vInit(&increase_pin);

	//initializing EXTI
	EXTI_Cng_t decrease_pin={
			EXTI_LINE1, EXTI_FALLING_EDGE
	};
	MEXTI_vInit(&decrease_pin);

	//PERIPHIRAL INTERRUPT ENABLE
	MNVIC_vEnable_Peripheral_INT(6);
	MNVIC_vEnable_Peripheral_INT(7);

	//clock mapping
	MSYSCFG_vSetEXTIPort(0, SYSCFG_PORTB);
	MSYSCFG_vSetEXTIPort(1, SYSCFG_PORTB);


	//__enable_irq();
	//ENABLE THE INTERRUPT
	MEXTI_vSetCallBack(increase, EXTI_LINE0);
	MEXTI_vSetCallBack(decrease, EXTI_LINE1);
	MEXTI_vEnableINT(EXTI_LINE0, EXTI_FALLING_EDGE);
	MEXTI_vEnableINT(EXTI_LINE1, EXTI_FALLING_EDGE);


	//
	while(1);
	return 0;
}
