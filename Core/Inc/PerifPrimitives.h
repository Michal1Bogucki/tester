
#ifndef INC_PERIFPRIM_H_
#define INC_PERIFPRIM_H_

#include <stm32f3xx_hal.h>
typedef struct{
	TIM_HandleTypeDef* timh;
	uint32_t Chanel;
}PRIM_PWM;

typedef struct{
	GPIO_TypeDef* gpioport;
	uint16_t gpiopin;
}PRIM_IOPIN;

typedef struct{
	// TO DO delete this shit
	ADC_HandleTypeDef adc;

}PRIM_ADC;


#endif
