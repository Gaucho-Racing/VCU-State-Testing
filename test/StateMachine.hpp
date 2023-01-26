#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP


//EventData base class for data attached during events
//event data on heap needs to be deleted
class EventData{
    public:
        virtual ~EventData();
};

//struct for the states to be used in the state maps
//struct StateStruct;


//class for finite state machine
class StateMachine {
    public:
        StateMachine(int max_states);
        
        virtual ~StateMachine(){}
    
    protected:

        int current_state;

        //default "states" for all derived classes for error handling in transition map
        enum default_states {EVENT_IGNORED = 0xFE, CANNOT_OCCUR};


        //creates an external event for the state machine
        void ExternalEvent(int, EventData*);
        //creates an internal event for the state machine
        void InternalEvent(int, EventData*);


        //this is to be implemented in the derived class, such as motor.hpp
        //returns the StateMap of the system for the order of the states (ordered pairs with transition)
        virtual const StateFunc* GetStateMap();

    private:

        const int num_max_states;
        bool event_generated;
        EventData* curr_event_data;
        void StateEngine();
};



//typedef for a pointer to a function

typedef void (*StateFunc)(EventData*);

// struct StateStruct {
//     //pointer to a function
//     StateFunc currStateFunc;    
// };







#endif //STATE_MACHINE_HPP

