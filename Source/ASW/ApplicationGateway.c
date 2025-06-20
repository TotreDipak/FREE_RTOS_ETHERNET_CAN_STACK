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
*   Project              :CAN and Ethernet Gateway
*   Platform             : ARM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : NA
*   Autosar Revision     :
*   Autosar Conf.Variant :
*   SW Version           : 1.0.0
*   Build Version        : STM32F407G
*
*   (c) Copyright 2025-2026 Dipak Totre
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
#include "ApplicationGateway.h"
#include"Dio.h"
#include "Can.h"
static void Actuator_DoorOpenCloseIndicatorLed(void);
static void Actuator_TurnIndicatorLed(void);
static void Actuator_WindowLifterActuator(void);
static void Actuator_DoorLockIndicatorLed(void);
static void Actuator_SeatBeltIndicatorLed(void);
static void SendCanDataOnBus(void);
static void PackCanDataBus(uint8 *Data);
static boolean Led_Blink(uint8 LedTime);
/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/
typedef enum {
   DCU_TURN_INDI_OFF = 0,
   DCU_TURN_INDI_LEFT = 1,
   DCU_TURN_INDI_RIGHT = 2,
   DCU_TURN_INDI_LEFT_RIGHT = 3
  }TurnIndSt;

  typedef enum {
     DCU_WL_CMD_UNKNOWN = 0,
	 DCU_WL_CMD_OFF = 1,
	 DCU_WL_CMD_UP = 2,
	 DCU_WL_CMD_DN = 3
    }WlSt;


    typedef enum {
       DCU_TURN_INDI_ACT_OFF = 0,
       DCU_TURN_INDI_ACT_LEFT = 1,
       DCU_TURN_INDI_ACT_RIGHT = 2,
	   DCU_TURN_INDI_ACT_LIFT_RIGHT = 3
      }TurnIndActSt;

#define DCU_TURNINDI_ON           (1U)
#define DCU_TURNINDI_OFF          (0U)

#define DCU_WL_ON                 (1U)
#define DCU_WL_OFF                (0U)

#define DCU_DOOR_CHILDLOCK_ST_LOCK           (1U)
#define DCU_DOOR_CHILDLOCK_ST_UNLOCK         (0U)
#define DCU_LOCK_CMD_LOCK           (1U)
#define DCU_LOCK_CMD_UNLOCK         (0U)

#define SEAT_BELT_ON_SPEED_LIMIT        (40U)
#define LOCK_ON_SPEED_LIMIT             (20U)

#define DCU_CHILDLOCK_CMD_LOCK           (1U)
#define DCU_CHILDLOCK_CMD_UNLOCK         (0U)
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

uint8 SduData[8]={ 0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55};

Can_PduType message = {
		&SduData,
		0x501,
		0x00,
		0x08
};

Can_PduType message1 = {
		&SduData,
		0x502,
		0x01,
		0x08
};

void Gateway_10ms_Task(void)
{
  Actuator_DoorOpenCloseIndicatorLed();
  Actuator_TurnIndicatorLed();
  Actuator_WindowLifterActuator();
  Actuator_DoorLockIndicatorLed();
  Actuator_SeatBeltIndicatorLed();
}

void Gateway_100ms_Task(void)
{
  SendCanDataOnBus();
}
static void Actuator_DoorOpenCloseIndicatorLed(void)
{
	Dio_LevelType LDoorStatus = FALSE;

	Rte_Read_R_Door_Contact_Sensor(&LDoorStatus);

	Dio_WriteChannel(GATEWAY_DO_CH_DOOR_STATUS, (Dio_LevelType)LDoorStatus);

}

static void Actuator_TurnIndicatorLed(void)
{
	TurnIndSt LTurn_Indi = DCU_TURN_INDI_OFF;
	TurnIndActSt TunIndiActStatus = DCU_TURN_INDI_ACT_OFF;
	boolean TurnInicator_Left = DCU_TURNINDI_OFF;
	boolean TurnInicator_Right = DCU_TURNINDI_OFF;

	Rte_Read_R_Turn_Indicator_Input_Sensor(&LTurn_Indi);
	  if (LTurn_Indi == DCU_TURN_INDI_OFF)
	  {
	    TurnInicator_Left = DCU_TURNINDI_OFF;
	    TurnInicator_Right = DCU_TURNINDI_OFF;
	    TunIndiActStatus = DCU_TURN_INDI_ACT_OFF;

	  }
	  else if (LTurn_Indi == DCU_TURN_INDI_RIGHT)
	  {
		TurnInicator_Right = Led_Blink(20);
	    TurnInicator_Left = DCU_TURNINDI_OFF;
	    TunIndiActStatus = DCU_TURN_INDI_ACT_RIGHT;
	  }
	  else if (LTurn_Indi == DCU_TURN_INDI_LEFT)
	  {
	     TurnInicator_Left = Led_Blink(20);
	     TurnInicator_Right = DCU_TURNINDI_OFF;
	     TunIndiActStatus = DCU_TURN_INDI_ACT_LEFT;
	  }
	  else
	  {
	    TunIndiActStatus = DCU_TURN_INDI_ACT_OFF;
	    /*Do Nothing*/
	  }
	  Rte_Write_Turn_Indicator_State_CAN_Data(TunIndiActStatus);
	  Dio_WriteChannel(GATEWAY_DO_CH_TURN_IND_LEFT, (Dio_LevelType)TurnInicator_Left);
	  Dio_WriteChannel(GATEWAY_DO_CH_TURN_IND_RIGHT, (Dio_LevelType)TurnInicator_Right);
}


static void Actuator_WindowLifterActuator(void)
{
	WlSt LWindowCmd = DCU_WL_CMD_UNKNOWN;
	boolean Wl_Up = DCU_WL_CMD_UNKNOWN;
	boolean Wl_Down = DCU_WL_CMD_UNKNOWN;

	Rte_Read_R_Window_Lifter_Control_Input(&LWindowCmd);
	  if ((LWindowCmd == DCU_WL_CMD_UNKNOWN) ||(LWindowCmd == DCU_WL_CMD_OFF))
	  {
		  Wl_Up = DCU_WL_OFF;
		  Wl_Down = DCU_WL_OFF;
	  }
	  else if (LWindowCmd == DCU_WL_CMD_UP)
	  {
		  Wl_Up = DCU_WL_ON;
		  Wl_Down = DCU_WL_OFF;
	  }
	  else if (LWindowCmd == DCU_WL_CMD_DN)
	  {
		  Wl_Up = DCU_WL_OFF;
		  Wl_Down = DCU_WL_ON;
	  }
	  else
	  {
	    /*Do Nothing*/
	  }
	  Dio_WriteChannel(GATEWAY_DO_WL_UP, (Dio_LevelType)Wl_Up);
	  Dio_WriteChannel(GATEWAY_DO_WL_DOWN, (Dio_LevelType)Wl_Down);
}
static void Actuator_DoorLockIndicatorLed(void)
{
	  uint8 ChildLockSt = 0;
	 uint8 DLCmd = 0;
	 uint8 LCarSpeed = 0;
	 static Dio_LevelType DoorOpenLockUnlock = DCU_LOCK_CMD_UNLOCK;
	 Rte_Read_R_Wireless_Key_ButtonLock_Unlock(&DLCmd);
	 Rte_Read_R_Child_Lock_Button(&ChildLockSt);
	 Rte_Read_R_Car_Speed_data(&LCarSpeed);
      if (ChildLockSt == DCU_DOOR_CHILDLOCK_ST_UNLOCK)
      {
        if (LCarSpeed > LOCK_ON_SPEED_LIMIT)
        {
          DoorOpenLockUnlock = DCU_LOCK_CMD_LOCK;
        }
        else if (DLCmd == DCU_CHILDLOCK_CMD_LOCK)
        {
          DoorOpenLockUnlock = DCU_LOCK_CMD_LOCK; 
        }
        else
        {
          DoorOpenLockUnlock = DCU_LOCK_CMD_UNLOCK;
        }     
      }
      else 
      {
    	  /*Do Nothing*/
      }
	  Dio_WriteChannel(GATEWAY_DO_CH_LOCK_STATUS, (Dio_LevelType)DoorOpenLockUnlock);
}
static void Actuator_SeatBeltIndicatorLed(void)
{
	Dio_LevelType LSeatBltStatus = FALSE;
	Rte_Read_R_Seat_Belt_Status(&LSeatBltStatus);
	Dio_WriteChannel(GATEWAY_DO_CH_SEAT_BELT_STATUS, (Dio_LevelType)LSeatBltStatus);
}

static void SendCanDataOnBus(void)
{

	PackCanDataBus(SduData);
	Can_Write(0x02,&message);
}

static void PackCanDataBus(uint8 *Data)
{
	Dio_LevelType LDoorStatus = FALSE;
	Dio_LevelType LSeatBltStatus = FALSE;
	TurnIndActSt TunIndiActStatus = DCU_TURN_INDI_ACT_OFF;
	Rte_Read_R_Door_Contact_Sensor(&LDoorStatus);
	Rte_Read_R_Seat_Belt_Status(&LSeatBltStatus);
	Rte_Read_R_Turn_Indicator_State(&TunIndiActStatus);
	Data[0] = LDoorStatus;
	Data[1] = LSeatBltStatus;
	Data[2] = TunIndiActStatus;

}

static boolean Led_Blink(uint8 LedTime)
{

static uint16 LedToggleTime = 20;
static boolean LedToggleSt = DCU_TURNINDI_ON;


if (LedToggleSt == DCU_TURNINDI_ON)
{
	if(LedToggleTime == 0)
	{
	  LedToggleSt = DCU_TURNINDI_OFF;
	  LedToggleTime = LedTime;
	}
}
else
{
	if(LedToggleTime == 0)
	{
	  LedToggleSt = DCU_TURNINDI_ON;
	  LedToggleTime = LedTime;
	}
}
if(LedToggleTime > 0)
{
	LedToggleTime--;
}

return LedToggleSt;
}

/** @} */
