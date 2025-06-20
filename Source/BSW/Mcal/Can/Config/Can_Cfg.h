/**
*   @file    Can_Cfg.h
*   @version 1.0.2
*
*   @brief   AUTOSAR Can - module interface
*   @details Configuration settings generated by user settings.
*
*   @addtogroup CAN_DRIVER
*   @{
*/


#ifndef CAN_CFG_H
#define CAN_CFG_H

#include "Can_Internal.h"


#ifdef __cplusplus
extern "C"{
#endif

/* @violates @ref Can_Cfg_h_REF_1 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h*/
#include "Std_Types.h"
#include "Can.h"


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @brief          Can FD mode support.
* @details        This parameter is used to indicate that which controller supports FD mode.
*/
#define CAN_FD_CONTROLLER_SUPPORTED ((uint32)0x00000001)

/**
* @brief          Support for User Mode feature.
* @details        This parameter is enabled only in order to support the write access to some registers are protected in user mode.
*/
#define CAN_MAXMBCOUNT_PB        5U
#define CAN_ENABLE_USER_MODE_SUPPORT (STD_OFF)
/**
* @brief          Support Interrupt for  derivatives which support UNIFIED_INTERRUPTS.
* @details        This parameter is enabled only for derivatives which support UNIFIED_INTERRUPTS.
*/
#define CAN_UNIFIED_INTERRUPTS (STD_OFF)
/**
* @brief          Support for Wakeup feature.
* @details        This parameter is enabled only for platforms which have wakeup were suppoted. This platform isn't supported Wakeup.
*/
#define CAN_ENABLE_WAKEUP_SUPPORT (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == CAN_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Can in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif /* (STD_ON == CAN_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */ 


/**
* @brief          Implicit index value used by Full can hardware objects.
* @details        Implicit index value used by Full can hardware objects.
*
*/
/* @violates @ref Can_Cfg_h_REF_3 Violates MISRA 2004 Required Rule 19.4, source code mentenability. */
#define CAN_MAXMASKCOUNT    (Can_HwHandleType)65535U

/**
* @brief          Can Controllers. Defines for conversion between object names and object IDs.
* @details        Can Controllers. Defines for conversion between object names and object IDs.
(PR-MCAL-2944)Numeric ID's in configuration and definition of symbolic names in Can_Cfg.h file
*
*/

#define CanConf_CanController_CanController_0 ((uint8)0U)

/**
* @brief          Can Hardware Objects.
* @details        Can Hardware Objects.
(PR-MCAL-2944)Numeric ID's in configuration and definition of symbolic names in Can_Cfg.h file.
*
*/


/*
* @brief          Symbolic names for CanObjectId
* @details        Symbolic names for CanObjectId maintained for compatibility with old testcases/applications 
*
*/
#define CanHardwareObject_0  0U /* RECEIVE object of Can Controller ID = 0 */
#define CanHardwareObject_1  1U /* RECEIVE object of Can Controller ID = 0 */
#define CanHardwareObject_2  2U /* RECEIVE object of Can Controller ID = 0 */
#define CanHardwareObject_3  3U /* TRANSMIT object of Can Controller ID = 0 */
#define CanHardwareObject_4  4U /* TRANSMIT object of Can Controller ID = 0 */
#define CanHardwareObject_5  5U /* TRANSMIT object of Can Controller ID = 0 */

/*
* @brief          Lpdu callout name
* @details        (CAN357_Conf) CanLPduReceiveCalloutFunction - This parameter sets the name of the LPDU callout.
*
*/

#define CAN_LPDU_NOTIFICATION_ENABLE  (STD_OFF)
#define BXCAN_OFFSET    ((uint8)0U)
#define CAN_NULL_OFFSET              ((uint8)0xFFU)
/*
* @brief          Extended identifiers.
* @details        Extended identifiers.
- (STD_ON)  - if at least one extended identifier is used.
- (STD_OFF) - if no extended identifiers are used at all
If no extended identifiers are used then the IDs and MASKs can be stored in uint16 rather than uint32.
*
*/
#define CAN_EXTENDEDID (STD_OFF)

#define CAN_SET_BAUDRATE_API (STD_OFF)

/*
* @brief          Switches the Can_ChangeBaudrate API and Can_CheckBaudRate API ON or OFF.
* @details        (CAN460) Configuration of Can_CheckBaudrate(Controller, Baudrate): If Can supports changing of the
baudrate and thus this service, shall be configurable via CAN_CHANGE_BAUDRATE_SUPPORT
*
*/
#define CAN_CHANGE_BAUDRATE_API (STD_OFF)

/*
* @brief          Switches the Development Error Detection and Notification ON or OFF.
* @details        (CAN028) Call the Development Error Tracer when DET is switched on and the Can module detects an error.
(CAN082) The detection of development errors is configurable (ON / OFF) at pre- compile time.
The switch CanDevErrorDetection (see chapter 10) shall activate or deactivate the detection of all development errors.
*
*/
#define CAN_DEV_ERROR_DETECT (STD_ON)

/*
* @brief          CAN driver support for multiple INTERRUPTs.
* @details        CAN driver support for multiple INTERRUPTs.
*
*/
#define CAN_MULTIPLE_INTERRUPTS_SUPPORT (STD_OFF)

/*
* @brief          Extended number of can hardware objects
* @details        Extended number of can hardware objects:
- STD_ON if more than 256 can hardware objects are needed (up to 65536)
- STD_OFF if no more than 256 can hardware objects are needed
The specification only allows up to 256 can hardware objects. The driver supports a non-standard extension of this limit.
@violates @ref Can_Cfg_h_REF_3 Violates MISRA 2004 Required Rule 19.4, source code mentenability.
*
*/
#define CAN_MBCOUNTEXTENSION (STD_ON)

/*
* @brief          Support for version info API
* @details        Switches the Can_GetVersionInfo() API ON or OFF.
*
*/
#define CAN_VERSION_INFO_API (STD_ON)

/*
* @brief          Support for Multiplexed Transmision
* @details        MB set for Tx is put on bus from any TxMB that is available (free).
*                 (CAN277) The Can module shall allow that the functionality Multiplexed Transmission is statically configurable (ON | OFF) at pre-compile time.
*
*/
#define CAN_MULTIPLEXED_TRANSMISSION (STD_OFF)

/*
* @brief          Support for Transmision Cancellation
* @details        Support for Transmision Cancellation
*                 (CAN278) The Can module shall allow that the functionality Transmit Cancellation is statically configurable (ON | OFF) at pre-compile time.
*
*/
#define CAN_HW_TRANSMIT_CANCELLATION (STD_OFF)

/*
* @brief          Support for Identical Id Cancellation
* @details        Enables/disables cancellation of pending PDUs with identical ID.
*
*/

/*
* @brief          Support for Special MB Abort API
* @details        Enable an additional API, to write an ABORT code (b1001) to the MBCB filed of the MB to abort a message transmission.
*
*/
#define CAN_API_ENABLE_ABORT_MB (STD_ON)

/*
* @brief          Support for MB Abort  API
* @details         This parameter is enabled only if CanMultiplexedTransmission=STD_ON and aborts only one message buffer
*/
#define CAN_ABORT_ONLY_ONE_MB (STD_ON)

/*
* @brief          Instance # of the driver - used for Det_ReportError().
* @details        Instance # of the driver - used for Det_ReportError().
*
*/
#define CAN_INSTANCE 0U

/*
* @brief          The define in order to check the trigger transmit feature is enabled or disabled.
* @details        The define in order to check the trigger transmit feature is enabled or disabled.
*
*/

#define CAN_TRIGGER_TRANSMIT_EN (STD_OFF)

/*
* @brief          Platform support mix of controllers with 64 and 32 MBs.
* @details        Platform support mix of controllers with 64 and 32 MBs.
*
*/
#define CAN_MIX_MB_SUPPORT (STD_OFF)

/*
* @brief          Platform support for detection and correction of memory errors
* @details        Platform support for detection and correction of memory errors
*
*/
#define CAN_MEMORY_ECC_SUPPORT (STD_OFF)


/*
* @brief          Disable errata e10368 in some derivative
* @details        In some derivative, it is not impacted by errata e10368. This define is for removing workaround when using these derivative.
*
*/

#define CAN_E10368_INCONSISTENT (STD_OFF)


/*
* @brief          Platform support for Pretended Networking
* @details        Platform support for Pretended Networking
*
*/
/*
* @brief          Maximum number of Message Buffers configured.
* @details        Maximum number of Message Buffers configured.
*
*/
#define CAN_MAXMBCOUNT_0 6U


/*
* @brief          Maximum possible Message Buffers per controller specific to this platform.
* @details        Maximum possible Message Buffers per controller specific to this platform.
*
*/
#define CAN_MAXMB_SUPPORTED 32U

/*
* @brief          Maximum number of Message Buffers configured.
* @details        Maximum number of Message Buffers configured.
*
*/
#define CAN_MAXMB_CONFIGURED 32U

/*
* @brief          Maximum possible controllers per specific derivative.
* @details        Maximum possible controllers per specific derivative.
*
*/
#define CAN_MAXCTRL_SUPPORTED 1U

/**
* @brief          Maximum No. of supported controllers (vary according to Processor Family).
* @details        Maximum No. of supported controllers (vary according to Processor Family).
*
*/
#define CAN_MAXCONTROLLERCOUNT 1U

/*
* @brief          Maximum No. of controllers Configured
* @details      Maximum No. of controllers Configured
*
*/
#define CAN_MAXCTRL_CONFIGURED 1U

/**
* @brief          Hardware events detected by an INTERRUPT or by POLLING
* @details        (CAN099) The hardware events may be detected by an INTERRUPT or by POLLING status flags of the hardware objects.
*                 The configuration possibilities regarding POLLING is hardware dependent (i.e. which events can be polled, which events need to be polled), and not restricted by this standard.
*                 (CAN007)It shall be possible to configure the driver such that no INTERRUPTs at all are used (complete POLLING).
*
*/
/**
* @brief          This macros enable INTERRUPTs for controllers if Tx processing is set to INTERRUPT Mode.
* @details        This macros enable INTERRUPTs for controllers if Tx processing is set to INTERRUPT Mode.
*
*/
#define CAN_A_TXINT_SUPPORTED   (STD_OFF)

/*
* @brief          This macro enables Can_MainFunction_Write() if at least one controller is set to process Tx in POLLING Mode.
* @details        This macro enables Can_MainFunction_Write() if at least one controller is set to process Tx in POLLING Mode.
*
*/
#define CAN_TXPOLL_SUPPORTED (STD_OFF)

/*
* @brief          This macro is used to check spurius interrupt if at least one controller is set to process Tx in INTERRUPT Mode.
* @details        This macro is used to check spurius interrupt if at least one controller is set to process Tx in INTERRUPT Mode.
*
*/
#define CAN_TXINT_SUPPORTED (STD_OFF)
/**
* @brief          This macros enable INTERRUPTs for controllers if Rx processing is set to INTERRUPT Mode.
* @details        This macros enable INTERRUPTs for controllers if Rx processing is set to INTERRUPT Mode.
*
*/
#define CAN_A_RXINT_SUPPORTED   (STD_OFF)

/*
* @brief          This macro enables Can_MainFunction_Read() if at least one controller is set to process Rx in POLLING Mode.
* @details        This macro enables Can_MainFunction_Read() if at least one controller is set to process Rx in POLLING Mode.
*
*/
#define CAN_RXPOLL_SUPPORTED (STD_OFF)

/*
* @brief          This macro is used to check spurius interrupt if at least one controller is set to process Rx in INTERRUPT Mode.
* @details        This macro is used to check spurius interrupt if at least one controller is set to process Rx in INTERRUPT Mode.
*
*/
#define CAN_RXINT_SUPPORTED (STD_ON)
/*
* @brief          This macro enables Can_ProcessTx() and Can_ProcessRx() if at least one controller is set to process TX/Rx in INTERRUPT Mode.
* @details        This macro enables Can_ProcessTx() and Can_ProcessRx() if at least one controller is set to process TX/Rx in INTERRUPT Mode.
*
*/
#define CAN_TX_RX_INTR_SUPPORTED    (STD_ON)

/**
* @brief          This macros enable INTERRUPTs for controllers if BusOff processing is set to INTERRUPT Mode.
* @details        This macros enable INTERRUPTs for controllers if BusOff processing is set to INTERRUPT Mode.
*
*/
#define CAN_A_BUSOFFINT_SUPPORTED   (STD_OFF)

/*
* @brief          This macro enables Can_MainFunction_BusOff() if at least one controller is set to process BusOff in POLLING Mode.
* @details        This macro enables Can_MainFunction_BusOff() if at least one controller is set to process BusOff in POLLING Mode.
*
*/
#define CAN_BUSOFFPOLL_SUPPORTED (STD_ON)

/*
* @brief          Maximum number of MB Filters configured.
* @details        Maximum number of MB Filters configured.
*
*/

/*
Note: Elektrobit Automotive GmbH modified the original code provided
by the third party supplier. The modification is provided for
convenience.
Please use the modification on your discretion and account, or
use the unmodified files provided with this distribution. 
Please see for the reasons in the file ImportantNotes.txt for tag

* ASCFREESCL-1214 CanHwFilter sub-container implementation deviates from ASR standard
* original Can_Cfg.h file is present in MCAL_Delivery\Origin_files\Can_TS_T40D2M10I2R0\generate_PC\include folder
*/

#define CAN_MAXFILTERCOUNT_0 2U
/**
* @brief          Maximum number of baudrate configured.
* @details        Maximum number of baudrate configured.
*                 Controller Baudrates configured are in kbps
*
*/
#define CAN_CFGSET0_BAUDRATE_FC_A_0     500U
#define CAN_CFGSET0_MAX_BAUDRATE_FC_A_0    1U

/* CAN FD INIT*/

#define BXCAN_BTR_ENABLE (STD_ON)

#define CAN_CONTROLLER_FD_ISO_CANFD (STD_ON)

#define CAN_CONTROLLER_FD_PREXCEN (STD_ON)

#define CAN_CONTROLLER_FD_EDFLTDIS (STD_ON)

/*
* @brief          Maximum number of Filters configured for RxFifo.
* @details        Maximum number of Filters configured for RxFifo.
*
*/
#define CAN_RXFILTER_CONFIG 3U
#define CAN_CONTROLLER_0                0
#define CAN_MAX_CONTROLLERS             1
#define CAN_MAXTFILTER 2U
/*
* @brief          Support for Rx Fifo
* @details        Support for Rx Fifo - If at least one controller supports RxFifo, then this define is set to STD_ON.
*                 This define is global for the entire hardware unit (all controllers). Every controller has particular
*                 configuration for Rx Fifo (see Can_ControllerConfigType structure).
*
*/
#define CAN_RXFIFO_ENABLE (STD_ON)

/*
* @brief          Set if Rx Fifo events (Warning/Overflow/FrameAvailable) are configured on the same int on INTC vector table.
* @details        Set if Rx Fifo events (Warning/Overflow/FrameAvailable) are configured on the same int on INTC vector table.
*                 Based on this define separate INTERRUPTs handlers or not will be used for the 3 events of the RxFifo.
*
*/
#define CAN_RXFIFO_EVENT_UNIFIED (STD_ON)

/*
* @brief          Error notification enabled/disabled.
* @details        Enables/Disables the Error Controller Notification. Used for INTERRUPTs mapping in Can_Irq.c file.
*
*/
#define CAN_ERROR_NOTIFICATION_ENABLE (STD_ON)

/*
* @brief          Index into the configuration structures.
* @details        Index into the configuration structures.Indexes used for accessing the 'Can_ControlerDescriptorType' structure.
*                 NOTE that index order from hardware (where CAN_A has always index 0, ..)
*                 may not be the same with the order from the 'Can_ControlerDescriptorType' structure (where user can define controllers in any order).
*                 Count also the number of controllers that have INTERRUPTs enabled.
*
*/
#define CAN_FCA_INDEX       ((uint8)0U)

/*
* @brief          Index into the hardware platform.
* @details        Index into the hardware platform.Indexes used for accessing the 'Can_ControlerDescriptorType' structure.
*
*/
#define BXCAN_A_OFFSET    ((uint8)0U)

/*
* @brief          RxFifo Functionality enabled/disabled. Used for INTERRUPTs mapping in Can_Irq.c file.
* @details        RxFifo Functionality enabled/disabled. Used for INTERRUPTs mapping in Can_Irq.c file.
*
*/
#define CAN_A_FIFO_EN (STD_ON)

/*
* @brief          Error notification enabled/disabled.
* @details        Enables/Disables the Error Controller Notification. Used for INTERRUPTs mapping in Can_Irq.c file.
*
*/
#define CAN_A_ERROR_NOTIFICATION_ENABLE (STD_ON)


/*
* @brief          Optimization of INTERRUPT service code for size.
* @details        Optimization of INTERRUPT service code for size.
*
*/
#define CAN_ISROPTCODESIZE (STD_OFF)

/*
* @brief          Enable Non-Autosar API for Dual-Clock support.
* @details        Enable Non-Autosar API for Dual-Clock support.
*                 This can be set to STD_ON only if it is activated from Resource file (Can.CanConfig.DualClockMode = STD_ON)
*
*/
#define CAN_DUAL_CLOCK_MODE (STD_OFF)

/*
* @brief          Enable Non-Autosar API for Dual-Clock support.
* @details        Enable Non-Autosar API for Dual-Clock support.
*                 This can be set to STD_ON only if it is activated from Resource file (Can.CanConfig.DualClockMode = STD_ON)
*
*/
#define  CAN_CLKSRC_CONFIG_MASK_U32 (0x00002000U)

/* This macro is only defined if it is activated from Resource file (Can.CanConfig.DualClockMode = STD_ON) */
#define CAN_FLEXCAN_CLKSRC_AVAIABLE


/*
* @brief          Specifies the maximum time for blocking function until a timeout is detected (implement as loop cycles).
* @details        The Can module shall use the free running timer provided by the system service for timeout detection in case the hardware does not react
*                  in the expected time (hardware malfunction) to prevent endless loops.
*
*/
#if defined(ERR_IPV_FLEXCAN_0008)
    #if (ERR_IPV_FLEXCAN_0008 == STD_ON)
        #define CAN_TIMEOUT_DURATION 50000U
    #else
        #error: The define ERR_IPV_FLEXCAN_0008 should not be STD_OFF
    #endif
#else
    #define CAN_TIMEOUT_DURATION 5000U
#endif /* ERR_IPV_FLEXCAN_0008 */
/*
* @brief          Define timeout as loop
* @details        Define that timeout implemented as loop cycle
*
*/
    #define CAN_TIMEOUT_AS_LOOP   (STD_ON)

/*
* @brief          Precompile Support.
* @details        (CAN220)VARIANT-PRE-COMPILE: Only pre-compile configuration parameters
*
*/
#define CAN_PRECOMPILE_SUPPORT (STD_ON)



/*
* @brief          Periods for cyclic call of Main function
* @details        (CAN355_Conf) CanMainFunctionBusoffPeriod - This parameter describes the period for cyclic call to Can_MainFunction_Busoff. Unit is seconds.
*
*/
#define CAN_MAINFUNCTION_PERIOD_BUSOFF (0U)


#define CAN_PUBLIC_ICOM_SUPPORT  (STD_OFF)

/*
* @brief          Periods for cyclic call of Main function
* @details        (ECUC_Can_00484) This parameter describes the period for cyclic call to Can_MainFunction_Read or Can_MainFunction_Write depending on the referring item. Unit is seconds. 
*                 Different poll-cycles will be configurable if more than one CanMainFunctionPeriod is configured. 
*                 In this case multiple Can_MainFunction_Read() or Can_MainFunction_Write() will be provided by the CAN Driver module..
*
*/
#define CAN_MAINFUNCTION_PERIOD         (0.01F)

/*
* @brief          Periods for cyclic call of Main function Mode
* @details        (CAN376_Conf) This parameter describes the period for cyclic call to Can_MainFunction_Mode. Unit is seconds.
*
*/
#define CAN_MAINFUNCTION_MODE_PERIOD 0U

/*
* @brief    Defines if Backwards Compatibility Configuration (BCC) feature of CAN controller is used in the configuration.
*           If BCC feature of CAN controller is enabled, Individual Rx masking and queue feature are disabled.
*           If BCC feature of CAN controller is disabled, Individual Rx masking and queue feature are enabled.
*/
#define CAN_BCC_SUPPORT_ENABLE (STD_OFF)

/*
@brief    Macro used to define the maximum of Can object IDs configured  .
*/
#define CAN_MAX_OBJECT_ID ((uint32)6U)

#define CAN_CONTROLLER_REFERENCE_COUNTER 1

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* @violates @ref Can_Cfg_h_REF_3 Violates MISRA 2004 Required Rule 19.4, source code mentenability. */
#define CAN_MB_CONTROLLER_1     32U

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* _CAN_CFG_H_ */

/** @} */
