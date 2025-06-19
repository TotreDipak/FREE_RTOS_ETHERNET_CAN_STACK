/*
 * Gpt_Cfg.h
 *
 *  Created on: Jul 31, 2024
 *      Author: AshsihP
 */

#include "Gpt_Internal.h"

#ifndef GPT_CFG_H_
#define GPT_CFG_H_

typedef const Gpt_ConfigType *Gpt_ConfigPtrType;

typedef struct
{
	uint8 u8NumTimer;                        /**< @brief Number of used Timer */
	Gpt_ConfigPtrType TimerConfig;           /**< @brief timer configuration */
} GPT_TimerConfigType;


extern CONST(GPT_TimerConfigType,GPT_CONST)  Gpt_Config[1];


#endif /* SOURCE_BSW_GPT_CONFIG_GPT_CFG_H_ */
