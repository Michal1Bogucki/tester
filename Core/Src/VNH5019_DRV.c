/*
 * VNH5019_DRV.c
 *
 *  Created on: 30 paź 2021
 *      Author: Boguc
 */

#include "VNH5019_DRV.h"

/*
 * TO DO
 *
 *
 *
 */

void VNH_Init(VNH_HANDLE* hVNH){

	if(hVNH==NULL){
		return;
	}
	// Start PWM
	VNH_DisableCurSens(hVNH);
	VNH_Disable(hVNH);
	HAL_TIM_PWM_Start(hVNH->PWM_sig.timh,hVNH->PWM_sig.Chanel);
	VNH_SetPWM(hVNH,0);

	VNH_SetDirLL(hVNH);




}

void VNH_Disable(VNH_HANDLE* hVNH){
	HAL_GPIO_WritePin(hVNH->ENA_sig.gpioport, hVNH->ENA_sig.gpiopin, GPIO_PIN_RESET);
}

void VNH_Enable(VNH_HANDLE* hVNH){
	HAL_GPIO_WritePin(hVNH->ENA_sig.gpioport, hVNH->ENA_sig.gpiopin, GPIO_PIN_RESET);
}


void VNH_SetDirHL(VNH_HANDLE*  hVNH){
	HAL_GPIO_WritePin(hVNH->MA_sig.gpioport, hVNH->MA_sig.gpiopin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(hVNH->MB_sig.gpioport, hVNH->MB_sig.gpiopin, GPIO_PIN_SET);
	hVNH->dir=dir_HL;

}

void VNH_SetDirLH(VNH_HANDLE*  hVNH){
	HAL_GPIO_WritePin(hVNH->MA_sig.gpioport, hVNH->MA_sig.gpiopin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(hVNH->MB_sig.gpioport, hVNH->MB_sig.gpiopin, GPIO_PIN_RESET);
	hVNH->dir=dir_LH;
}

void VNH_SetDirHH(VNH_HANDLE*  hVNH){
	HAL_GPIO_WritePin(hVNH->MA_sig.gpioport, hVNH->MA_sig.gpiopin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(hVNH->MB_sig.gpioport, hVNH->MB_sig.gpiopin, GPIO_PIN_SET);
	hVNH->dir=dir_HH;
}

void VNH_SetDirLL(VNH_HANDLE*  hVNH){

	HAL_GPIO_WritePin(hVNH->MA_sig.gpioport, hVNH->MA_sig.gpiopin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(hVNH->MB_sig.gpioport, hVNH->MB_sig.gpiopin, GPIO_PIN_RESET);
	hVNH->dir=dir_LL;
}

void VNH_TogleDir(VNH_HANDLE* hVNH){
	switch(hVNH->dir){
	case dir_HL:
		VNH_SetDirLH(hVNH);
		break;

	case dir_LH:
		VNH_SetDirHL(hVNH);
		break;
	default:
		VNH_SetDirLL(hVNH);
		break;
	}
}

void VNH_SetDir(VNH_HANDLE* hVNH ,VNH_dir dir){

	switch(dir){
	case dir_HL:
		VNH_SetDirHL(hVNH);
		break;

	case dir_LH:
		VNH_SetDirLH(hVNH);
		break;
	default:
		VNH_SetDirLL(hVNH);
		break;
	}
}

void VNH_SetPWM(VNH_HANDLE* hVNH, uint8_t duty){

	hVNH->PWM_dutycicle=duty;
	 __HAL_TIM_SET_COMPARE(hVNH->PWM_sig.timh,hVNH->PWM_sig.Chanel,__HAL_TIM_GET_AUTORELOAD(hVNH->PWM_sig.timh)*duty/0xff);
}

void VNH_DisableCurSens(VNH_HANDLE* hVNH){

	HAL_GPIO_WritePin(hVNH->CS_dis_sig.gpioport,hVNH->CS_dis_sig.gpiopin,GPIO_PIN_SET);
}

void VNH_EnableCurSens(VNH_HANDLE* hVNH){

	HAL_GPIO_WritePin(hVNH->CS_dis_sig.gpioport,hVNH->CS_dis_sig.gpiopin,GPIO_PIN_RESET);
}

float VNH_GetCurValue(VNH_HANDLE* hVNH){

	return (uint32_t)(*hVNH->CS_sig/hVNH->CS_Rez_Val);
}
