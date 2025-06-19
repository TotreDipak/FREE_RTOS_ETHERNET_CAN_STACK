#include "Port.h"
#include"StdRegMacros.h"

static P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) Port_ConfigPtr = NULL_PTR;

static Port_DriverStatusType Port_DriverStatus = PORT_S_UNINITIALIZED;

static FUNC(void, PORT_CODE) Port_InitArch(P2CONST(Port_ConfigType, AUTOMATIC,PORT_APPL_CONST )PortConfigPtr);

static FUNC(void, PORT_CODE) Port_InitArch(P2CONST(Port_ConfigType, AUTOMATIC,PORT_APPL_CONST )PortConfigPtr)
{
	uint8 idx;
	Port_PinModeType Testval;
	for(idx= 0U; idx < PortConfigPtr->u8NumPins; idx++)
	{

		if(PortConfigPtr->PadConfig[idx].unPinAvbl == TRUE)
		{
			//Testval = PortConfigPtr->PadConfig[idx].unMODER;
			REG_RMW32(GPIO_OSPEEDR_ADDR32(PortConfigPtr->PadConfig[idx].unGpioID), GPIO_OSPEEDR_Mask(PortConfigPtr->PadConfig[idx].unPin), \
								GPIO_OSPEEDR_VAL(PortConfigPtr->PadConfig[idx].unPin, PortConfigPtr->PadConfig[idx].unOSPEEDR));
			REG_RMW32(GPIO_OTYPER_ADDR32(PortConfigPtr->PadConfig[idx].unGpioID), GPIO_OTYPER_MASK(PortConfigPtr->PadConfig[idx].unPin), \
					GPIO_OTYPER_VAL(PortConfigPtr->PadConfig[idx].unPin, PortConfigPtr->PadConfig[idx].unOTYPER));
			REG_RMW32(GPIO_PUPDR_ADDR32(PortConfigPtr->PadConfig[idx].unGpioID), GPIO_PUPDR_MASK(PortConfigPtr->PadConfig[idx].unPin), \
					GPIO_PUPDR_VAL(PortConfigPtr->PadConfig[idx].unPin, PortConfigPtr->PadConfig[idx].unPUPDR));
			REG_RMW32(GPIO_LCKR_ADDR32(PortConfigPtr->PadConfig[idx].unGpioID), GPIO_LCKR_MASK(PortConfigPtr->PadConfig[idx].unPin), \
					GPIO_LCKR_VAL(PortConfigPtr->PadConfig[idx].unPin, PortConfigPtr->PadConfig[idx].unLCKR));
			REG_RMW32(GPIO_AFRL_ADDR32(PortConfigPtr->PadConfig[idx].unGpioID), GPIO_AFRL_MASK(PortConfigPtr->PadConfig[idx].unPin), \
					GPIO_AFRL_VAL(PortConfigPtr->PadConfig[idx].unPin, PortConfigPtr->PadConfig[idx].unAFRL));
			REG_RMW32(GPIO_AFRH_ADDR32(PortConfigPtr->PadConfig[idx].unGpioID), GPIO_AFRH_MASK(PortConfigPtr->PadConfig[idx].unPin), \
					GPIO_AFRH_VAL(PortConfigPtr->PadConfig[idx].unPin, PortConfigPtr->PadConfig[idx].unAFRH));
			REG_RMW32(GPIO_MODER_ADDR32(PortConfigPtr->PadConfig[idx].unGpioID), GPIO_MODER_MASK(PortConfigPtr->PadConfig[idx].unPin), \
					GPIO_MODER_VAL(PortConfigPtr->PadConfig[idx].unPin, PortConfigPtr->PadConfig[idx].unMODER));
		}
		else
		{
			/*REG_RMW32(GPIO_MODER_ADDR32(PortConfigPtr->PadConfig[idx].unGpioID), GPIO_MODER_MASK(PortConfigPtr->PadConfig[idx].unPin), \
					GPIO_MODER_VAL(PortConfigPtr->PadConfig[idx].unPin, PortConfigPtr->PadConfig[idx].unMODER));
			REG_RMW32(GPIO_OTYPER_ADDR32(PortConfigPtr->PadConfig[idx].unGpioID), GPIO_OTYPER_MASK(PortConfigPtr->PadConfig[idx].unPin),\
					GPIO_OTYPER_VAL(PortConfigPtr->PadConfig[idx].unPin,  PortConfigPtr->PadConfig[idx].unOTYPER));
			REG_RMW32(GPIO_PUPDR_ADDR32(PortConfigPtr->PadConfig[idx].unGpioID), GPIO_PUPDR_MASK(PortConfigPtr->PadConfig[idx].unPin), \
					GPIO_PUPDR_VAL(PortConfigPtr->PadConfig[idx].unPin, PortConfigPtr->PadConfig[idx].unPUPDR));*/
		}
	}
}

FUNC(void, PORT_CODE) Port_Init(P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) ConfigPtr)
{

	if(NULL_PTR == ConfigPtr)
	{
		Port_ConfigPtr	= Port_Config;
	}
	else
	{

	}

	Port_InitArch(Port_ConfigPtr);

	Port_DriverStatus = PORT_S_INITIALIZED;
	return;
}

