/*
** Copyright (C) ARM Limited, 2016. All rights reserved.
*/

/* This file contains the main() program that displays a welcome message, enables the caches,
   performs a float calculation to demonstrate floating point, then runs the main application (sorts) */

#include <stdio.h>
#include <arm_acle.h>
#include "typedefs.h"
#include "generictimer.h"
#include "v8rgicv3cpuif.h"

#define MILLISECOND 0x186A0		//100000 assuming 100MHz
#define DUALTIMER0BASE 0x9C110000
#define SYSLEDBASE 0x9C010000

extern void enable_caches(void);
extern void GIC_configure(void);
extern void GIC_enableVirtualTimerInterrupt(void);
extern void GIC_enableDualTimer0Interrupt(void);
extern int compare_sorts(void);
float calculate( float a, float b );
void enableSystemCounter(void);
void enableDualTimer0(unsigned int);

int main(void)
{
	/* Display a welcome message via semihosting */
    printf("Cortex-R52 bare-metal GIC example\r\n");

    /* Enable the caches */
    enable_caches();
	
    /* Perform a float calculation to demonstrate floating point (using the FPU, if compiled appropriately) */
#ifdef __ARM_FP
    printf("Floating point calculation using the FPU...\r\n");
#else
    printf("Floating point calculation using the software floating point library (no FPU)...\r\n");
#endif
    printf("Float result is        %f\r\n", calculate(1.5f, 2.5f));
    printf("Float result should be 0.937500\r\n");

    /* Run the main application (sorts) */
    compare_sorts();

    /* Configure GIC */
	GIC_configure();

	/* Enable Virtual Timer */
	enableSystemCounter();
	setCNTV_TVAL(MILLISECOND);
	enableVirtualTimer();

	/* Configure Virtual Timer Interrupt */
	GIC_enableVirtualTimerInterrupt();
	
	/* Configure and enable Dual Timer 0 Interrupt */
	enableDualTimer0(0x29aa);
	GIC_enableDualTimer0Interrupt();

	/* Switch on first LED */
	*((unsigned int*)SYSLEDBASE+2) = 0x1;
	
	/* Enable IRQ and FIQ in SVC mode */
	asm ("CPSIE if");							

	while (1)
	{
		__wfi();		
	}
	
    return 0;
}

float calculate( float a, float b )
{
    float temp1, temp2;

    temp1 = a + b;
    temp2 = a * b;
    return temp2 / temp1;
}
void enableSystemCounter(void)
{
	vuint32_t* CNTCR = (vuint32_t*) 0xAA430000; 	// CNTCR (Counter Control register)
	*CNTCR |= 0x3;									// Enable counter and freeze in debug
}
void virtualTimerIRQhandler (void)
{
	setCNTV_TVAL(MILLISECOND);
	sendGroup1SGI(0x1000000/*ID 1*/, 0x0 /* IRM =0 */, 0x1 /* Target CPU0 */);
}

void SGI1IRQhandler (void)
{
	static unsigned char Buffer[10];
	static unsigned char Seconds;
	static unsigned char Minutes;
	static unsigned char Hours;

	vuint32_t i = 0;
	static uint32_t ms = 1;

	if (ms==1000)
	{
		ms = 1;
		Buffer[i % 10] = i;
		if (0 == i % 10)
		{
			// update timer
			if (59 == Seconds)
			{
				Seconds = 0;
				if (59 == Minutes)
				{
					Minutes = 0;
					if (23 == Hours)
					{
						Hours = 0;
					}
					else
					{
						Hours++;
					}
				}
				else
				{
					Minutes++;
				}
			}
			else
			{
				Seconds++;
			}
			if (Hours >= 10)
			{
				printf("%d",Hours);
			}
			else
			{
				printf("0%d",Hours);
			}
			printf(":");
			if (Minutes >= 10)
			{
				printf("%d",Minutes);
			}
			else
			{
				printf("0%d",Minutes);
			}
			printf(":");
			if (Seconds >= 10)
			{
				printf("%d",Seconds);
			}
			else
			{
				printf("0%d",Seconds);
			}
			printf("\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r");

		}
	}
	else
		ms++;
}

void enableDualTimer0(unsigned int period)
{
	// Timer setup (ARM Dual-Timer Module (SP804))
	unsigned int* DualTimer0 = (unsigned int*)DUALTIMER0BASE;
	*(DualTimer0+0x2) = 0x0;
	*(DualTimer0+0x0) = period;
	*(DualTimer0+0x2) = 0xe2;
}

void DualTimer0IRQhandler (void)
{
	unsigned int* DualTimer0 = (unsigned int*)DUALTIMER0BASE;
	unsigned int* SysLed = (unsigned int*)SYSLEDBASE;
	*(DualTimer0+0x3) = 0x0;
	if (*(SysLed+0x2)!= 0x80)
	{
		*(SysLed+0x2) = *(SysLed+0x2)<<1;
	}
	else
		*(SysLed+0x2) = 0x1;
}
