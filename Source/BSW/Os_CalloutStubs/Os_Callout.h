/*
 * Os_Callout.h
 *
 *  Created on: May 2, 2024
 *      Author: AshsihP
 */

#ifndef OS_CALLOUT_H
#define OS_CALLOUT_H
#include "cmsis_os2.h"

void SysTick_Handler (void);

// Declaration of the 1ms task
void vTask1ms(void *argument);
// Declaration of the 5ms task
void vTask5ms(void *argument);
// Declaration of the 10ms task
void vTask10ms(void *argument);



#endif /* OS_CALLOUT_H */
