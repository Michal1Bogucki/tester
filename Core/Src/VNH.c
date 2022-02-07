/*
 * VNH.c
 *
 *  Created on: 5 lut 2022
 *      Author: Boguc
 */

#include "VNH.h"

VNH_HANDLE hVNH1;
VNH_HANDLE hVNH2;
uint32_t adc_dma_buffer[2];

void Motors_Init(void){
	// IO Pins set
	PRIM_IOPIN IOpin;
	//M1
	IOpin.gpiopin=M1_ENA_Pin;
	IOpin.gpioport=M1_ENA_GPIO_Port;
	hVNH1.ENA_sig=IOpin;

	IOpin.gpiopin=M1_INA_Pin;
	IOpin.gpioport=M1_INA_GPIO_Port;
	hVNH1.MA_sig=IOpin;

	IOpin.gpiopin=M1_INB_Pin;
	IOpin.gpioport=M1_INB_GPIO_Port;
	hVNH1.MB_sig=IOpin;

	IOpin.gpiopin=CMES_ENA_Pin;
	IOpin.gpioport=CMES_ENA_GPIO_Port;

	hVNH1.CS_dis_sig=IOpin;
	//M2
	IOpin.gpiopin=M2_ENA_Pin;
	IOpin.gpioport=M2_ENA_GPIO_Port;
	hVNH2.ENA_sig=IOpin;

	IOpin.gpiopin=M2_INA_Pin;
	IOpin.gpioport=M2_INA_GPIO_Port;
	hVNH2.MA_sig=IOpin;

	IOpin.gpiopin=M2_INB_Pin;
	IOpin.gpioport=M2_INB_GPIO_Port;
	hVNH2.MB_sig=IOpin;

	IOpin.gpiopin=CMES_ENA_Pin;
	IOpin.gpioport=CMES_ENA_GPIO_Port;

	hVNH2.CS_dis_sig=IOpin;

	//PWM SET
	//M1
	PRIM_PWM PWMpin;

	PWMpin.Chanel=TIM_CHANNEL_1;
	PWMpin.timh=&htim17;
	hVNH1.PWM_sig=PWMpin;
	//M2
	PWMpin.Chanel=TIM_CHANNEL_4;
	PWMpin.timh=&htim2;
	hVNH2.PWM_sig=PWMpin;

	//ADC SET
	HAL_ADCEx_Calibration_Start(&hadc1,ADC_SINGLE_ENDED);
	while (HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_BUSY_INTERNAL)){
		HAL_Delay(1);
	}

	HAL_ADC_Start_DMA(&hadc1,adc_dma_buffer,2);


	hVNH1.CS_sig=&adc_dma_buffer[0];
	hVNH2.CS_sig=&adc_dma_buffer[1];




}