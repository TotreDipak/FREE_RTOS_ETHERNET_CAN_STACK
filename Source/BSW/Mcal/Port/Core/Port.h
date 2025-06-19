#ifndef PORT_H
#define PORT_H

#include "Port_Cfg.h"
#include "stm32f407xx.h"


extern FUNC(void, PORT_CODE) Port_Init(P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) ConfigPtr);
#endif // PORT_H
