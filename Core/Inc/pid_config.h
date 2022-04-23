/*
 * pid_config.h
 *
 *  Created on: Feb 19, 2022
 *      Author: Boguc
 */

#ifndef INC_PID_CONFIG_H_
#define INC_PID_CONFIG_H_

#include "PID_lib.h"
extern PID_handler PIDh1;
extern PID_handler PIDh2;
extern float pid1_setpoint;
extern float pid2_setpoint;

void def_pid_1();
void def_pid_2();
void test_pid(PID_handler*);








#endif /* INC_PID_CONFIG_H_ */
