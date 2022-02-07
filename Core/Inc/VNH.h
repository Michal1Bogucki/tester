/*
 * VNH.h
 *	This file provides code for the configuration
 *  of the motors instances
 *
 *  Created on: 5 lut 2022
 *      Author: Boguc
 */

#ifndef INC_VNH_H_
#define INC_VNH_H_

#include "main.h"
#include "adc.h"
#include "tim.h"

extern VNH_HANDLE hVNH1;
extern VNH_HANDLE hVNH2;
extern uint32_t adc_dma_buffer[2];

void Motors_Init(void);



#endif /* INC_VNH_H_ */
