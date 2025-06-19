/*
 * Os_Callout.c
 *
 *  Created on: May 2, 2024
 *      Author: AshsihP
 */
#include"stm32f4xx.h"
#include"stm32f407xx.h"

#include"Gpt.h"
#include "Mcu.h"
#include "Port.h"
#include "stm32f4xx.h"
#include "Mcu_RegTypes.h"
#include "Mcu_InternalTypes.h"
#include "Os_Callout.h"
#include "Std_Types.h"
#include "Can.h"
#include"Dio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"
#include "FreeRTOSConfig.h"
#include "SignalProcessor.h"
#include "ApplicationGateway.h"
//uint8 SduData[8]={ 0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55};


const osThreadAttr_t Task1_attributes = {
		.name = "Task1",
		.stack_size = 512,
		.priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Task2 */
const osThreadAttr_t Task2_attributes = {
		.name = "Task2",
		.stack_size = 512,
		.priority = (osPriority_t) osPriorityLow,
};

/* Definitions for Task2 */
const osThreadAttr_t Task3_attributes = {
		.name = "Task3",
		.stack_size = 512,
		.priority = (osPriority_t) osPriorityLow,
};

ISR(WDG_IrqHandler)
{
	while(1);
}

void vTask1ms(void *argument) {

	for (;;) {
		 Gateway_100ms_Task();
		osDelay(100);  // Delay for 1ms
	}

}

void vTask5ms(void *argument) {
	for (;;) {
		Can_MainFunction_BusOff();
		Can_MainFunction_Mode();
		Signal_Process_5ms_Task();
		osDelay(5);   // Delay for 5ms
	}
}

void vTask10ms(void *argument) {
	for(;;)
	{
		//Can_Write(0x02,&message);
		    Gateway_10ms_Task();
		osDelay(10);   // Delay for 10ms
	}
}

void SysTick_Handler (void)
{
	//Clear overflow flag
	SysTick->CTRL;
	if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED) {
		//Call tick handler
		xPortSysTickHandler();
	}
}

#if ( configCHECK_FOR_STACK_OVERFLOW > 0 )

void vApplicationStackOverflowHook( TaskHandle_t xTask,
		char * pcTaskName )
{
	/* Check pcTaskName for the name of the offending task,
	 * or pxCurrentTCB if pcTaskName has itself been corrupted. */
	( void ) xTask;
	( void ) pcTaskName;
}

#endif
