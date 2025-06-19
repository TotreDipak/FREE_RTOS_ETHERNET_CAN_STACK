/*
 * Gpt_Internal.h
 *
 *  Created on: Jul 30, 2024
 *      Author: AshsihP
 */

#ifndef GPT_INTERNAL_H_
#define GPT_INTERNAL_H_

#include "Std_Types.h"
#include "GPT_RegTypes.h"
#include "StdRegMacros.h"


typedef enum
{
	TIM_1,
	TIM_2,
	TIM_3,
	TIM_4,
	TIM_5,
	TIM_6,
	TIM_7,
	TIM_8,
	TIM_9,
	TIM_10,
	TIM_11,
	TIM_12,
	TIM_13,
	TIM_14,
	TIM_MAX
}TimerIDType;



typedef enum
{
    GPT_S_ILLEGAL,
	GPT_S_UNINITIALIZED,
	GPT_S_INITIALIZED
}Gpt_DriverStatusType;


typedef enum
{
	CEN_DISABLED=0x0000,
	CEN_ENABLED=0x0001
}Cr1CenType;

typedef enum
{
	UEV_ENABLED=0x0000,
	UEV_DISABLED=0x0002
}Cr1UdisType;

typedef enum
{
	UDIS_DISABLED=0x0000,
	UDIS_ENABLED=0x0004
}Cr1URSType;

typedef enum
{
	OPM_DISABLED=0x0000,
	OPM_ENABLED=0x0008
}Cr1OpmType;

typedef enum
{
	UPCOUNTER=0x0000,
	DOWNCOUNTER=0x0010
}Cr1DirType;

typedef enum
{
	Edge_ALIGNMODE=0x0000,
	Center_ALIGNMODE1=0x020,
	Center_ALIGNMODE2=0x040,
	Center_ALIGNMODE3=0x060
}Cr1CMSType;

typedef enum
{
	ARR_DISABLED=0x0000,
	ARR_ENABLED=0x0080
}Cr1ArpeType;

typedef enum
{
	SAMPLING_CLOCK=0x0000,
	SAMPLING_CLOCK_TWICE=0x0100,
	SAMPLING_CLOCK_FOUR=0x0200,
	RESERVED=0x0300
}Cr1CkdType;

typedef enum
{
	UIF_CLEARED=0x0000
}SrUifType;

typedef enum
{
	UIR_DISABLED=0x0000,
	UIR_ENABLED=0x0001
}DierUieType;
typedef struct
{
	/*TimerID*/
	VAR(TimerIDType,AUTOMATIC) unTIMID;   /**< @brief TIMER ID */
/*	Gpt_ControlRegister1*/
	VAR(boolean, AUTOMATIC) unTimAvblValue;
	VAR(Cr1UdisType,AUTOMATIC) unUDISValue;
	VAR(Cr1URSType, AUTOMATIC) unURSValue;
	VAR(Cr1OpmType, AUTOMATIC) unOPMValue;
	VAR(Cr1DirType, AUTOMATIC) unDIRValue;
	VAR(Cr1CMSType, AUTOMATIC) unCMSValue;
	VAR(Cr1ArpeType, AUTOMATIC) unARPEValue;
	VAR(Cr1CkdType, AUTOMATIC) unCKDValue;
/*Gpt_AutoreloadRegister*/
	VAR(uint32, AUTOMATIC) unARR;      /**< @briefARR register*/
	/*Gpt_CounterRegister*/
	VAR(uint32, AUTOMATIC) unCNT;      /**< @briefCounter register*/
	/*Gpt_PSCRegister*/
	VAR(uint16, AUTOMATIC) unPSC;      /**< @briefPrescale register*/
}Gpt_ConfigType;

/*control Register mask*/
#define  GPT_CR1_CEN_MASK          ((uint32)0x00000001)
#define  GPT_CR1_UDIS_MASK         ((uint32)0x00000002)
#define  GPT_CR1_URS_MASK          ((uint32)0x00000004)
#define  GPT_CR1_OPM_MASK          ((uint32)0x00000008)
#define  GPT_CR1_DIR_MASK          ((uint32)0x00000010)
#define  GPT_CR1_CMS_MASK          ((uint32)0x00000060)
#define  GPT_CR1_ARPE_MASK          ((uint32)0x00000080)
#define  GPT_CR1_CKD_MASK          ((uint32)0x00000300)

/*control Register Offset*/
#define  GPT_CR1_UDIS_OFFSET         ((uint8)0x01)
#define  GPT_CR1_URS_OFFSET          ((uint8)0x02)
#define  GPT_CR1_OPM_OFFSET          ((uint8)0x03)
#define  GPT_CR1_DIR_OFFSET          ((uint8)0x04)
#define  GPT_CR1_CMS_OFFSET          ((uint8)0x05)
#define  GPT_CR1_ARPE_OFFSET         ((uint8)0x07)
#define  GPT_CR1_CKD_OFFSET          ((uint8)0x08)

/*Autoreload  Register mask*/
#define  GPT_ARR_MASK          ((uint32)0xFFFFFFFF)
#define  GPT_ARR_PRESET        ((uint32)0xFFFFFFFF)

/*Autoreload  Register mask*/
#define  GPT_CNT_MASK          ((uint32)0x00000001)
/*Autoreload  Register mask*/
#define  GPT_PSC_MASK          ((uint16)0x0001)

/*Status  Register mask*/
#define  GPT_SR_UIF_MASK          ((uint32)0x00000001)

/*DIER Register mask*/
#define  GPT_DIER_UIE_MASK         ((uint32)0x00000001)

#endif /* SOURCE_BSW_GPT_CORE_GPT_INTERNAL_H_ */


