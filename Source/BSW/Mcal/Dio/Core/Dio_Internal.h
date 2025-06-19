/*
 * Dio_Internal.h
 *
 *  Created on: Jul 26, 2024
 *      Author: AshsihP
 */

#ifndef DIO_INTERNAL_H
#define DIO_INTERNAL_H

#include "Std_Types.h"
#include "Port_RegTypes.h"
#include "StdRegMacros.h"


#define BIT_HIGH	(uint8)0x01
#define BIT_LOW		(uint8)0x00
#define DIO_HIGH	(uint8)0x01
#define DIO_LOW		(uint8)0x00

typedef uint8 Dio_LevelType;

typedef uint32 Dio_PortLevelType;

typedef uint8 Dio_PortType;


typedef uint16 Dio_ChannelType;
/**
* @brief          Type of a DIO channel group representation.
*
* @implements     Dio_ChannelGroupType_struct
*
* @api
*/
typedef struct
{
    VAR(Dio_PortType, AUTOMATIC)      port;      /**< @brief Port identifier.  */
    VAR(uint8, AUTOMATIC)             u8offset;    /**< @brief Bit offset within the port. */
    VAR(Dio_PortLevelType, AUTOMATIC) mask;      /**< @brief Group mask. */
} Dio_ChannelGroupType;


typedef enum
{
	GPIO_DIO_A,
	GPIO_DIO_B,
	GPIO_DIO_C,
	GPIO_DIO_D,
	GPIO_DIO_E,
	GPIO_DIO_F,
	GPIO_DIO_G,
	GPIO_DIO_H,
	GPIO_DIO_I,
	GPIO_DIO_J,
	GPIO_DIO_K
} Dio_PinGpioID;

typedef struct
{

	VAR(uint8,                 AUTOMATIC)   unPin;        /**< @brief Pin Defined on PORT */
	VAR(Dio_PinGpioID,        AUTOMATIC)   unGpioID;     /**< @brief Pin Defined on PORT */
} Dio_PinConfigType;

#endif /* SOURCE_BSW_DIO_CORE_DIO_INTERNAL_H_ */
