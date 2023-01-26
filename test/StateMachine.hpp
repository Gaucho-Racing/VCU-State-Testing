#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP


//EventData base class for data attached during events
//event data on heap needs to be deleted
class EventData{
    public:
        virtual ~EventData();
};

//struct for the states to be used in the state maps
struct StateStruct;


//class for finite state machine
class StateMachine {
    public:
        StateMachine(unsigned char max_states);
        
        virtual ~StateMachine(){}
    
    protected:

        unsigned char current_state;

        //default "states" for all derived classes for error handling in transition map
        enum default_states {EVENT_IGNORED, CANNOT_OCCUR};


        //creates an external event for the state machine
        void ExternalEvent(unsigned char, EventData* = nullptr);
        //creates an internal event for the state machine
        void InternalEvent(unsigned char, EventData* = nullptr);


        //this is to be implemented in the derived class, such as motor.hpp
        //returns the StateMap of the system for the order of the states (ordered pairs with transition)
        virtual const StateStruct* GetStateMap();

    private:

        const unsigned char num_max_states;
        bool event_generated;
        EventData* curr_event_data;
        void StateEngine();
};



//no clue how this works but works instead of the StateFunc struct
typedef void (StateMachine::*StateFunc)(EventData *);

struct StateStruct {
    //pointer to a function
    StateFunc currStateFunc;    
};







#endif //STATE_MACHINE_HPP

