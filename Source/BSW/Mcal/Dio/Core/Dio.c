/**
 *   @file    Dio.c
 *   @implements        Dio_HLD_unit
 *   @version 1.0.2
 *
 *   @brief   AUTOSAR Dio high level code.
 *   @details This file contains the Autosar DIO driver high level code.
 *
 *   @addtogroup DIO_MODULE
 *   @{
 */

#ifdef __cplusplus
extern "C"{
#endif


#include "Dio.h"
#include "Dio_Internal.h"
#include "Port_RegTypes.h"
#include "StdRegMacros.h"

/** @violates @ref Dio_C_REF_5 This warning appears when defining functions or objects that will be used by the upper layers. */
FUNC(Dio_LevelType, DIO_CODE) Dio_ReadChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
)
{
    boolean ReturnVal= DIO_LOW;
	 VAR(uint16, AUTOMATIC)  PortVal = 0U;
	    VAR(uint16, AUTOMATIC)  ChVal = 0U;
	    VAR(uint32, AUTOMATIC)  IDRValue = 0U;
	    VAR(uint32, AUTOMATIC)  Temp = 0U;
	    PortVal = ((ChannelId & 0xF0) >> 4);
	    ChVal   = (ChannelId & 0x0F);

	    IDRValue = REG_READ32(GPIO_IDR_ADDR32(PortVal));
	    Temp = GPIO_IDR_MASK(ChVal);
	    if ((IDRValue & Temp) != 0U)
	    {
	    	ReturnVal = DIO_HIGH;
	    }
return (ReturnVal);
}

/*================================================================================================*/
/**
* @brief          Sets the level of a channel.
* @details        If the specified channel is configured as an output channel,
*                 this function shall set the specified level on the
*                 specified channel. If the specified channel is configured
*                 as an input channel, this function shall have no influence
*                 on the physical output and on the result of the next read
*                 service.
*
* @param[in]      ChannelId   Specifies the required channel id.
* @param[in]      Level       Specifies the channel desired level.
*
* @implements     Dio_WriteChannel_Activity
*
* @api
*/
/** @violates @ref Dio_C_REF_5 This warning appears when defining functions or objects that will be used by the upper layers. */
FUNC(void, DIO_CODE) Dio_WriteChannel
(
    CONST(Dio_ChannelType,  AUTOMATIC) ChannelId,
    CONST(Dio_LevelType,    AUTOMATIC) Level
)
{
	uint8 PortVal ;
	uint8 ChVal ;

	PortVal = ((ChannelId & 0xF0)>>4);

	ChVal = (ChannelId & 0x0F);

	if(Level == DIO_HIGH)
	{
		REG_RMW32(GPIO_BSRR_ADDR32(PortVal), GPIO_BSRR_MASK(ChVal),GPIO_BSRR_SET(ChVal,BIT_HIGH ));
	}
	else
	{
		if(Level == DIO_LOW)
		{
			REG_RMW32(GPIO_BSRR_ADDR32(PortVal), GPIO_BSRR_MASK(ChVal),GPIO_BSRR_RESET(ChVal,BIT_HIGH));
		}
	}
}


#ifdef __cplusplus
}
#endif

/** @} */
