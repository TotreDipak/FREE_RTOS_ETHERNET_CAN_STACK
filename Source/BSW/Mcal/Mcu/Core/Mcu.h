#ifndef MCU_H
#define MCU_H

#include "Mcu_Internal.h"
#include"Mcu_Config.h"
extern FUNC(void, MCU_CODE) Mcu_Init( Mcu_ConfigType* pConfigPtr);
extern FUNC( Std_ReturnType, MCU_CODE) Mcu_InitClock( Mcu_ConfigType* pConfigPtr);
extern FUNC( Std_ReturnType, MCU_CODE) Mcu_DistributePllClock( Mcu_ConfigType* pConfigPtr);
extern FUNC( Std_ReturnType, MCU_CODE) Mcu_GetPllStatus( VAR( void, AUTOMATIC));
FUNC( Mcu_ResetType, MCU_CODE) Mcu_GetResetReason( VAR( void, AUTOMATIC));
#endif // MCU_H
