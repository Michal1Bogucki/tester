#ifndef _gui_state_mach_
#define  _gui_state_mach_


#define _number_of_states_ 10;

typedef enum{
    Enc_decrement,
    Enc_increment,
    Button_push,
    Button_release,
    Data_in,
    Timer_tick,
    Draw_request,
    Events_number_
}Event_name;

typedef struct{


void (State_aktivation)(State_handler),
}State_handler;

typedef struct{
uint32_t stateID,
uint32_t states_counter,

void (*_state_activation[_number_of_states_])(State_handler*),


void (*_event_proces[Events_number_])(void); 



}SMhadler;




typedef struct{
Event_name _Event_name,
void (*_event_proces)(void)=0; 


}State_handler;



void initSM(SMhandler*);
void addState(SMhandler*,State_handler);
void runSM(SMhadler*);
void process_event(SMhandler,Event_name);








#endif
