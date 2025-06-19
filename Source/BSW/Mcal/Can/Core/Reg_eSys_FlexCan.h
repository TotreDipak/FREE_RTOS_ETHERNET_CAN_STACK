/**
*   @file    Reg_eSys_FlexCan.h
*   @version 1.0.2
*
*   @brief   AUTOSAR Can - MPC560xB FlexCan Registers and Macros Definitions.
*   @details Header file for MPC560xB FlexCan Registers and Macros Definitions.
*
*   @addtogroup CAN_DRIVER
*   @{
*/


#ifndef REG_ESYS_BXCAN_H
#define REG_ESYS_BXCAN_H
#endif
#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "Reg_eSys.h"
#include"Can_Internal.h"
#include"stm32f407xx.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define REGION_LENGTH (512U)
#define ARBITRATION_FIELD (8U)

/* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/   
#define BXCAN_MB_OFFSET(mb) ((((&(Can_pCurrentConfig->MBConfigContainer))->pMessageBufferConfigsPtr) + (mb))->u16MBOffsetAddr)

/*******************************************************************************************************************************/

#define CAN_ID_STD                  (0x00000000U)  /*!< Standard Id */
#define CAN_ID_EXT                  (0x00000004U)  /*!< Extended Id */


#define CAN_RTR_DATA                (0x00000000U)  /*!< Data frame   */
#define CAN_RTR_REMOTE              (0x00000002U)  /*!< Remote frame */

#define     BXCAN_32BITS_NO   32
#define FLEXCAN_NULL_OFFSET_U8              ((uint8)0xFFU)

#define MCR_RESET        (0x00000000U)
#define MCR_INRQ_RESET        (0x00000000U)
#define TI0R_TXRQ_SET        (0x00000001U)



#define CAN_RX_FIFO0                (0x00000000U)  /*!< CAN receive FIFO 0 */
#define CAN_RX_FIFO1                (0x00000001U)  /*!< CAN receive FIFO 1 */


#define CAN_FILTER_SCALE_16BIT    0x00
#define CAN_FILTER_SCALE_32BIT    0x01

#define CAN_FILTER_MODE_IDMASK    0x00
#define CAN_FILTER_MODE_IDLIST    0x01

#define CAN_FILTER_FIFO0          0x00
#define CAN_FILTER_FIFO1          0x01

#define CAN_FILTER_ENABLE         0x01
#define CAN_FILTER_DISABLE        0x00


#define CAN_ERROR_NONE            (0x00000000U)  /*!< No error                                             */
#define CAN_ERROR_EWG             (0x00000001U)  /*!< Protocol Error Warning                               */
#define CAN_ERROR_EPV             (0x00000002U)  /*!< Error Passive                                        */
#define CAN_ERROR_BOF             (0x00000004U)  /*!< Bus-off error                                        */
#define CAN_ERROR_STF             (0x00000008U)  /*!< Stuff error                                          */
#define CAN_ERROR_FOR             (0x00000010U)  /*!< Form error                                           */
#define CAN_ERROR_ACK             (0x00000020U)  /*!< Acknowledgment error                                 */
#define CAN_ERROR_BR              (0x00000040U)  /*!< Bit recessive error                                  */
#define CAN_ERROR_BD              (0x00000080U)  /*!< Bit dominant error                                   */
#define CAN_ERROR_CRC             (0x00000100U)  /*!< CRC error                                            */
#define CAN_ERROR_RX_FOV0         (0x00000200U)  /*!< Rx FIFO0 overrun error                               */
#define CAN_ERROR_RX_FOV1         (0x00000400U)  /*!< Rx FIFO1 overrun error                               */
#define CAN_ERROR_TX_ALST0        (0x00000800U)  /*!< TxMailbox 0 transmit failure due to arbitration lost */
#define CAN_ERROR_TX_TERR0        (0x00001000U)  /*!< TxMailbox 0 transmit failure due to transmit error   */
#define CAN_ERROR_TX_ALST1        (0x00002000U)  /*!< TxMailbox 1 transmit failure due to arbitration lost */
#define CAN_ERROR_TX_TERR1        (0x00004000U)  /*!< TxMailbox 1 transmit failure due to transmit error   */
#define CAN_ERROR_TX_ALST2        (0x00008000U)  /*!< TxMailbox 2 transmit failure due to arbitration lost */
#define CAN_ERROR_TX_TERR2        (0x00010000U)  /*!< TxMailbox 2 transmit failure due to transmit error   */
#define CAN_ERROR_TIMEOUT         (0x00020000U)  /*!< Timeout error                                        */
#define CAN_ERROR_NOT_INITIALIZED (0x00040000U)  /*!< Peripheral not initialized                           */
#define CAN_ERROR_NOT_READY       (0x00080000U)  /*!< Peripheral not ready                                 */
#define CAN_ERROR_NOT_STARTED     (0x00100000U)  /*!< Peripheral not started                               */
#define CAN_ERROR_PARAM           (0x00200000U)  /*!< Parameter error

/*==================================================================================================
                BIT MASKS FOR MODULE CONFIGURATION REGISTER: MCR (Base+0x0000)
==================================================================================================*/
/**
* @brief MCR bit31: Module Disable (module disabled when 1)
*/
#define BXCAN_MCR_DBF_U32                           ((uint32)0x00010000U)
/**
* @brief MCR bit30: Freeze enable (enable to enter freeze mode when HALT is set)
*/

#define BXCAN_MCR_RESET_U32                         ((uint32)0x00008000U)
/**
* @brief MCR bit29: FIFO mode enable
*/

#define BXCAN_MCR_TTCM_U32                          ((uint32)0x00000080U)
/**
* @brief MCR bit28: Module Halt (module enters freeze mode when this bit is set providing the FRZ bit is set)
*/

#define BXCAN_MCR_ABOM_U32                          ((uint32)0x00000040U)
/**
* @brief MCR bit27: Module Not Ready (either disabled or in freeze mode)
*/

#define BXCAN_MCR_AWUM_U32                          ((uint32)0x00000020U)
/**
* @brief MCR bit26: Wake Up Interrupt Mask (1 = Wake Up Interrupt is enabled, 0 = Wake Up Interrupt is disabled)
*/

#define BXCAN_MCR_NART_U32                          ((uint32)0x00000010U)
/**
* @brief MCR bit25: Module Soft Reset (the bit remains set until reset is completed)
*/

#define BXCAN_MCR_RFLM_U32                          ((uint32)0x00000008U)
/**
* @brief MCR bit24: Freeze Mode Acknowledge
*/

#define BXCAN_MCR_TXFP_U32                    	    ((uint32)0x00000004U)


#define BXCAN_MCR_SLEEP_U32                         ((uint32)0x00000002U)
/**
* @brief MCR bit22: Self Wakeup from Doze or Stop modes
*/

#define BXCAN_MCR_INRQ_U32                          ((uint32)0x00000001U)



#define BXCAN_MSR_INAK_U32                          ((uint32)0x00000001U)

#define BXCAN_MSR_SLAK_U32                          ((uint32)0x00000002U)


#define BXCAN_FMR_FINIT_U32                         ((uint32)0x00000001U)

#define BXCAN_FMR_CAN2SB_U32                 	    ((uint32)0x00003F00U)


#define BXCAN_FM1R_FACT0_U32                        ((uint32)0x00000001U)


#define BXCAN_CAN_TSR_TME0_U32                      ((uint32)0x04000000U)

#define BXCAN_CAN_TSR_TME1_U32                      ((uint32)0x08000000U)

#define BXCAN_CAN_TSR_TME2_U32                      ((uint32)0x10000000U)

#define BXCAN_CAN_TSR_CODE_U32                      ((uint32)0x03000000U)

#define BXCAN_CAN_TSR_RQCP0_U32                      ((uint32)0x00000001U)

#define BXCAN_CAN_TSR_TXOK0_U32                      ((uint32)0x00000002U)

#define BXCAN_CAN_TSR_ALST0_U32                      ((uint32)0x00000004U)

#define BXCAN_CAN_TSR_TERRO_U32                      ((uint32)0x00000008U)

#define BXCAN_CAN_TSR_ABRQ0_U32                      ((uint32)0x00000080U)

#define BXCAN_CAN_TSR_RQCP1_U32                      ((uint32)0x00000100U)

#define BXCAN_CAN_TSR_TXOK1_U32                      ((uint32)0x00000200U)

#define BXCAN_CAN_TSR_ALST1_U32                      ((uint32)0x00000400U)

#define BXCAN_CAN_TSR_TERR1_U32                      ((uint32)0x00000800U)

#define BXCAN_CAN_TSR_ABRQ1_U32                      ((uint32)0x00008000U)

#define BXCAN_CAN_TSR_RQCP2_U32                      ((uint32)0x00010000U)

#define BXCAN_CAN_TSR_TXOK2_U32                      ((uint32)0x00020000U)

#define BXCAN_CAN_TSR_ALST2_U32                      ((uint32)0x00040000U)

#define BXCAN_CAN_TSR_TERR2_U32                      ((uint32)0x00080000U)




#define BXCAN_CAN_IER_TMEIE_U32                      ((uint32)0x00000001U)
#define BXCAN_CAN_IER_FMPIE0_U32                     ((uint32)0x00000002U)
#define BXCAN_CAN_IER_FFIE0_U32                      ((uint32)0x00000004U)
#define BXCAN_CAN_IER_FOVIE0_U32                     ((uint32)0x00000008U)
#define BXCAN_CAN_IER_FMPIE1_U32                     ((uint32)0x00000010U)
#define BXCAN_CAN_IER_FFIE1_U32                      ((uint32)0x00000020U)
#define BXCAN_CAN_IER_FOVIE1_U32                     ((uint32)0x00000040U)
#define BXCAN_CAN_IER_BOFIE_U32                      ((uint32)0x00000400U)
#define BXCAN_CAN_IER_SLKIE_U32                      ((uint32)0x00020000U)


#define BXCAN_CAN_TDT0R_TGT_U32                     ((uint32)0x00000100U)

#define BXCAN_CAN_TI0R_TXRQ_U32                     ((uint32)0x00000001U)

#define BXCAN_CAN_RF0R_FMP0_U32                      ((uint32)0x00000003U)
#define BXCAN_CAN_RF0R_FULL0_U32                     ((uint32)0x00000008U)
#define BXCAN_CAN_RF0R_FOVR0_U32                     ((uint32)0x00000010U)
#define BXCAN_CAN_RF0R_RFOM0_U32                     ((uint32)0x00000020U)



#define BXCAN_CAN_RF1R_FMP1_U32                      ((uint32)0x00000003U)
#define BXCAN_CAN_RF1R_FULL1_U32                     ((uint32)0x00000008U)
#define BXCAN_CAN_RF1R_FOVR1_U32                     ((uint32)0x00000010U)
#define BXCAN_CAN_RF1R_RFOM1_U32                     ((uint32)0x00000020U)


#define BXCAN_CAN_RI0R_IDE_U32                      ((uint32)0x00000004U)

#define BXCAN_CAN_RI0R_STID_U32                     ((uint32)0xFFE00000U)

#define BXCAN_CAN_RI0R_EXID_U32                     ((uint32)0x001FFFF8U)

#define BXCAN_CAN_RI0R_RTR_U32                      ((uint32)0x00000002U)

#define BXCAN_CAN_RDT0R_DLC_U32                     ((uint32)0x0000000FU)

#define BXCAN_CAN_RDT0R_FMI_U32                     ((uint32)0x0000FF00U)

#define BXCAN_CAN_RDT0R_TIME_U32                    ((uint32)0xFFFF0000U)



#define BXCAN_CAN_RDL0R_DATA0_U32                   ((uint32)0x000000FFU)
#define BXCAN_CAN_RDL0R_DATA1_U32                   ((uint32)0x0000FF00U)
#define BXCAN_CAN_RDL0R_DATA2_U32                   ((uint32)0x00FF0000U)
#define BXCAN_CAN_RDL0R_DATA3_U32                   ((uint32)0xFF000000U)
#define BXCAN_CAN_RDL0R_DATA4_U32                   ((uint32)0x000000FFU)
#define BXCAN_CAN_RDL0R_DATA5_U32                   ((uint32)0x0000FF00U)
#define BXCAN_CAN_RDL0R_DATA6_U32                   ((uint32)0x00FF0000U)
#define BXCAN_CAN_RDL0R_DATA7_U32                   ((uint32)0xFF000000U)


#define BXCAN_CAN_RF0R_RFOM0_U32                   ((uint32)0x00000020U)
#define BXCAN_CAN_RF1R_RFOM1_U32                   ((uint32)0x00000020U)




                          /*!<FIFO 0 Message Pending */




#define IS_CAN_MODE(MODE) (((MODE) == CAN_MODE_NORMAL) || \
                           ((MODE) == CAN_MODE_LOOPBACK)|| \
                           ((MODE) == CAN_MODE_SILENT) || \
                           ((MODE) == CAN_MODE_SILENT_LOOPBACK))
#define IS_CAN_SJW(SJW) (((SJW) == CAN_SJW_1TQ) || ((SJW) == CAN_SJW_2TQ) || \
                         ((SJW) == CAN_SJW_3TQ) || ((SJW) == CAN_SJW_4TQ))
#define IS_CAN_BS1(BS1) (((BS1) == CAN_BS1_1TQ) || ((BS1) == CAN_BS1_2TQ) || \
                         ((BS1) == CAN_BS1_3TQ) || ((BS1) == CAN_BS1_4TQ) || \
                         ((BS1) == CAN_BS1_5TQ) || ((BS1) == CAN_BS1_6TQ) || \
                         ((BS1) == CAN_BS1_7TQ) || ((BS1) == CAN_BS1_8TQ) || \
                         ((BS1) == CAN_BS1_9TQ) || ((BS1) == CAN_BS1_10TQ)|| \
                         ((BS1) == CAN_BS1_11TQ)|| ((BS1) == CAN_BS1_12TQ)|| \
                         ((BS1) == CAN_BS1_13TQ)|| ((BS1) == CAN_BS1_14TQ)|| \
                         ((BS1) == CAN_BS1_15TQ)|| ((BS1) == CAN_BS1_16TQ))
#define IS_CAN_BS2(BS2) (((BS2) == CAN_BS2_1TQ) || ((BS2) == CAN_BS2_2TQ) || \
                         ((BS2) == CAN_BS2_3TQ) || ((BS2) == CAN_BS2_4TQ) || \
                         ((BS2) == CAN_BS2_5TQ) || ((BS2) == CAN_BS2_6TQ) || \
                         ((BS2) == CAN_BS2_7TQ) || ((BS2) == CAN_BS2_8TQ))
#define IS_CAN_PRESCALER(PRESCALER) (((PRESCALER) >= 1U) && ((PRESCALER) <= 1024U))
#define IS_CAN_FILTER_ID_HALFWORD(HALFWORD) ((HALFWORD) <= 0xFFFFU)
#define IS_CAN_FILTER_BANK_DUAL(BANK) ((BANK) <= 27U)
#define IS_CAN_FILTER_BANK_SINGLE(BANK) ((BANK) <= 13U)
#define IS_CAN_FILTER_MODE(MODE) (((MODE) == CAN_FILTERMODE_IDMASK) || \
                                  ((MODE) == CAN_FILTERMODE_IDLIST))
#define IS_CAN_FILTER_SCALE(SCALE) (((SCALE) == CAN_FILTERSCALE_16BIT) || \
                                    ((SCALE) == CAN_FILTERSCALE_32BIT))
#define IS_CAN_FILTER_ACTIVATION(ACTIVATION) (((ACTIVATION) == CAN_FILTER_DISABLE) || \
                                              ((ACTIVATION) == CAN_FILTER_ENABLE))
#define IS_CAN_FILTER_FIFO(FIFO) (((FIFO) == CAN_FILTER_FIFO0) || \
                                  ((FIFO) == CAN_FILTER_FIFO1))
#define IS_CAN_TX_MAILBOX(TRANSMITMAILBOX) (((TRANSMITMAILBOX) == CAN_TX_MAILBOX0 ) || \
                                            ((TRANSMITMAILBOX) == CAN_TX_MAILBOX1 ) || \
                                            ((TRANSMITMAILBOX) == CAN_TX_MAILBOX2 ))
#define IS_CAN_TX_MAILBOX_LIST(TRANSMITMAILBOX) ((TRANSMITMAILBOX) <= (CAN_TX_MAILBOX0 | CAN_TX_MAILBOX1 | \
                                                                       CAN_TX_MAILBOX2))
#define IS_CAN_STDID(STDID)   ((STDID) <= 0x7FFU)
#define IS_CAN_EXTID(EXTID)   ((EXTID) <= 0x1FFFFFFFU)
#define IS_CAN_DLC(DLC)       ((DLC) <= 8U)
#define IS_CAN_IDTYPE(IDTYPE)  (((IDTYPE) == CAN_ID_STD) || \
                                ((IDTYPE) == CAN_ID_EXT))
#define IS_CAN_RTR(RTR) (((RTR) == CAN_RTR_DATA) || ((RTR) == CAN_RTR_REMOTE))
#define IS_CAN_RX_FIFO(FIFO) (((FIFO) == CAN_RX_FIFO0) || ((FIFO) == CAN_RX_FIFO1))
#define IS_CAN_IT(IT) ((IT) <= (CAN_IT_TX_MAILBOX_EMPTY     | CAN_IT_RX_FIFO0_MSG_PENDING      | \
                                CAN_IT_RX_FIFO0_FULL        | CAN_IT_RX_FIFO0_OVERRUN          | \
                                CAN_IT_RX_FIFO1_MSG_PENDING | CAN_IT_RX_FIFO1_FULL             | \
                                CAN_IT_RX_FIFO1_OVERRUN     | CAN_IT_WAKEUP                    | \
                                CAN_IT_SLEEP_ACK            | CAN_IT_ERROR_WARNING             | \
                                CAN_IT_ERROR_PASSIVE        | CAN_IT_BUSOFF                    | \
                                CAN_IT_LAST_ERROR_CODE      | CAN_IT_ERROR))




#define BXCAN_CTRL_SILM_U32                     ((uint32)0x80000000U)
/**
* @brief CTRL bit23-22: Resynchronization jump width (the width is field value plus 1 time quantum)
*/
#define BXCAN_CTRL_LBKM_U32                     ((uint32)0x40000000U)
/**
* @brief CTRL bit21-19: Phase segment 1 (length of the segment is field value plus 1 time quantum)
*/
#define BXCAN_CTRL_SJW_U32                      ((uint32)0x03000000U)
/**
* @brief CTRL bit18-16: Phase segment 2 (length of the segment is field value plus 1 time quantum)
*/
#define BXCAN_CTRL_TS2_U32                      ((uint32)0x00700000U)
/**
* @brief CTRL bit15: Bus Off Mask (bus off interrupt enabled when set)
*/
#define BXCAN_CTRL_TS1_U32                      ((uint32)0x000F0000U)
/**
* @brief CTRL bit14: Error Mask (error interrupt enabled when set)
*/
#define BXCAN_CTRL_BRP_U32                      ((uint32)0x000003FFU)





/**
* @brief Macro for Returning Base address of the controller.
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/


/**
* @brief Macro for Module Configuration (MCR) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/


#define  CAN_MCR_OFFSET_ADDR32         ((uint32)0x0000UL)


/**
* @brief Macro for Control Register (CTRL) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define  CAN_MSR_OFFSET_ADDR32          ((uint32)0x0004UL)


/**
* @brief Macro for Free Running Timer (TIMER) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define  CAN_TSR_OFFSET_ADDR32          ((uint32)0x0008UL)

/**
* @brief Macro for Rx Global Mask (RXGMASK) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define  CAN_RF0R_OFFSET_ADDR32          ((uint32)0x000CUL)


/**
* @brief Macro for Rx Buffer 14 Mask (RX14MASK) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define  CAN_RF1R_OFFSET_ADDR32          ((uint32)0x0010UL)


/**
* @brief Macro for Rx Buffer 15 Mask (RX15MASK) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define  CAN_IER_OFFSET_ADDR32          ((uint32)0x0014UL)


/**
* @brief Macro for Error Counter Register (ECR) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define  CAN_ESR_OFFSET_ADDR32          ((uint32)0x0018UL)


/**
* @brief Macro for Error and Status Register (ESR) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define  CAN_BTR_OFFSET_ADDR32          ((uint32)0x001CUL)



/**
* @brief Macro for Interrupt Masks 1 (IMASK1) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

/*CAN Mailbox Register
 *
 * TIxR
 * TDTxR
 * TDLxR
 * TDHxR     /// where x=1,2,3
 */

#define  CAN_TI0R_OFFSET_ADDR32           ((uint32)0x0180UL)
#define  CAN_TDT0R_OFFSET_ADDR32          ((uint32)0x0184UL)
#define  CAN_TDL0R_OFFSET_ADDR32          ((uint32)0x0188UL)
#define  CAN_TDH0R_OFFSET_ADDR32          ((uint32)0x018CUL)



#define  CAN_TI1R_OFFSET_ADDR32           ((uint32)0x0190UL)
#define  CAN_TDT1R_OFFSET_ADDR32          ((uint32)0x0194UL)
#define  CAN_TDL1R_OFFSET_ADDR32          ((uint32)0x0198UL)
#define  CAN_TDH1R_OFFSET_ADDR32          ((uint32)0x019CUL)



#define  CAN_TI2R_OFFSET_ADDR32          ((uint32)0x01A0UL)
#define  CAN_TDT2R_OFFSET_ADDR32          ((uint32)0x01A4UL)
#define  CAN_TDL2R_OFFSET_ADDR32          ((uint32)0x01A8UL)
#define  CAN_TDH2R_OFFSET_ADDR32          ((uint32)0x01ACUL)


/*CAN Mailbox Register
 *
 * RIxR
 * RITxR
 * RILxR
 * RIHxR     /// where x= 1 and 2
 */


#define  CAN_RI0R_OFFSET_ADDR32           ((uint32)0x01B0UL)
#define  CAN_RDT0R_OFFSET_ADDR32          ((uint32)0x01B4UL)
#define  CAN_RDL0R_OFFSET_ADDR32          ((uint32)0x01B8UL)
#define  CAN_RDH0R_OFFSET_ADDR32          ((uint32)0x01BCUL)



#define  CAN_RI1R_OFFSET_ADDR32           ((uint32)0x01C0UL)
#define  CAN_RDT1R_OFFSET_ADDR32          ((uint32)0x01C4UL)
#define  CAN_RDL1R_OFFSET_ADDR32         ((uint32)0x01C8UL)
#define  CAN_RDH1R_OFFSET_ADDR32          ((uint32)0x01CCUL)

/*CAN Filter Register
 *
 * FMR
 * FM1R
 * FS1R
 * FFA1R
 * FA1R
 * FxR1  where x = 1,2....27
 * FxR2  where x = 1,2....27
 */
#define  CAN_FMR_OFFSET_ADDR32           ((uint32)0x0200UL)
#define  CAN_FM1R_OFFSET_ADDR32          ((uint32)0x0204UL)
#define  CAN_FS1R_OFFSET_ADDR32          ((uint32)0x020CUL)
#define  CAN_FFA1R_OFFSET_ADDR32         ((uint32)0x0214UL)
#define  CAN_FA1R_OFFSET_ADDR32         ((uint32)0x021CUL)
#define  CAN_FR1_OFFSET_ADDR32         ((uint32)0x0240UL)
#define  CAN_FR2_OFFSET_ADDR32         ((uint32)0x0244UL)

#define CAN_MCR_ADDR32(x)               (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_MCR_OFFSET_ADDR32)
#define CAN_MSR_ADDR32(x)               (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_MSR_OFFSET_ADDR32)
#define CAN_TSR_ADDR32(x)               (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_TSR_OFFSET_ADDR32)
#define CAN_RF0R_ADDR32(x)              (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_RF0R_OFFSET_ADDR32)
#define CAN_RF1R_ADDR32(x)              (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_RF1R_OFFSET_ADDR32)
#define CAN_IER_ADDR32(x)               (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_IER_OFFSET_ADDR32)
#define CAN_ESR_ADDR32(x)               (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_ESR_OFFSET_ADDR32)
#define CAN_BTR_ADDR32(x)               (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_BTR_OFFSET_ADDR32)
#define CAN_TI0R_ADDR32(x)              (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_TI0R_OFFSET_ADDR32)
#define CAN_TD0R_ADDR32(x)              (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_TD0R_OFFSET_ADDR32)
#define CAN_TDT0R_ADDR32(x)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_TDT0R_OFFSET_ADDR32)
#define CAN_TDL0R_ADDR32(x)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_TDL0R_OFFSET_ADDR32)
#define CAN_TDH0R_ADDR32(x)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_TDH0R_OFFSET_ADDR32)
#define CAN_TD1R_ADDR32(x)              (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_TD1R_OFFSET_ADDR32)
#define CAN_TDT1R_ADDR32(x)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_TDT1R_OFFSET_ADDR32)
#define CAN_TDL1R_ADDR32(x)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_TDL1R_OFFSET_ADDR32)
#define CAN_TDH1R_ADDR32(x)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_TDH1R_OFFSET_ADDR32)
#define CAN_TD2R_ADDR32(x)              (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_TD2R_OFFSET_ADDR32)
#define CAN_TDT2R_ADDR32(x)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_TDT2R_OFFSET_ADDR32)
#define CAN_TDL2R_ADDR32(x)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_TDL2R_OFFSET_ADDR32)
#define CAN_TDH2R_ADDR32(x)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_TDH2R_OFFSET_ADDR32)
#define CAN_RI0R_ADDR32(x)              (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_RI0R_OFFSET_ADDR32)
#define CAN_RDT0R_ADDR32(x)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_RDT0R_OFFSET_ADDR32)
#define CAN_RDL0R_ADDR32(x)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_RDL0R_OFFSET_ADDR32)
#define CAN_RDH0R_ADDR32(x)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_RDH0R_OFFSET_ADDR32)
#define CAN_RI1R_ADDR32(x)              (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_RI1R_OFFSET_ADDR32)
#define CAN_RDT1R_ADDR32(x)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_RDT1R_OFFSET_ADDR32)
#define CAN_RDL1R_ADDR32(x)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_RDL1R_OFFSET_ADDR32)
#define CAN_RDH1R_ADDR32(x)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_RDH1R_OFFSET_ADDR32)
#define CAN_FMR_ADDR32(x)               (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_FMR_OFFSET_ADDR32)
#define CAN_FM1R_ADDR32(x)              (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_FM1R_OFFSET_ADDR32)
#define CAN_FS1R_ADDR32(x)              (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_FS1R_OFFSET_ADDR32)
#define CAN_FFA1R_ADDR32(x)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_FFA1R_OFFSET_ADDR32)
#define CAN_FA1R_ADDR32(x)              (CAN_BASE +((uint32)(x) * (uint32)0x0400) + CAN_FA1R_OFFSET_ADDR32)
#define CAN_FR1_ADDR32(x,y)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + (CAN_FR1_OFFSET_ADDR32+(uint32)(y) * (uint32)0x08))
#define CAN_FR2_ADDR32(x,y)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + (CAN_FR2_OFFSET_ADDR32+(uint32)(y) * (uint32)0x08))

#define CAN_TIXR_ADDR32(x,y)              (CAN_BASE +((uint32)(x) * (uint32)0x0400) + (CAN_TI0R_OFFSET_ADDR32+(uint32)(y) * (uint32)0x10))
#define CAN_TDXR_ADDR32(x,y)              (CAN_BASE +((uint32)(x) * (uint32)0x0400) + (CAN_TD0R_OFFSET_ADDR32+(uint32)(y) * (uint32)0x10))
#define CAN_TDTXR_ADDR32(x,y)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + (CAN_TDT0R_OFFSET_ADDR32+(uint32)(y) * (uint32)0x10))
#define CAN_TDLXR_ADDR32(x,y)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + (CAN_TDL0R_OFFSET_ADDR32+(uint32)(y) * (uint32)0x10))
#define CAN_TDHXR_ADDR32(x,y)             (CAN_BASE +((uint32)(x) * (uint32)0x0400) + (CAN_TDH0R_OFFSET_ADDR32+(uint32)(y) * (uint32)0x10))

/*MASk value*/
#define  CAN_TMEIE_MASK              ((uint32)0x00000001)
#define  CAN_FMPIE0_MASK             ((uint32)0x00000002)
#define  CAN_FFIE0_MASK              ((uint32)0x00000004)
#define  CAN_FOVIE0_MASK             ((uint32)0x00000008)
#define  CAN_FMPIE1_MASK             ((uint32)0x00000010)
#define  CAN_FFIE1_MASK              ((uint32)0x00000020)
#define  CAN_FOVIE1_MASK             ((uint32)0x00000040)
#define  CAN_WKUIE_MASK              ((uint32)0x00010000)
#define  CAN_BOFIE_MASK              ((uint32)0x00000400)
#define  CAN_ERRIE_MASK              ((uint32)0x00008000)

#define  CAN1_BTR_MASK                ((uint32)0xFFFFFFFF)
#define  CAN1_BRP_MASK                ((uint32)0x000003FF)
#define  CAN1_TS1_MASK                ((uint32)0x000F0000)
#define  CAN1_TS2_MASK                ((uint32)0x00700000)
#define  CAN1_SJW_MASK                ((uint32)0x03000000)
#define  CAN1_SILM_MASK               ((uint32)0x80000000)
#define  CAN1_LBKM_MASK               ((uint32)0x40000000)
#define  CAN1_BTR_RESET_MASK          ((uint32)0x00000000)

#define  CAN1_MCR_MASK                ((uint32)0xFFFFFFFF)

#define  CAN1_TTCM_MASK              ((uint32)0x00000080)
#define  CAN1_ABOM_MASK              ((uint32)0x00000040)
#define  CAN1_AWUM_MASK              ((uint32)0x00000020)
#define  CAN1_NART_MASK              ((uint32)0x00000010)
#define  CAN1_RFLM_MASK              ((uint32)0x00000008)
#define  CAN1_TXFP_MASK              ((uint32)0x00000004)

#define  CAN1_INRQ_MASK              ((uint32)0x00000001)
#define  CAN1_INAK_MASK              ((uint32)0x00000001)
#define  CAN1_SLEEP_MASK              ((uint32)0x00000002)
#define  CAN1_SLAK                   ((uint32)0x00000000)
#define  CAN1_SLEEP_SET             ((uint32)0x00000002)
#define  CAN1_INRQ_RESET            ((uint32)0x00000000)
#define  CAN1_SLEEP_RESET           ((uint32)0x00000000)
#define  CAN1_SLAK_MASK              ((uint32)0x00000002)
#define  CAN1_TXRQ_MASK              ((uint32)0x00000001)
#define  BxCAN_NOTRDY_U32            ((uint32)0x00000001)
#define  CAN_FMR_MASK                ((uint32)0xFFFFFFFF)
#define  CAN_FMR_FINITMASK           ((uint32)0x00000001)
#define  CAN_FMR_CAN2SBMASK           ((uint32)0x00003F00)
#define  CAN_FBM0_MASK                ((uint32)0x00000001)
#define  CAN_FBM1_MASK                ((uint32)0x00000002)
#define  CAN_FBM2_MASK                ((uint32)0x00000004)
#define  CAN_FSC0_MASK                ((uint32)0x00000001)
#define  CAN_FSC1_MASK                ((uint32)0x00000002)
#define  CAN_FSC2_MASK                ((uint32)0x00000004)
#define  CAN1_BOFF_MASK              ((uint32)0x00000004)
#define  CAN1_BOFF_RESET              ((uint32)0x00000000)
#define  CAN1_ESRBOF_MASK              ((uint32)0x00000004)
#define  CAN1_STDID_MASK              ((uint32)0xFFE00000)
#define  CAN_FRx_MASK                ((uint32)0xFFFFFFFF)


//Register value
#define  CAN_FSC0_32                ((uint32)0x00000001)
#define  CAN_FSC1_32                ((uint32)0x00000002)
#define  CAN_FSC2_32                ((uint32)0x00000004)

#define  CAN_FSC0_16                ((uint32)0x00000001)
#define  CAN_FSC1_16                ((uint32)0x00000002)
#define  CAN_FSC2_16                ((uint32)0x00000004)

#define  CAN_MASK_MODE               ((uint32)0x00000000)


#define CAN_BS1_1TQ                 (0x00000000U)                                                /*!< 1 time quantum  */
#define CAN_BS1_2TQ                 ((uint32)CAN_BTR_TS1_0)                                    /*!< 2 time quantum  */
#define CAN_BS1_3TQ                 ((uint32)CAN_BTR_TS1_1)                                    /*!< 3 time quantum  */
#define CAN_BS1_4TQ                 ((uint32)(CAN_BTR_TS1_1 | CAN_BTR_TS1_0))                  /*!< 4 time quantum  */
#define CAN_BS1_5TQ                 ((uint32)CAN_BTR_TS1_2)                                    /*!< 5 time quantum  */
#define CAN_BS1_6TQ                 ((uint32)(CAN_BTR_TS1_2 | CAN_BTR_TS1_0))                  /*!< 6 time quantum  */
#define CAN_BS1_7TQ                 ((uint32)(CAN_BTR_TS1_2 | CAN_BTR_TS1_1))                  /*!< 7 time quantum  */
#define CAN_BS1_8TQ                 ((uint32)(CAN_BTR_TS1_2 | CAN_BTR_TS1_1 | CAN_BTR_TS1_0))  /*!< 8 time quantum  */
#define CAN_BS1_9TQ                 ((uint32)CAN_BTR_TS1_3)                                    /*!< 9 time quantum  */
#define CAN_BS1_10TQ                ((uint32)(CAN_BTR_TS1_3 | CAN_BTR_TS1_0))                  /*!< 10 time quantum */
#define CAN_BS1_11TQ                ((uint32)(CAN_BTR_TS1_3 | CAN_BTR_TS1_1))                  /*!< 11 time quantum */
#define CAN_BS1_12TQ                ((uint32)(CAN_BTR_TS1_3 | CAN_BTR_TS1_1 | CAN_BTR_TS1_0))  /*!< 12 time quantum */
#define CAN_BS1_13TQ                ((uint32)(CAN_BTR_TS1_3 | CAN_BTR_TS1_2))                  /*!< 13 time quantum */
#define CAN_BS1_14TQ                ((uint32)(CAN_BTR_TS1_3 | CAN_BTR_TS1_2 | CAN_BTR_TS1_0))  /*!< 14 time quantum */
#define CAN_BS1_15TQ                ((uint32)(CAN_BTR_TS1_3 | CAN_BTR_TS1_2 | CAN_BTR_TS1_1))  /*!< 15 time quantum */
#define CAN_BS1_16TQ                ((uint32)CAN_BTR_TS1) /*!< 16 time quantum */
/**
  * @}
  */

/** @defgroup CAN_time_quantum_in_bit_segment_2 CAN Time Quantum in Bit Segment 2
  * @{
  */
#define CAN_BS2_1TQ                 (0x00000000U)                                /*!< 1 time quantum */
#define CAN_BS2_2TQ                 ((uint32)CAN_BTR_TS2_0)                    /*!< 2 time quantum */
#define CAN_BS2_3TQ                 ((uint32)CAN_BTR_TS2_1)                    /*!< 3 time quantum */
#define CAN_BS2_4TQ                 ((uint32)(CAN_BTR_TS2_1 | CAN_BTR_TS2_0))  /*!< 4 time quantum */
#define CAN_BS2_5TQ                 ((uint32)CAN_BTR_TS2_2)                    /*!< 5 time quantum */
#define CAN_BS2_6TQ                 ((uint32)(CAN_BTR_TS2_2 | CAN_BTR_TS2_0))  /*!< 6 time quantum */
#define CAN_BS2_7TQ                 ((uint32)(CAN_BTR_TS2_2 | CAN_BTR_TS2_1))  /*!< 7 time quantum */
#define CAN_BS2_8TQ                 ((uint32)CAN_BTR_TS2)                      /*!< 8 time quantum */




#define CAN_SJW_1TQ                 (0x00000000U)              /*!< 1 time quantum */
#define CAN_SJW_2TQ                 ((uint32)CAN_BTR_SJW_0)  /*!< 2 time quantum */
#define CAN_SJW_3TQ                 ((uint32)CAN_BTR_SJW_1)  /*!< 3 time quantum */
#define CAN_SJW_4TQ                 ((uint32)CAN_BTR_SJW)    /*!< 4 time quantum */




/*==================================================================================================
                CONTROLLER OPTIONS
==================================================================================================*/
/**
* @{
* @brief Controller options - set by the Tresos configuration
*/
#define CAN_CONTROLLERCONFIG_BUSOFFSWREC_U32    ((uint32)0x00000001U)
#define CAN_CONTROLLERCONFIG_RXFIFO_U32         ((uint32)0x00000002U)
#define CAN_CONTROLLERCONFIG_IDAM_A_U32         ((uint32)0x00000004U)
#define CAN_CONTROLLERCONFIG_IDAM_B_U32         ((uint32)0x00000008U)
#define CAN_CONTROLLERCONFIG_IDAM_C_U32         ((uint32)0x00000010U)
#define CAN_CONTROLLERCONFIG_IDAM_D_U32         ((uint32)0x00000020U)
#define CAN_CONTROLLERCONFIG_WAKEUP_SRC_U32     ((uint32)0x00000040U)
#define CAN_CONTROLLERCONFIG_LPRIO_EN_U32       ((uint32)0x00000080U)
#define CAN_CONTROLLERCONFIG_OVER_EN_U32        ((uint32)0x00000100U)
#define CAN_CONTROLLERCONFIG_WARN_EN_U32        ((uint32)0x00000200U)
#define CAN_CONTROLLERCONFIG_RXPOL_EN_U32       ((uint32)0x00000400U)
#define CAN_CONTROLLERCONFIG_TXPOL_EN_U32       ((uint32)0x00000800U)
#define CAN_CONTROLLERCONFIG_BOPOL_EN_U32       ((uint32)0x00001000U)
#define CAN_CONTROLLERCONFIG_WKPOL_EN_U32       ((uint32)0x00002000U)
#define CAN_CONTROLLERCONFIG_WRNINT_EN_U32      ((uint32)0x00004000U)
#define CAN_CONTROLLERCONFIG_WAKSUP_EN_U32      ((uint32)0x00008000U)
#define CAN_CONTROLLERCONFIG_ERR_EN_U32         ((uint32)0x00020000U)
#if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
    #define CAN_CONTROLLERCONFIG_BCC_EN_U32     ((uint32)0x00010000U)
#endif /* (CAN_BCC_SUPPORT_ENABLE == STD_ON) */
#define CAN_CONTROLLERCONFIG_IDAM_MASK_U32      ((uint32)0x0000003CU)
/**@}*/







/*==================================================================================================
                            BXCAN Register Configuration Macros
==================================================================================================*/

/*==================================================================================================
                            BXCAN Register Read Macros
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#define CAN_START_SEC_CONST_UNSPECIFIED
/* @violates @ref Reg_eSys_FlexCan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */

#include "Can_MemMap.h"
#define BXCAN_CONTROLLERS_NO 1UL



extern CONST(uint32, CAN_CONST) Can_u32BaseAddress[BXCAN_CONTROLLERS_NO];

#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/


#include "Can_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_START_SEC_CODE
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "Can_MemMap.h"

#define CAN_STOP_SEC_CODE
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif



