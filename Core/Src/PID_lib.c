#include "PID_lib.h"

PID_handler* Pid_Create(PID_handler* hPID){
	hPID->I_max=(float)0xffff;
	hPID->I_mini=(float)-0xffff;
	hPID->Kd=0;
	hPID->Ki=0;
	hPID->Kp=0;
	hPID->omax=(float)0xffff;
	hPID->omin=(float)-0xffff;
	hPID->status=PID_NotInit;
	hPID->input=0;
	hPID->output=0;
	hPID->mode=PID_synchronous;
	return hPID;
}



void pid_Init(PID_handler* hPID, float kp, float ki, float kd)
{

	if (hPID->input==0||hPID->output==0) return;


	pid_out_limits(hPID,hPID->omin ,hPID->omax);
	pid_I_limits(hPID,hPID->I_max,hPID->I_mini);
	if(hPID->mode==PID_synchronous){
	hPID->D_last=*(hPID->input);

	pid_tune(hPID, kp, ki, kd);


	}else{
	hPID->lasttime=pid_get_time_ms();
	}






}



bool pid_status(PID_handler* hPID)
{
	return hPID->status;
}

void pid_compute(PID_handler* hPID)
{
	if (hPID->status==PID_Disable||hPID->status==PID_NotInit) return;
	if (hPID->mode==PID_synchronous){

		float pid_error = (*(hPID->setpoint))-(*(hPID->input));
		float prop= pid_error*hPID->Kp;

		hPID->I_accum=(pid_error)*hPID->sampletime;
		if (hPID->I_accum>hPID->I_max) hPID->I_accum=hPID->I_max;
		if (hPID->I_accum<hPID->I_mini) hPID->I_accum=hPID->I_mini;
		float integr = hPID->I_accum*hPID->Ki;

		float deriv=(*(hPID->input)-hPID->D_last)*hPID->Kp;
		hPID->D_last=*hPID->input;

		float out= prop+integr+deriv;
		if (out>hPID->omax) out=hPID->omax;
		if (out<hPID->omin) out=hPID->omin;

		*hPID->output=out;

	}




	

}

void pid_tune(PID_handler* hPID, float kp, float ki, float kd)
{
	// Check for validity
	if (kp < 0 || ki < 0 || kd < 0)
		return;
	



	hPID->Kp = kp;
	hPID->Ki = ki;
	hPID->Kd = kd / hPID->sampletime;


}


void pid_out_limits(PID_handler* pid, float min, float max)
{
	if (min >= max) return;
	pid->omin = min;
	pid->omax = max;
	//Adjust output to new limits

		if (*(pid->output) > pid->omax)
			*(pid->output) = pid->omax;
		else if (*(pid->output) < pid->omin)
			*(pid->output) = pid->omin;

}

void pid_I_limits(PID_handler* pid, float min, float max)
{
	if (min >= max) return;
	pid->I_mini = min;
	pid->I_max = max;
	//Adjust output to new limits



		if (pid->I_accum > pid->I_max)
			pid->I_accum = pid->I_max;
		else if (pid->I_accum < pid->I_mini)
			pid->I_accum = pid->I_mini;
}




__attribute__((weak)) uint32_t pid_get_tick(){
	return 0;
}
