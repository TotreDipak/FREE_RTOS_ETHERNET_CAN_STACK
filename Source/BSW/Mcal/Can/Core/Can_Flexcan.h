/**
*   @file    Can_FlexCan.h
*   @implements Can_FlexCan.h_Artifact
*   @version 1.0.2
*
*   @brief   AUTOSAR Can - LLD module interface.
*   @details Low Level Driver header file for IPV = FlexCan.
*
*   @addtogroup CAN_DRIVER
*   @{
*/


#ifndef CAN_FLEXCAN_H
#define CAN_FLEXCAN_H
#endif

#ifdef __cplusplus
extern "C"{
#endif
#include "StdRegMacros.h"
#include "Reg_eSys_FlexCan.h"
#include "Can_GeneralTypes.h"
#include "ComStack_Types.h"
/*#include "CanIf_Cbk.h"*/
#include "Mcal.h"
#include "Can.h"
#include"stm32f407xx.h"
#include"Can_Cfg.h"
#include"Can_internal.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Can_MemMap.h"
extern VAR(Can_ControllerStatusType, CAN_VAR) Can_ControllerStatuses[CAN_MAXCTRL_CONFIGURED];
#define CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

extern FUNC (void, CAN_CODE) BxCan_InitVariables( void);

extern FUNC (Std_ReturnType, CAN_CODE) BxCan_InitController(uint8 CanControllerId ,
		P2CONST(Can_ConfigType, AUTOMATIC, AUTOMATIC) Can_CurrentConfig);

extern FUNC (Can_ReturnType, CAN_CODE) BxCan_Write( Can_HwHandleType Hth,
                                               P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_CONST) PduInfo);
extern FUNC (Std_ReturnType, CAN_CODE) BxCan_CheckBusOff( VAR(uint8, AUTOMATIC) CanControllerId);

extern FUNC (Can_ReturnType, CAN_CODE) BxCan_SetControllerMode( VAR(uint8, AUTOMATIC) Controller,
                                                           P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) PCanConfig,
                                                           Can_StateTransitionType Transition);

extern FUNC (void, CAN_CODE) BxCan_MainFunctionMode(uint8 (CanControllerId));

extern FUNC(void, CAN_CODE) BxCan_RxFifo0MsgPendingCallback(void);

extern FUNC(Can_ReturnType, CAN_CODE) CAN_GetRxMessage(P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) pCanConfig);

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

