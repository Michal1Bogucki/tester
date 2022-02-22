#ifndef _gui_state_mach_
#define  _gui_state_mach_


#define _number_of_states_ 10;

typedef struct{


void (State_aktivation)(State_handler),
}State_handler;

typedef struct{
uint32_t stateID,
uint32_t states_counter,

void (*_state_activation[_number_of_states_])(State_handler*),


void (*_event_process)(void); 



}SMhadler;

typedef struct{
void ()


}State_handler;

typedef enum{
    Enc_decrement,
    Enc_increment,
    Button_push,
    Button_release,
    Data_in,
    Timer_tick,
    Drwa_reguest,
    Events_cumber_,
}Event_name;

void initSM(SMhandler*);
void addState(SMhandler*,State_handler);
void runSM(SMhadler*);
void process_event(SMhandler,Event_name);








#endif
