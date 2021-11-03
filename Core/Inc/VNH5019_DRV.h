/*
 * VNH5019_DRV.h
 *
 *  Created on: Oct 25, 2021
 *      Author: Boguc
 */

#ifndef INC_VNH5019_DRV_H_
#define INC_VNH5019_DRV_H_
#include <PerifPrimitives.h>

typedef enum{
	dir_HH,
	dir_HL,
	dir_LH,
	dir_LL
}VNH_dir;

typedef struct{
PRIM_PWM PWM_sig;
PRIM_IOPIN MA_sig;
PRIM_IOPIN MB_sig;
PRIM_IOPIN CS_dis_sig;
PRIM_ADC CS_sig;
uint16_t CS_Rez_Val;
VNH_dir dir;


uint32_t ramp_steps;
uint32_t ramp_curentstep;
float ramp_delta;


uint8_t PWM_dutycicle;

}VNH_HANDLE;

void VNH_Init(VNH_HANDLE*);

void VNH_SetDirHL(VNH_HANDLE*);
void VNH_SetDirLH(VNH_HANDLE*);

void VNH_SetDirHH(VNH_HANDLE*);
void VNH_SetDirLL(VNH_HANDLE*);
void VNH_TogleDir(VNH_HANDLE*);

void VNH_SetDir(VNH_HANDLE*,VNH_dir);


void VNH_SetPWM(VNH_HANDLE*, uint8_t);

void VNH_SetRamp(VNH_HANDLE*, uint8_t,uint32_t);

void VNH_ResetRamp(VNH_HANDLE*);

void VNH_StateUpdateCallBack(VNH_HANDLE*,uint32_t);




#endif /* INC_VNH5019_DRV_H_ */
