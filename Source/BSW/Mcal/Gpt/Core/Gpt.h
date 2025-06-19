/*
 * Gpt.h
 *
 *  Created on: Jul 31, 2024
 *      Author: AshsihP
 */

#ifndef GPT_H_
#define GPT_H_

#include "Gpt_Cfg.h"
#include "stm32f407xx.h"


typedef uint8 Gpt_ChannelType;

typedef uint32 Gpt_ValueType;


extern FUNC(void, GPT_CODE)Gpt_Init (P2CONST(GPT_TimerConfigType, AUTOMATIC, GPT_APPL_CONST) ConfigPtr);

extern FUNC(void, GPT_CODE)Gpt_StartTimer(VAR(Gpt_ChannelType, AUTOMATIC) channel,VAR(Gpt_ValueType, AUTOMATIC) value);
extern FUNC(void, GPT_CODE)Gpt_StopTimer(VAR(Gpt_ChannelType, AUTOMATIC) channel);
extern FUNC(void, GPT_CODE)Gpt_EnableNotification(VAR(Gpt_ChannelType, AUTOMATIC) channel);
extern FUNC(void, GPT_CODE)Gpt_DisbleNotification(VAR(Gpt_ChannelType, AUTOMATIC) channel);



#endif /* SOURCE_BSW_GPT_CORE_GPT_H_ */
