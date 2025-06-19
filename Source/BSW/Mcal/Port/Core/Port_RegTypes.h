#ifndef MCU_REGTYPES_H
#define MCU_REGTYPES_H

#include "Std_Types.h"


#define GPIO_BASEADDR              ((uint32)0x40020000)

/*                         GPIO_MODER                       */
/*                            OFFSET(0->4)                 */
/***********************************************************/
#define  GPIO_MODER_OFFSET_ADDR32          ((uint32)0x0000UL)


/***********************************************************/
/*                         GPIO_OTYPER                       */
/*                            OFFSET(0->4)                 */
/***********************************************************/
#define  GPIO_OTYPER_OFFSET_ADDR32          ((uint32)0x0004UL)


/***********************************************************/
/*                         GPIO_OSPEEDR                       */
/*                            OFFSET(0->4)                 */
/***********************************************************/
#define  GPIO_OSPEEDR_OFFSET_ADDR32         ((uint32)0x0008UL)


/***********************************************************/
/*                          GPIO_PUPDR                       */
/*                            OFFSET(0->4)                 */
/***********************************************************/
#define  GPIO_PUPDR_OFFSET_ADDR32          ((uint32)0x000CUL)


/***********************************************************/
/*                         GPIO_IDR                       */
/*                            OFFSET(0->4)                 */
/***********************************************************/
#define  GPIO_IDR_OFFSET_ADDR32          ((uint32)0x0010UL)


/***********************************************************/
/*                         GPIO_ODR                       */
/*                            OFFSET(0->4)                 */
/***********************************************************/
#define  GPIO_ODR_OFFSET_ADDR32          ((uint32)0x0014UL)


/***********************************************************/
/*                         GPIO_BSRR                       */
/*                            OFFSET(0->4)                 */
/***********************************************************/
#define  GPIO_BSRR_OFFSET_ADDR32          ((uint32)0x0018UL)


/***********************************************************/
/*                         GPIO_LCKR                       */
/*                            OFFSET(0->4)                 */
/***********************************************************/
#define  GPIO_LCKR_OFFSET_ADDR32          ((uint32)0x001CUL)

/***********************************************************/
/*                         GPIO_AFRL                       */
/*                            OFFSET(0->4)                 */
/***********************************************************/
#define  GPIO_AFRL_OFFSET_ADDR32          ((uint32)0x0020UL)

/***********************************************************/
/*                         GPIO_AFRH                       */
/*                            OFFSET(0->4)                 */
/***********************************************************/
#define  GPIO_AFRH_OFFSET_ADDR32          ((uint32)0x0024UL)




/* @violates @ref Reg_eSys_Gpio_H_REF_1 Function-like macro defined */
#define GPIO_MODER_ADDR32(port)		((uint32)(GPIO_BASEADDR + GPIO_MODER_OFFSET_ADDR32 + ((uint32)(port) * (uint32)0x0400)))
#define GPIO_MODER_BASEMASK			(uint32)(0x00000003)
#define GPIO_MODER_MASK(pin)		(uint32)(GPIO_MODER_BASEMASK << ((uint32)0x02*(uint32)(pin)))
#define GPIO_MODER_VAL(pin, value)	(uint32)(value << ((uint32)0x02*(uint32)(pin)))


/* @violates @ref Reg_eSys_Gpio_H_REF_1 Function-like macro defined */
#define GPIO_OTYPER_ADDR32(port)    ((uint32)(GPIO_BASEADDR + GPIO_OTYPER_OFFSET_ADDR32 + ((uint32)(port) * (uint32)0x0400) ))
#define GPIO_OTYPER_BASEMASK        (uint32)(0x00000001)
#define GPIO_OTYPER_MASK(pin)       ((uint32)(GPIO_OTYPER_BASEMASK << (pin)))
#define GPIO_OTYPER_VAL(pin, value)	(uint32)(value << ((uint32)(pin)))

/* @violates @ref Reg_eSys_Gpio_H_REF_1 Function-like macro defined */
#define GPIO_OSPEEDR_ADDR32(port)   ((uint32)(GPIO_BASEADDR + GPIO_OSPEEDR_OFFSET_ADDR32 + ((uint32)(port) * (uint32)0x0400) ))
#define GPIO_OSPEEDR_BASEMASK       (uint32)(0x00000003)
#define GPIO_OSPEEDR_Mask(pin)      (uint32)(GPIO_OSPEEDR_BASEMASK << ((uint32)0x02*(uint32)(pin)))
#define GPIO_OSPEEDR_VAL(pin, value)(uint32)(value << ((uint32)0x02*(uint32)(pin)))

/* @violates @ref Reg_eSys_Gpio_H_REF_1 Function-like macro defined */
#define GPIO_PUPDR_ADDR32(port)     ((uint32)(GPIO_BASEADDR + GPIO_PUPDR_OFFSET_ADDR32 + ((uint32)(port) * (uint32)0x0400) ))
#define GPIO_PUPDR_BASEMASK         (uint32)(0x00000003)
#define GPIO_PUPDR_MASK(pin)		(uint32)(GPIO_PUPDR_BASEMASK << ((uint32)0x02*(uint32)(pin)))
#define GPIO_PUPDR_VAL(pin, value)	(uint32)(value << ((uint32)0x02*(uint32)(pin)))


#define GPIO_IDR_ADDR32(port)       ((uint32)(GPIO_BASEADDR + GPIO_IDR_OFFSET_ADDR32 + ((uint32)(port) * (uint32)0x0400) ))
#define GPIO_IDR_BASEMASK		    (uint32)(0x0000FFFF)
#define GPIO_IDR_MASK(pin)		    (uint32)(GPIO_IDR_BASEMASK & ((uint32)(1 << (uint32)(pin))))
#define GPIO_IDR_VAL(pin, value)	(uint32)(value << ((uint32)(pin)))


/* @violates @ref Reg_eSys_Gpio_H_REF_1 Function-like macro defined */
#define GPIO_ODR_ADDR32(port)       ((uint32)(GPIO_BASEADDR + GPIO_ODR_OFFSET_ADDR32 + ((uint32)(port) * (uint32)0x0400) ))
#define GPIO_ODR_BASEMASK		    (uint32)(0x00000001)
#define GPIO_ODR_MASK(pin)		    (uint32)(GPIO_ODR_BASEMASK << ((uint32)(1 << (uint32)(pin))))
#define GPIO_ODR_VAL(pin, value)	(uint32)(value << ((uint32)(pin)))

/* @violates @ref Reg_eSys_Gpio_H_REF_1 Function-like macro defined */
#define GPIO_BSRR_ADDR32(port)      ((uint32)(GPIO_BASEADDR + GPIO_BSRR_OFFSET_ADDR32 + ((uint32)(port) * (uint32)0x0400) ))
#define GPIO_BSRR_BASEMASK		    (uint32)(0x00000001)
#define GPIO_BSRR_MASK(pin)		    (uint32)(GPIO_BSRR_BASEMASK << ((uint32)(1 << (uint32)(pin))))
#define GPIO_BSRR_SET(pin, value)	(uint32)(value << ((uint32)(pin)))
#define GPIO_BSRR_RESET(pin, value)	(uint32)((value << ((uint32)(pin))) << 16)

/* @violates @ref Reg_eSys_Gpio_H_REF_1 Function-like macro defined */
#define GPIO_LCKR_ADDR32(port)      ((uint32)(GPIO_BASEADDR + GPIO_LCKR_OFFSET_ADDR32 + ((uint32)(port) * (uint32)0x0400) ))
#define GPIO_LCKR_BASEMASK		    (uint32)(0x00000001)
#define GPIO_LCKR_MASK(pin)		    (uint32)(GPIO_LCKR_BASEMASK << ((uint32)(1 << (uint32)(pin))))
#define GPIO_LCKR_VAL(pin, value)	(uint32)(value << ((uint32)0x02*(uint32)(pin)))


/* @violates @ref Reg_eSys_Gpio_H_REF_1 Function-like macro defined */
#define GPIO_AFRL_ADDR32(port)      ((uint32)(GPIO_BASEADDR + GPIO_AFRL_OFFSET_ADDR32 + ((uint32)(port) * (uint32)0x0400) ))
#define GPIO_AFRL_BASEMASK		    (uint32)(0x0000000F)
#define GPIO_AFRL_MASK(pin)		    (uint32)(GPIO_AFRL_BASEMASK << ((uint32)0x04*(uint32)(pin)))
#define GPIO_AFRL_VAL(pin, value)	(uint32)(value << ((uint32)0x04*(uint32)(pin)))


/* @violates @ref Reg_eSys_Gpio_H_REF_1 Function-like macro defined */
#define GPIO_AFRH_ADDR32(port)      ((uint32)(GPIO_BASEADDR + GPIO_AFRH_OFFSET_ADDR32 + ((uint32)(port) * (uint32)0x0400) ))
#define GPIO_AFRH_BASEMASK		    (uint32)(0x0000000F)
#define GPIO_AFRH_MASK(pin)		    (uint32)(GPIO_AFRH_BASEMASK << ((uint32)0x04*(uint32)(pin - 0x08)))
#define GPIO_AFRH_VAL(pin, value)	(uint32)(value << ((uint32)0x04*(uint32)(pin-0x08)))





#endif /* MCU_REGTYPES_H */
