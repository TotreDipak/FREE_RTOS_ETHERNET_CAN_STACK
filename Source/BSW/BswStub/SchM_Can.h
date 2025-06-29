/**
*   @file    SchM_Can.h
*   @version 1.0.2
*
*   @brief   AUTOSAR Rte - module interface
*   @details This file contains the functions prototypes and data types of the AUTOSAR Rte.
*            This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup RTE_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.2
*   Build Version        : S32K14xS32K14X_MCAL_1_0_2_RTM_ASR_REL_4_2_REV_0002_20190426
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2019 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef SCHM_CAN_H
#define SCHM_CAN_H

#ifdef __cplusplus
extern "C" {
#endif
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef MCAL_TESTING_ENVIRONMENT
/** 
@brief   This function checks that all entered exclusive areas were also exited. 
@details This function checks that all entered exclusive areas were also exited. The check
         is done by verifying that all reentry_guard_* static variables are back to the
         zero value.
    
@param[in]     void       No input parameters
@return        void       This function does not return a value. Test asserts are used instead. 

@pre  None
@post None

@remarks Covers 
@remarks Implements 
*/
FUNC(void, RTE_CODE) SchM_Check_can(void);
#endif /*MCAL_TESTING_ENVIRONMENT*/

extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_00(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_01(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_02(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_03(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_04(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_05(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_06(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_07(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_08(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_09(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_10(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_11(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_12(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_13(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_14(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_15(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_16(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_17(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_18(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_19(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_20(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_21(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_22(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_23(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_24(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_25(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_26(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_27(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_28(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_29(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_30(void);

extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_00(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_01(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_02(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_03(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_04(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_05(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_06(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_07(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_08(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_09(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_10(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_11(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_12(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_13(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_14(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_15(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_16(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_17(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_18(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_19(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_20(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_21(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_22(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_23(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_24(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_25(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_26(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_27(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_28(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_29(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_30(void);


#ifdef __cplusplus
}
#endif

#endif /* SCHM_CAN_H */

/** @} */
