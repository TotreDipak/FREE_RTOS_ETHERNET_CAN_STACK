/**
 *   @file    Can.h
 *   @implements Can.h_Artifact
 *   @version 1.0.2
 *
 *   @brief   AUTOSAR Can - module interface.
 *   @details API header for CAN driver.
 *
 *   @addtogroup CAN_DRIVER
 *   @{
 */


#ifndef CAN_H
#define CAN_H

#ifdef __cplusplus
extern "C"{
#endif
/**
 * @file           Can.h
 */
#include "ComStack_Types.h"
#include "Can_Cfg.h"
#include "Can_GeneralTypes.h"
#include"Can_Internal.h"

/*
    Internal micro-dependent versioning. Check of AUTOSAR & Vendor specification version.
 */
/**
 * @{
 * @file           Can.h
 */


/**
 * @brief          Can_ObjType
 * @details        Used for value received by Tressos interface configuration.
 *                 Describe the MB configuration.
 *
 */
typedef enum
{
	CAN_RECEIVE = 0U,   /**< @brief Receive MB */
	CAN_TRANSMIT        /**< @brief Transmit MB */
} Can_ObjType;


/**
 * @brief          CanIdType
 * @details        Used for value received by Tressos interface configuration.
 *                 Used to diferentiate Extended, Mixed or Standard Id type.
 *
 */
typedef enum
{
	CAN_EXTENDED = 0U,  /**< @brief Extended ID (29 bits) */
	CAN_STANDARD,       /**< @brief Standard ID (11 bits) */
	CAN_MIXED           /**< @brief Mixed ID (29 bits) */
} CanIdType;


/**
 * @brief          Can_StatusType
 * @details        CAN Driver status used for checking and preventing double driver intialization.
 *                 CAN_UNINIT = The CAN controller is not initialized. The CAN Controller is not participating on the CAN bus.
 *                              All registers belonging to the CAN module are in reset state, CAN interrupts are disabled.
 *                 CAN_READY = Controller has initialized: static variables, including flags;
 *                             Common setting for the complete CAN HW unit; CAN controller specific settings for each CAN controller.
 *
 */
typedef enum
{
	CAN_UNINIT = 0U, /**< @brief Driver not initialized */
	CAN_READY       /**< @brief Driver ready */
} Can_StatusType;

typedef enum
{
	CAN_PROCESS_TYPE_INTERRUPT,
	CAN_PROCESS_TYPE_POLLING
} Can_ProcessType;


/**************************************************************************************************
 *                                STRUCTURES AND OTHER TYPEDEFS
***************************************************************************************************/


/*
 * @{
 * @brief          Can_IdPtrType
 * @details        Type for storing pointer to the Identifier Lenght Type.
 *                 - used by "Can_ConfigType" structure (pointer to the FilterMasks).
 *
 */
typedef CONSTP2CONST(Can_IdType, CAN_CONST, CAN_APPL_CONST) Can_IdPtrType;
/**@}*/

/**
 * @brief          Type for pointer to function.
 * @details        Type for pointer to function. Used for user handlers from plugin.
 *
 */
typedef void (*Can_PCallBackType)( void);


/**
 * @brief          Rx Fifo Table IDs and Filter Masks
 * @details        Rx Fifo Table IDs and Filter Masks
 *
 */
typedef struct
{	VAR(uint32,                        AUTOMATIC)   u32FilterIdHigh;
    VAR(uint32,                        AUTOMATIC)   u32FilterMaskIdHigh;
	VAR(uint32,                        AUTOMATIC)   u32FilterIdLow;                 /**< @brief for ExtID*/
	VAR(uint32,                        AUTOMATIC)   u32FilterMaskIdLow;             /**< @brief  */
	VAR(Can_FilterFIFOAssignment,      AUTOMATIC)   u32FilterFIFOAssignment;        /**< @brief  */
	VAR(Can_FilterBank,         	   AUTOMATIC)   u32FilterBank;                  /**< @brief  */
	VAR(Can_FilterMode,         	   AUTOMATIC)   u32FilterMode;                  /**< @brief */
	VAR(Can_FilterScale,               AUTOMATIC)   u32FilterScale;                 /**< @brief */
	VAR(Can_FilterActivation,          AUTOMATIC)   u32FilterActivation;            /**< @brief */
} Can_HwFilterConfigType;



typedef struct
{
	P2CONST(Can_HwFilterConfigType, CAN_CONST, CAN_APPL_CONST) pRxCanFilterConfig;
	VAR(uint32,                       AUTOMATIC)    u32SlaveStartFilterBank;
}Can_FilterConfigType  ;


/**
 * @brief          Can_MBConfigObjectType
 * @details        Type for storing information about Message Buffers (CAN hardware objs).
 *                 Used by Can_MBConfigContainerType.
 *
 */
typedef struct
{

	CONST(uint8, CAN_CONST) u8ControllerId; /**< @brief Controller ID (index into controller address array containing Can_ControllerPtrType). */
	VAR(CanIdType, CAN_VAR) uIdType; /**< @brief ID type: CAN_EXTENDED, CAN_STANDARD, CAN_MIXED. */
	CONST(Can_HandleType, CAN_CONST)  CanHandleType;
	VAR(Can_ObjType, CAN_VAR) eMBType; /**< @brief Receive/Transmit */
	VAR(Can_IdType, CAN_VAR) uMessageId;
	VAR(uint32, CAN_VAR) u32HWObjID; /**< @brief HW Obiect ID */
	CONST(uint8, CAN_CONST)  u8MBPayloadLength;        /**< @brief MB data size */
	VAR(uint32, CAN_VAR) IDE; /**<Specifies the type of identifier */
	VAR(uint32, CAN_VAR) RTR; /**Specifies the type of frame for the message*/
} Can_MBConfigObjectType;

typedef struct
{
	VAR(Can_BTR_BRP, AUTOMATIC)   	ClockPrescaler;
	VAR(Can_BTR_SILM, AUTOMATIC)   	CanMode;
	VAR(Can_BTR_LBKM, AUTOMATIC)   	LoopBack;
	VAR(uint32, AUTOMATIC)   		TSegment1;
	VAR(uint32, AUTOMATIC)   		TSegment2;
	VAR(uint32, AUTOMATIC)   	    SyncJumpWidth;
	CONST(uint16, CAN_CONST) 		u16ControllerBaudRate;
} Can_ControllerBaudrateConfigType;


/**
 * @brief          Structure for describing individual FlexCAN controllers on the chip.
 * @details        HRH = Hardware Receive Handle (HRH) is defined and provided by the CAN driver.
 *                       Each HRH represents exactly one hardware object.
 *                       The HRH can be used to optimize software filtering.
 *                 HTH = The Hardware Transmit Handle (HTH) is defined and provided by the CAN driver.
 *                       Each HTH represents one or several hardware objects, that are
 *                       configured as hardware transmit pool.
 *
 */
typedef struct
{
	CONST(uint8, CAN_CONST) u8ControllerOffset;
	CONST(uint8, CAN_CONST) u8MaxMBCount; /**< @brief Max Message Buffer number. */
	CONST(uint8, CAN_CONST) ControllersConfigured;
	P2CONST(Can_ControllerBaudrateConfigType, CAN_CONST, CAN_APPL_CONST) pControllerBaudrateConfigsPtr;
	CONST(uint8, CAN_CONST) u8RxFiFoUsedMb; /**< @brief Number of MBs used by Rx Fifo */

	CONST(Can_PCallBackType, CAN_CONST) Can_RxFifoOverflowNotification; /**< @brief Pointer to RX FIFO Overflow notification function. */

	CONST(Can_PCallBackType, CAN_CONST) Can_RxFifoWarningNotification; /**< @brief Pointer to RX FIFO Warning notification function. */

} Can_ControlerDescriptorType;


/**
 * @brief          Top Level structure containing all Driver configuration.
 * @details        A pointer to this structure is transmitted to Can_Init() to initalize the driver at startup.
 *                 The application selects one of the configurations by using a pointer to one of the elements
 *                 of this array as a parameter of the Can_Init function.
 *
 */
typedef struct
{
	VAR(uint32,                    AUTOMATIC)   CanControllerBaseAddr;     /* registers base address */
	VAR(uint32,                    AUTOMATIC)   CanController;     /* Controller ID */
	VAR(Can_TriggerMode,           AUTOMATIC)   TriggerMode;
	VAR(Can_Autobusoff,            AUTOMATIC)   Autobusoff;
	VAR(Can_AutoWakeup,            AUTOMATIC)   AutoWakeup;
	VAR(Can_AutoRetransmission,    AUTOMATIC)   AutoRetransmission;
	VAR(Can_ReceivedFifolocked,    AUTOMATIC)   ReceivedFifolocked;
	VAR(Can_TransmitFifoProperty,  AUTOMATIC)   TransmitFifoProperty;
	VAR(Can_ProcessType,           AUTOMATIC)   CanBusOffProcessing;
	VAR(Can_ProcessType,           AUTOMATIC)   CanRxProcessing;
	VAR(Can_ProcessType,           AUTOMATIC)   CanTxProcessing;
	VAR(Can_BTR_LBKM,              AUTOMATIC)   LoopbackMode;
	/**< @brief Pointer to the first FlexCAN Controller description. */
	P2CONST(Can_ControlerDescriptorType, CAN_CONST, CAN_APPL_CONST) ControlerDescriptors;
	P2CONST(Can_FilterConfigType, CAN_CONST, CAN_APPL_CONST) Can_FilterConfigType;
	/**< @brief Pointer to the first MB configuration of this Controller. */
	P2CONST(Can_MBConfigObjectType, CAN_CONST, CAN_APPL_CONST) pMessageBufferConfigsPtr;
	CONST(Can_HwHandleType, CONST) uCanFirstHTHIndex;

} Can_ConfigType;

extern CONST(Can_ConfigType, CAN_CONST) Can_ConfigSet[CAN_MAX_CONTROLLERS];

/*==================================================================================================
 *                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define CAN_START_SEC_VAR_INIT_UNSPECIFIED
#include "Can_MemMap.h"

extern VAR(Can_StatusType, CAN_VAR) Can_eDriverStatus;

#define CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Can_MemMap.h"


#define CAN_START_SEC_VAR_INIT_UNSPECIFIED
#include "Can_MemMap.h"

/* Pointer to the current Driver Configuration (passed to the driver during initialization). Initialized by Can_Init(). */
extern P2CONST(Can_ConfigType, CAN_VAR, CAN_APPL_CONST) Can_pCurrentConfig;

#define CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"


extern FUNC(void, CAN_CODE) Can_Init( P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) Config);

extern FUNC(Can_ReturnType, CAN_CODE) Can_SetControllerMode( VAR(uint8, AUTOMATIC) Controller,
		VAR(Can_StateTransitionType, AUTOMATIC) Transition);

extern FUNC(void, CAN_CODE) Can_DisableControllerInterrupts( VAR(uint8, AUTOMATIC) Controller);

extern FUNC(void, CAN_CODE) Can_EnableControllerInterrupts( VAR(uint8, AUTOMATIC) Controller);

extern FUNC(Can_ReturnType, CAN_CODE) Can_Write( VAR(Can_HwHandleType, AUTOMATIC) Hth,
		P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_CONST) PduInfo);


#if (CAN_TXPOLL_SUPPORTED == STD_ON)
extern FUNC(void, CAN_CODE) Can_MainFunction_Write( void );
#else
#define Can_MainFunction_Write()
#endif

#if (CAN_RXPOLL_SUPPORTED == STD_ON)
extern FUNC(void, CAN_CODE) Can_MainFunction_Read( void);
#else
#define Can_MainFunction_Read()
#endif

#if (CAN_BUSOFFPOLL_SUPPORTED == STD_ON)
extern FUNC(void, CAN_CODE) Can_MainFunction_BusOff( void);
#else
#define Can_MainFunction_BusOff()
#endif


#ifdef CAN_WAKEUPPOLL_SUPPORTED
#if (CAN_WAKEUPPOLL_SUPPORTED  == STD_ON)
extern FUNC(void, CAN_CODE) Can_MainFunction_Wakeup( void);
#else
#define Can_MainFunction_Wakeup()
#endif
#endif


extern FUNC(void, CAN_CODE) Can_MainFunction_Mode( void);


#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*CAN_H*/
