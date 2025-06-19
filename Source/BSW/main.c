
#include"stm32f407xx.h"
#include  "Gpt.h"
#include "stm32f4xx.h"
#include "Mcu_RegTypes.h"
#include "Mcu_InternalTypes.h"
#include"Can.h"
#include"Mcu.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Os_Callout.h"
#include "IntSrc.h"

osThreadId_t Task1Handle;
osThreadId_t Task2Handle;
osThreadId_t Task3Handle;

extern const osThreadAttr_t Task1_attributes;
extern const osThreadAttr_t Task2_attributes;
extern const osThreadAttr_t Task3_attributes;

void vTask5ms(void *argument);
void vTask10ms(void *argument);
void vTask1ms(void *argument);
void NVIC_InitHandler(void);

int main()
{
	NVIC_InitHandler();
	Mcu_Init(&Mcu_ConfigSet[0]);
	Mcu_InitClock(&Mcu_ConfigSet[0]);
	while (MCU_PLL_LOCKED != Mcu_GetPllStatus());
	Mcu_DistributePllClock(&Mcu_ConfigSet[0]);
	Port_Init(NULL_PTR);
	Can_Init(NULL_PTR);
	Gpt_Init(NULL_PTR);
	Gpt_DisbleNotification(0x01);
	Gpt_EnableNotification(0x01);
	Gpt_StartTimer(0x01,999999);   // 1Ms timer
	Gpt_DisbleNotification(0x04);
	Gpt_EnableNotification(0x04);
	Gpt_StartTimer(0x04,999999);   // 1Ms timer

	Can_SetControllerMode(0x0,CAN_T_SLEEP);
	Can_SetControllerMode(0x0,CAN_T_WAKEUP);
	Can_SetControllerMode(0x0,CAN_T_START);

	osKernelInitialize();

	/* creation of Task1 */
	Task1Handle = osThreadNew(vTask1ms, NULL, &Task1_attributes);
	/* creation of Task2 */
	Task2Handle = osThreadNew(vTask5ms, NULL, &Task2_attributes);
	/* creation of Task3 */
	Task3Handle = osThreadNew(vTask10ms, NULL, &Task3_attributes);

	osKernelStart();

	while (1)
	{

	}

}
void NVIC_InitHandler(void)
{
	NVIC_SetPriority(TIM2_IRQn, 0x14);
	NVIC_EnableIRQ(TIM2_IRQn);
	NVIC_SetVector(TIM2_IRQn, (uint32_t)&TIM2_IRQ_Handler);
	NVIC_SetPriority(TIM5_IRQn, 0x14);
	NVIC_EnableIRQ(TIM5_IRQn);
	NVIC_SetVector(TIM5_IRQn, (uint32_t)&TIM5_IRQ_Handler);

	NVIC_SetPriority(SysTick_IRQn, 0x00);

	NVIC_SetPriority(CAN1_TX_IRQn, 0x14);
	NVIC_EnableIRQ(CAN1_TX_IRQn);
	NVIC_SetVector(CAN1_TX_IRQn, (uint32_t)&CAN1_TXIRQHandler);

	NVIC_SetPriority(CAN1_RX0_IRQn,0x14);
	NVIC_EnableIRQ(CAN1_RX0_IRQn);
	NVIC_SetVector(CAN1_RX0_IRQn, (uint32_t)&CAN1_RX0IRQHandler);

	NVIC_SetPriority(CAN1_RX1_IRQn, 0x14);
	NVIC_EnableIRQ(CAN1_RX1_IRQn);
	NVIC_SetVector(CAN1_RX1_IRQn, (uint32_t)&CAN1_RX1IRQHandler);
}
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
	/* USER CODE END Error_Handler_Debug */
}



