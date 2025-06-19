#ifndef PORT_CFG_H
#define PORT_CFG_H

#include "Port_Internal.h"

#define PORT_MAX_CONFIGURED_PADS_U16			(uint8)0x50;


typedef const Port_Port_Ci_PinConfigType *Port_Port_Ci_PinConfigPtrType;

typedef struct
{
	uint8 u8NumPins;                                   /**< @brief Number of used pads (to be configured) */
	Port_Port_Ci_PinConfigPtrType PadConfig;               /**< @brief Pad configuration */
} Port_ConfigType;


extern CONST(Port_ConfigType, PORT_CONST)  Port_Config[1];

#endif /* PORT_CFG_H */
