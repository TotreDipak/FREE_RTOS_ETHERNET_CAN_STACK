#include "Std_Types.h"
#include "Dio_Cfg.h"

static const Dio_PinConfigType Dio_aPinConfigDefault[]=
{
		/*Pin*/ /*GpioID*/
		{ 12,   GPIO_DIO_D},
};


CONST(Dio_ConfigType, PORT_CONST) Dio_Config[1] =
{
		{
				1,
				Dio_aPinConfigDefault
		}
};

