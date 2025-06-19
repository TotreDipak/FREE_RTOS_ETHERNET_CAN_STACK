
#ifndef CAN_INTERNAL_H
#define CAN_INTERNAL_H

#include "Std_Types.h"
#include "Reg_eSys_FlexCan.h"
#include "StdRegMacros.h"
#include"stm32f4xx.h"
#include"Can_GeneralTypes_Cfg.h"
#include"Can_GeneralTypes.h"

#define CAN_TIMEOUT_COUNT 168000;
typedef enum
{
	CAN_1,
	CAN_2
}Can_Instance;

typedef enum
{
	TriggerMode_Disable = 0,
	TriggerMode_Enable
}Can_TriggerMode;


typedef enum
{
	Autobusoff_Disable = 0,
	Autobusoff_Enable
}Can_Autobusoff;

typedef enum
{
	AutoWakeup_Disable = 0,
	AutoWakeup_Enable=0x00000020
}Can_AutoWakeup;

typedef enum
{
	AutoRetransmission_Disable = 0,
	AutoRetransmission_Enable=0x00000010
}Can_AutoRetransmission;

typedef enum
{
	ReceivedFifolocked_Disable = 0,
	ReceivedFifolocked_Enable=0x00000008
}Can_ReceivedFifolocked;

typedef enum
{
	TransmitFifoProperty_Disable = 0,
	TransmitFifoProperty_Enable
}Can_TransmitFifoProperty;


typedef enum
{
	TMEIE_Disable = 0x00000000,
	TMEIE_Enable  = 0x00000001
}Can_IER_TMEIE;

typedef enum
{
	FMPIE0_Disable = 0x00000000,
	FMPIE0_Enable  = 0x00000002
}Can_IER_FMPIE0;

typedef enum
{
	FFIE0_Disable = 0x00000000,
	FFIE0_Enable  = 0x00000004
}Can_IER_FFIE0;

typedef enum
{
	FOVIE0_Disable = 0x00000000,
	FOVIE0_Enable  = 0x00000008
}Can_IER_FOVIE0;


typedef enum
{
	FMPIE1_Disable = 0x00000000,
	FMPIE1_Enable  = 0x00000010
}Can_IER_FMPIE1;

typedef enum
{
	FFIE1_Disable = 0x00000000,
	FFIE1_Enable  = 0x00000020
}Can_IER_FFIE1;


typedef enum
{
	FOVIE1_Disable = 0x00000000,
	FOVIE1_Enable  = 0x00000040
}Can_IER_FOVIE1;


typedef enum
{
	BOFIE_Disable = 0x00000000,
	BOFIE_Enable  = 0x00000400
}Can_IER_BOFIE;

typedef enum
{
	WKUIE_Disable = 0x00000000,
	WKUIE_Enable  = 0x00010000
}Can_IER_WKUIE;

typedef enum
{
	ERRIE_Disable = 0x00000000,
	ERRIE_Enable  = 0x00008000
}Can_IER_ERRIE;

typedef enum
{
	CAN_MODE=0x00000000
}Can_BTR_SILM;



typedef enum
{   LOOPBACK_DISABLED=0x00000000,
	LOOPBACK_ENABLED=0x40000000
}Can_BTR_LBKM;


typedef enum
{
	PRESCALER_1 = 0x00000001,
	PRESCALER_2 = 0x00000002,
	PRESCALER_3 = 0x00000003,
	PRESCALER_4 = 0x00000004,
	PRESCALER_5 = 0x00000005,
	PRESCALER_6 = 0x00000006,
	PRESCALER_7 = 0x00000007,
	PRESCALER_8 = 0x00000008,
	PRESCALER_9 = 0x00000009,
	PRESCALER_10 =0x0000000A

}Can_BTR_BRP;

typedef enum
{
	CAN_FILTER_FIFO_0,
	CAN_FILTER_FIFO_1
}Can_FilterFIFOAssignment;

typedef enum
{
	FILTER_BANK_0,
	FILTER_BANK_1,
	FILTER_BANK_2,
	FILTER_BANK_3,
	FILTER_BANK_4,
	FILTER_BANK_5,
	FILTER_BANK_6,
	FILTER_BANK_7,
	FILTER_BANK_8,
	FILTER_BANK_9,
	FILTER_BANK_10,
	FILTER_BANK_11,
	FILTER_BANK_12,
	FILTER_BANK_13,
	FILTER_BANK_14,
	FILTER_BANK_15,
	FILTER_BANK_16,
	FILTER_BANK_17,
	FILTER_BANK_18,
	FILTER_BANK_19,
	FILTER_BANK_20,
	FILTER_BANK_21,
	FILTER_BANK_22,
	FILTER_BANK_23,
	FILTER_BANK_24,
	FILTER_BANK_25,
	FILTER_BANK_26,
	FILTER_BANK_27
}Can_FilterBank;

typedef enum
{
	CAN_FILTERMODE_IDMASK,
	CAN_FILTERMODE_IDLIST
}Can_FilterMode;


typedef enum
{
	CAN_FILTERSCALE_16BIT,
	CAN_FILTERSCALE_32BIT
}Can_FilterScale;

typedef enum
{
	Can_FILTER_DISABLE,
	Can_FILTER_ENABLE
}Can_FilterActivation;

typedef enum
{
	CAN_INTERRUPT_DISABLED = 0U,
	CAN_INTERRUPT_ENABLED

} Can_InterruptStateType;


typedef enum
{
	CAN_STATE_UNINIT             = 0x00U,
	CAN_STATE_STOP               = 0x01U,
	CAN_STATE_START              = 0x02U,
	CAN_STATE_SLEEP              = 0x03U,
	CAN_STATE_ERROR              = 0x04U

} HAL_CAN_StateTypeDef;

typedef struct
{
	CONST(uint32, CAN_CONST) u32CanIflag;
	CONST(uint32, CAN_CONST) u32CanImask;
} Can_MaskFlagType;


typedef struct
{
	CAN_TypeDef                   		     *Instance;
	VAR(uint32,                     AUTOMATIC)   ErrorCode;
	VAR(PduIdType,                    CAN_VAR) u32TxPduId[3];
	VAR(Can_InterruptStateType,       CAN_VAR) eInterruptMode;
	VAR(Can_ControllerStateType,      CAN_VAR) State;
} Can_ControllerStatusType;


typedef enum
{
	CAN_BASIC = 0U,
	/*CAN_FULL*//*Not implemented*/
} Can_HandleType;


typedef enum
{
	HAL_OK       = 0x00U,
	HAL_ERROR    = 0x01U,
	HAL_BUSY     = 0x02U,
	HAL_TIMEOUT  = 0x03U
} HAL_StatusTypeDef;


#endif

/* Transmit Interrupt */
#define CanItTxMailboxEmpty     ((uint32)CAN_IER_TMEIE)   /*!< Transmit mailbox empty interrupt */

/* Receive Interrupts */
#define CAN_IT_RX_FIFO0_MSG_PENDING ((uint32)CAN_IER_FMPIE0)  /*!< FIFO 0 message pending interrupt */
#define CAN_IT_RX_FIFO0_FULL        ((uint32)CAN_IER_FFIE0)   /*!< FIFO 0 full interrupt            */
#define CAN_IT_RX_FIFO0_OVERRUN     ((uint32)CAN_IER_FOVIE0)  /*!< FIFO 0 overrun interrupt         */
#define CAN_IT_RX_FIFO1_MSG_PENDING ((uint32)CAN_IER_FMPIE1)  /*!< FIFO 1 message pending interrupt */
#define CAN_IT_RX_FIFO1_FULL        ((uint32)CAN_IER_FFIE1)   /*!< FIFO 1 full interrupt            */
#define CAN_IT_RX_FIFO1_OVERRUN     ((uint32)CAN_IER_FOVIE1)  /*!< FIFO 1 overrun interrupt         */

/* Operating Mode Interrupts */
#define CAN_IT_WAKEUP               ((uint32)CAN_IER_WKUIE)   /*!< Wake-up interrupt                */
#define CAN_IT_SLEEP_ACK            ((uint32)CAN_IER_SLKIE)   /*!< Sleep acknowledge interrupt      */

/* Error Interrupts */
#define CAN_IT_ERROR_WARNING        ((uint32)CAN_IER_EWGIE)   /*!< Error warning interrupt          */
#define CAN_IT_ERROR_PASSIVE        ((uint32)CAN_IER_EPVIE)   /*!< Error passive interrupt          */
#define CAN_IT_BUSOFF               ((uint32)CAN_IER_BOFIE)   /*!< Bus-off interrupt                */
#define CAN_IT_LAST_ERROR_CODE      ((uint32)CAN_IER_LECIE)   /*!< Last error code interrupt        */
#define CAN_IT_ERROR                ((uint32)CAN_IER_ERRIE)   /*!< Error Interrupt                  */



/*******************  Bit definition for CAN_TSR register  ********************/
#define CanTsrRqcp0_Pos      (0U)
#define CanTsrRqcp0_Msk      (0x1UL << CAN_TSR_RQCP0_Pos)                     /*!< 0x00000001 */
#define CanTsrRqcp0          CAN_TSR_RQCP0_Msk                               /*!<Request Completed Mailbox0 */
#define CanTsrTxOk0_Pos      (1U)
#define CanTsrTxOk0_Msk      (0x1UL << CAN_TSR_TXOK0_Pos)                     /*!< 0x00000002 */
#define CanTsrTxOk0          CAN_TSR_TXOK0_Msk                               /*!<Transmission OK of Mailbox0 */
#define CanTsrAlst0_Pos      (2U)
#define CanTsrAlst0_Msk      (0x1UL << CAN_TSR_ALST0_Pos)                     /*!< 0x00000004 */
#define CanTsrAlst0          CAN_TSR_ALST0_Msk                               /*!<Arbitration Lost for Mailbox0 */
#define CanTsrTERR0_Pos      (3U)
#define CanTsrTERR0_Msk      (0x1UL << CAN_TSR_TERR0_Pos)                     /*!< 0x00000008 */
#define CanTsrTERR0          CAN_TSR_TERR0_Msk                               /*!<Transmission Error of Mailbox0 */
#define CAN_TSR_ABRQ0_Pos      (7U)
#define CAN_TSR_ABRQ0_Msk      (0x1UL << CAN_TSR_ABRQ0_Pos)                     /*!< 0x00000080 */
#define CAN_TSR_ABRQ0          CAN_TSR_ABRQ0_Msk                               /*!<Abort Request for Mailbox0 */
#define CAN_TSR_RQCP1_Pos      (8U)
#define CAN_TSR_RQCP1_Msk      (0x1UL << CAN_TSR_RQCP1_Pos)                     /*!< 0x00000100 */
#define CAN_TSR_RQCP1          CAN_TSR_RQCP1_Msk                               /*!<Request Completed Mailbox1 */
#define CAN_TSR_TXOK1_Pos      (9U)
#define CAN_TSR_TXOK1_Msk      (0x1UL << CAN_TSR_TXOK1_Pos)                     /*!< 0x00000200 */
#define CAN_TSR_TXOK1          CAN_TSR_TXOK1_Msk                               /*!<Transmission OK of Mailbox1 */
#define CAN_TSR_ALST1_Pos      (10U)
#define CAN_TSR_ALST1_Msk      (0x1UL << CAN_TSR_ALST1_Pos)                     /*!< 0x00000400 */
#define CAN_TSR_ALST1          CAN_TSR_ALST1_Msk                               /*!<Arbitration Lost for Mailbox1 */
#define CAN_TSR_TERR1_Pos      (11U)
#define CAN_TSR_TERR1_Msk      (0x1UL << CAN_TSR_TERR1_Pos)                     /*!< 0x00000800 */
#define CAN_TSR_TERR1          CAN_TSR_TERR1_Msk                               /*!<Transmission Error of Mailbox1 */
#define CAN_TSR_ABRQ1_Pos      (15U)
#define CAN_TSR_ABRQ1_Msk      (0x1UL << CAN_TSR_ABRQ1_Pos)                     /*!< 0x00008000 */
#define CAN_TSR_ABRQ1          CAN_TSR_ABRQ1_Msk                               /*!<Abort Request for Mailbox 1 */
#define CAN_TSR_RQCP2_Pos      (16U)
#define CAN_TSR_RQCP2_Msk      (0x1UL << CAN_TSR_RQCP2_Pos)                     /*!< 0x00010000 */
#define CAN_TSR_RQCP2          CAN_TSR_RQCP2_Msk                               /*!<Request Completed Mailbox2 */
#define CAN_TSR_TXOK2_Pos      (17U)
#define CAN_TSR_TXOK2_Msk      (0x1UL << CAN_TSR_TXOK2_Pos)                     /*!< 0x00020000 */
#define CAN_TSR_TXOK2          CAN_TSR_TXOK2_Msk                               /*!<Transmission OK of Mailbox 2 */
#define CAN_TSR_ALST2_Pos      (18U)
#define CAN_TSR_ALST2_Msk      (0x1UL << CAN_TSR_ALST2_Pos)                     /*!< 0x00040000 */
#define CAN_TSR_ALST2          CAN_TSR_ALST2_Msk                               /*!<Arbitration Lost for mailbox 2 */
#define CAN_TSR_TERR2_Pos      (19U)
#define CAN_TSR_TERR2_Msk      (0x1UL << CAN_TSR_TERR2_Pos)                     /*!< 0x00080000 */
#define CAN_TSR_TERR2          CAN_TSR_TERR2_Msk                               /*!<Transmission Error of Mailbox 2 */
#define CAN_TSR_ABRQ2_Pos      (23U)
#define CAN_TSR_ABRQ2_Msk      (0x1UL << CAN_TSR_ABRQ2_Pos)                     /*!< 0x00800000 */
#define CAN_TSR_ABRQ2          CAN_TSR_ABRQ2_Msk                               /*!<Abort Request for Mailbox 2 */
#define CAN_TSR_CODE_Pos       (24U)
#define CAN_TSR_CODE_Msk       (0x3UL << CAN_TSR_CODE_Pos)                      /*!< 0x03000000 */
#define CAN_TSR_CODE           CAN_TSR_CODE_Msk                                /*!<Mailbox Code */

#define CAN_TSR_TME_Pos        (26U)
#define CAN_TSR_TME_Msk        (0x7UL << CAN_TSR_TME_Pos)                       /*!< 0x1C000000 */
#define CAN_TSR_TME            CAN_TSR_TME_Msk                                 /*!<TME[2:0] bits */
#define CAN_TSR_TME0_Pos       (26U)
#define CAN_TSR_TME0_Msk       (0x1UL << CAN_TSR_TME0_Pos)                      /*!< 0x04000000 */
#define CAN_TSR_TME0           CAN_TSR_TME0_Msk                                /*!<Transmit Mailbox 0 Empty */
#define CAN_TSR_TME1_Pos       (27U)
#define CAN_TSR_TME1_Msk       (0x1UL << CAN_TSR_TME1_Pos)                      /*!< 0x08000000 */
#define CAN_TSR_TME1           CAN_TSR_TME1_Msk                                /*!<Transmit Mailbox 1 Empty */
#define CAN_TSR_TME2_Pos       (28U)
#define CAN_TSR_TME2_Msk       (0x1UL << CAN_TSR_TME2_Pos)                      /*!< 0x10000000 */
#define CAN_TSR_TME2           CAN_TSR_TME2_Msk                                /*!<Transmit Mailbox 2 Empty */

#define CAN_TSR_LOW_Pos        (29U)
#define CAN_TSR_LOW_Msk        (0x7UL << CAN_TSR_LOW_Pos)                       /*!< 0xE0000000 */
#define CAN_TSR_LOW            CAN_TSR_LOW_Msk                                 /*!<LOW[2:0] bits */
#define CAN_TSR_LOW0_Pos       (29U)
#define CAN_TSR_LOW0_Msk       (0x1UL << CAN_TSR_LOW0_Pos)                      /*!< 0x20000000 */
#define CAN_TSR_LOW0           CAN_TSR_LOW0_Msk                                /*!<Lowest Priority Flag for Mailbox 0 */
#define CAN_TSR_LOW1_Pos       (30U)
#define CAN_TSR_LOW1_Msk       (0x1UL << CAN_TSR_LOW1_Pos)                      /*!< 0x40000000 */
#define CAN_TSR_LOW1           CAN_TSR_LOW1_Msk                                /*!<Lowest Priority Flag for Mailbox 1 */
#define CAN_TSR_LOW2_Pos       (31U)
#define CAN_TSR_LOW2_Msk       (0x1UL << CAN_TSR_LOW2_Pos)                      /*!< 0x80000000 */
#define CAN_TSR_LOW2           CAN_TSR_LOW2_Msk                                /*!<Lowest Priority Flag for Mailbox 2 */


/* Transmit Flags */
#define CAN_FLAG_RQCP0                (0x00000500U)  /*!< Request complete MailBox 0 flag   */
#define CAN_FLAG_TXOK0              (0x00000501U)  /*!< Transmission OK MailBox 0 flag    */
#define CAN_FLAG_ALST0              (0x00000502U)  /*!< Arbitration Lost MailBox 0 flag   */
#define CAN_FLAG_TERR0              (0x00000503U)  /*!< Transmission error MailBox 0 flag */
#define CAN_FLAG_RQCP1              (0x00000508U)  /*!< Request complete MailBox1 flag    */
#define CAN_FLAG_TXOK1              (0x00000509U)  /*!< Transmission OK MailBox 1 flag    */
#define CAN_FLAG_ALST1              (0x0000050AU)  /*!< Arbitration Lost MailBox 1 flag   */
#define CAN_FLAG_TERR1              (0x0000050BU)  /*!< Transmission error MailBox 1 flag */
#define CAN_FLAG_RQCP2              (0x00000510U)  /*!< Request complete MailBox2 flag    */
#define CAN_FLAG_TXOK2              (0x00000511U)  /*!< Transmission OK MailBox 2 flag    */
#define CAN_FLAG_ALST2              (0x00000512U)  /*!< Arbitration Lost MailBox 2 flag   */
#define CAN_FLAG_TERR2              (0x00000513U)  /*!< Transmission error MailBox 2 flag */
#define CAN_FLAG_TME0               (0x0000051AU)  /*!< Transmit mailbox 0 empty flag     */
#define CAN_FLAG_TME1               (0x0000051BU)  /*!< Transmit mailbox 1 empty flag     */
#define CAN_FLAG_TME2               (0x0000051CU)  /*!< Transmit mailbox 2 empty flag     */
#define CAN_FLAG_LOW0               (0x0000051DU)  /*!< Lowest priority mailbox 0 flag    */
#define CAN_FLAG_LOW1               (0x0000051EU)  /*!< Lowest priority mailbox 1 flag    */
#define CAN_FLAG_LOW2               (0x0000051FU)  /*!< Lowest priority mailbox 2 flag    */
#define CAN_FLAG_MASK  (0x000000FFU)

#define CAN_CLEAR_FLAG(__HANDLE__, __FLAG__) \
		((((__FLAG__) >> 8U) == 5U)? (((__HANDLE__)->Instance->TSR) = (1U << ((__FLAG__) & CAN_FLAG_MASK))): \
				(((__FLAG__) >> 8U) == 2U)? (((__HANDLE__)->Instance->RF0R) = (1U << ((__FLAG__) & CAN_FLAG_MASK))): \
						(((__FLAG__) >> 8U) == 4U)? (((__HANDLE__)->Instance->RF1R) = (1U << ((__FLAG__) & CAN_FLAG_MASK))): \
								(((__FLAG__) >> 8U) == 1U)? (((__HANDLE__)->Instance->MSR) = (1U << ((__FLAG__) & CAN_FLAG_MASK))): 0U)

