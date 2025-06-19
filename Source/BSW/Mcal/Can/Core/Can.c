/**
*   @file    Can.c
*   @implements Can.c_Artifact
*   @version 1.0.2
*   @file    Can.c
*   @implements Can_module
*
*   @brief   AUTOSAR Can - module interface
*   @details API implementation for CAN driver.
*
*   @addtogroup CAN_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


#include "Can_MemMap.h"
#include "Can.h"
#include "Std_Types.h"
#include"Port_Internal.h"
#include"Can_Flexcan.h"
#include"Can_Cfg.h"


#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"


#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_INIT_UNSPECIFIED
#include "Can_MemMap.h"

/**
* @brief          This variable holds the state of the driver.
* @details        This variable holds the state of the driver. After reset is UNINIT. The output of Can_Init() function
*                 (only to first call) should set this variable into READY state.
*                  CAN_UNINIT = The CAN controller is not initialized. All registers belonging to the CAN module are in reset state, CAN interrupts are disabled.
*                  The CAN Controller is not participating on the CAN bus.
*                  The Can module must only implement a variable for the module state, when the development error tracing is switched on.
*                  When the development error tracing is switched off, the Can module does not need to implement this 'state machine',
*                  because the state information is only needed to check if Can_Init was called prior to any Can module function.
*
*/
/* @violates @ref Can_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
VAR(Can_StatusType, CAN_VAR) Can_eDriverStatus = CAN_UNINIT;

/* Pointer to the current Driver Configuration (passed to the driver during initialization). Initialized by Can_Init(). */
P2CONST(Can_ConfigType, CAN_VAR, CAN_APPL_CONST) Can_pCurrentConfig = NULL_PTR;
P2CONST(Can_ControlerDescriptorType, CAN_VAR, CAN_APPL_CONST) Can_pControlerDescriptors = NULL_PTR;

#define CAN_STOP_SEC_VAR_INIT_UNSPECIFIED

#include "Can_MemMap.h"


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define CAN_START_SEC_CODE

#include "Can_MemMap.h"



FUNC(void, CAN_CODE) Can_Init( P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) Config)
{
    /* Variable for indexing the controllers. */
    VAR(uint8, AUTOMATIC) can_controller = 0U;
    if ( CAN_READY == Can_eDriverStatus )
    {
    	/* ReportError*/
    }
    else
    {
    	if (NULL_PTR != Config)
    	{
    		Can_pCurrentConfig = Config;
    	}
    	else
    	{
            (void)Config; /* Prevent compiler warning */
    		/* Update config pointer with default configuration if precompile support on. */
    		Can_pCurrentConfig = &Can_ConfigSet[0];
            for (can_controller = 0 ;can_controller < (uint8)CAN_MAX_CONTROLLERS;can_controller++)
            {
            	BxCan_InitController(can_controller, Can_pCurrentConfig);
            }
            Can_eDriverStatus = CAN_READY;
        }     
    }
}



FUNC(Can_ReturnType, CAN_CODE) Can_SetControllerMode( VAR(uint8, AUTOMATIC) Controller,
                                                      VAR(Can_StateTransitionType, AUTOMATIC) Transition )
{
	P2CONST(Can_ConfigType, CAN_VAR, CAN_APPL_CONST) LpCanConfig = NULL_PTR;
    /* Returns the result of transition mode. */
    VAR(Can_ReturnType, AUTOMATIC)  eReturnValue = CAN_NOT_OK;
    LpCanConfig = &Can_pCurrentConfig[Controller];
    /* If Can_pCurrentConfig is NULL_PTR then the Driver was not initialised yet. */
    if ( CAN_UNINIT == Can_eDriverStatus )
    {

    }
    else
    {
        /* Controller ID must be within range and the selected Controller must be configured for use in the config tool. */
        if ( Controller >= (uint8)CAN_MAX_CONTROLLERS)
        {
  
        }
        else
        {
        	eReturnValue = (Can_ReturnType) BxCan_SetControllerMode
        			( Controller, LpCanConfig, Transition);
        }
    }

    return (eReturnValue);
}



FUNC(Can_ReturnType, CAN_CODE) Can_Write( VAR(Can_HwHandleType, AUTOMATIC) Hth,
                                          P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_CONST) PduInfo)
{
    /* Variable for return status */
    VAR(Can_ReturnType, AUTOMATIC)  eReturnValue = CAN_NOT_OK;

#if (CAN_DEV_ERROR_DETECT == STD_ON)
    /* If Can_pCurrentConfig is NULL_PTR then the driver was not initialised yet. */
    if ( CAN_UNINIT == Can_eDriverStatus )
    {

    }
    else
    {
    	/* Call the IPW function for transmitting data. */
    	   eReturnValue = (Can_ReturnType)BxCan_Write(Hth,PduInfo);
    }
    
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
    return (eReturnValue);
}

#if (CAN_BUSOFFPOLL_SUPPORTED == STD_ON)

FUNC(void, CAN_CODE) Can_MainFunction_BusOff( void)
{
    /* Variable for indexing the controllers */
    VAR(uint8, AUTOMATIC) can_controller = 0U;
	P2CONST(Can_ConfigType, CAN_VAR, CAN_APPL_CONST) LpCanConfig = NULL_PTR;

    /* Test whether the driver is already initialised. */
    if ( CAN_UNINIT == Can_eDriverStatus )
    {

    }
    else
    {
        /* Loop through all Can controllers configured based CanControllerId parameter. */
        for ( can_controller = (uint8)0U; can_controller < (uint8)CAN_MAX_CONTROLLERS; can_controller++)
        {
        	LpCanConfig = &Can_pCurrentConfig[can_controller];
        	if ( (uint8)E_OK == BxCan_CheckBusOff(can_controller) )
        	{
        		if ( CAN_OK == (Can_ReturnType)BxCan_SetControllerMode( can_controller, LpCanConfig, CAN_T_STOP))
        		{
        			/*Clear Busoff flag in Interrupt Status*/
        			BxCan_ProcessBusOff(can_controller);
        			/*CanIf_ControllerBusOff(can_controller);*/
        		}

        	}
        }
    }
}

#endif

FUNC(void, CAN_CODE) Can_MainFunction_Mode( void)
{
    /* Variable for indexing the controllers */
    VAR(uint8, AUTOMATIC) can_controller = 0U;
    /* Test whether the driver is already initialised. */
    if ( CAN_UNINIT == Can_eDriverStatus )
    {

    }
    else
    {
    	/* Loop through all Can controllers configured based CanControllerId parameter. */
    	for ( can_controller = (uint8)0U; can_controller < (uint8)CAN_MAX_CONTROLLERS; can_controller++)
    	{
    		BxCan_MainFunctionMode(can_controller);
    	}
    }
}

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"


#ifdef __cplusplus
}
#endif

