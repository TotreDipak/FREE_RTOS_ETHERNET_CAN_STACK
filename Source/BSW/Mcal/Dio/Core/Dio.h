/*
 * Dio.h
 *
 *  Created on: Jul 26, 2024
 *      Author: AshsihP
 */

#ifndef DIO_H
#define DIO_H

#include"Compiler.h"
#include"Compiler_Cfg.h"
#include"Dio_Cfg.h"

FUNC(Dio_LevelType, DIO_CODE) Dio_ReadChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
);

FUNC(void, DIO_CODE) Dio_WriteChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId,
    CONST(Dio_LevelType,   AUTOMATIC) Level
);


FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadPort
(
    CONST(Dio_PortType, AUTOMATIC) PortId
);

FUNC(void, DIO_CODE) Dio_WritePort
(
    CONST(Dio_PortType,      AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level
);

FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadChannelGroup
(
  P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr
);

FUNC(void, DIO_CODE) Dio_WriteChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr,
    CONST  (Dio_PortLevelType,    AUTOMATIC)                 Level
);


#endif /* SOURCE_BSW_DIO_CORE_DIO_H_ */
