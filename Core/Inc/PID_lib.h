#ifndef __PID_lib__
#define  __PID_lib__
#include <stdbool.h>
#include <stdint.h>




#ifdef	__cplusplus
extern "C" {
#endif

enum pid_control_directions {
	E_PID_DIRECT,
	E_PID_REVERSE,
};
typedef enum{
	PID_asynchronous,
	PID_synchronous
}PID_mode;



typedef enum {
	PID_NieedCompute,
	PID_PreCompute,
	PID_Disable,
	PID_NotInit
}PID_status;


/**
 * Structure that holds PID all the PID controller data, multiple instances are
 * posible using different structures for each controller
 */
typedef struct{
	// Input, output and setpoint
	float * input; //!< Current Process Value
	float * output; //!< Corrective Output from PID Controller
	float * setpoint; //!< Controller Setpoint
	// Tuning parameters
	float Kp; //!< Stores the gain for the Proportional term
	float Ki; //!< Stores the gain for the Integral term
	float Kd; //!< Stores the gain for the Derivative term
	// Output minimum and maximum values
	float omin; //!< Maximum value allowed at the output
	float omax; //!< Minimum value allowed at the output
	// Variables for PID algorithm
	float I_accum; //!< Accumulator for integral term
	float D_last; //!< Last input value for differential term
	float I_max;
	float I_mini;

	float lasttime; //!< Stores the time when the control loop ran last time
	float sampletime; //!< Defines the PID sample time
	PID_status status;
	PID_mode mode;

}PID_handler;


/*-------------------------------------------------------------*/
/*		Function prototypes				*/
/*-------------------------------------------------------------*/
	PID_handler* Pid_Create(PID_handler*);
	void pid_Init(PID_handler* pid, float kp, float ki, float kd);


	enum PID_status pid_Status(PID_handler pid);


	void pid_compute(PID_handler* pid);


	void pid_tune(PID_handler* , float , float ki, float kd);


	void pid_sample(PID_handler* , uint32_t time);


	void pid_out_limits(PID_handler* , float min, float max);

	void pid_I_limits(PID_handler* , float min, float max);

	void pid_Enable(PID_handler* );

	void pid_Disable(PID_handler* );

	void pid_reset_I(PID_handler*);

	float pid_get_time_ms();




#ifdef	__cplusplus
}
#endif

#endif // __PID_lib__
