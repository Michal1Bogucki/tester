/*
 * gui.h
 *
 *  Created on: Oct 11, 2021
 *      Author: Boguc
 */

#ifndef INC_GUI_H_
#define INC_GUI_H_

#include <stdint.h>
#include <stdio.h>
typedef enum {
	GUI_STATE_START,
	GUI_STATE_IDLE
}GUI_SCREEN_STATE_def;

typedef enum{
	GUI_EVENT_IDLE,
	GUI_EVENT_BUTONPRESS,
	GUI_EVENT_NOBINC,
	GUI_EVENT_NOBDEC,
	GUI_EVENT_TIMEOUT

}GUI_EVENT_def;



typedef struct{
	GUI_SCREEN_STATE_def Current_Screen;
	uint16_t  cusor_pos;
	GUI_EVENT_def Last_Event;
}GUI_Handle;

void GUI_INIT(GUI_Handle*);

void GUI_SCREEN_HANDLE(GUI_Handle*);
void GUI_EVENT_HANDLE(GUI_Handle*);


void GUI_STARTSCREAN_DRAW(void);
void GUI_NUBER_PRINT(uint32_t);



#endif /* INC_GUI_H_ */
