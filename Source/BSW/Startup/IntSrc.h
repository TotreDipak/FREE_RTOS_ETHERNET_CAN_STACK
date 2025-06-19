/*
 * IntSrc.h
 *
 *  Created on: Jun 10, 2025
 *      Author: AshsihP
 */

#ifndef SOURCE_BSW_STARTUP_INTSRC_H_
#define SOURCE_BSW_STARTUP_INTSRC_H_

void CAN1_TXIRQHandler(void);
void CAN1_RX0IRQHandler(void);
void CAN1_RX1IRQHandler(void);
void CAN1_BusOffIRQHandler(void);


void CanTxProcess(void); //  declaration
void CanRxProcess(void); //  declaration
void CanBusOffProcess(void); //  declaration

extern void TIM2_IRQ_Handler(void);
extern void TIM3_IRQ_Handler(void);
extern void TIM4_IRQ_Handler(void);
extern void TIM5_IRQ_Handler(void);
extern void SysTick_Handler (void);
#endif /* SOURCE_BSW_STARTUP_INTSRC_H_ */
