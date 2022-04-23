#include "pid_config.h"


	float pid1_input;
	float pid1_output;
	float pid1_setpoint;
	PID_handler PIDh1;
	float pid2_input;
	float pid2_output;
	float pid2_setpoint;
	PID_handler PIDh2;

void def_pid_1(){
	Pid_Create(&PIDh1);
	PIDh1.Kp=0.05;
	PIDh1.Ki=10;
	PIDh1.Kd=0.1;

	pid1_setpoint=800;
	PIDh1.omin=0;
	PIDh1.omax=100;
	PIDh1.I_max=50;
	PIDh1.I_mini=-50;

	PIDh1.sampletime=(float)1/1000;
	PIDh1.input=&pid1_input;
	PIDh1.output=&pid1_output;
	PIDh1.setpoint=&pid1_setpoint;

}

void def_pid_2(){
	Pid_Create(&PIDh2);
	PIDh2.Kp=0.05;
	PIDh2.Ki=10;
	PIDh2.Kd=0.1;

	pid2_setpoint=800;
	PIDh2.omin=0;
	PIDh2.omax=100;
	PIDh2.I_max=50;
	PIDh2.I_mini=-50;

	PIDh2.sampletime=(float)1/1000;
	PIDh2.input=&pid2_input;
	PIDh2.output=&pid2_output;
	PIDh2.setpoint=&pid2_setpoint;

}

void test_pid(PID_handler* hPID){

	pid1_input=0;
	pid1_setpoint=10;
	pid_Enable(hPID);

	pid_compute(hPID);

	pid_compute(hPID);

	pid_compute(hPID);

	pid_compute(hPID);



}
