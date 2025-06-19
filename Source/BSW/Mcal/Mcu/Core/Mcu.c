#include "Mcu.h"
#include "Mcu_Config.h"
#include "Mcu_Internal.h"
#include "Mcu_RegTypes.h"
#include "stm32f407xx.h"
#include "StdRegMacros.h"
#include"Compiler_Common.h"
#include"Compiler.h"
Mcu_ConfigType* Mcu_pConfigPtr = NULL_PTR;

#define RCC_CRREG  ((uint32*)RCCREG_BASE)

static FUNC(void, MCU_CODE) Mcu_Pwr_Init(VAR(Mcu_ConfigType* pConfigPtr, AUTOMATIC));
static FUNC(void, MCU_CODE) Mcu_Flash_Init(VAR(Mcu_ConfigType* pConfigPtr, AUTOMATIC));
static FUNC(void, MCU_CODE) Mcu_AllPeriphralReset(VAR( void, AUTOMATIC));
static FUNC(void, MCU_CODE) Mcu_AHB1Init(VAR(Mcu_ConfigType* pConfigPtr, AUTOMATIC));
static FUNC(void, MCU_CODE) Mcu_AHB2Init(VAR(Mcu_ConfigType* pConfigPtr, AUTOMATIC));
static FUNC(void, MCU_CODE) Mcu_AHB3Init(VAR(Mcu_ConfigType* pConfigPtr, AUTOMATIC));
static FUNC(void, MCU_CODE) Mcu_APB1Init(VAR(Mcu_ConfigType* pConfigPtr, AUTOMATIC));
static FUNC(void, MCU_CODE) Mcu_APB2Init(VAR(Mcu_ConfigType* pConfigPtr, AUTOMATIC));

static FUNC(void, MCU_CODE) Mcu_Pwr_Init(VAR(Mcu_ConfigType* pConfigPtr, AUTOMATIC))
{

#if(MCU_VOS_SCALE_USED == STD_ON)

REG_RMW32(PWR_CR_ADDR, PWR_VOS_MASK, pConfigPtr->PWRConfgSet->unVOS);

#endif
#if(MCU_FPDS_USED == STD_ON)
	LpPWR_Reg->CR |= LpPwrConfigPtr->PwrCRConfgVal.FPDS;
#endif
#if(MCU_DBP_USED == STD_ON)
	LpPWR_Reg->CR |= LpPwrConfigPtr->PwrCRConfgVal.DBP;
#endif
#if(MCU_PLS_USED == STD_ON)
	LpPWR_Reg->CR |= LpPwrConfigPtr->PwrCRConfgVal.PLS;
#endif
#if(MCU_PVDE_USED == STD_ON)
	LpPWR_Reg->CR |= LpPwrConfigPtr->PwrCRConfgVal.PVDE;
#endif
#if(MCU_PDDS_USED == STD_ON)
	LpPWR_Reg->CR |= LpPwrConfigPtr->PwrCRConfgVal.PDDS;
#endif
#if(MCU_LPDS_USED == STD_ON)
	LpPWR_Reg->CR |= LpPwrConfigPtr->PwrCRConfgVal.LPDS;
#endif

#if(MCU_BRE_USED == STD_ON)
	LpPWR_Reg->CSR |= LpPwrConfigPtr->PwrCSRConfgVal.BRE;
#endif
#if(MCU_EWUP_USED == STD_ON)
	LpPWR_Reg->CSR |= LpPwrConfigPtr->PwrCSRConfgVal.EWUP;
#endif

}

static FUNC(void, MCU_CODE) Mcu_Flash_Init(VAR(Mcu_ConfigType* pConfigPtr, AUTOMATIC))
{
#if(MCU_DCRST_USED == STD_ON)
	LpFLASH_Reg->ACR |= LpFlashconfigPtr->FLASHACRConfgVal.DCRST;
#endif
#if(MCU_ICRST_USED == STD_ON)
	LpFLASH_Reg->ACR |= LpFlashconfigPtr->FLASHACRConfgVal.ICRST;
#endif
#if(MCU_LATENCY_USED == STD_ON)
	REG_RMW32(FLASH_ACR_ADDR, FLASH_LATENCY_MASK,pConfigPtr->FlashConfgSet->unLATENCY);
#endif
#if(MCU_DCEN_USED == STD_ON)
	REG_RMW32(FLASH_ACR_ADDR, FLASH_DCEN_MASK,pConfigPtr->FlashConfgSet->unDCEN);
#endif
#if(MCU_ICEN_USED == STD_ON)
	REG_RMW32(FLASH_ACR_ADDR, FLASH_ICEN_MASK,pConfigPtr->FlashConfgSet->unICEN);
#endif
#if(MCU_PRFTEN_USED == STD_ON)
	REG_RMW32(FLASH_ACR_ADDR,FLASH_PRFTEN_MASK,pConfigPtr->FlashConfgSet->unPRFTEN);
#endif
}
static FUNC(void, MCU_CODE) Mcu_AllPeriphralReset(VAR( void, AUTOMATIC))
{


	/*Reset the MCU Peripherals */
	REG_RMW32(RCC_AHB1RSTR_ADDR, RCC_AHB1RSTR_MASK,RCC_AHB1RSTR_SET);
	REG_RMW32(RCC_AHB1RSTR_ADDR, RCC_AHB1RSTR_MASK,RCC_AHB1RSTR_RESET);

	REG_RMW32(RCC_AHB2RSTR_ADDR, RCC_AHB2RSTR_MASK,RCC_AHB2RSTR_SET);
	REG_RMW32(RCC_AHB2RSTR_ADDR, RCC_AHB2RSTR_MASK,RCC_AHB2RSTR_RESET);

	REG_RMW32(RCC_AHB3RSTR_ADDR, RCC_AHB3RSTR_MASK,RCC_AHB3RSTR_SET);
	REG_RMW32(RCC_AHB3RSTR_ADDR, RCC_AHB3RSTR_MASK,RCC_AHB3RSTR_RESET);

	REG_RMW32(RCC_APB1RSTR_ADDR, RCC_APB1RSTR_MASK,RCC_APB1RSTR_SET);
	REG_RMW32(RCC_APB1RSTR_ADDR, RCC_APB1RSTR_MASK,RCC_APB1RSTR_RESET);

	REG_RMW32(RCC_APB2RSTR_ADDR, RCC_APB2RSTR_MASK,RCC_APB2RSTR_SET);
	REG_RMW32(RCC_APB2RSTR_ADDR, RCC_APB2RSTR_MASK,RCC_APB2RSTR_RESET);
	/*Reset the MCU Peripherals */
}
static FUNC(void, MCU_CODE) Mcu_AHB1Init(VAR(Mcu_ConfigType* pConfigPtr, AUTOMATIC))
{


	/*McuAHB1ENRConfgVal*/
#ifdef MCU_USB_OTG_USED
#if(OTGHSULPIEN_USED == STD_ON)
	LpRCC_Reg->AHB1ENR |= LpMcuClockConfigPtr->McuAHB1ENRConfgVal.OTGHSULPIEN;
#endif
#if(OTGHSEN_USED == STD_ON)
	LpRCC_Reg->AHB1ENR |= LpMcuClockConfigPtr->McuAHB1ENRConfgVal.OTGHSEN;
#endif
#endif

#ifdef MCU_ETHMAC_USED
#if(ETHMACPTPEN_USED == STD_ON)
REG_RMW32(RCC_AHB1ENR_ADDR,RCC_ETHMACPTP_MASK,pConfigPtr->McuClockConfgSet->unETHMACPTP);
#endif
#endif
#ifdef MCU_CCM_DATA_RAM_USED
#if(CCMDATARAMEN_USED == STD_ON)
	REG_RMW32(RCC_AHB1ENR_ADDR,RCC_CCMDATARAM_MASK,pConfigPtr->McuClockConfgSet->unCCMDATARAM);
#endif
#endif
#if(ETHMACEN_USED == STD_ON)
	REG_RMW32(RCC_AHB1ENR_ADDR,RCC_ETHMAC_MASK,pConfigPtr->McuClockConfgSet->unETHMAC);
#endif

#if(ETHMACTXEN_USED == STD_ON)
	REG_RMW32(RCC_AHB1ENR_ADDR,RCC_ETHMACTX_MASK,pConfigPtr->McuClockConfgSet->unETHMACTX);
#endif

#if(ETHMACRXEN_USED == STD_ON)
	REG_RMW32(RCC_AHB1ENR_ADDR,RCC_ETHMACRX_MASK,pConfigPtr->McuClockConfgSet->unETHMACRX);
#endif

#ifdef MCU_DMA_USED
#if(DMA2EN_USED == STD_ON)
	LpRCC_Reg->AHB1ENR |= LpMcuClockConfigPtr->McuAHB1ENRConfgVal.DMA2EN;
#endif
#if(DMA1EN_USED == STD_ON)
	LpRCC_Reg->AHB1ENR |= LpMcuClockConfigPtr->McuAHB1ENRConfgVal.DMA1EN;
#endif
#endif



#ifdef MCU_BKP_SRAM_USED
#if(BKPSRAMEN_USED == STD_ON)
	LpRCC_Reg->AHB1ENR |= LpMcuClockConfigPtr->McuAHB1ENRConfgVal.BKPSRAMEN;
#endif
#endif

#ifdef MCU_CRC_USED
#if(CRCEN_USED == STD_ON)
	LpRCC_Reg->AHB1ENR |= LpMcuClockConfigPtr->McuAHB1ENRConfgVal.CRCEN;
#endif
#endif

#ifdef MCU_GPIO_USED
#if(GPIOIEN_USED == STD_ON)
	LpRCC_Reg->AHB1ENR |= LpMcuClockConfigPtr->McuAHB1ENRConfgVal.GPIOIEN;
#endif
#if(GPIOHEN_USED == STD_ON)
	REG_RMW32(RCC_AHB1ENR_ADDR,RCC_GPIOH_MASK,pConfigPtr->McuClockConfgSet->unGPIOH);
#endif
#if(GPIOGEN_USED == STD_ON)
	LpRCC_Reg->AHB1ENR |= LpMcuClockConfigPtr->McuAHB1ENRConfgVal.GPIOGEN;
#endif
#if(GPIOFEN_USED == STD_ON)
	LpRCC_Reg->AHB1ENR |= LpMcuClockConfigPtr->McuAHB1ENRConfgVal.GPIOFEN;
#endif
#if(GPIOEEN_USED == STD_ON)
	LpRCC_Reg->AHB1ENR |= LpMcuClockConfigPtr->McuAHB1ENRConfgVal.GPIOEEN;
#endif

#if(GPIODEN_USED == STD_ON)
	REG_RMW32(RCC_AHB1ENR_ADDR,RCC_GPIOD_MASK,pConfigPtr->McuClockConfgSet->unGPIOD);
#endif

#if(GPIOCEN_USED == STD_ON)
	REG_RMW32(RCC_AHB1ENR_ADDR,RCC_GPIOC_MASK,pConfigPtr->McuClockConfgSet->unGPIOC);
#endif
#if(GPIOBEN_USED == STD_ON)
	REG_RMW32(RCC_AHB1ENR_ADDR,RCC_GPIOB_MASK,pConfigPtr->McuClockConfgSet->unGPIOB);
#endif
#if(GPIOAEN_USED == STD_ON)
	REG_RMW32(RCC_AHB1ENR_ADDR,RCC_GPIOA_MASK,pConfigPtr->McuClockConfgSet->unGPIOA);
#endif
#endif
}
static FUNC(void, MCU_CODE) Mcu_AHB2Init(VAR(Mcu_ConfigType* pConfigPtr, AUTOMATIC))
{


	/*McuAHB2ENRConfgVal*/
#if(OTGFSEN_USED == STD_ON)
	LpRCC_Reg->AHB2ENR |= LpMcuClockConfigPtr->McuAHB2ENRConfgVal.OTGFSEN;
#endif
#if(RNGEN_USED == STD_ON)
	LpRCC_Reg->AHB2ENR |= LpMcuClockConfigPtr->McuAHB2ENRConfgVal.RNGEN;
#endif
#if(HASHEN_USED == STD_ON)
	LpRCC_Reg->AHB2ENR |= LpMcuClockConfigPtr->McuAHB2ENRConfgVal.HASHEN;
#endif
#if(CRYPEN_USED == STD_ON)
	LpRCC_Reg->AHB2ENR |= LpMcuClockConfigPtr->McuAHB2ENRConfgVal.CRYPEN;
#endif
#if(DCMIEN_USED == STD_ON)
	LpRCC_Reg->AHB2ENR |= LpMcuClockConfigPtr->McuAHB2ENRConfgVal.DCMIEN;
#endif


}
static FUNC(void, MCU_CODE) Mcu_AHB3Init(VAR(Mcu_ConfigType* pConfigPtr, AUTOMATIC))
{

#if(DCMIEN_USED == STD_ON)
	LpRCC_Reg->AHB3ENR |= LpMcuClockConfigPtr->McuAHB3ENRConfgVal.FSMCEN;
#endif
}
static FUNC(void, MCU_CODE) Mcu_APB1Init(VAR(Mcu_ConfigType* pConfigPtr, AUTOMATIC))
{
	/*McuAPB1ENRConfgVal*/
#ifdef MCU_DAC_USED
#if(DACEN_USED == STD_ON)
	LpRCC_Reg->APB1ENR |= LpMcuClockConfigPtr->McuAPB1ENRConfgVal.DACEN;
#endif
#endif
#ifdef MCU_PWR_USED
#if(PWREN_USED == STD_ON)
REG_RMW32(RCC_APB1ENR_ADDR,RCC_PWREN_MASK,pConfigPtr->McuClockConfgSet->unPWR);
#endif
#endif
#ifdef MCU_CAN_USED
#if(CAN2EN_USED == STD_ON)
	REG_RMW32(RCC_APB1ENR_ADDR,RCC_CAN1_MASK,pConfigPtr->McuClockConfgSet->unCAN2);
#endif
#if(CAN1EN_USED == STD_ON)
	REG_RMW32(RCC_APB1ENR_ADDR,RCC_CAN1_MASK,pConfigPtr->McuClockConfgSet->unCAN1);
#endif
#endif

#ifdef MCU_I2C_USED
#if(I2C3EN_USED == STD_ON)
	LpRCC_Reg->APB1ENR |= LpMcuClockConfigPtr->McuAPB1ENRConfgVal.I2C3EN;
#endif
#if(I2C2EN_USED == STD_ON)
	LpRCC_Reg->APB1ENR |= LpMcuClockConfigPtr->McuAPB1ENRConfgVal.I2C2EN;
#endif
#if(I2C1EN_USED == STD_ON)
	LpRCC_Reg->APB1ENR |= LpMcuClockConfigPtr->McuAPB1ENRConfgVal.I2C1EN;
#endif
#endif
#ifdef MCU_UART_USED
#if(UART5EN_USED == STD_ON)
	LpRCC_Reg->APB1ENR |= LpMcuClockConfigPtr->McuAPB1ENRConfgVal.UART5EN;
#endif
#if(UART4EN_USED == STD_ON)
	LpRCC_Reg->APB1ENR |= LpMcuClockConfigPtr->McuAPB1ENRConfgVal.UART4EN;
#endif
#endif
#ifdef MCU_USART_USED
#if(USART3EN_USED == STD_ON)
	LpRCC_Reg->APB1ENR |= LpMcuClockConfigPtr->McuAPB1ENRConfgVal.USART3EN;
#endif
#if(USART2EN_USED == STD_ON)
	LpRCC_Reg->APB1ENR |= LpMcuClockConfigPtr->McuAPB1ENRConfgVal.USART2EN;
#endif
#endif
#ifdef MCU_SPI_USED
#if(SPI3EN_USED == STD_ON)
	LpRCC_Reg->APB1ENR |= LpMcuClockConfigPtr->McuAPB1ENRConfgVal.SPI3EN;
#endif
#if(SPI2EN_USED == STD_ON)
	LpRCC_Reg->APB1ENR |= LpMcuClockConfigPtr->McuAPB1ENRConfgVal.SPI2EN;
#endif
#endif
#if(WWDGEN_USED == STD_ON)
	LpRCC_Reg->APB1ENR |= LpMcuClockConfigPtr->McuAPB1ENRConfgVal.WWDGEN;
#endif
#ifdef MCU_TIM_USED
#if(TIM14EN_USED == STD_ON)
	LpRCC_Reg->APB1ENR |= LpMcuClockConfigPtr->McuAPB1ENRConfgVal.UART4EN;
#endif
#if(TIM13EN_USED == STD_ON)
	LpRCC_Reg->APB1ENR |= LpMcuClockConfigPtr->McuAPB1ENRConfgVal.TIM13EN;
#endif
#if(TIM12EN_USED == STD_ON)
	LpRCC_Reg->APB1ENR |= LpMcuClockConfigPtr->McuAPB1ENRConfgVal.TIM12EN;
#endif
#if(TIM7EN_USED == STD_ON)
	LpRCC_Reg->APB1ENR |= LpMcuClockConfigPtr->McuAPB1ENRConfgVal.TIM7EN;
#endif
#if(TIM6EN_USED == STD_ON)
	REG_RMW32(RCC_APB1ENR_ADDR,RCC_TIM6_MASK,pConfigPtr->McuClockConfgSet->unTIM6);
#endif
#if(TIM5EN_USED == STD_ON)
	REG_RMW32(RCC_APB1ENR_ADDR,RCC_TIM5_MASK,pConfigPtr->McuClockConfgSet->unTIM5);
#endif
#if(TIM4EN_USED == STD_ON)
	REG_RMW32(RCC_APB1ENR_ADDR,RCC_TIM4_MASK,pConfigPtr->McuClockConfgSet->unTIM4);
#endif
#if(TIM3EN_USED == STD_ON)
	REG_RMW32(RCC_APB1ENR_ADDR,RCC_TIM3_MASK,pConfigPtr->McuClockConfgSet->unTIM3);
#endif
#if(TIM2EN_USED == STD_ON)
	REG_RMW32(RCC_APB1ENR_ADDR,RCC_TIM2_MASK,pConfigPtr->McuClockConfgSet->unTIM2);
#endif
#endif

}
static FUNC(void, MCU_CODE) Mcu_APB2Init(VAR(Mcu_ConfigType* pConfigPtr, AUTOMATIC))
{


	/*McuAPB2ENRConfgVal*/
#ifdef MCU_TIM_USED
#if(TIM11EN_USED == STD_ON)
	LpRCC_Reg->APB2ENR |= LpMcuClockConfigPtr->McuAPB2ENRConfgVal.TIM11EN;
#endif
#if(TIM10EN_USED == STD_ON)
	LpRCC_Reg->APB2ENR |= LpMcuClockConfigPtr->McuAPB2ENRConfgVal.TIM10EN;
#endif
#if(TIM9EN_USED == STD_ON)
	LpRCC_Reg->APB2ENR |= LpMcuClockConfigPtr->McuAPB2ENRConfgVal.TIM9EN;
#endif
#endif
#if(SYSCFGEN_USED == STD_ON)

	REG_RMW32(RCC_APB2ENR_ADDR,RCC_SYSCFGEN_MASK,pConfigPtr->McuClockConfgSet->unSYSCFG);
#endif
#if(SPI1EN_USED == STD_ON)
	LpRCC_Reg->APB2ENR |= LpMcuClockConfigPtr->McuAPB2ENRConfgVal.SPI1EN;
#endif
#if(SPI1EN_USED == STD_ON)
	LpRCC_Reg->APB2ENR |= LpMcuClockConfigPtr->McuAPB2ENRConfgVal.SDIOEN;
#endif
#ifdef MCU_ADC_USED
#if(ADC3EN_USED == STD_ON)
	LpRCC_Reg->APB2ENR |= LpMcuClockConfigPtr->McuAPB2ENRConfgVal.ADC3EN;
#endif
#if(ADC3EN_USED == STD_ON)
	LpRCC_Reg->APB2ENR |= LpMcuClockConfigPtr->McuAPB2ENRConfgVal.ADC2EN;
#endif
#if(ADC3EN_USED == STD_ON)
	LpRCC_Reg->APB2ENR |= LpMcuClockConfigPtr->McuAPB2ENRConfgVal.ADC1EN;
#endif
#endif
#ifdef MCU_USART_USED
#if(USART6EN_USED == STD_ON)
	LpRCC_Reg->APB2ENR |= LpMcuClockConfigPtr->McuAPB2ENRConfgVal.USART6EN;
#endif
#if(USART5EN_USED == STD_ON)
	LpRCC_Reg->APB2ENR |= LpMcuClockConfigPtr->McuAPB2ENRConfgVal.USART1EN;
#endif
#endif
#ifdef MCU_TIM_USED
#if(TIM8EN_USED == STD_ON)
	LpRCC_Reg->APB2ENR |= LpMcuClockConfigPtr->McuAPB2ENRConfgVal.TIM8EN;
#endif
#if(TIM1EN_USED == STD_ON)
	LpRCC_Reg->APB2ENR |= LpMcuClockConfigPtr->McuAPB2ENRConfgVal.TIM1EN;
#endif
#endif
}

/*
 * Enable Peripherals
 * 	Mcu_AHB1Init();
 * 	Mcu_AHB2Init();
 * 	Mcu_AHB3Init();
 * 	Mcu_APB1Init();
 * 	Mcu_APB2Init(); */
FUNC(void, MCU_CODE) Mcu_Init( Mcu_ConfigType* pConfigPtr)
{
	Mcu_AllPeriphralReset();
	Mcu_Pwr_Init(pConfigPtr);
	Mcu_Flash_Init(pConfigPtr);
	Mcu_AHB1Init(pConfigPtr);
	Mcu_AHB2Init(pConfigPtr);
	Mcu_AHB3Init(pConfigPtr);
	Mcu_APB1Init(pConfigPtr);
	Mcu_APB2Init(pConfigPtr);
}
/*
 * Enable HSE or HSI
 * Configure PLLCFGR
 * Configure CFGR (if applicable)
 * Configuring PLL */
FUNC( Std_ReturnType, MCU_CODE) Mcu_InitClock( Mcu_ConfigType* pConfigPtr)
{
	REG_RMW32(RCC_CR_ADDR,RCC_HSITRIM_MASK,HSITRIM_DEFAULT);
	REG_RMW32(RCC_CR_ADDR,RCC_HSI_MASK,HSION_ON);
#if(MCU_HSI_USED == STD_ON)
	REG_RMW32(RCC_CR_ADDR,RCC_HSI_MASK,HSION_ON);
#endif
	/*HSI TRIM -> Set to Default value -->to be Implemented*/

#if(MCU_HSE_USED == STD_ON)
	REG_RMW32(RCC_CR_ADDR,RCC_HSE_MASK,HSE_ON);
	/* Wait for HSEON ready*/
	while (!(REG_READ32(RCC_CR_ADDR & RCC_HSERDY_MASK)));

#if(MCU_PLL_USED == STD_OFF)
	LpRCC_Reg->CFGR |= LpMcuClockConfigPtr->McuCFGRConfgVal.SW;
#endif
#endif
	/* Configure AHB PreScaler->HCLK,
	 * APB1 Prescaler->PCLK1,
	 * APB2 Prescaler->PCLK2*/
	/*Clear SW, HPRE, PPRE1, and PPRE2 bits*/
	//RCC->CFGR &= ~(RCC_CFGR_HPRE | RCC_CFGR_PPRE1 | RCC_CFGR_PPRE2);
	REG_RMW32(RCC_CFGR_ADDR, RCC_HPRE_MASK, RCC_CFGR_RESET);
	REG_RMW32(RCC_CFGR_ADDR, RCC_PPRE1_MASK,RCC_CFGR_RESET);
	REG_RMW32(RCC_CFGR_ADDR, RCC_PPRE2_MASK,RCC_CFGR_RESET);
	/*RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV8;
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;*/


	/* Configure AHB prescaler*/
	REG_RMW32(RCC_CFGR_ADDR, RCC_HPRE_MASK, HRPE_SYSCLK_1);
	/* Configure APB1 prescaler*/
	REG_RMW32(RCC_CFGR_ADDR, RCC_PPRE1_MASK,PRE1_AHB_8);
	/*Configure APB2 prescaler*/
	REG_RMW32(RCC_CFGR_ADDR, RCC_PPRE2_MASK,PRE2_AHB_2);


//Reset PLLCFGR

	REG_RMW32(RCC_PLLCFGR_ADDR, RCC_PLLCFGR_MASK,RCC_PLLCFGR_RESET);

#if(MCU_PLL_USED == STD_ON)
	REG_RMW32(RCC_PLLCFGR_ADDR, RCC_PLLCFGR_PLLM_MASK,pConfigPtr->McuClockConfgSet->unPLLM);
	REG_RMW32(RCC_PLLCFGR_ADDR, RCC_PLLCFGR_PLLN_MASK,pConfigPtr->McuClockConfgSet->unPLLN);
	REG_RMW32(RCC_PLLCFGR_ADDR, RCC_PLLCFGR_PLLP_MASK,pConfigPtr->McuClockConfgSet->unPLLP);
	REG_RMW32(RCC_PLLCFGR_ADDR, RCC_PLLCFGR_PLLQ_MASK,pConfigPtr->McuClockConfgSet->unPLLQ);
	REG_RMW32(RCC_PLLCFGR_ADDR, RCC_PLLCFGR_PLLSRC_MASK,pConfigPtr->McuClockConfgSet->unPLLSRC);
#endif

#if(MCU_MCO2_USED == STD_ON)
	LpRCC_Reg->CFGR |= LpMcuClockConfigPtr->McuCFGRConfgVal.MCO2;
	LpRCC_Reg->CFGR |= LpMcuClockConfigPtr->McuCFGRConfgVal.MCO2PRE;
#endif
#if(MCU_MCO1_USED == STD_ON)
	LpRCC_Reg->CFGR |= LpMcuClockConfigPtr->McuCFGRConfgVal.MCO1;
	LpRCC_Reg->CFGR |= LpMcuClockConfigPtr->McuCFGRConfgVal.MCO1PRE;
#endif
#if(MCU_I2SSRC_USED == STD_ON)
	LpRCC_Reg->CFGR |= LpMcuClockConfigPtr->McuCFGRConfgVal.I2SSRC;
#endif
#if(MCU_RTC_USED == STD_ON)
	LpRCC_Reg->CFGR |= LpMcuClockConfigPtr->McuCFGRConfgVal.RTCPRE;
#endif



#if 0
#if(MCU_RTC_PREHSE_1_USED == STD_ON)
	LpRCC_Reg->CIR|=LpMcuClockConfigPtr->McuCIRConfgVal.PLLI2SRDYIE;
#endif
#if(MCU_RTC_PREHSE_1_USED == STD_ON)
	LpRCC_Reg->CIR|=LpMcuClockConfigPtr->McuCIRConfgVal.PLLRDYIE;
#endif
#if(MCU_RTC_PREHSE_1_USED == STD_ON)
	LpRCC_Reg->CIR|=LpMcuClockConfigPtr->McuCIRConfgVal.HSERDYIE;
#endif
#if(MCU_RTC_PREHSE_1_USED == STD_ON)
	LpRCC_Reg->CIR|=LpMcuClockConfigPtr->McuCIRConfgVal.HSIRDYIE;
#endif
#if(MCU_RTC_PREHSE_1_USED == STD_ON)
	LpRCC_Reg->CIR|=LpMcuClockConfigPtr->McuCIRConfgVal.LSERDYIE;
#endif
#if(MCU_RTC_PREHSE_1_USED == STD_ON)
	LpRCC_Reg->CIR|=LpMcuClockConfigPtr->McuCIRConfgVal.LSIRDYIE;
#endif
#endif

#if(MCU_PLL_USED == STD_ON)
	REG_RMW32(RCC_CR_ADDR,RCC_PLLON_MASK,PLL_ON);
#endif

#if(MCU_PLLI2S_USED == STD_ON)
	LpRCC_Reg->CR |= LpMcuClockConfigPtr->McuCRConfgVal.PLLI2SON;
#endif

#if 0
	LpRCC_Reg->BDCR = LpMcuClockConfigPtr->McuBDCRConfgVal.BDRST;
	LpRCC_Reg->BDCR = LpMcuClockConfigPtr->McuBDCRConfgVal.RTCEN;
	LpRCC_Reg->BDCR = LpMcuClockConfigPtr->McuBDCRConfgVal.RTCSEL;
	LpRCC_Reg->BDCR = LpMcuClockConfigPtr->McuBDCRConfgVal.LSEBYP;
	LpRCC_Reg->BDCR = LpMcuClockConfigPtr->McuBDCRConfgVal.LSEON;
	LpRCC_Reg->CSR = LpMcuClockConfigPtr->McuCSRConfgVal.LSION;
	LpRCC_Reg->SSCGR = LpMcuClockConfigPtr->McuSSCGRConfgVal.SSCGEN;
	LpRCC_Reg->SSCGR = LpMcuClockConfigPtr->McuSSCGRConfgVal.SPREADSEL;
	LpRCC_Reg->SSCGR = LpMcuClockConfigPtr->McuSSCGRConfgVal.INCSTEP;
	LpRCC_Reg->SSCGR = LpMcuClockConfigPtr->McuSSCGRConfgVal.MODPER;
	LpRCC_Reg->PLLI2SCFGR = LpMcuClockConfigPtr->McuPLLI2SCFGRConfgVal.PLLI2SR;
	LpRCC_Reg->PLLI2SCFGR = LpMcuClockConfigPtr->McuPLLI2SCFGRConfgVal.PLLI2SN;
#endif
	return E_OK;
}

/* Get Status of PLL after turning PLL to ON in CR */
FUNC( Std_ReturnType, MCU_CODE) Mcu_GetPllStatus(VAR( void, AUTOMATIC))
{
	static Mcu_PllStatusType status = MCU_PLL_STATUS_UNDEFINED;


#if(MCU_PLL_USED == STD_OFF)
	status = MCU_PLL_LOCKED;
#else

	// Check if PLL is ready
	if (!(REG_READ32(RCC_CR_ADDR) & RCC_PLLRDY_MASK))
	{
		status = MCU_PLL_LOCKED;
	} else {
		status = MCU_PLL_UNLOCKED;
	}
	return status;
#endif
}

/* Distribute HSI/ HSE/ PLL via CFGR->SW1_SW0*/
FUNC( Std_ReturnType, MCU_CODE) Mcu_DistributePllClock( Mcu_ConfigType* pConfigPtr)
{

#if(MCU_CSS_USED == STD_ON)
	LpRCC_Reg->CR |= LpMcuClockConfigPtr->McuCRConfgVal.CSSON;
#endif
	REG_RMW32(RCC_CFGR_ADDR, RCC_SW_MASK,pConfigPtr->McuClockConfgSet->unSw);

	return E_OK;
}


FUNC(Mcu_ResetType, MCU_CODE) Mcu_GetResetReason(VAR( void, AUTOMATIC))
{
    /* Return value of the function. */
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    VAR(Mcu_ResetType, AUTOMATIC) eResetReason = MCU_RESET_UNDEFINED;
#else
    VAR(Mcu_ResetType, AUTOMATIC) eResetReason;
#endif

#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_HLDChecksEntry(MCU_GETRESETREASON_ID))
    {
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
        /* Get the reset reason. */
#if 0
        eResetReason = (Mcu_ResetType)Mcu_Ipw_GetResetReason();
#endif
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
        Mcu_HLDChecksExit( (Std_ReturnType)E_OK ,MCU_GETRESETREASON_ID);
    }
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/

    return (Mcu_ResetType)eResetReason;
}


