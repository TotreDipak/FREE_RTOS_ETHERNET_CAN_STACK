#include "Can.h"
#include "Mcal.h"
#include"Can_Internal.h"
#include"Reg_esys_FlexCan.h"
#include"Can_Flexcan.h"

/**
 * @brief  Handles CAN interrupt request
 * @param  canHandle pointer to a CAN_HandleTypeDef structure that contains
 *         the configuration information for the specified CAN.
 * @retval None
 */


void CanTxProcess (void)
{

	 uint32 errorCode 			= 	CAN_ERROR_NONE;
	 VAR(uint8, AUTOMATIC)   CanControllerId = 0U;
	/* Transmit Mailbox empty interrupt management *****************************/
if ((REG_READ32(CAN_IER_ADDR32(CanControllerId)) & BXCAN_CAN_IER_TMEIE_U32) != 0U)
	{
		/* Transmit Mailbox 0 management *********************************/
if ((REG_READ32(CAN_TSR_ADDR32(CanControllerId)) & BXCAN_CAN_TSR_RQCP0_U32) != 0U)
		{
	/* Clear the Transmission Complete flag (and TXOK0, ALST0, TERR0 bits) */
	REG_BIT_SET32(CAN_TSR_ADDR32(CanControllerId), BXCAN_CAN_TSR_RQCP0_U32);

if ((REG_READ32(CAN_TSR_ADDR32(CanControllerId)) & BXCAN_CAN_TSR_TXOK0_U32) != 0U)
			{


			}
			else
			{
				if ((REG_READ32(CAN_TSR_ADDR32(CanControllerId)) & BXCAN_CAN_TSR_ALST0_U32) != 0U)
				{
					/* Update error code */
					errorCode |= CAN_ERROR_TX_ALST0;
				}
				else if ((REG_READ32(CAN_TSR_ADDR32(CanControllerId)) & BXCAN_CAN_TSR_TERRO_U32) != 0U)
				{
					/* Update error code */
					errorCode |= CAN_ERROR_TX_TERR0;
				}
				else
				{
					;
				}
			}
		}
	}
/* Transmit Mailbox 1 management *********************************/
if ((REG_READ32(CAN_TSR_ADDR32(CanControllerId)) & BXCAN_CAN_TSR_RQCP1_U32) != 0U)
		{
	/* Clear the Transmission Complete flag (and TXOK1, ALST1, TERR1 bits) */
	REG_BIT_SET32(CAN_TSR_ADDR32(CanControllerId), BXCAN_CAN_TSR_RQCP1_U32);
if ((REG_READ32(CAN_TSR_ADDR32(CanControllerId)) & BXCAN_CAN_TSR_TXOK1_U32) != 0U)
			{
			/* Transmission Mailbox 1 complete callback */

		/* Call registered callback*/


			}
			else
			{
				if ((REG_READ32(CAN_TSR_ADDR32(CanControllerId)) & BXCAN_CAN_TSR_ALST1_U32) != 0U)
				{
					/* Update error code */
					errorCode |= CAN_ERROR_TX_ALST1;
				}
				else if ((REG_READ32(CAN_TSR_ADDR32(CanControllerId)) & BXCAN_CAN_TSR_TERR1_U32) != 0U)
				{
					/* Update error code */
					errorCode |= CAN_ERROR_TX_TERR1;
				}
				else
				{
					;
				}
			}
		}
/* Transmit Mailbox 2 management *********************************/
if ((REG_READ32(CAN_TSR_ADDR32(CanControllerId)) & BXCAN_CAN_TSR_RQCP2_U32) != 0U)
		{
	/* Clear the Transmission Complete flag (and TXOK2, ALST2, TERR2 bits) */
	REG_BIT_SET32(CAN_TSR_ADDR32(CanControllerId), BXCAN_CAN_TSR_RQCP2_U32);
if ((REG_READ32(CAN_TSR_ADDR32(CanControllerId)) & BXCAN_CAN_TSR_TXOK2_U32) != 0U)
			{
			/* Transmission Mailbox 1 complete callback */

		/* Call registered callback*/


			}
			else
			{
				if ((REG_READ32(CAN_TSR_ADDR32(CanControllerId)) & BXCAN_CAN_TSR_ALST2_U32) != 0U)
				{
					/* Update error code */
					errorCode |= CAN_ERROR_TX_ALST2;
				}
				else if ((REG_READ32(CAN_TSR_ADDR32(CanControllerId)) & BXCAN_CAN_TSR_TERR2_U32) != 0U)
				{
					/* Update error code */
					errorCode |= CAN_ERROR_TX_TERR2;
				}
				else
				{
					;
				}
			}
		}

}

void CanRxProcess (void)
{
	uint32 errorCode 			= 	CAN_ERROR_NONE;
	 VAR(uint8, AUTOMATIC)   CanControllerId = 0U;

/*	   Receive FIFO 0 overrun interrupt management *****************************/
	  if ((REG_READ32(CAN_IER_ADDR32(CanControllerId)) & BXCAN_CAN_IER_FOVIE0_U32) != 0U)

	  {
	    	if ((REG_READ32(CAN_RF0R_ADDR32(CanControllerId)) & BXCAN_CAN_RF0R_FOVR0_U32) != 0U)
	    {
/*	       Set CAN error code to Rx Fifo 0 overrun error*/
	      errorCode |= CAN_ERROR_RX_FOV0;

/*	       Clear FIFO0 Overrun Flag*/
			REG_BIT_SET32(CAN_RF0R_ADDR32(CanControllerId), BXCAN_CAN_RF0R_FOVR0_U32);

	    }
	  }

/*	   Receive FIFO 0 full interrupt management ********************************/
	  if ((REG_READ32(CAN_IER_ADDR32(CanControllerId)) & BXCAN_CAN_IER_FFIE0_U32) != 0U)

	  {
		  if ((REG_READ32(CAN_RF0R_ADDR32(CanControllerId)) & BXCAN_CAN_RF0R_FULL0_U32) != 0U)
		  {
/*	       Clear FIFO 0 full Flag*/
			REG_BIT_SET32(CAN_RF0R_ADDR32(CanControllerId), BXCAN_CAN_RF0R_FULL0_U32);

/*	       Receive FIFO 0 full Callback*/

	    }
	  }

/*	   Receive FIFO 0 message pending interrupt management *********************/
	  if ((REG_READ32(CAN_IER_ADDR32(CanControllerId)) & BXCAN_CAN_IER_FMPIE0_U32) != 0U)
	  {
/*		   Check if message is still pending*/
		  if ((REG_READ32(CAN_RF0R_ADDR32(CanControllerId)) & BXCAN_CAN_RF0R_FMP0_U32) != 0U)
		  {
/*	       Receive FIFO 0 message pending Callback*/
			  BxCan_RxFifo0MsgPendingCallback();
	    }

	  }


/*	   Receive FIFO 1 overrun interrupt management*/
	  	  if ((REG_READ32(CAN_IER_ADDR32(CanControllerId)) & BXCAN_CAN_IER_FOVIE1_U32) != 0U)

	  	  {
	  	    	if ((REG_READ32(CAN_RF1R_ADDR32(CanControllerId)) & BXCAN_CAN_RF1R_FOVR1_U32) != 0U)
	  	    {
/*	  	       Set CAN error code to Rx Fifo 0 overrun error*/
	  	      errorCode |= CAN_ERROR_RX_FOV1;

/*	  	       Clear FIFO0 Overrun Flag*/
	  			REG_BIT_SET32(CAN_RF1R_ADDR32(CanControllerId), BXCAN_CAN_RF1R_FULL1_U32);

	  	    }
	  	  }

/*	  	   Receive FIFO 1 full interrupt management*/
	  	  if ((REG_READ32(CAN_IER_ADDR32(CanControllerId)) & BXCAN_CAN_IER_FFIE1_U32) != 0U)

	  	  {
	  		  if ((REG_READ32(CAN_RF1R_ADDR32(CanControllerId)) & BXCAN_CAN_RF1R_FULL1_U32) != 0U)
	  		  {
/*	  	       Clear FIFO 1 full Flag*/
	  			REG_BIT_SET32(CAN_RF1R_ADDR32(CanControllerId), BXCAN_CAN_RF1R_FULL1_U32);


/*	  	       Receive FIFO 0 full Callback*/

	  	    }
	  	  }

	  	   /*Receive FIFO 1 message pending interrupt management*/
	  	  if ((REG_READ32(CAN_IER_ADDR32(CanControllerId)) & BXCAN_CAN_IER_FMPIE1_U32) != 0U)
	  	  {
	  		  /* Check if message is still pending*/
	  		  if ((REG_READ32(CAN_RF1R_ADDR32(CanControllerId)) & BXCAN_CAN_RF1R_FMP1_U32) != 0U)
	  		  {
	  	       /*Receive FIFO 1 message pending Callback*/
	  	    }
	  	  }
}

void CanBusOffProcess (void)
{
	/*To be implemented- configre as polling*/
}

