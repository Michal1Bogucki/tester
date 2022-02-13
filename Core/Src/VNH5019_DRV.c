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
	hVNH->pol_reverse=0;
	// Start PWM
	VNH_DisableCurSens(hVNH);
	VNH_Disable(hVNH);
	HAL_TIM_PWM_Start(hVNH->PWM_sig.timh,hVNH->PWM_sig.Chanel);
	VNH_SetPWM(hVNH,0);

	VNH_SetDir(hVNH,dir_LL);



}

void VNH_Disable(VNH_HANDLE* hVNH){
	HAL_GPIO_WritePin(hVNH->ENA_sig.gpioport, hVNH->ENA_sig.gpiopin, GPIO_PIN_RESET);
	VNH_SetIOLL(hVNH);


}

void VNH_Enable(VNH_HANDLE* hVNH){
	HAL_GPIO_WritePin(hVNH->ENA_sig.gpioport, hVNH->ENA_sig.gpiopin, GPIO_PIN_RESET);
	VNH_SetDir(hVNH,hVNH->dir);
}


void VNH_SetIOHL(VNH_HANDLE*  hVNH){

	HAL_GPIO_WritePin(hVNH->MA_sig.gpioport, hVNH->MA_sig.gpiopin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(hVNH->MB_sig.gpioport, hVNH->MB_sig.gpiopin, GPIO_PIN_SET);
	//hVNH->dir=dir_HL;

}

void VNH_SetIOLH(VNH_HANDLE*  hVNH){
	HAL_GPIO_WritePin(hVNH->MA_sig.gpioport, hVNH->MA_sig.gpiopin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(hVNH->MB_sig.gpioport, hVNH->MB_sig.gpiopin, GPIO_PIN_RESET);
	//hVNH->dir=dir_LH;
}

void VNH_SetIOHH(VNH_HANDLE*  hVNH){
	HAL_GPIO_WritePin(hVNH->MA_sig.gpioport, hVNH->MA_sig.gpiopin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(hVNH->MB_sig.gpioport, hVNH->MB_sig.gpiopin, GPIO_PIN_SET);
	//hVNH->dir=dir_HH;
}

void VNH_SetIOLL(VNH_HANDLE*  hVNH){

	HAL_GPIO_WritePin(hVNH->MA_sig.gpioport, hVNH->MA_sig.gpiopin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(hVNH->MB_sig.gpioport, hVNH->MB_sig.gpiopin, GPIO_PIN_RESET);
	//hVNH->dir=dir_LL;
}

void VNH_TogleDir(VNH_HANDLE* hVNH){

	switch(hVNH->dir){
	case dir_HL:
		VNH_SetDir(hVNH,dir_LH);

		break;
	case dir_LH:
		VNH_SetDir(hVNH,dir_HL);
		break;
	case dir_LL:
		VNH_SetDir(hVNH,dir_HH);
		break;
	case dir_HH:
		VNH_SetDir(hVNH,dir_LL);
		break;
	default:
		VNH_SetDir(hVNH,dir_LL);
		break;
	}
}

void VNH_SetDir(VNH_HANDLE* hVNH ,VNH_dir dir){
	if (hVNH->pol_reverse){
		switch(dir){
		case dir_HL:
			VNH_SetIOHL(hVNH);
			hVNH->dir=dir_HL;
			break;

		case dir_LH:
			VNH_SetIOLH(hVNH);
			hVNH->dir=dir_LH;
			break;
		case dir_HH:
			VNH_SetIOHH(hVNH);
			hVNH->dir=dir_HH;
			break;
		case dir_LL:
			VNH_SetIOLL(hVNH);
			hVNH->dir=dir_LL;
			break;
		default:
			VNH_SetIOLL(hVNH);
			hVNH->dir=dir_LL;
			break;
		}
	}else{
		switch(dir){
		case dir_LH:
			VNH_SetIOHL(hVNH);
			hVNH->dir=dir_LH;
			break;

		case dir_HL:
			VNH_SetIOLH(hVNH);
			hVNH->dir=dir_HL;
			break;
		case dir_HH:
			VNH_SetIOHH(hVNH);
			hVNH->dir=dir_HH;
			break;
		case dir_LL:
			VNH_SetIOLL(hVNH);
			hVNH->dir=dir_LL;
			break;
		default:
			VNH_SetIOLL(hVNH);
			hVNH->dir=dir_LL;
			break;
		}
	}

}

void VNH_Reverse_pol(VNH_HANDLE* hVNH){
	if (hVNH->pol_reverse<1){
		hVNH->pol_reverse=1;
		VNH_SetDir(hVNH,hVNH->dir);

	}else{
		hVNH->pol_reverse=0;
		VNH_SetDir(hVNH,hVNH->dir);
	}
}

void VNH_SetPWM(VNH_HANDLE* hVNH, uint8_t duty){
	if (duty>100) duty=100;
 	hVNH->PWM_dutycicle=duty;

	 //__HAL_TIM_SET_COMPARE(hVNH->PWM_sig.timh,hVNH->PWM_sig.Chanel,(uint8_t)__HAL_TIM_GET_AUTORELOAD(hVNH->PWM_sig.timh)*duty/100);
 	__HAL_TIM_SET_COMPARE(hVNH->PWM_sig.timh,hVNH->PWM_sig.Chanel,(uint8_t)__HAL_TIM_GET_AUTORELOAD(hVNH->PWM_sig.timh)*duty/100);
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
