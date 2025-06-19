/*
 * Dio_Cfg.h
 *
 *  Created on: Jul 26, 2024
 *      Author: AshsihP
 */

#ifndef DIO_CFG_H
#define DIO_CFG_H

#include"Dio_Internal.h"


typedef const Dio_PinConfigType *Dio_PinConfigPtrType;

typedef struct
{
	uint8 u8NumPins;                                   /**< @brief Number of used pads (to be configured) */
	Dio_PinConfigPtrType DioPadConfig;               /**< @brief Pad configuration */
} Dio_ConfigType;

/* PortVal GPIOA=0, GPIOB=1,GPIOC=2
 * Cal--> DioChannelId = PortVal*32 + PinVal
 *
 * */
#define  DioConf_DioChannel_DioChannel_D12 	((uint16)0x003CU)
#define  DioConf_DioChannel_DioChannel_D13 	((uint16)0x003DU)
#define  DioConf_DioChannel_DioChannel_D14 	((uint16)0x003EU)
#define  DioConf_DioChannel_DioChannel_D15 	((uint16)0x003FU)


#endif /* DIO_CFG_H */
