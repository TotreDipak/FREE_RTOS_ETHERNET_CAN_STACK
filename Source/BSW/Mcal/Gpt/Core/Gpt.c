/*
 * Gpt.c
 *
 *  Created on: Jul 31, 2024
 *      Author: AshsihP
 */

#include"Gpt.h"
#include"Std_types.h"
#include"StdRegMacros.h"

static Gpt_DriverStatusType Gpt_DriverStatus = GPT_S_UNINITIALIZED;
static P2CONST(GPT_TimerConfigType, AUTOMATIC, GPT_APPL_CONST) Gpt_ConfigPtr = NULL_PTR;

static FUNC(void, GPT_CODE) Gpt_InitArch(P2CONST(GPT_TimerConfigType, AUTOMATIC,GPT_APPL_CONST )GptConfigPtr);


static FUNC (void, GPT_CODE) Gpt_Ch_StartTimer(VAR(uint8, AUTOMATIC) u8HwChannel, VAR(Gpt_ValueType, AUTOMATIC) u32Value);


static FUNC(void, GPT_CODE) Gpt_InitArch(P2CONST(GPT_TimerConfigType, AUTOMATIC,GPT_APPL_CONST )GptConfigPtr)
{
	uint8 id;

	for(id= 0U; id < TIM_MAX; id++)
	{
		if(GptConfigPtr->TimerConfig[id].unTimAvblValue == TRUE)
		{

			switch(GptConfigPtr->TimerConfig[id].unTIMID)
			{
				case TIM_1:
					REG_RMW32(TIMx_CR1_ADDR(TIM_1), GPT_CR1_UDIS_MASK, GptConfigPtr->TimerConfig[id].unUDISValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_1), GPT_CR1_URS_MASK, GptConfigPtr->TimerConfig[id].unURSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_1), GPT_CR1_OPM_MASK, GptConfigPtr->TimerConfig[id].unOPMValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_1), GPT_CR1_DIR_MASK, GptConfigPtr->TimerConfig[id].unDIRValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_1), GPT_CR1_CMS_MASK, GptConfigPtr->TimerConfig[id].unCMSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_1), GPT_CR1_ARPE_MASK, GptConfigPtr->TimerConfig[id].unARPEValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_1), GPT_CR1_CKD_MASK, GptConfigPtr->TimerConfig[id].unCKDValue);
					REG_RMW32(TIMx_ARR_ADDR(TIM_1), GPT_ARR_MASK, GptConfigPtr->TimerConfig[id].unARR);
					REG_RMW32(TIMx_CNT_ADDR(TIM_1), GPT_CNT_MASK, GptConfigPtr->TimerConfig[id].unCNT);
					REG_RMW16(TIMx_PSC_ADDR(TIM_1), GPT_PSC_MASK, GptConfigPtr->TimerConfig[id].unPSC);

					break;
				case TIM_2:
					REG_RMW32(TIMx_CR1_ADDR(TIM_2), GPT_CR1_UDIS_MASK, GptConfigPtr->TimerConfig[id].unUDISValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_2), GPT_CR1_URS_MASK, GptConfigPtr->TimerConfig[id].unURSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_2), GPT_CR1_OPM_MASK, GptConfigPtr->TimerConfig[id].unOPMValue);
					REG_RMW32(TIMx_CNT_ADDR(TIM_2), GPT_CNT_MASK, GptConfigPtr->TimerConfig[id].unCNT);
					REG_RMW32(TIMx_CR1_ADDR(TIM_2), GPT_CR1_DIR_MASK, GptConfigPtr->TimerConfig[id].unDIRValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_2), GPT_CR1_CMS_MASK, GptConfigPtr->TimerConfig[id].unCMSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_2), GPT_CR1_ARPE_MASK, GptConfigPtr->TimerConfig[id].unARPEValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_2), GPT_CR1_CKD_MASK, GptConfigPtr->TimerConfig[id].unCKDValue);
					REG_RMW32(TIMx_ARR_ADDR(TIM_2), GPT_ARR_MASK, GptConfigPtr->TimerConfig[id].unARR);
					REG_RMW16(TIMx_PSC_ADDR(TIM_2), GPT_PSC_MASK, GptConfigPtr->TimerConfig[id].unPSC);

					break;
				case TIM_3:
					REG_RMW32(TIMx_CR1_ADDR(TIM_3), GPT_CR1_UDIS_MASK, GptConfigPtr->TimerConfig[id].unUDISValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_3), GPT_CR1_URS_MASK, GptConfigPtr->TimerConfig[id].unURSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_3), GPT_CR1_OPM_MASK, GptConfigPtr->TimerConfig[id].unOPMValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_3), GPT_CR1_DIR_MASK, GptConfigPtr->TimerConfig[id].unDIRValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_3), GPT_CR1_CMS_MASK, GptConfigPtr->TimerConfig[id].unCMSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_3), GPT_CR1_ARPE_MASK, GptConfigPtr->TimerConfig[id].unARPEValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_3), GPT_CR1_CKD_MASK, GptConfigPtr->TimerConfig[id].unCKDValue);
					REG_RMW32(TIMx_ARR_ADDR(TIM_3), GPT_ARR_MASK, (uint16)GptConfigPtr->TimerConfig[id].unARR);
					REG_RMW32(TIMx_CNT_ADDR(TIM_3), GPT_CNT_MASK,(uint16) GptConfigPtr->TimerConfig[id].unCNT);
					REG_RMW16(TIMx_PSC_ADDR(TIM_3), GPT_PSC_MASK, (uint16)GptConfigPtr->TimerConfig[id].unPSC);

					break;
				case TIM_4:
					REG_RMW32(TIMx_CR1_ADDR(TIM_4), GPT_CR1_UDIS_MASK, GptConfigPtr->TimerConfig[id].unUDISValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_4), GPT_CR1_URS_MASK, GptConfigPtr->TimerConfig[id].unURSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_4), GPT_CR1_OPM_MASK, GptConfigPtr->TimerConfig[id].unOPMValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_4), GPT_CR1_DIR_MASK, GptConfigPtr->TimerConfig[id].unDIRValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_4), GPT_CR1_CMS_MASK, GptConfigPtr->TimerConfig[id].unCMSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_4), GPT_CR1_ARPE_MASK, GptConfigPtr->TimerConfig[id].unARPEValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_4), GPT_CR1_CKD_MASK, GptConfigPtr->TimerConfig[id].unCKDValue);
					REG_RMW32(TIMx_ARR_ADDR(TIM_4), GPT_ARR_MASK, (uint16)GptConfigPtr->TimerConfig[id].unARR);
					REG_RMW32(TIMx_CNT_ADDR(TIM_4), GPT_CNT_MASK, (uint16)GptConfigPtr->TimerConfig[id].unCNT);
					REG_RMW16(TIMx_PSC_ADDR(TIM_4), GPT_PSC_MASK, (uint16)GptConfigPtr->TimerConfig[id].unPSC);

					break;
				case TIM_5:
					REG_RMW32(TIMx_CR1_ADDR(TIM_5), GPT_CR1_UDIS_MASK, GptConfigPtr->TimerConfig[id].unUDISValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_5), GPT_CR1_URS_MASK, GptConfigPtr->TimerConfig[id].unURSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_5), GPT_CR1_OPM_MASK, GptConfigPtr->TimerConfig[id].unOPMValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_5), GPT_CR1_DIR_MASK, GptConfigPtr->TimerConfig[id].unDIRValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_5), GPT_CR1_CMS_MASK, GptConfigPtr->TimerConfig[id].unCMSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_5), GPT_CR1_ARPE_MASK, GptConfigPtr->TimerConfig[id].unARPEValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_5), GPT_CR1_CKD_MASK, GptConfigPtr->TimerConfig[id].unCKDValue);
					REG_RMW32(TIMx_ARR_ADDR(TIM_5), GPT_ARR_MASK,    GptConfigPtr->TimerConfig[id].unARR);
					REG_RMW32(TIMx_CNT_ADDR(TIM_5), GPT_CNT_MASK,    GptConfigPtr->TimerConfig[id].unCNT);
					REG_RMW16(TIMx_PSC_ADDR(TIM_5), GPT_PSC_MASK,    GptConfigPtr->TimerConfig[id].unPSC);

					break;
				case TIM_6:
					REG_RMW32(TIMx_CR1_ADDR(TIM_6), GPT_CR1_UDIS_MASK, GptConfigPtr->TimerConfig[id].unUDISValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_6), GPT_CR1_URS_MASK, GptConfigPtr->TimerConfig[id].unURSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_6), GPT_CR1_OPM_MASK, GptConfigPtr->TimerConfig[id].unOPMValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_6), GPT_CR1_DIR_MASK, GptConfigPtr->TimerConfig[id].unDIRValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_6), GPT_CR1_CMS_MASK, GptConfigPtr->TimerConfig[id].unCMSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_6), GPT_CR1_ARPE_MASK, GptConfigPtr->TimerConfig[id].unARPEValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_6), GPT_CR1_CKD_MASK, GptConfigPtr->TimerConfig[id].unCKDValue);
					REG_RMW32(TIMx_ARR_ADDR(TIM_6), GPT_ARR_MASK, GptConfigPtr->TimerConfig[id].unARR);
					REG_RMW32(TIMx_CNT_ADDR(TIM_6), GPT_CNT_MASK, GptConfigPtr->TimerConfig[id].unCNT);
					REG_RMW16(TIMx_PSC_ADDR(TIM_6), GPT_PSC_MASK, GptConfigPtr->TimerConfig[id].unPSC);

					break;
				case TIM_7:
					REG_RMW32(TIMx_CR1_ADDR(TIM_7), GPT_CR1_UDIS_MASK, GptConfigPtr->TimerConfig[id].unUDISValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_7), GPT_CR1_URS_MASK, GptConfigPtr->TimerConfig[id].unURSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_7), GPT_CR1_OPM_MASK, GptConfigPtr->TimerConfig[id].unOPMValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_7), GPT_CR1_DIR_MASK, GptConfigPtr->TimerConfig[id].unDIRValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_7), GPT_CR1_CMS_MASK, GptConfigPtr->TimerConfig[id].unCMSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_7), GPT_CR1_ARPE_MASK, GptConfigPtr->TimerConfig[id].unARPEValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_7), GPT_CR1_CKD_MASK, GptConfigPtr->TimerConfig[id].unCKDValue);
					REG_RMW32(TIMx_ARR_ADDR(TIM_7), GPT_ARR_MASK, GptConfigPtr->TimerConfig[id].unARR);
					REG_RMW32(TIMx_CNT_ADDR(TIM_7), GPT_CNT_MASK, GptConfigPtr->TimerConfig[id].unCNT);
					REG_RMW16(TIMx_PSC_ADDR(TIM_7), GPT_PSC_MASK, GptConfigPtr->TimerConfig[id].unPSC);

					break;
				case TIM_8:
					REG_RMW32(TIMx_CR1_ADDR(TIM_8), GPT_CR1_UDIS_MASK, GptConfigPtr->TimerConfig[id].unUDISValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_8), GPT_CR1_URS_MASK, GptConfigPtr->TimerConfig[id].unURSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_8), GPT_CR1_OPM_MASK, GptConfigPtr->TimerConfig[id].unOPMValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_8), GPT_CR1_DIR_MASK, GptConfigPtr->TimerConfig[id].unDIRValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_8), GPT_CR1_CMS_MASK, GptConfigPtr->TimerConfig[id].unCMSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_8), GPT_CR1_ARPE_MASK, GptConfigPtr->TimerConfig[id].unARPEValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_8), GPT_CR1_CKD_MASK, GptConfigPtr->TimerConfig[id].unCKDValue);
					REG_RMW32(TIMx_ARR_ADDR(TIM_8), GPT_ARR_MASK, GptConfigPtr->TimerConfig[id].unARR);
					REG_RMW32(TIMx_CNT_ADDR(TIM_8), GPT_CNT_MASK, GptConfigPtr->TimerConfig[id].unCNT);
					REG_RMW16(TIMx_PSC_ADDR(TIM_8), GPT_PSC_MASK, GptConfigPtr->TimerConfig[id].unPSC);

					break;
				case TIM_9:
					REG_RMW32(TIMx_CR1_ADDR(TIM_9), GPT_CR1_UDIS_MASK, GptConfigPtr->TimerConfig[id].unUDISValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_9), GPT_CR1_URS_MASK, GptConfigPtr->TimerConfig[id].unURSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_9), GPT_CR1_OPM_MASK, GptConfigPtr->TimerConfig[id].unOPMValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_9), GPT_CR1_DIR_MASK, GptConfigPtr->TimerConfig[id].unDIRValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_9), GPT_CR1_CMS_MASK, GptConfigPtr->TimerConfig[id].unCMSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_9), GPT_CR1_ARPE_MASK, GptConfigPtr->TimerConfig[id].unARPEValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_9), GPT_CR1_CKD_MASK, GptConfigPtr->TimerConfig[id].unCKDValue);
					REG_RMW32(TIMx_ARR_ADDR(TIM_9), GPT_ARR_MASK, GptConfigPtr->TimerConfig[id].unARR);
					REG_RMW32(TIMx_CNT_ADDR(TIM_9), GPT_CNT_MASK, GptConfigPtr->TimerConfig[id].unCNT);
					REG_RMW16(TIMx_PSC_ADDR(TIM_9), GPT_PSC_MASK, GptConfigPtr->TimerConfig[id].unPSC);

					break;
				case TIM_10:
					REG_RMW32(TIMx_CR1_ADDR(TIM_10), GPT_CR1_UDIS_MASK, GptConfigPtr->TimerConfig[id].unUDISValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_10), GPT_CR1_URS_MASK, GptConfigPtr->TimerConfig[id].unURSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_10), GPT_CR1_OPM_MASK, GptConfigPtr->TimerConfig[id].unOPMValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_10), GPT_CR1_DIR_MASK, GptConfigPtr->TimerConfig[id].unDIRValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_10), GPT_CR1_CMS_MASK, GptConfigPtr->TimerConfig[id].unCMSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_10), GPT_CR1_ARPE_MASK, GptConfigPtr->TimerConfig[id].unARPEValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_10), GPT_CR1_CKD_MASK, GptConfigPtr->TimerConfig[id].unCKDValue);
					REG_RMW32(TIMx_ARR_ADDR(TIM_10), GPT_ARR_MASK, GptConfigPtr->TimerConfig[id].unARR);
					REG_RMW32(TIMx_CNT_ADDR(TIM_10), GPT_CNT_MASK, GptConfigPtr->TimerConfig[id].unCNT);
					REG_RMW16(TIMx_PSC_ADDR(TIM_10), GPT_PSC_MASK, GptConfigPtr->TimerConfig[id].unPSC);

					break;
				case TIM_11:
					REG_RMW32(TIMx_CR1_ADDR(TIM_11), GPT_CR1_UDIS_MASK, GptConfigPtr->TimerConfig[id].unUDISValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_11), GPT_CR1_URS_MASK, GptConfigPtr->TimerConfig[id].unURSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_11), GPT_CR1_OPM_MASK, GptConfigPtr->TimerConfig[id].unOPMValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_11), GPT_CR1_DIR_MASK, GptConfigPtr->TimerConfig[id].unDIRValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_11), GPT_CR1_CMS_MASK, GptConfigPtr->TimerConfig[id].unCMSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_11), GPT_CR1_ARPE_MASK, GptConfigPtr->TimerConfig[id].unARPEValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_11), GPT_CR1_CKD_MASK, GptConfigPtr->TimerConfig[id].unCKDValue);
					REG_RMW32(TIMx_ARR_ADDR(TIM_11), GPT_ARR_MASK, GptConfigPtr->TimerConfig[id].unARR);
					REG_RMW32(TIMx_CNT_ADDR(TIM_11), GPT_CNT_MASK, GptConfigPtr->TimerConfig[id].unCNT);
					REG_RMW16(TIMx_PSC_ADDR(TIM_11), GPT_PSC_MASK, GptConfigPtr->TimerConfig[id].unPSC);

					break;
				case TIM_12:
					REG_RMW32(TIMx_CR1_ADDR(TIM_12), GPT_CR1_UDIS_MASK, GptConfigPtr->TimerConfig[id].unUDISValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_12), GPT_CR1_URS_MASK, GptConfigPtr->TimerConfig[id].unURSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_12), GPT_CR1_OPM_MASK, GptConfigPtr->TimerConfig[id].unOPMValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_12), GPT_CR1_DIR_MASK, GptConfigPtr->TimerConfig[id].unDIRValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_12), GPT_CR1_CMS_MASK, GptConfigPtr->TimerConfig[id].unCMSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_12), GPT_CR1_ARPE_MASK, GptConfigPtr->TimerConfig[id].unARPEValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_12), GPT_CR1_CKD_MASK, GptConfigPtr->TimerConfig[id].unCKDValue);
					REG_RMW32(TIMx_ARR_ADDR(TIM_12), GPT_ARR_MASK, GptConfigPtr->TimerConfig[id].unARR);
					REG_RMW32(TIMx_CNT_ADDR(TIM_12), GPT_CNT_MASK, GptConfigPtr->TimerConfig[id].unCNT);
					REG_RMW16(TIMx_PSC_ADDR(TIM_12), GPT_PSC_MASK, GptConfigPtr->TimerConfig[id].unPSC);

					break;
				case TIM_13:
					REG_RMW32(TIMx_CR1_ADDR(TIM_13), GPT_CR1_UDIS_MASK, GptConfigPtr->TimerConfig[id].unUDISValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_13), GPT_CR1_URS_MASK, GptConfigPtr->TimerConfig[id].unURSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_13), GPT_CR1_OPM_MASK, GptConfigPtr->TimerConfig[id].unOPMValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_13), GPT_CR1_DIR_MASK, GptConfigPtr->TimerConfig[id].unDIRValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_13), GPT_CR1_CMS_MASK, GptConfigPtr->TimerConfig[id].unCMSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_13), GPT_CR1_ARPE_MASK, GptConfigPtr->TimerConfig[id].unARPEValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_13), GPT_CR1_CKD_MASK, GptConfigPtr->TimerConfig[id].unCKDValue);
					REG_RMW32(TIMx_ARR_ADDR(TIM_13), GPT_ARR_MASK, GptConfigPtr->TimerConfig[id].unARR);
					REG_RMW32(TIMx_CNT_ADDR(TIM_13), GPT_CNT_MASK, GptConfigPtr->TimerConfig[id].unCNT);
					REG_RMW16(TIMx_PSC_ADDR(TIM_13), GPT_PSC_MASK, GptConfigPtr->TimerConfig[id].unPSC);

					break;
				case TIM_14:
					REG_RMW32(TIMx_CR1_ADDR(TIM_14), GPT_CR1_UDIS_MASK, GptConfigPtr->TimerConfig[id].unUDISValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_14), GPT_CR1_URS_MASK, GptConfigPtr->TimerConfig[id].unURSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_14), GPT_CR1_OPM_MASK, GptConfigPtr->TimerConfig[id].unOPMValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_14), GPT_CR1_DIR_MASK, GptConfigPtr->TimerConfig[id].unDIRValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_14), GPT_CR1_CMS_MASK, GptConfigPtr->TimerConfig[id].unCMSValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_14), GPT_CR1_ARPE_MASK, GptConfigPtr->TimerConfig[id].unARPEValue);
					REG_RMW32(TIMx_CR1_ADDR(TIM_14), GPT_CR1_CKD_MASK, GptConfigPtr->TimerConfig[id].unCKDValue);
					REG_RMW32(TIMx_ARR_ADDR(TIM_14), GPT_ARR_MASK, GptConfigPtr->TimerConfig[id].unARR);
					REG_RMW32(TIMx_CNT_ADDR(TIM_14), GPT_CNT_MASK, GptConfigPtr->TimerConfig[id].unCNT);
					REG_RMW16(TIMx_PSC_ADDR(TIM_14), GPT_PSC_MASK, GptConfigPtr->TimerConfig[id].unPSC);


					break;
				default:
					break;

			}
		}
	}
}





 FUNC(void, GPT_CODE)Gpt_Init (P2CONST(GPT_TimerConfigType, AUTOMATIC, GPT_APPL_CONST) ConfigPtr)
{
	 if(NULL_PTR == ConfigPtr)
	 	{
		 Gpt_ConfigPtr	= &Gpt_Config[0];
	 	}
	 	else
	 	{

	 	}

	    Gpt_InitArch(Gpt_ConfigPtr);

	 	Gpt_DriverStatus = GPT_S_INITIALIZED;
	 	return;
}





FUNC(void, GPT_CODE) Gpt_StartTimer(VAR(Gpt_ChannelType,AUTOMATIC) channel,VAR(Gpt_ValueType,AUTOMATIC) value)
{

	Gpt_Ch_StartTimer(channel, value);

}

FUNC(void, GPT_CODE) Gpt_Ch_StartTimer(VAR(uint8, AUTOMATIC) u8HwChannel, VAR(Gpt_ValueType, AUTOMATIC) u32Value)
{

	switch(u8HwChannel)
	{
	case TIM_2:
		REG_RMW32(TIMx_CR1_ADDR(TIM_2), GPT_CR1_CEN_MASK, CEN_DISABLED);
		REG_RMW32(TIMx_ARR_ADDR(TIM_2), GPT_ARR_MASK, u32Value);
		REG_RMW32(TIMx_CR1_ADDR(TIM_2), GPT_CR1_CEN_MASK, CEN_ENABLED);
		break;

	case TIM_3:
		REG_RMW16(TIMx_CR1_ADDR(TIM_3), GPT_CR1_CEN_MASK, (uint16)CEN_DISABLED);
		REG_RMW16(TIMx_ARR_ADDR(TIM_3), GPT_ARR_MASK, (uint16)u32Value);
		REG_RMW16(TIMx_CR1_ADDR(TIM_3), GPT_CR1_CEN_MASK, (uint16)CEN_ENABLED);
		break;

	case TIM_4:
		REG_RMW16(TIMx_CR1_ADDR(TIM_4), GPT_CR1_CEN_MASK,(uint16) CEN_DISABLED);
		REG_RMW16(TIMx_ARR_ADDR(TIM_4), GPT_ARR_MASK, (uint16)u32Value);
		REG_RMW16(TIMx_CR1_ADDR(TIM_4), GPT_CR1_CEN_MASK,(uint16) CEN_ENABLED);
		break;

	case TIM_5:
		REG_RMW32(TIMx_CR1_ADDR(TIM_5), GPT_CR1_CEN_MASK, CEN_DISABLED);
		REG_RMW32(TIMx_ARR_ADDR(TIM_5), GPT_ARR_MASK, u32Value);
		REG_RMW32(TIMx_CR1_ADDR(TIM_5), GPT_CR1_CEN_MASK, CEN_ENABLED);
		break;
	case TIM_6:
	    REG_RMW32(TIMx_CR1_ADDR(TIM_6), GPT_CR1_CEN_MASK, CEN_DISABLED);
	    REG_RMW32(TIMx_ARR_ADDR(TIM_6), GPT_ARR_MASK, u32Value);
	    REG_RMW32(TIMx_CR1_ADDR(TIM_6), GPT_CR1_CEN_MASK, CEN_ENABLED);
	    break;
	default:
		break;


	return;
}
}

FUNC(void, GPT_CODE) Gpt_StopTimer(VAR(Gpt_ChannelType, AUTOMATIC) u8HwChannel)
		{

			switch(u8HwChannel)
			{
			case TIM_2:
				REG_RMW32(TIMx_ARR_ADDR(TIM_2), GPT_ARR_MASK,GPT_ARR_PRESET);
				REG_RMW32(TIMx_CR1_ADDR(TIM_2), GPT_CR1_CEN_MASK, CEN_DISABLED);
				break;

			case TIM_3:
				REG_RMW16(TIMx_ARR_ADDR(TIM_3), GPT_ARR_MASK, (uint16)GPT_ARR_PRESET);
				REG_RMW16(TIMx_CR1_ADDR(TIM_3), GPT_CR1_CEN_MASK, CEN_DISABLED);
				break;

			case TIM_4:
				REG_RMW16(TIMx_ARR_ADDR(TIM_4), GPT_ARR_MASK,(uint16)GPT_ARR_PRESET);
				REG_RMW16(TIMx_CR1_ADDR(TIM_4), GPT_CR1_CEN_MASK, CEN_DISABLED);
				break;

			case TIM_5:
				REG_RMW32(TIMx_ARR_ADDR(TIM_5), GPT_ARR_MASK,GPT_ARR_PRESET );
				REG_RMW32(TIMx_CR1_ADDR(TIM_5), GPT_CR1_CEN_MASK,CEN_DISABLED);
				break;
			case TIM_6:
				REG_RMW32(TIMx_ARR_ADDR(TIM_6), GPT_ARR_MASK,GPT_ARR_PRESET );
				REG_RMW32(TIMx_CR1_ADDR(TIM_6), GPT_CR1_CEN_MASK,CEN_DISABLED);
				break;
			default:
				break;


			return;
		}
		}


FUNC(void, GPT_CODE) Gpt_EnableNotification(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{
	switch(channel)
				{
				case TIM_2:
					REG_RMW32(TIMx_SR_ADDR(TIM_2), GPT_SR_UIF_MASK, UIF_CLEARED);
					REG_RMW32(TIMx_DIER_ADDR(TIM_2), GPT_DIER_UIE_MASK, UIR_ENABLED);
					break;

				case TIM_3:
					REG_RMW16(TIMx_SR_ADDR(TIM_3), GPT_SR_UIF_MASK, UIF_CLEARED);
					REG_RMW16(TIMx_DIER_ADDR(TIM_3), GPT_DIER_UIE_MASK, UIR_ENABLED);
					break;

				case TIM_4:
					REG_RMW16(TIMx_SR_ADDR(TIM_4), GPT_SR_UIF_MASK, UIF_CLEARED);
					REG_RMW16(TIMx_DIER_ADDR(TIM_4), GPT_DIER_UIE_MASK, UIR_ENABLED);
					break;

				case TIM_5:
					REG_RMW32(TIMx_SR_ADDR(TIM_5), GPT_SR_UIF_MASK, UIF_CLEARED);
					REG_RMW32(TIMx_DIER_ADDR(TIM_5), GPT_DIER_UIE_MASK, UIR_ENABLED);
					break;
				case TIM_6:
					REG_RMW32(TIMx_SR_ADDR(TIM_6), GPT_SR_UIF_MASK, UIF_CLEARED);
					REG_RMW32(TIMx_DIER_ADDR(TIM_6), GPT_DIER_UIE_MASK, UIR_ENABLED);
					break;
				default:
					break;
				return;
			}

}


FUNC(void, GPT_CODE) Gpt_DisbleNotification(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{
	switch(channel)
				{
				case TIM_2:
					REG_RMW32(TIMx_SR_ADDR(TIM_2), GPT_SR_UIF_MASK, UIF_CLEARED);
					REG_RMW32(TIMx_DIER_ADDR(TIM_2), GPT_DIER_UIE_MASK, UIR_DISABLED);
					break;

				case TIM_3:
					REG_RMW16(TIMx_SR_ADDR(TIM_3), GPT_SR_UIF_MASK,(uint16)UIF_CLEARED);
					REG_RMW16(TIMx_DIER_ADDR(TIM_3), GPT_DIER_UIE_MASK, UIR_DISABLED);
					break;

				case TIM_4:
					REG_RMW32(TIMx_SR_ADDR(TIM_4), GPT_SR_UIF_MASK, (uint16)UIF_CLEARED);
					REG_RMW16(TIMx_DIER_ADDR(TIM_4), GPT_DIER_UIE_MASK, UIR_DISABLED);
					break;

				case TIM_5:
					REG_RMW32(TIMx_SR_ADDR(TIM_5), GPT_SR_UIF_MASK, UIF_CLEARED);
					REG_RMW32(TIMx_DIER_ADDR(TIM_5), GPT_DIER_UIE_MASK, UIR_DISABLED);
					break;
				case TIM_6:
					REG_RMW32(TIMx_SR_ADDR(TIM_6), GPT_SR_UIF_MASK, UIF_CLEARED);
					REG_RMW32(TIMx_DIER_ADDR(TIM_6), GPT_DIER_UIE_MASK, UIR_DISABLED);
					break;
				default:
					break;

				return;
			}

}
