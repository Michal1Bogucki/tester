/*
 * gui.c
 *
 *  Created on: Oct 12, 2021
 *      Author: Boguc
 */
#include "gui.h"

#ifndef DEBUG
#include "GFX.h"
#endif



void GUI_INIT(GUI_Handle* _gui_handle){
	_gui_handle->Current_Screen=GUI_STATE_START;
	_gui_handle->Last_Event=GUI_EVENT_IDLE;
	_gui_handle->cusor_pos=0;
}

void GUI_STARTSCREAN_DRAW(void){
	#ifndef DEBUG

		GFX_draw_string(30, 40, (unsigned char*)"Boguc", SSD1306_BLACK, SSD1306_WHITE, 2, 2);
		//GFX_draw_string(1, 10, (unsigned char*)"Technology", SSD1306_BLACK, SSD1306_WHITE, 2, 1);

	#endif
}

void GUI_NUBER_PRINT(uint32_t num){

#ifndef DEBUG
	char ch[10];
	sprintf(ch,"%u",(unsigned int)num);

	GFX_draw_string(20, 40, (unsigned char*)ch, SSD1306_BLACK, SSD1306_WHITE, 2, 2);


#endif
}
