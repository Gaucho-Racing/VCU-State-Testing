#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP


//event data class
class EventData{
    public:
        virtual ~EventData();
};

struct StateStruct;


//class for FSM
class StateMachine {
    public:
        StateMachine(unsigned char maxStates);
        
        virtual ~StateMachine(){}
    
    protected:
        unsigned char current_state;

        enum default_states {EVENT_IGNORED = 0xFE, CANNOT_OCCUR};

        void ExternalEvent(unsigned char, EventData* = nullptr);
        void InternalEvent(unsigned char, EventData* = nullptr);

        virtual const StateStruct* GetStateMap() = 0;

    private:

        const unsigned char num_max_states;
        bool event_generated;
        EventData* curr_event_data;
        void StateEngine();
};


//no clue how this works but works instead of the StateFunc struct
typedef void (StateMachine::*StateFunc)(EventData *);

struct StateStruct {
    StateFunc currStateFunc;    
};






#endif //STATE_MACHINE_HPP

