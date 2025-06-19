/*
 * IntSrc.c
 *
 *  Created on: Jun 10, 2025
 *      Author: AshsihP
 */
#include "IntSrc.h"
#include "Platform_Types.h"
static uint32 count=0;
void CAN1_TXIRQHandler(void)
{
	CanTxProcess();
}

void CAN1_RX0IRQHandler(void)
{
	CanRxProcess();
}
void CAN1_RX1IRQHandler(void)
{
	CanRxProcess();
}

void CAN1_BusOffIRQHandler(void)
{
	CanBusOffProcess();
}
