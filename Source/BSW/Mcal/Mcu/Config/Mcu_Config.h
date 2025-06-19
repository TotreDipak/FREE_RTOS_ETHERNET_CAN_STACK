#ifndef MCU_CFG_H
#define MCU_CFG_H
typedef uint32 Mcu_ModeType;

#define McuModeSettingConf_0   ((Mcu_ModeType)0U)
#define McuConf_McuModeSettingConf_McuModeSettingConf_0   ((Mcu_ModeType)0U)

/*PwrCRConfgVal*/
#define MCU_VOS_SCALE_USED   	STD_ON
#define MCU_FPDS_USED 		    STD_OFF
#define MCU_DBP_USED 			STD_OFF
#define MCU_PLS_USED 		    STD_OFF
#define MCU_PVDE_USED 			STD_OFF
#define MCU_PDDS_USED 			STD_OFF
#define MCU_LPDS_USED 		    STD_OFF

/*PwrCSRConfgVal*/
#define MCU_BRE_USED   	        STD_OFF
#define MCU_EWUP_USED 		    STD_OFF


/*FLASHACRConfgVal*/
#define MCU_DCRST_USED 		    STD_OFF
#define MCU_ICRST_USED 			STD_OFF
#define MCU_LATENCY_USED 	    STD_ON
#define MCU_DCEN_USED 			STD_ON
#define MCU_ICEN_USED 			STD_ON
#define MCU_PRFTEN_USED 	    STD_ON


/*McuCRConfgVal*/

#define MCU_PLLI2S_USED 		STD_OFF
#define MCU_PLL_USED 			STD_ON
#define MCU_CSS_USED 			STD_OFF
#define MCU_HSE_USED 			STD_ON
#define MCU_HSITRIM_USED 		STD_OFF
#define MCU_HSI_USED 			STD_OFF

/*McuPLLCFGRConfgVal*/

#define MCU_PLLM_USED 			STD_ON
#define MCU_PLLN_USED 			STD_ON
#define MCU_PLLP_USED 			STD_ON
#define MCU_PLLSRC_USED		    STD_ON
#define MCU_PLLQ_USED 			STD_ON

/*McuCFGRConfgVal*/
#define MCU_MCO2_USED    		STD_OFF
#define MCU_I2SSRC_USED     	STD_OFF
#define MCU_MCO1_USED       	STD_OFF
#define MCU_RTC_USED  			STD_OFF

/*McuCIRConfgVal*/
#define PLLI2SRDYIELI_USED      STD_OFF
#define PLLRDYIELI_USED         STD_OFF
#define HSERDYIEI_USED          STD_OFF
#define HSIRDYIEI_USED          STD_OFF
#define LSERDYIEI_USED          STD_OFF
#define LSIRDYIEI_USED          STD_OFF

/*McuAHB1ENRConfgVal*/
#define MCU_USB_OTG_USED
#define MCU_ETHMAC_USED
#define MCU_DMA_USED
#define MCU_BKP_SRAM_USED
#define MCU_CCM_DATA_RAM_USED
#define MCU_CRC_USED
#define MCU_GPIO_USED

/*McuAHB1ENRConfgVal*/
#define OTGHSULPIEN_USED              STD_OFF
#define OTGHSEN_USED                  STD_OFF
#define ETHMACPTPEN_USED              STD_OFF
#define ETHMACRXEN_USED               STD_OFF
#define ETHMACTXEN_USED               STD_OFF
#define ETHMACEN_USED                 STD_OFF
#define DMA2EN_USED                   STD_OFF
#define DMA1EN_USED                   STD_OFF
#define CCMDATARAMEN_USED             STD_OFF
#define BKPSRAMEN_USED                STD_OFF
#define CRCEN_USED                    STD_OFF
#define GPIOIEN_USED                  STD_OFF
#define GPIOHEN_USED                  STD_OFF
#define GPIOGEN_USED                  STD_OFF
#define GPIOFEN_USED                  STD_OFF
#define GPIOEEN_USED                  STD_OFF
#define GPIODEN_USED                  STD_ON
#define GPIOCEN_USED                  STD_ON
#define GPIOBEN_USED                  STD_OFF
#define GPIOAEN_USED                  STD_OFF


/*McuAHB2ENRConfgVal*/
#define OTGFSEN_USED                  STD_OFF
#define RNGEN_USED                    STD_OFF
#define HASHEN_USED                   STD_OFF
#define CRYPEN_USED                   STD_OFF
#define DCMIEN_USED                   STD_OFF


/*McuAHB3ENRConfgVal*/
#define FSMCEN_USED                   STD_OFF


/*McuAPB1ENRConfgVal*/

#define MCU_DAC_USED
#define MCU_PWR_USED
#define MCU_CAN_USED
#define MCU_I2C_USED
#define MCU_UART_USED
#define MCU_USART_USED
#define MCU_SPI_USED
#define MCU_WWDG_USED
#define MCU_TIM_USED



/*McuAPB1ENRConfgVal*/
#define DACEN_USED                    STD_OFF
#define PWREN_USED                    STD_ON
#define CAN2EN_USED                   STD_OFF
#define CAN1EN_USED                   STD_ON
#define I2C3EN_USED                   STD_OFF
#define I2C2EN_USED                   STD_OFF
#define I2C1EN_USED                   STD_OFF
#define UART5EN_USED                  STD_OFF
#define UART4EN_USED                  STD_OFF
#define USART3EN_USED                 STD_OFF
#define USART2EN_USED                 STD_OFF
#define SPI3EN_USED                   STD_OFF
#define SPI2EN_USED                   STD_OFF
#define WWDGEN_USED                   STD_OFF
#define TIM14EN_USED                  STD_OFF
#define TIM13EN_USED                  STD_OFF
#define TIM12EN_USED                  STD_OFF
#define TIM7EN_USED                   STD_OFF
#define TIM6EN_USED                   STD_OFF
#define TIM5EN_USED                   STD_ON
#define TIM4EN_USED                   STD_OFF
#define TIM3EN_USED                   STD_OFF
#define TIM2EN_USED                   STD_ON

/*McuAPB2ENRConfgVal*/


#define MCU_TIM_USED
#define MCU_SYS_USED
#define MCU_SPI_USED
#define MCU_SDI_USED
#define MCU_ADC_USED
#define MCU_USART_USED


/*McuAPB2ENRConfgVal*/
#define TIM11EN_USED                STD_OFF
#define TIM10EN_USED                STD_OFF
#define TIM9EN_USED                 STD_OFF
#define SYSCFGEN_USED               STD_ON
#define SPI1EN_USED                 STD_OFF
#define SDIOEN_USED                 STD_OFF
#define ADC3EN_USED                 STD_OFF
#define ADC2EN_USED                 STD_OFF
#define ADC1EN_USED                 STD_OFF
#define USART6EN_USED               STD_OFF
#define USART1EN_USED               STD_OFF
#define TIM8EN_USED                 STD_OFF
#define TIM1EN_USED                 STD_OFF

/*McuBDCRConfgVal*/
#define BDRST_USED                  STD_OFF
#define RTCEN_USED                  STD_OFF
#define RTCSEL_USED                 STD_OFF
#define LSEBYP_USED                 STD_OFF
#define LSEON_USED                  STD_OFF


/*McuCSRConfgVal*/

#define LSION_USED                  STD_OFF


/*McuSSCGRConfgVal*/
#define SSCGEN_USED                 STD_OFF
#define SPREADSEL_USED              STD_OFF
#define INCSTEP_USED                STD_OFF
#define MODPER_USED                 STD_OFF


/*McuPLLI2SCFGRConfgVal*/
#define PLLI2SR_USED                STD_OFF
#define PLLI2SN_USED                STD_OFF

typedef enum {
    RESET_NONE = 0,         // No reset
    RESET_POWER_ON,         // Power-on reset (POR)
    RESET_BROWN_OUT,        // Brown-out reset (BOR)
    RESET_WATCHDOG,         // Watchdog timer reset (WDT)
    RESET_SOFTWARE,         // Software reset (SWR)
    RESET_EXTERNAL,         // External reset (NRST pin)
    RESET_BOOTLOADER,       // Bootloader reset (USER button or NRST pin with BOOT0 tied to VDD)
    RESET_DEBUG,            // Debug reset (debugger or NRST pin with BOOT0 tied to GND)
	MCU_RESET_UNDEFINED,
    RESET_MAX               // Maximum number of reset types
} Mcu_ResetType;


#endif /* MCU_CFG_H */
