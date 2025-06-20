/*
 * Gpt_RegTypes.h
 *
 *  Created on: Jul 30, 2024
 *      Author: AshsihP
 */

#ifndef GPT_REGTYPES_H_
#define GPT_REGTYPES_H_

#include "Std_Types.h"

#define TIM_1_BASEADDR				((uint32)0x40010000)
#define TIM_2_BASEADDR				((uint32)0x40000000)
#define TIM_3_BASEADDR              ((uint32)0x40000400)
#define TIM_4_BASEADDR              ((uint32)0x40000800)
#define TIM_5_BASEADDR              ((uint32)0x40000C00)
#define TIM_6_BASEADDR              ((uint32)0x40001000)
#define TIM_7_BASEADDR              ((uint32)0x40001400)
#define TIM_8_BASEADDR              ((uint32)0x40010400)
#define TIM_9_BASEADDR              ((uint32)0x40014000)
#define TIM_10_BASEADDR             ((uint32)0x40014400)
#define TIM_11_BASEADDR             ((uint32)0x40014800)
#define TIM_12_BASEADDR             ((uint32)0x40001800)
#define TIM_13_BASEADDR             ((uint32)0x40001C00)
#define TIM_14_BASEADDR             ((uint32)0x40002000)


#define  GPT_TIM_CR1_OFFSET_ADDR32          ((uint32)0x00000000UL)
#define  GPT_TIM_CR2_OFFSET_ADDR32          ((uint32)0x00000004UL)
#define  GPT_TIM_SMCR_OFFSET_ADDR32         ((uint32)0x00000008UL)
#define  GPT_TIM_DIER_OFFSET_ADDR32         ((uint32)0x0000000CUL)
#define  GPT_TIM_SR_OFFSET_ADDR32           ((uint32)0x00000010UL)
#define  GPT_TIM_EGR_OFFSET_ADDR32          ((uint32)0x00000014UL)
#define  GPT_TIM_CCMR1_OFFSET_ADDR32        ((uint32)0x00000018UL)
#define  GPT_TIM_CCMR2_OFFSET_ADDR32        ((uint32)0x0000001CUL)
#define  GPT_TIM_CCER_OFFSET_ADDR32         ((uint32)0x00000020UL)
#define  GPT_TIM_CNT_OFFSET_ADDR32          ((uint32)0x00000024UL)
#define  GPT_TIM_PSC_OFFSET_ADDR32          ((uint32)0x00000028UL)
#define  GPT_TIM_ARR_OFFSET_ADDR32          ((uint32)0x0000002CUL)
#define  GPT_TIM_RCR_OFFSET_ADDR32          ((uint32)0x00000030UL)
#define  GPT_TIM_CCR1_OFFSET_ADDR32         ((uint32)0x00000034UL)
#define  GPT_TIM_CCR2_OFFSET_ADDR32         ((uint32)0x00000038UL)
#define  GPT_TIM_CCR3_OFFSET_ADDR32         ((uint32)0x0000003CUL)
#define  GPT_TIM_CCR4_OFFSET_ADDR32         ((uint32)0x00000040UL)
#define  GPT_TIM_BDTR_OFFSET_ADDR32         ((uint32)0x00000044UL)
#define  GPT_TIM_DCR_OFFSET_ADDR32          ((uint32)0x00000048UL)
#define  GPT_TIM_DMAR_OFFSET_ADDR32         ((uint32)0x0000004CUL)
#define  GPT_TIM_OR_OFFSET_ADDR32           ((uint32)0x00000050UL)
/*Offset End*/


/*Resgiters BAseAddress*/
#define TIMx_BASEADDR(x) x##_BASEADDR
#define TIMx_CR1_ADDR(x) (TIMx_BASEADDR(x) + GPT_TIM_CR1_OFFSET_ADDR32)
#define TIMx_CR2_ADDR(x) (TIMx_BASEADDR(x) + GPT_TIM_CR2_OFFSET_ADDR32)
#define TIMx_SMCR_ADDR(x) (TIMx_BASEADDR(x) + GPT_TIM_SMCR_OFFSET_ADDR32)
#define TIMx_DIER_ADDR(x) (TIMx_BASEADDR(x) + GPT_TIM_DIER_OFFSET_ADDR32)
#define TIMx_SR_ADDR(x)   (TIMx_BASEADDR(x) + GPT_TIM_SR_OFFSET_ADDR32)
#define TIMx_EGR_ADDR(x)  (TIMx_BASEADDR(x) + GPT_TIM_EGR_OFFSET_ADDR32)
#define TIMx_CCMR1_ADDR(x) (TIMx_BASEADDR(x) + GPT_TIM_CCMR1_OFFSET_ADDR32)
#define TIMx_CCMR2_ADDR(x)  (TIMx_BASEADDR(x) + GPT_TIM_CCMR2_OFFSET_ADDR32)
#define TIMx_CCER_ADDR(x)   (TIMx_BASEADDR(x) + GPT_TIM_CCER_OFFSET_ADDR32)
#define TIMx_CNT_ADDR(x)   (TIMx_BASEADDR(x) + GPT_TIM_CNT_OFFSET_ADDR32)
#define TIMx_PSC_ADDR(x)  (TIMx_BASEADDR(x) + GPT_TIM_PSC_OFFSET_ADDR32)
#define TIMx_ARR_ADDR(x)  (TIMx_BASEADDR(x) + GPT_TIM_ARR_OFFSET_ADDR32)
#define TIMx_RCR_ADDR(x)  (TIMx_BASEADDR(x) + GPT_TIM_RCR_OFFSET_ADDR32)
#define TIMx_CCR1_ADDR(x) (TIMx_BASEADDR(x) + GPT_TIM_CCR1_OFFSET_ADDR32)
#define TIMx_CCR2_ADDR(x) (TIMx_BASEADDR(x) + GPT_TIM_CCR2_OFFSET_ADDR32)
#define TIMx_CCR3_ADDR(x) (TIMx_BASEADDR(x) + GPT_TIM_CCR3_OFFSET_ADDR32)
#define TIMx_CCR4_ADDR(x) (TIMx_BASEADDR(x) + GPT_TIM_CCR4_OFFSET_ADDR32)
#define TIMx_BDTR_ADDR(x) (TIMx_BASEADDR(x) + GPT_TIM_BDTR_OFFSET_ADDR32)
#define TIMx_DCR_ADDR(x)  (TIMx_BASEADDR(x) + GPT_TIM_DCR_OFFSET_ADDR32)
#define TIMx_DMAR_ADDR(x) (TIMx_BASEADDR(x) + GPT_TIM_DMAR_OFFSET_ADDR32)
#define TIMx_OR_ADDR(x)  (TIMx_BASEADDR(x) + GPT_TIM_OR_OFFSET_ADDR32)

#endif /* SOURCE_BSW_GPT_CORE_GPT_REGTYPES_H_ */
