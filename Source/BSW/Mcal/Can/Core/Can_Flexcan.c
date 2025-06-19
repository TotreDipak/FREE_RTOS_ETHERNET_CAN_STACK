/**
 *   @file    Can_FlexCan.c
 *   @version 1.0.2
 *
 *   @brief   AUTOSAR Can - LLD module implementation.
 *   @details Low Level Driver implementation.
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
#include"Can_Internal.h"
#include"stm32f4xx.h"
#include"Can_Cfg.h"
#include"Can_Flexcan.h"
#include"stm32f407xx.h"
#include"SignalProcessor.h"
extern VAR(Can_ControllerStatusType, CAN_VAR) Can_ControllerStatus[CAN_MAXCTRL_CONFIGURED];


//#define CAN_TIMEOUT_AS_LOOP
#if (CAN_DEV_ERROR_DETECT == STD_ON)
/*#include "Det.h"*/
#endif

void wait_for_initialization(void);

extern void TIM2_IRQ_Handler(void);


#define CAN_TIMEOUT_VALUE 10

/*
 * @violates @ref Can_Flexcan_c_REF_3 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
 */

#include "SchM_Can.h"
#include "Mcal.h"


#define CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref Can_Flexcan_c_REF_1 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref Can_Flexcan_c_REF_3 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "Can_MemMap.h"
/**
 * @brief          Array holding current status/run-time configuration of individual FlexCAN controllers
 * @details        Array holding current status/run-time configuration of individual FlexCAN controllers
 *                 - information like Guard bits, Pre-calculated MB INT masks, Storage space for id, INT nesting level,
 *                 Index of MB buffer being cancelled, Index of the first MB used for Tx , Controller Options.
 *
 *
 */
/* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
VAR(Can_ControllerStatusType, CAN_VAR) Can_ControllerStatus[CAN_MAXCTRL_CONFIGURED];

/**
 * @brief          Variable to hold the number of tick correspond to TimeOutDuration
 * @details        Variable to hold the number of tick correspond to TimeOutDuration
 *
 */
#define CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref Can_Flexcan_c_REF_1 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref Can_Flexcan_c_REF_3 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "Can_MemMap.h"


#define CAN_START_SEC_CODE
/* @violates @ref Can_Flexcan_c_REF_1 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref Can_Flexcan_c_REF_3 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "Can_MemMap.h"



/*================================================================================================*/
static FUNC (Can_ReturnType, CAN_CODE) BxCan_SetControllerToStopMode(  VAR(uint8, AUTOMATIC) Controller,
		P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) pCanConfig);
static FUNC (Can_ReturnType, CAN_CODE) BxCan_SetControllerToStartMode(  VAR(uint8, AUTOMATIC) Controller,
		P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) pCanConfig);
static FUNC (Can_ReturnType, CAN_CODE) BxCan_SetControllerToSleepMode(  VAR(uint8, AUTOMATIC) Controller,
		P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) pCanConfig );
static FUNC (Can_ReturnType, CAN_CODE) BxCan_SetControllerToWakeupMode(  VAR(uint8, AUTOMATIC) Controller,
		P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) pCanConfig );




FUNC (Std_ReturnType, CAN_CODE) BxCan_InitController(uint8 CanControllerId , P2CONST(Can_ConfigType, AUTOMATIC, AUTOMATIC) Can_CurrentConfig)
{

	P2CONST(Can_ConfigType, AUTOMATIC, AUTOMATIC)  LpCan_pCurrentConfig = &Can_CurrentConfig[CanControllerId];
	P2CONST(Can_ControllerBaudrateConfigType, AUTOMATIC, AUTOMATIC)  LpControllerBaudrateConfig = LpCan_pCurrentConfig->ControlerDescriptors->pControllerBaudrateConfigsPtr;
	P2CONST(Can_FilterConfigType, AUTOMATIC, AUTOMATIC)  LpCan_FilterConfig =LpCan_pCurrentConfig->Can_FilterConfigType;
	/* Variable for indexing the controllers. */

	VAR(uint8, AUTOMATIC)  filternbrbitpos = 0U;
	VAR(uint16, AUTOMATIC)  LTimeOutCtr = 0U;
	VAR(uint32, AUTOMATIC)  lddInakSlak = 0U;
	/* Variable for return status. */
	VAR(Std_ReturnType, AUTOMATIC)  eResetReturn = (Std_ReturnType)CAN_NOT_OK;

	Can_ControllerStatus[CanControllerId].State = CAN_CS_STOPPED;
	// sleep to  initialize
	REG_RMW32(CAN_MCR_ADDR32(CanControllerId), CAN1_INRQ_MASK, CAN_MCR_INRQ);
	/*delay(2000);*/
	// exit from sleep mode
	REG_BIT_CLEAR32(CAN_MCR_ADDR32(CanControllerId), CAN_MCR_SLEEP);
	/*delay(2000);*/
	LTimeOutCtr = 2000U;
	lddInakSlak = REG_READ32(CAN_MSR_ADDR32(CanControllerId)) & (BXCAN_MSR_INAK_U32|BXCAN_MSR_SLAK_U32);

	/* Wait the acknowledge */
	/*Initialization SLAK= 0 INAK = 1*/
	while ((lddInakSlak != 0x00000001)&&(LTimeOutCtr > 0))
	{
		LTimeOutCtr--;
		lddInakSlak = REG_READ32(CAN_MSR_ADDR32(CanControllerId)) & (BXCAN_MSR_INAK_U32|BXCAN_MSR_SLAK_U32);
	}
	if(LTimeOutCtr ==0 )
	{
		Can_ControllerStatus[CanControllerId].ErrorCode = CAN_ERROR_TIMEOUT;
		Can_ControllerStatus[CanControllerId].State = CAN_CS_UNINIT;
		return eResetReturn;
	}
	else
	{
		if (Can_ControllerStatus[CanControllerId].State == CAN_CS_STOPPED)
		{
			REG_RMW32(CAN_MCR_ADDR32(CanControllerId),CAN1_TTCM_MASK,(uint32)Can_pCurrentConfig->TriggerMode);
			REG_RMW32(CAN_MCR_ADDR32(CanControllerId),CAN1_ABOM_MASK,(uint32)Can_pCurrentConfig->Autobusoff);
			REG_RMW32(CAN_MCR_ADDR32(CanControllerId),CAN1_AWUM_MASK,(uint32)Can_pCurrentConfig->AutoWakeup);
			REG_RMW32(CAN_MCR_ADDR32(CanControllerId),CAN1_NART_MASK,(uint32)Can_pCurrentConfig->AutoRetransmission);
			REG_RMW32(CAN_MCR_ADDR32(CanControllerId),CAN1_RFLM_MASK,(uint32)Can_pCurrentConfig->ReceivedFifolocked);
			REG_RMW32(CAN_MCR_ADDR32(CanControllerId),CAN1_TXFP_MASK,(uint32)Can_pCurrentConfig->TransmitFifoProperty);

			REG_RMW32(CAN_BTR_ADDR32(CanControllerId),CAN1_BRP_MASK,(uint32)LpControllerBaudrateConfig->ClockPrescaler);
			REG_RMW32(CAN_BTR_ADDR32(CanControllerId),CAN1_SILM_MASK,(uint32)LpControllerBaudrateConfig->CanMode);
		if (LpCan_pCurrentConfig->LoopbackMode != LOOPBACK_DISABLED)
		{
			REG_RMW32(CAN_BTR_ADDR32(CanControllerId),CAN1_LBKM_MASK,LpControllerBaudrateConfig->LoopBack);
		}
			REG_RMW32(CAN_BTR_ADDR32(CanControllerId),CAN1_TS1_MASK,(uint32)LpControllerBaudrateConfig->TSegment1);
			REG_RMW32(CAN_BTR_ADDR32(CanControllerId),CAN1_TS2_MASK,(uint32)LpControllerBaudrateConfig->TSegment2);
			REG_RMW32(CAN_BTR_ADDR32(CanControllerId),CAN1_SJW_MASK,(uint32)LpControllerBaudrateConfig->SyncJumpWidth);


			/* Enter Initialization mode to configure filters */
			REG_RMW32(CAN_FMR_ADDR32(CanControllerId),CAN_FMR_FINITMASK,BXCAN_FMR_FINIT_U32 );

			REG_BIT_CLEAR32(CAN_FMR_ADDR32(CanControllerId), BXCAN_FMR_CAN2SB_U32);

			// assign all filter(0-13) bank to CAN1 (MASTER CAN)
			REG_RMW32(CAN_FMR_ADDR32(CanControllerId),BXCAN_FMR_CAN2SB_U32,
					(LpCan_FilterConfig->u32SlaveStartFilterBank) << CAN_FMR_CAN2SB_Pos);

			for ( uint8 u8Index = 0U; u8Index < (uint8)LpCan_FilterConfig->u32SlaveStartFilterBank; u8Index++)
			{
				/* Convert filter bank number into bit position */
				filternbrbitpos = (uint32)1 << (LpCan_FilterConfig->pRxCanFilterConfig[u8Index].u32FilterBank & 0x1FU);

				/* Filter Deactivation */
				REG_BIT_CLEAR32(CAN_FA1R_ADDR32(CanControllerId), filternbrbitpos);

				/* Filter Scale */
				if (LpCan_FilterConfig->pRxCanFilterConfig[u8Index].u32FilterScale == CAN_FILTER_SCALE_16BIT)
				{
					/* 16-bit scale for the filter */
					REG_BIT_CLEAR32(CAN_FS1R_ADDR32(CanControllerId),filternbrbitpos);

					/* First 16-bit identifier and First 16-bit mask */
					/* Or First 16-bit identifier and Second 16-bit identifier */
					REG_RMW32(CAN_FR1_ADDR32(CanControllerId,LpCan_FilterConfig->pRxCanFilterConfig[u8Index].u32FilterBank),
							CAN_FRx_MASK,((0x0000FFFFU & (uint32)LpCan_FilterConfig->pRxCanFilterConfig[u8Index].u32FilterMaskIdLow) << 16U) |
							(0x0000FFFFU & (uint32)LpCan_FilterConfig->pRxCanFilterConfig[u8Index].u32FilterIdLow));


					REG_RMW32(CAN_FR2_ADDR32(CanControllerId,LpCan_FilterConfig->pRxCanFilterConfig[u8Index].u32FilterBank),
							CAN_FRx_MASK,((0x0000FFFFU & (uint32)LpCan_FilterConfig->pRxCanFilterConfig[u8Index].u32FilterMaskIdHigh) << 16U) |
							(0x0000FFFFU & (uint32)LpCan_FilterConfig->pRxCanFilterConfig[u8Index].u32FilterIdHigh));
				}

				if (LpCan_FilterConfig->pRxCanFilterConfig->u32FilterScale == CAN_FILTER_SCALE_32BIT)
				{

					REG_BIT_SET32(CAN_FS1R_ADDR32(CanControllerId),filternbrbitpos);

					REG_RMW32(CAN_FR1_ADDR32(CanControllerId,LpCan_FilterConfig->pRxCanFilterConfig[u8Index].u32FilterBank),
							CAN_FRx_MASK,(uint32)(((0x0000FFFFU & (uint32)LpCan_FilterConfig->pRxCanFilterConfig[u8Index].u32FilterIdHigh) << 16U) |
									(0x0000FFFFU & (uint32)LpCan_FilterConfig->pRxCanFilterConfig[u8Index].u32FilterIdLow)));


					REG_RMW32(CAN_FR2_ADDR32(CanControllerId,LpCan_FilterConfig->pRxCanFilterConfig[u8Index].u32FilterBank),
							CAN_FRx_MASK,(((0x0000FFFFU & (uint32)LpCan_FilterConfig->pRxCanFilterConfig[u8Index].u32FilterMaskIdHigh) << 16U) |
									(0x0000FFFFU & (uint32)LpCan_FilterConfig->pRxCanFilterConfig[u8Index].u32FilterMaskIdLow)));
				}

				/* Filter Mode */
				if (LpCan_FilterConfig->pRxCanFilterConfig[u8Index].u32FilterMode == CAN_FILTER_MODE_IDMASK)
				{
					REG_BIT_CLEAR32(CAN_FM1R_ADDR32(CanControllerId),filternbrbitpos);
				}
				else /* FilterConfig->FilterMode == CAN_FILTER_MODE_IDLIST */
				{
					REG_BIT_SET32(CAN_FM1R_ADDR32(CanControllerId),filternbrbitpos);
				}

				/* Filter FIFO assignment */
				if (LpCan_FilterConfig->pRxCanFilterConfig[u8Index].u32FilterFIFOAssignment == CAN_FILTER_FIFO0)
				{
					/* FIFO 0 assign for the filter */
					REG_BIT_CLEAR32(CAN_FFA1R_ADDR32(CanControllerId), filternbrbitpos);
				}
				else
				{
					/* FIFO 1 assign for the filter */
					REG_BIT_SET32(CAN_FFA1R_ADDR32(CanControllerId), filternbrbitpos);
				}

				/* Filter activation */
				if (LpCan_FilterConfig->pRxCanFilterConfig[u8Index].u32FilterActivation == CAN_FILTER_ENABLE)
				{
					REG_BIT_SET32(CAN_FA1R_ADDR32(CanControllerId), filternbrbitpos);
				}
			}

			/* Leave the initialisation mode in the end of filtering */
			REG_BIT_CLEAR32(CAN_FMR_ADDR32(CanControllerId), CAN_FMR_FINIT);


			if (LpCan_pCurrentConfig->CanTxProcessing != CAN_PROCESS_TYPE_INTERRUPT)
			{
				REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_TMEIE_MASK,  TMEIE_Disable);
			}
			else
			{
				REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_TMEIE_MASK,  TMEIE_Enable);
			}

			if (LpCan_pCurrentConfig->CanRxProcessing != CAN_PROCESS_TYPE_INTERRUPT)
			{
				REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_FMPIE0_MASK, FMPIE0_Disable);
				REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_FFIE0_MASK,  FFIE0_Disable);
				REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_FOVIE0_MASK, FOVIE0_Disable);
				REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_FMPIE1_MASK, FMPIE1_Disable);
				REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_FFIE1_MASK,  FFIE1_Disable);
				REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_FOVIE1_MASK, FOVIE1_Disable);

			}
			else
			{
				REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_FMPIE0_MASK, FMPIE0_Enable);
				REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_FFIE0_MASK,  FFIE0_Enable);
				REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_FOVIE0_MASK, FOVIE0_Enable);
				REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_FMPIE1_MASK, FMPIE1_Enable);
				REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_FFIE1_MASK,  FFIE1_Enable);
				REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_FOVIE1_MASK, FOVIE1_Enable);

			}
			if (LpCan_pCurrentConfig->CanBusOffProcessing != CAN_PROCESS_TYPE_INTERRUPT)
			{
				/*ERRIE*/
				REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_ERRIE_MASK,  ERRIE_Disable);
				/*BOFIE*/
				REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_BOFIE_MASK,  BOFIE_Disable);
			}
			else
			{   /*ERRIE*/
				REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_ERRIE_MASK,  ERRIE_Enable);
				/*BOFIE*/
				REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_BOFIE_MASK,  BOFIE_Enable);
			}

			Can_ControllerStatus[CanControllerId].eInterruptMode= CAN_INTERRUPT_ENABLED;
			/* Initialize the error code */
			Can_ControllerStatus[CanControllerId].ErrorCode = CAN_ERROR_NONE;
			eResetReturn = CAN_OK;
			/* Return function status */
			return eResetReturn;
		}
	}
}
/* Stage1: init RxFifo ******************************************************************** */


/* Stage2: Init Rx and Tx MBs ******************************************************************** */

/**
 * @brief          This function checks if a BusOff has occurred for the given controller.
 * @details        This routine is called by:
 *                  - Can_MainFunction_BusOff() from Can.c file.
 *
 * @param[in]      controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
 *
 * @return        Std_ReturnType
 * @retval        E_OK BusOff detected
 * @retval        E_NOT_OK BusOff not detected
 *
 * @pre            A request for busoff checking is required.
 * @post           Report the occurence or not for an busoff event.
 *
 */
/* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (Std_ReturnType, CAN_CODE) BxCan_CheckBusOff( VAR(uint8, AUTOMATIC) CanControllerId)
{
	/* Return value. */
	VAR(uint8, AUTOMATIC) eReturnValue = (uint8)E_NOT_OK;

	if (REG_READ32(CAN_ESR_ADDR32(CanControllerId)) & CAN1_ESRBOF_MASK)
	{
		/* Controller is in BusOff state. */
		eReturnValue = E_OK;
	}
	else
	{
		return (eReturnValue);
	}
}


FUNC(Can_ReturnType, CAN_CODE) CAN_GetRxMessage(P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) pCanConfig)
{
	VAR(uint32,            AUTOMATIC) ReceivedMessageId = 0U;
	VAR(uint16,            AUTOMATIC)      u32MbHrh = 0U;
	VAR(uint8,             AUTOMATIC)      CanController = 0U;
	VAR(uint8,             AUTOMATIC)      aData[64];
	VAR(uint32,            AUTOMATIC)      RX_IDE;
	VAR(uint32,            AUTOMATIC)      DataLength;
	VAR(uint8,             AUTOMATIC)      u8DatabyteIndex = 0U;
	P2CONST(Can_HwFilterConfigType, CAN_CONST, CAN_APPL_CONST) LpRxFilterConfig=NULL_PTR;
	LpRxFilterConfig=pCanConfig->Can_FilterConfigType->pRxCanFilterConfig;

	if (Can_ControllerStatus[CanController].State == CAN_CS_STARTED)
	{
		/*	 Check the Rx FIFO  */
		for (uint8 filterIndex = 0U; filterIndex < CAN_RXFILTER_CONFIG; filterIndex++)
		{

		if (LpRxFilterConfig[filterIndex].u32FilterFIFOAssignment== CAN_RX_FIFO0)  /*Rx element is assigned to Rx FIFO 0*/
		{
			/* Check that the Rx FIFO 0 is not empty*/
			if ((REG_READ32(CAN_RF0R_ADDR32(CanController)) & CAN_RF0R_FMP0) == 0U)

			{

				Can_ControllerStatus[CanController].ErrorCode |= CAN_ERROR_PARAM;

				return CAN_NOT_OK;
			}
		}
		else if  (LpRxFilterConfig[filterIndex].u32FilterFIFOAssignment== CAN_RX_FIFO1)
		{
			/* Check that the Rx FIFO 1 is not empty*/
		    if ((REG_READ32(CAN_RF1R_ADDR32(CanController)) & CAN_RF1R_FMP1) == 0U)
			{

				Can_ControllerStatus[CanController].ErrorCode |= CAN_ERROR_PARAM;

				return CAN_NOT_OK;
			}
		}
		}

		/* Get the ID Type*/
		RX_IDE = CAN_RI0R_IDE & REG_READ32(CAN_RI0R_ADDR32(CanController));


		if (RX_IDE == CAN_ID_STD)
		{
			ReceivedMessageId = (CAN_RI0R_STID & REG_READ32(CAN_RI0R_ADDR32(CanController))) >> CAN_TI0R_STID_Pos;

		}
		else
		{
			ReceivedMessageId = ((CAN_RI0R_EXID | CAN_RI0R_STID) &
					REG_READ32(CAN_RI0R_ADDR32(CanController))) >> CAN_RI0R_EXID_Pos;

		}

		if (((CAN_RDT0R_DLC & REG_READ32(CAN_RI0R_ADDR32(CanController))) >> CAN_RDT0R_DLC_Pos) >= 8U)
		{
			/*  Truncate DLC to 8 if received field is over range*/
			DataLength = 8U;
		}
		else
		{
			DataLength = (uint8)(CAN_RDT0R_DLC & REG_READ32(CAN_RDT0R_ADDR32(CanController))) >> CAN_RDT0R_DLC_Pos;
		}

		// Storing filterMatch Index
		u32MbHrh = (CAN_RDT0R_FMI & REG_READ32(CAN_RDT0R_ADDR32(CanController))) >> CAN_RDT0R_FMI_Pos;


		/* Get the data */
		for (u8DatabyteIndex = 0; u8DatabyteIndex < DataLength; u8DatabyteIndex++)
		{
			if (u8DatabyteIndex < 4)
			{
				aData[u8DatabyteIndex] = (uint8)((REG_READ32(CAN_RDL0R_ADDR32(CanController)) >> (u8DatabyteIndex * 8)) & 0xFF);
			}
			else
			{
				aData[u8DatabyteIndex] = (uint8)((REG_READ32(CAN_RDH0R_ADDR32(CanController)) >> ((u8DatabyteIndex - 4) * 8)) & 0xFF);
			}
		}

		/*	     Release the FIFO*/
		for (uint8 filterIndex = 0U; filterIndex < CAN_RXFILTER_CONFIG; filterIndex++)
		{
		    if (LpRxFilterConfig[filterIndex].u32FilterFIFOAssignment == CAN_RX_FIFO0)
		    {
		        /* Release RX FIFO 0 */
		        REG_BIT_SET32(CAN_RF0R_ADDR32(CanController), CAN_RF0R_RFOM0);
		    }
		    else if (LpRxFilterConfig[filterIndex].u32FilterFIFOAssignment == CAN_RX_FIFO1)
		    {
		        /* Release RX FIFO 1 */
		        REG_BIT_SET32(CAN_RF1R_ADDR32(CanController), CAN_RF1R_RFOM1);
		    }
		}


		//process CanIf_RxIndication
		CanIf_RxIndication(u32MbHrh, ReceivedMessageId,DataLength, &aData[0]);

		return CAN_OK;

	}
	else
	{
		/* Update error code*/
		Can_ControllerStatus[CanController].ErrorCode |= CAN_ERROR_NOT_INITIALIZED;

		return CAN_NOT_OK;
	}
}





Can_ReturnType BxCan_Write(Can_HwHandleType Hth, P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_CONST) PduInfo)
{
	//uint32 data = PduInfo->sdu;
	VAR(Can_ReturnType, AUTOMATIC) eReturnValue = CAN_BUSY;
	 VAR(uint8, AUTOMATIC)   CanControllerId = 0U;
	VAR(uint8, AUTOMATIC)          u8MbIndex = 0U;
	VAR(uint32, AUTOMATIC)         transmitmailbox;

	P2CONST(Can_ConfigType, CAN_VAR, CAN_APPL_CONST) LpCanConfig = NULL_PTR;
	LpCanConfig = &Can_pCurrentConfig[CanControllerId];

	uint32 tsr = REG_READ32(CAN_TSR_ADDR32(CanControllerId));

	if (Can_ControllerStatus[CanControllerId].State  == CAN_CS_STARTED)
	{

		if  (((tsr & CAN_TSR_TME0)!= 0U) ||
		    ((tsr & CAN_TSR_TME1) != 0U)  ||
			((tsr & CAN_TSR_TME2) != 0U))
		{
			transmitmailbox = (tsr & CAN_TSR_CODE) >> CAN_TSR_CODE_Pos;
			/* Store the Tx mailbox */
			/* Set up the Id */
			if (LpCanConfig->pMessageBufferConfigsPtr[Hth].IDE == CAN_ID_STD)
			{
				REG_WRITE32(CAN_TIXR_ADDR32(CanControllerId,transmitmailbox),((PduInfo->id << CAN_TI0R_STID_Pos) |
						LpCanConfig->pMessageBufferConfigsPtr[Hth].RTR));
			}
			else
			{
				REG_WRITE32(CAN_TIXR_ADDR32(CanControllerId,transmitmailbox),((PduInfo->id << CAN_TI0R_EXID_Pos) |
						LpCanConfig->pMessageBufferConfigsPtr[Hth].IDE |
						LpCanConfig->pMessageBufferConfigsPtr[Hth].RTR));
			}

			/* Set up the DLC */
			REG_WRITE32(CAN_TDTXR_ADDR32(CanControllerId,transmitmailbox), (PduInfo->length));

		     // store Pdu handle ID for Tx confiramtion
			Can_ControllerStatus[CanControllerId].u32TxPduId[u8MbIndex] = PduInfo->swPduHandle;

			/* Set up the data field */
			REG_WRITE32(CAN_TDHXR_ADDR32(CanControllerId,transmitmailbox),
					((uint32)PduInfo->sdu[7] << CAN_TDH0R_DATA7_Pos) |
					((uint32)PduInfo->sdu[6] << CAN_TDH0R_DATA6_Pos) |
					((uint32)PduInfo->sdu[5] << CAN_TDH0R_DATA5_Pos) |
					((uint32)PduInfo->sdu[4] << CAN_TDH0R_DATA4_Pos));

			REG_WRITE32(CAN_TDLXR_ADDR32(CanControllerId,transmitmailbox),
					((uint32)PduInfo->sdu[3] << CAN_TDL0R_DATA3_Pos) |
					((uint32)PduInfo->sdu[2] << CAN_TDL0R_DATA2_Pos) |
					((uint32)PduInfo->sdu[1] << CAN_TDL0R_DATA1_Pos) |
					((uint32)PduInfo->sdu[0] << CAN_TDL0R_DATA0_Pos));


			/* Request transmission */

			REG_BIT_SET32(CAN_TIXR_ADDR32(CanControllerId,transmitmailbox),CAN_TI0R_TXRQ);

			eReturnValue = CAN_OK;
		}
		else
		{
			eReturnValue = CAN_BUSY;
		}
	}
	else
	{
		eReturnValue = CAN_NOT_OK;
	}

	return eReturnValue;
}



FUNC (void, CAN_CODE) BxCan_ProcessBusOff( CONST(uint8, AUTOMATIC) CanControllerId)
{
	REG_RMW32(CAN_ESR_ADDR32(CanControllerId), CAN1_BOFF_MASK, CAN1_BOFF_RESET);
}

FUNC (void, CAN_CODE) BxCan_MainFunctionMode(uint8 (CanControllerId))
{
	VAR(uint32, AUTOMATIC)  lddInakSlak = 0U;
	if(CAN_CS_SLEEP !=Can_ControllerStatus[CanControllerId].State)
	{
		lddInakSlak = REG_READ32(CAN_MSR_ADDR32(CanControllerId)) & (BXCAN_MSR_INAK_U32|BXCAN_MSR_SLAK_U32);
		if ((CAN_CS_STARTED == Can_ControllerStatus[CanControllerId].State) && (lddInakSlak == 0x00000001))
		{
			Can_ControllerStatus[CanControllerId].State = CAN_CS_STOPPED;
		}
		else
		{
			if ((CAN_CS_STOPPED == Can_ControllerStatus[CanControllerId].State) && (lddInakSlak == 0x00000000))
			{
				Can_ControllerStatus[CanControllerId].State = CAN_CS_STARTED;
			}
			else
			{
				if ((CAN_CS_SLEEP == Can_ControllerStatus[CanControllerId].State) && (lddInakSlak == 0x00000000))
				{
					Can_ControllerStatus[CanControllerId].State = CAN_CS_STOPPED;
				}
			}
		}
	}
}

FUNC (Can_ReturnType, CAN_CODE) BxCan_SetControllerMode( VAR(uint8, AUTOMATIC) Controller,
		P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) PCanConfig,
		VAR(Can_StateTransitionType, AUTOMATIC) Transition)
{

	/* Variable for return status. */
	VAR(Can_ReturnType, AUTOMATIC)  eReturnValue = CAN_NOT_OK;
	switch (Transition)
	{
		case (CAN_T_STOP):
				eReturnValue = BxCan_SetControllerToStopMode(Controller, PCanConfig);
		break;

		/* CANIF_CS_STOPPED -> CANIF_CS_STARTED. */
		case (CAN_T_START):
				eReturnValue = BxCan_SetControllerToStartMode(Controller, PCanConfig);
		break;

		/* CANIF_CS_STOPPED -> CANIF_CS_SLEEP. */
		case (CAN_T_SLEEP):
				eReturnValue = BxCan_SetControllerToSleepMode(Controller, PCanConfig);
		break;
		/* CANIF_CS_SLEEP -> CANIF_CS_STOPPED */
		case (CAN_T_WAKEUP):
				eReturnValue = BxCan_SetControllerToWakeupMode(Controller, PCanConfig);
		break;
		/* Unknown transition requested. */
		default:
			break;

	} /* end switch */

	return (eReturnValue);
}

static FUNC (Can_ReturnType, CAN_CODE) BxCan_SetControllerToStopMode(  VAR(uint8, AUTOMATIC) CanControllerId,
		P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) pCanConfig)
{
	/* Variable for return status. */
	VAR(Can_ReturnType, AUTOMATIC)  eReturnValue = CAN_NOT_OK;


	if ( CAN_CS_STOPPED ==Can_ControllerStatus[CanControllerId].State)
	{
		eReturnValue = CAN_OK;
	}
	else
	{
		{	/* Valid transitions to Stop are only from Start and Wakeup. */
			if ( CAN_CS_STARTED !=Can_ControllerStatus[CanControllerId].State )
			{
				eReturnValue = CAN_NOT_OK;
			}
			else
			{
				/* Check if Ints are enabled by Can_EnableControllerInterrupts. */
				if ( CAN_INTERRUPT_ENABLED == Can_ControllerStatus[CanControllerId].eInterruptMode )
				{

					REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_TMEIE_MASK,  TMEIE_Disable);
					REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_FMPIE0_MASK, FMPIE0_Disable);
					REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_FFIE0_MASK,  FFIE0_Disable);
					REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_FOVIE0_MASK, FOVIE0_Disable);
					REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_FMPIE1_MASK, FMPIE1_Disable);
					REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_FFIE1_MASK,  FFIE1_Disable);
					REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_FOVIE1_MASK, FOVIE1_Disable);
					/*ERRIE*/
					REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_ERRIE_MASK,  ERRIE_Disable);
					/*BOFIE*/
					REG_RMW32(CAN_IER_ADDR32(CanControllerId), CAN_BOFIE_MASK,  BOFIE_Disable);

					eReturnValue = CAN_OK;
				}
				/* @violates @ref Can_Flexcan_c_REF_8 Results boolean operations whose results are maybe variant */
				if (CAN_OK == eReturnValue)
				{
					uint16 LTimeOutCtr = 0xFFFF;
					/* Disable module */
					SchM_Enter_Can_CAN_EXCLUSIVE_AREA_06();

					/* Request initialization  SET INRQBIT . ACK */
					REG_BIT_SET32(CAN_MCR_ADDR32(CanControllerId), BXCAN_MCR_INRQ_U32);
					// exit from sleep mode
					REG_BIT_CLEAR32(CAN_MCR_ADDR32(CanControllerId), CAN_MCR_SLEEP);

					uint32 lddInakSlak = REG_READ32(CAN_MSR_ADDR32(CanControllerId)) & (BXCAN_MSR_INAK_U32|BXCAN_MSR_SLAK_U32);

					/* Wait the acknowledge */
					/*Initialization SLAK= 0 INAK = 1*/
					while ((lddInakSlak != 0x00000001)&&(LTimeOutCtr > 0))
					{
						LTimeOutCtr--;
						lddInakSlak = REG_READ32(CAN_MSR_ADDR32(CanControllerId)) & (BXCAN_MSR_INAK_U32|BXCAN_MSR_SLAK_U32);
					}
					if(LTimeOutCtr ==0 )
					{
						Can_ControllerStatus[CanControllerId].ErrorCode |= CAN_ERROR_TIMEOUT;
						eReturnValue = CAN_NOT_OK;
					}
					else
					{
						Can_ControllerStatus[CanControllerId].State = CAN_CS_STOPPED;
						Can_ControllerStatus[CanControllerId].ErrorCode = CAN_ERROR_NONE;

						eReturnValue = CAN_OK;
					}
					SchM_Exit_Can_CAN_EXCLUSIVE_AREA_06();
				}
			}
		}
		Can_ControllerStatus[CanControllerId].State = CAN_CS_STOPPED;

		return eReturnValue;
	}
}

static FUNC (Can_ReturnType, CAN_CODE) BxCan_SetControllerToStartMode(  VAR(uint8, AUTOMATIC) CanControllerId,
		P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) pCanConfig
)
{
	/* Variable for return status. */
	VAR(Can_ReturnType, AUTOMATIC)  eReturnValue = CAN_NOT_OK;
	/* Valid transitions to Start mode are only from Stop state. */
	if ( CAN_CS_STOPPED != Can_ControllerStatus[CanControllerId].State)
	{
		eReturnValue = CAN_NOT_OK;
	}
	else
	{
		if ((Std_ReturnType)E_OK == 
		BxCan_InitController(CanControllerId,&pCanConfig[CanControllerId]))
		{
			eReturnValue = CAN_OK;

			if  (Can_ControllerStatus[CanControllerId].State == CAN_CS_STOPPED)
			{
				REG_BIT_CLEAR32(CAN_MCR_ADDR32(CanControllerId), CAN1_INRQ_MASK) ;

				uint16 LTimeOutCtr = 0xFFFF;
				uint32 lddInakSlak = REG_READ32(CAN_MSR_ADDR32(CanControllerId)) & (BXCAN_MSR_INAK_U32|BXCAN_MSR_SLAK_U32);

				/* Wait the acknowledge */
				/*Initialization SLAK= 0 INAK = 0*/
				while ((lddInakSlak != 0x00000000)&&(LTimeOutCtr > 0))
				{
					LTimeOutCtr--;
					lddInakSlak = REG_READ32(CAN_MSR_ADDR32(CanControllerId)) & (BXCAN_MSR_INAK_U32|BXCAN_MSR_SLAK_U32);
				}
				if(LTimeOutCtr ==0 )
				{
					Can_ControllerStatus[CanControllerId].ErrorCode |= CAN_ERROR_TIMEOUT;
					eReturnValue = CAN_NOT_OK;
				}
				else
				{
					Can_ControllerStatus[CanControllerId].State = CAN_CS_STARTED;
					Can_ControllerStatus[CanControllerId].ErrorCode = CAN_ERROR_NONE;
					// Return function status
					eReturnValue = CAN_OK;
				}

			}
			else
			{
				// Update error code
				Can_ControllerStatus[CanControllerId].ErrorCode |= CAN_ERROR_NOT_READY;

				eReturnValue = CAN_NOT_OK;
			}
		}
	}

	return eReturnValue;
}

static FUNC (Can_ReturnType, CAN_CODE) BxCan_SetControllerToSleepMode(  VAR(uint8, AUTOMATIC) CanControllerId,
		P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) pCanConfig)
{
	/* Variable for return status. */
	VAR(Can_ReturnType, AUTOMATIC)  eReturnValue = CAN_NOT_OK;

	/*
       (PR-MCAL-3057) The Can driver shall not create a development error if the CanIf requests a transision to a state that was already reached.
	 */
	if (CAN_CS_SLEEP == Can_ControllerStatus[CanControllerId].State)
	{
		/* If the controller is already in SLEEP state, return CAN_OK. */
		eReturnValue = CAN_OK;
	}
	else
	{
		/* Valid transitions to Sleep state are only from Stop state. */
		if ( CAN_CS_STOPPED != Can_ControllerStatus[CanControllerId].State)
		{
			eReturnValue = CAN_NOT_OK;
			/*  (void)Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_E_TRANSITION);*/
		}
		else
		{
			uint32 LTimeOutCtr = 0xFFFF;
			REG_RMW32(CAN_MCR_ADDR32(CanControllerId), CAN1_SLEEP_MASK, CAN1_SLEEP_SET);
			REG_RMW32(CAN_MCR_ADDR32(CanControllerId), CAN1_INRQ_MASK, CAN1_INRQ_RESET);
			uint32 lddInakSlak = REG_READ32(CAN_MSR_ADDR32(CanControllerId)) & (BXCAN_MSR_INAK_U32|BXCAN_MSR_SLAK_U32);

			/* Wait the acknowledge */
			/*Initialization SLAK= 1 INAK = 0*/
			/*while ((lddInakSlak != 0x00000002)&&(LTimeOutCtr > 0))
			{
				LTimeOutCtr--;
				lddInakSlak = REG_READ32(CAN_MSR_ADDR32(CanControllerId)) & (BXCAN_MSR_INAK_U32|BXCAN_MSR_SLAK_U32);
			}
			if(LTimeOutCtr ==0 )
			{
				Can_ControllerStatus[CanControllerId].ErrorCode |= CAN_ERROR_TIMEOUT;
				eReturnValue = CAN_NOT_OK;
			}
			else*/
			{
				Can_ControllerStatus[CanControllerId].State = CAN_CS_SLEEP;
				//CanIf_ControllerModeIndication(Controller, CANIF_CS_SLEEP);
				Can_ControllerStatus[CanControllerId].ErrorCode = CAN_ERROR_NONE;
				// Return function status
				eReturnValue = CAN_OK;
			}
		}
	}
	return eReturnValue;
}

static FUNC (Can_ReturnType, CAN_CODE) BxCan_SetControllerToWakeupMode(  VAR(uint8, AUTOMATIC) CanControllerId ,
		P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) pCanConfig)
{
	/* Variable for return status. */
	VAR(Can_ReturnType, AUTOMATIC)  eReturnValue = CAN_NOT_OK;
	/*Controllers option for wakeup support(CAN_CONTROLLERCONFIG_WAKSUP_EN_U32) is not necessarly to be checked because if this is not supported,
    the controller cannot be in state CAN_CS_SLEEP, so the Det_ReportError will be raised*/
	if (CAN_CS_STOPPED == Can_ControllerStatus[CanControllerId].State)
	{
		/*CanIf shall be notified only for transitions.
        [CAN373] The function Can_Mainfunction_Mode shall call the function CanIf_ControllerModeIndication to
        notify the upper layer about a successful state transition of the CAN controller, in case the state transition
        was triggered by function Can_SetControllerMode
		 */
		eReturnValue = CAN_OK;
	}
	else
	{
		/*
            Valid transitions to Wakeup state are only from Sleep state.
		 */
		if (CAN_CS_SLEEP != Can_ControllerStatus[CanControllerId].State)
		{
			eReturnValue = CAN_NOT_OK;
			/*(void)Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_E_TRANSITION);*/
		}
		else
		{
			/* When Wakeup is not supported the driver should do nothing and return CAN_OK. */
			REG_BIT_CLEAR32(CAN_MCR_ADDR32(CanControllerId), CAN1_SLEEP_MASK) ;

			uint16 LTimeOutCtr = 0xFFFF;
			uint32 lddInakSlak = REG_READ32(CAN_MSR_ADDR32(CanControllerId)) & (BXCAN_MSR_INAK_U32|BXCAN_MSR_SLAK_U32);

			/* Wait the acknowledge */
			/*Initialization SLAK= 0 INAK = 0*/
			while ((lddInakSlak != 0x00000000)&&(LTimeOutCtr > 0))
			{
				LTimeOutCtr--;
				lddInakSlak = REG_READ32(CAN_MSR_ADDR32(CanControllerId)) & (BXCAN_MSR_INAK_U32|BXCAN_MSR_SLAK_U32);
			}
			if(LTimeOutCtr ==0 )
			{
				Can_ControllerStatus[CanControllerId].ErrorCode |= CAN_ERROR_TIMEOUT;
				eReturnValue = CAN_NOT_OK;
			}
			else
			{
				Can_ControllerStatus[CanControllerId].State = CAN_CS_STOPPED;
				//CanIf_ControllerModeIndication(Controller, CANIF_CS_STOPPED);
				Can_ControllerStatus[CanControllerId].ErrorCode = CAN_ERROR_NONE;
				// Return function status
				eReturnValue = CAN_OK;
			}
		}
	}

	return eReturnValue;
}

// RX data processing
FUNC(void, CAN_CODE) BxCan_RxFifo0MsgPendingCallback(void)
{
	if (CAN_GetRxMessage(&Can_pCurrentConfig[0]) != CAN_OK)
	{
		/*Message process failed*/
	}
}


/*================================================================================================*/

#define CAN_STOP_SEC_CODE

#include "Can_MemMap.h"


#ifdef __cplusplus
}
#endif
