/**
*   @file    ApplicationGateway
*   @version 1.0.0
*
*   @brief
*   @details
*
*
*   @addtogroup
*   @{
*/
/*==================================================================================================
*   Project              : CAN and Ethernet Gateway
*   Platform             : ARM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : NA
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.0
*   Build Version        : STM32F407G
*
*   (c) (c) Copyright 2005-2026 Dipak Totre
*
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/




/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "SignalProcessorType.h"
#include "Std_Types.h"
#include "Platform_Types.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
extern uint8 Rte_CtInput_Door_Contact_SensorData;
extern uint8 Rte_CtInput_Seat_Belt_Status;
extern uint8 Rte_CtInput_Child_Lock_Button;
extern uint8 Rte_CtInput_Wireless_Key_ButtonLock_Unlock;
extern uint8 Rte_CtInput_Turn_Indicator_Input_Sensor;
extern uint8 Rte_CtInput_Window_Lifter_Control_Input;
extern uint8 Rte_CtInput_Ignition_Information;
extern uint8 Rte_CtInput_Car_Speed_data;
extern uint8 Rte_CtInput_Turn_Indicator_State;

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define DIO_PORTID_PD5     (53U)
#define DIO_PORTID_PD6     (54U)
#define GATEWAY_DI_SEAT_BELT            DIO_PORTID_PD5
#define GATEWAY_DI_DOOR_CONTACT         DIO_PORTID_PD6

#  define Rte_Read_R_Door_Contact_Sensor Rte_Read_Door_Contact_Sensor_DIO_Read
#  define Rte_Read_Door_Contact_Sensor_DIO_Read(data) (*(data) = Rte_CtInput_Door_Contact_SensorData, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Door_Contact_Sensor_DioData Rte_Write_Door_Contact_Sensor_Data
#  define Rte_Write_Door_Contact_Sensor_Data(data) (Rte_CtInput_Door_Contact_SensorData = (data), ((Std_ReturnType)RTE_E_OK))

#  define Rte_Read_R_Seat_Belt_Status Rte_Read_Seat_Belt_Status_DIO_Read
#  define Rte_Read_Seat_Belt_Status_DIO_Read(data) (*(data) = Rte_CtInput_Seat_Belt_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Belt_Status_DioData Rte_Write_Seat_Belt_Status_Data
#  define Rte_Write_Seat_Belt_Status_Data(data) (Rte_CtInput_Seat_Belt_Status = (data), ((Std_ReturnType)RTE_E_OK))


#  define Rte_Read_R_Child_Lock_Button Rte_Read_Child_Lock_Button_CAN_Read
#  define Rte_Read_Child_Lock_Button_CAN_Read(data) (*(data) = Rte_CtInput_Child_Lock_Button, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Child_Lock_Button_CAN_Data Rte_Write_Child_Lock_Button_CAN_Data_port
#  define Rte_Write_Child_Lock_Button_CAN_Data_port(data) (Rte_CtInput_Child_Lock_Button = (data), ((Std_ReturnType)RTE_E_OK))

#  define Rte_Read_R_Wireless_Key_ButtonLock_Unlock Rte_Read_Key_ButtonLock_Unlock_CAN_Read
#  define Rte_Read_Key_ButtonLock_Unlock_CAN_Read(data) (*(data) = Rte_CtInput_Wireless_Key_ButtonLock_Unlock, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Wireless_Key_ButtonLock_UnlockCAN_Data Rte_Write_Key_ButtonLock_Unlock_CAN_Data
#  define Rte_Write_Key_ButtonLock_Unlock_CAN_Data(data) (Rte_CtInput_Wireless_Key_ButtonLock_Unlock = (data), ((Std_ReturnType)RTE_E_OK))


#  define Rte_Read_R_Turn_Indicator_Input_Sensor Rte_Read_Turn_Indicator_Input_Sensor_CAN_Read
#  define Rte_Read_Turn_Indicator_Input_Sensor_CAN_Read(data) (*(data) = Rte_CtInput_Turn_Indicator_Input_Sensor, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Turn_Indicator_Input_Sensor_CAN_Data Rte_Write_Turn_Indicator_Input_Sensor_Data
#  define Rte_Write_Turn_Indicator_Input_Sensor_Data(data) (Rte_CtInput_Turn_Indicator_Input_Sensor = (data), ((Std_ReturnType)RTE_E_OK))


#  define Rte_Read_R_Window_Lifter_Control_Input Rte_Read_Window_Lifter_Control_Input_CAN_Read
#  define Rte_Read_Window_Lifter_Control_Input_CAN_Read(data) (*(data) = Rte_CtInput_Window_Lifter_Control_Input, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Window_Lifter_Control_Input_CAN_Data Rte_Write_Window_Lifter_Control_Input_Data
#  define Rte_Write_Window_Lifter_Control_Input_Data(data) (Rte_CtInput_Window_Lifter_Control_Input = (data), ((Std_ReturnType)RTE_E_OK))


#  define Rte_Read_R_Ignition_Information Rte_Read_Ignition_Information_CAN_Read
#  define Rte_Read_Ignition_Information_CAN_Read(data) (*(data) = Rte_CtInput_Ignition_Information, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Ignition_Information_CAN_Data Rte_Write_Ignition_Information_Data
#  define Rte_Write_Ignition_Information_Data(data) (Rte_CtInput_Ignition_Information = (data), ((Std_ReturnType)RTE_E_OK))

#  define Rte_Read_R_Car_Speed_data Rte_Read_Car_Speed_data_CAN_Read
#  define Rte_Read_Car_Speed_data_CAN_Read(data) (*(data) = Rte_CtInput_Car_Speed_data, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Car_Speed_CAN_Data Rte_Write_Car_Speed_data_Data
#  define Rte_Write_Car_Speed_data_Data(data) (Rte_CtInput_Car_Speed_data = (data), ((Std_ReturnType)RTE_E_OK))


#  define Rte_Read_R_Turn_Indicator_State Rte_Read_Turn_Indicator_State_CAN_Read
#  define Rte_Read_Turn_Indicator_State_CAN_Read(data) (*(data) = Rte_CtInput_Turn_Indicator_State, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Turn_Indicator_State_CAN_Data Rte_Write_Turn_Indicator_State_Data
#  define Rte_Write_Turn_Indicator_State_Data(data) (Rte_CtInput_Turn_Indicator_State = (data), ((Std_ReturnType)RTE_E_OK))

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

#if 0
typedef enum {
   DCU_WL_UNDEFINED = 0,
   DCU_WL_AUTO_UP = 1,
   DCU_WL_AUTO_DOWN = 2,
   DCU_WL_STOP =3
  }WlSwitchSt;

typedef enum {
   DCU_WL_MODE_STOP = 0,
   DCU_WL_MODE_RUN = 1,
   DCU_WL_MODE_PINCH = 2,
   DCU_WL_MODE_CHILD_LOCK = 3
  }WlMode;

typedef enum {
   DCU_WL_ACT_UNDEFINED = 0,
   DCU_WL_ACT_AUTO_UP = 1,
   DCU_WL_ACT_AUTO_DOWN = 2,
   DCU_WL_ACT_PINCH = 3,
   DCU_WL_ACT_STOP = 4
  }WlActSt;
typedef enum {
   DCU_TURN_INDI_ACT_UNKNOWN = 0,
   DCU_TURN_INDI_ACT_OFF = 1,
   DCU_TURN_INDI_ACT_LEFT = 2,
   DCU_TURN_INDI_ACT_RIGHT = 3
  }TurnIndActSt;

typedef enum {
   DCU_TURN_INDI_UNKNOWN = 0,
   DCU_TURN_INDI_OFF = 1,
   DCU_TURN_INDI_LEFT = 2,
   DCU_TURN_INDI_RIGHT = 3
  }TurnIndSt;

typedef enum {
   DCU_WL_POSION_UNKNOWN = 0,
   DCU_WL_POSION_CLOSE = 1,
   DCU_WL_POSION_OPEN = 2
  }WlSensSt;

typedef enum {
   DCU_MIR_UNKNOWN = 0,
   DCU_MIR_FOLD = 1,
   DCU_MIR_UNFOLD = 2,
   DCU_MIR_IDLE = 3
  }MirFoldSt;

typedef enum {
   DCU_ST_BELT_W_UNKNOWN = 0,
   DCU_ST_BELT_W_ON = 1,
   DCU_ST_BELT_W_OFF = 2
  }StBeltSt;

typedef enum {
   DCU_LOCK_ST_UNKNOWN = 0,
   DCU_LOCK_ST_LOCK = 1,
   DCU_LOCK_ST_UNLOCK = 2
  }LkActSt;

#endif
/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
extern void Input_Sensor_Data_Read(void);
extern void Signal_Process_5ms_Task(void);
#define CanIf_RxIndication(Hrh, CanId, CanDlc, CanSduPtr)                                           CanIf_RxIndicationAsr403((Hrh), (CanId), (CanDlc), (CanSduPtr))
/** @} */
