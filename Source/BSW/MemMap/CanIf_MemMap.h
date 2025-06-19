/**
*   @file           PduR_MemMap.h
*   @implements     MemMap.h_Artifact
*   @version 1.0.2
*
*   @brief   AUTOSAR Base - Memory mapping specification.
*   @details This document specifies mechanisms for the mapping of code and data to specific
*            memory sections via memory mapping file. For many ECUs and microcontroller platforms
*            it is of utmost necessity to be able to map code, variables and constants module
*            wise to specific memory sections.
*            This file contains sample code only. It is not part of the production code deliverables
*   @addtogroup BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : S32K14X
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

/**
* @brief Symbol used for checking correctness of the includes
*/
#define MEMMAP_ERROR
/**************************************************************************************************/
/********************************************* Linaro *********************************************/
/**************************************************************************************************/

/**************************************** CANIF *******************************/
#ifdef CANIF_START_SEC_CONFIG_DATA_8
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_CONFIG_DATA_8
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_CONFIG_DATA_16
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_CONFIG_DATA_16
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_CONFIG_DATA_32
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_CONFIG_DATA_32
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_CONST_BOOLEAN
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_CONST_BOOLEAN
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_CONST_8
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_CONST_8
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_CONST_8
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_CONST_8
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_CONST_16
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_CONST_16
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_CONST_16
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_CONST_16
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_CONST_32
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_CONST_32
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_CONST_32
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_CONST_32
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_CODE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_CODE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_CODE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_CODE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_RAMCODE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_RAMCODE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_RAMCODE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_RAMCODE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_CODE_AC
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_CODE_AC
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_CODE_AC
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_CODE_AC
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_CLEARED_8
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_CLEARED_8
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_CLEARED_8
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_CLEARED_8
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif


#ifdef CANIF_START_SEC_VAR_CLEARED_16
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_CLEARED_16
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_CLEARED_16
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_CLEARED_16
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_NO_INIT_8
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_NO_INIT_8
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif


#ifdef CANIF_START_SEC_VAR_NO_INIT_16
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_NO_INIT_16
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_NO_INIT_32
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_NO_INIT_32
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_INIT_8
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_INIT_8
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_INIT_8
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_INIT_8
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_INIT_16
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_INIT_16
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_INIT_16
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_INIT_16
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_INIT_32
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_INIT_32
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_INIT_32
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_INIT_32
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif


#ifdef CANIF_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Pwm_MemMap.h
    * @violates @ref Pwm_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

/**************************************************************************************************/
/****************************************** Report error ******************************************/
/**************************************************************************************************/
#ifdef MEMMAP_ERROR
    #error "MemMap.h, no valid memory mapping symbol defined."
#endif
