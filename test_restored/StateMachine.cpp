#include "StateMachine.hpp"
#include <assert.h>
#include <string>


//initializer list in the constructor for the const variable max_states
StateMachine::StateMachine(int max_states): num_max_states(max_states) {
    current_state = 0;
    event_generated = false;
    curr_event_data = nullptr;
}

void StateMachine::ExternalEvent(int new_state, EventData* data){
    if(new_state == EVENT_IGNORED) {
        if(data) delete data;
    }
    else {
        // TODO - capture software lock here for thread-safety  
        // generate the event and execute the state engine
        InternalEvent(new_state, data); 
        StateEngine();     
		// TODO - release software lock 
    }
}

void StateMachine::InternalEvent(int new_state, EventData* data)
{
	if (data == nullptr)
		data = new EventData();

    curr_event_data = data;
    event_generated = true;
    current_state = new_state;
}


//state engine
void StateMachine::StateEngine(){

    EventData* temp_event_data = nullptr;

    while(event_generated){
        temp_event_data = curr_event_data;  
        curr_event_data = nullptr;          
        event_generated = false;            

        assert(current_state < num_max_states);

        const int* state_map = GetStateMap();

        //execute the state passing in the event data if any
        //executing the current state function through the state map
        //(*state_map[current_state])(temp_event_data);

        //doing the same thing but without the annoying typedef
        //by using the virtual helper function execState

        execState(state_map[current_state], curr_event_data);
                    


        if(temp_event_data){
            delete temp_event_data;
            temp_event_data = nullptr;
        }

    }
}
