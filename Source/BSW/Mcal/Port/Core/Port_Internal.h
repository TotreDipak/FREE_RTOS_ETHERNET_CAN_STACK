
#ifndef PORT_INTERNAL_H
#define PORT_INTERNAL_H

#include "Std_Types.h"
#include "Port_RegTypes.h"
#include "StdRegMacros.h"


typedef enum
{
	PORT_S_ILLEGAL,
	PORT_S_UNINITIALIZED,
	PORT_S_INITIALIZED
}Port_DriverStatusType;

typedef enum
{
	GPIO_A,
	GPIO_B,
	GPIO_C,
	GPIO_D,
	GPIO_E,
	GPIO_F,
	GPIO_G,
	GPIO_H,
	GPIO_I,
	GPIO_J,
	GPIO_K
} Port_PinGpioID;

typedef enum
{
	PORT_PIN_MODE_INPUT,
	PORT_PIN_MODE_OUTPUT,
	PORT_PIN_MODE_ALTERNATE_FUNCTION,
	PORT_PIN_MODE_ANALOG,
} Port_PinModeType;

typedef enum
{
	PORT_PIN_OTYPE_PUSH_PULL,
	PORT_PIN_OTYPE_OPEN_DRAIN
} Port_PinOutputType;

typedef enum
{
	GPIO_SPEED_FREQ_LOW,
	GPIO_SPEED_FREQ_MEDIUM,
	GPIO_SPEED_FREQ_HIGH,
	GPIO_SPEED_FREQ_VERY_HIGH

}Port_PinSpeed;

typedef enum
{
	NO_PULLUP_NOPULLDOWN,
	PULLUP,
	PULLUPDOWN,
	RESERVED_0
} Port_PinPullType;


typedef enum
{
	PORT_PIN_CFG_NOT_LOCKED,
	PORT_PIN_CFG_LOCKED
}Port_PinLockRegister;


typedef enum
{
	PORT_PIN_SET,
	PORT_PIN_RESET
}Port_PinSetReset;

typedef enum
{
	AF0_Selection = 0x00000000,
	AF9_Selection= 0x09,
	AF11_Selection=0x0B

}Port_PinAFR_Selection;


typedef struct
{

	VAR(uint8,                 AUTOMATIC)   unPin;        /**< @brief Pin Defined on PORT */
	VAR(boolean,        	   AUTOMATIC)   unPinAvbl;    /**< @brief Pin Defined on PORT */
	VAR(Port_PinGpioID,        AUTOMATIC)   unGpioID;     /**< @brief Pin Defined on PORT */
	VAR(Port_PinModeType,      AUTOMATIC)   unMODER;      /**< @brief MODER Register */
	VAR(Port_PinOutputType,    AUTOMATIC)   unOTYPER;     /**< @brief OTYPER Register */
	VAR(Port_PinSpeed,   	   AUTOMATIC)   unOSPEEDR;     /**< @brief OTYPER Register */
	VAR(Port_PinPullType,      AUTOMATIC)   unPUPDR;      /**< @brief PUPDR Register */
	VAR(Port_PinLockRegister,  AUTOMATIC)   unLCKR;       /**< @brief LCKR Register*/
	VAR(Port_PinAFR_Selection, AUTOMATIC)   unAFRL;       /**< @brief AFRL Register*/
	VAR(Port_PinAFR_Selection, AUTOMATIC)   unAFRH;       /**< @brief AFRH Register*/

} Port_Port_Ci_PinConfigType;




#endif












