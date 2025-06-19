/**
*   @file    Can_Cfg.c
*   @version 1.0.2
*
*   @brief   AUTOSAR Can - module interface
*   @details Configuration Structures for PreCompile.
*
*   @addtogroup CAN_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can.h"
#include "Can_Cfg.h"

static CONST(Can_ControllerBaudrateConfigType, CAN_CONST) ControllerBaudrateCfgSet[CAN_CFGSET0_MAX_BAUDRATE_FC_A_0];
static CONST(Can_HwFilterConfigType, CAN_CONST) CanRxFilterConfig[CAN_RXFILTER_CONFIG];
static CONST(Can_FilterConfigType, CAN_CONST) CanHWFilterConfig[CAN_MAX_CONTROLLERS];
static CONST(Can_MBConfigObjectType, CAN_CONST) MessageBufferConfigs[CAN_MAXMBCOUNT_PB];

static CONST(Can_MBConfigObjectType, CAN_CONST) MessageBufferConfigs[CAN_MAXMBCOUNT_PB] =
{
		/*Rx0 */
		{       (uint8)0U, /* ControllerId  - based on the order from CanController list */
				(CanIdType)CAN_STANDARD, /* ID type: EXTENDED, STANDARD, MIXED */
				CAN_BASIC,
				(Can_ObjType)CAN_RECEIVE, /* Receive/Transmit MB configuration */
				(Can_IdType)0x201U, /* MessageId */
				(Can_HwHandleType)0x0U, /* Hardware Object ID */
				(uint8)8U,    /* Payload lenth of Message Buffer */
				CAN_ID_STD,
				CAN_RTR_DATA,
		},
		/*Rx1 */
		{
				(uint8)0U, /* ControllerId  - based on the order from CanController list */
				(CanIdType)CAN_STANDARD, /* ID type: EXTENDED, STANDARD, MIXED */
				CAN_BASIC,
				(Can_ObjType)CAN_RECEIVE, /* Receive/Transmit MB configuration */
				(Can_IdType)0x202U, /* MessageId */
				(Can_HwHandleType)0x1U, /* Hardware Object ID */
				(uint8)8U,    /* Payload lenth of Message Buffer */
				CAN_ID_STD,
				CAN_RTR_DATA,
		},
		/*Rx2 */
		{
				(uint8)0U, /* ControllerId  - based on the order from CanController list */
				(CanIdType)CAN_STANDARD, /* ID type: EXTENDED, STANDARD, MIXED */
				CAN_BASIC,
				(Can_ObjType)CAN_RECEIVE, /* Receive/Transmit MB configuration */
				(Can_IdType)0x203U, /* MessageId */
				(Can_HwHandleType)0x2U, /* Hardware Object ID */
				(uint8)8U,    /* Payload lenth of Message Buffer */
				CAN_ID_STD,
				CAN_RTR_DATA,
		},
		{/*Tx0*/
				(uint8)0U, /* ControllerId  - based on the order from CanController list */
				(CanIdType)CAN_STANDARD, /* ID type: EXTENDED, STANDARD, MIXED */
				CAN_BASIC,
				(Can_ObjType)CAN_TRANSMIT, /* Receive/Transmit MB configuration */
				(Can_IdType)0x0U, /* MessageId */
				(Can_HwHandleType)0x3U, /* Hardware Object ID */
				(uint8)8U,    /* Payload lenth of Message Buffer */
				CAN_ID_STD,
				CAN_RTR_DATA,
		},
		{/*Tx1*/
				(uint8)0U, /* ControllerId  - based on the order from CanController list */
				(CanIdType)CAN_STANDARD, /* ID type: EXTENDED, STANDARD, MIXED */
				CAN_BASIC,
				(Can_ObjType)CAN_TRANSMIT, /* Receive/Transmit MB configuration */
				(Can_IdType)0x0U, /* MessageId */
				(Can_HwHandleType)0x4U, /* Hardware Object ID */
				(uint8)8U,    /* Payload lenth of Message Buffer */
				CAN_ID_STD,
			    CAN_RTR_DATA,
		}
};


static CONST(Can_ControllerBaudrateConfigType, CAN_CONST)
		ControllerBaudrateCfgSet[1] =
{
		{
				/* 500kbps baud rate */
				.u16ControllerBaudRate = (uint16)500,
				.ClockPrescaler = PRESCALER_5,
				.CanMode = CAN_MODE,
				.LoopBack=LOOPBACK_DISABLED,
				.TSegment1 = CAN_BS1_11TQ,
				.TSegment2 = CAN_BS2_2TQ,
				.SyncJumpWidth = CAN_SJW_1TQ,
		},
};

static CONST(Can_ControlerDescriptorType, CAN_CONST) ControlerDescriptorsConfig[CAN_MAXCONTROLLERCOUNT] =
{
		/* ControlerDescriptor of CanController_0*/
		{       BXCAN_OFFSET,
				/* No. of Message Buffers for current controller - u8MaxMBCount */
				(uint8)4U, /* No. of Message Buffers for current controller - u8MaxMBCount */
				(uint8)1U,
				/* NBaudRate configured for current controller */
				&ControllerBaudrateCfgSet[0],
				/* Number of MBs used by Rx Fifo - u8RxFiFoUsedMb */
				(uint8)2U,
				/* Pointer to RxFifo Overflow notification function. - Can_RxFifoOverflowNotification */
				NULL_PTR,
				/* Pointer to RxFifo Warning notification function. - Can_RxFifoWarningNotification */
				NULL_PTR
		}
};
static CONST(Can_HwFilterConfigType, CAN_CONST) CanRxFilterConfig[CAN_RXFILTER_CONFIG]=
{

		{
				(uint32)(0x201 << 5), /* Filter Identifier in CAN_F0R1 register*/
				(uint32)(0x201 << 5),  /* Filter Mask (correspond to CAN_F0R2) register) */
				.u32FilterIdLow=0x00000000,
				.u32FilterMaskIdLow=0x00000000,
				.u32FilterFIFOAssignment = CAN_FILTER_FIFO_0,
				.u32FilterBank=FILTER_BANK_0,
				.u32FilterMode = CAN_FILTERMODE_IDLIST,
				.u32FilterScale = CAN_FILTERSCALE_32BIT,
				.u32FilterActivation =CAN_FILTER_ENABLE,
		},
		{
				(uint32)(0x202 << 5), /* Filter Identifier in CAN_F1R1 register*/
				(uint32)(0x202 << 5),  /* Filter Mask (correspond to CAN_F1R2 register) */
				.u32FilterIdLow=0x00000000,
				.u32FilterMaskIdLow=0x00000000,
				.u32FilterFIFOAssignment = CAN_FILTER_FIFO_0,
				.u32FilterBank=FILTER_BANK_1,
				.u32FilterMode = CAN_FILTERMODE_IDLIST,
				.u32FilterScale = CAN_FILTERSCALE_32BIT,
				.u32FilterActivation =CAN_FILTER_ENABLE,
		},
		{
				(uint32)(0x203 << 5), /* Filter Identifier in CAN_F1R1 register*/
				(uint32)(0x203 << 5),  /* Filter Mask (correspond to CAN_F1R2 register) */
				.u32FilterIdLow=0x00000000,
				.u32FilterMaskIdLow=0x00000000,
				.u32FilterFIFOAssignment = CAN_FILTER_FIFO_0,
				.u32FilterBank=FILTER_BANK_2,
				.u32FilterMode = CAN_FILTERMODE_IDLIST,
				.u32FilterScale = CAN_FILTERSCALE_32BIT,
				.u32FilterActivation =CAN_FILTER_ENABLE,
		}
};

static CONST(Can_FilterConfigType, CAN_CONST) CanHWFilterConfig[CAN_MAX_CONTROLLERS] =
{
		{
				&CanRxFilterConfig[0],
				3 // filter bank assigned to CAN0
		}
};

CONST(Can_ConfigType, CAN_CONST) Can_ConfigSet[CAN_MAX_CONTROLLERS] =
{
		{
				CAN1,
				0,
				TriggerMode_Disable,
				Autobusoff_Disable,
				AutoWakeup_Disable,
				AutoRetransmission_Disable,
				ReceivedFifolocked_Enable,
				TransmitFifoProperty_Disable,
				CAN_PROCESS_TYPE_POLLING,            /* CanBusOffProcessing */
				CAN_PROCESS_TYPE_INTERRUPT,          /* CanRxProcessing */
				CAN_PROCESS_TYPE_INTERRUPT,          /* CanTxProcessing */
				LOOPBACK_DISABLED,
				/* BxCAN controller description - ControlerDescriptors*/
				&ControlerDescriptorsConfig[0],
				/* Can_RxFiFoTableIdConfigType - pRxFiFoTableIdConfig */
				&CanHWFilterConfig[0],
				&MessageBufferConfigs[0], /* pMessageBufferConfigsPtr */
				/* The index of the first HTH configured */
				(Can_HwHandleType)2U
		}
};


#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
