#ifndef _STATE_MACHINE_H
#define _STATE_MACHINE_H

 
class EventData {
    public:
        //virtual destructor
        virtual ~EventData() {};  
};

struct StateStruct;
 
// base class for state machine handling events and state transitions
class StateMachine {
    public:
        //constructor
        StateMachine(unsigned char maxStates);

        //destructor
        virtual ~StateMachine() {}

    protected:
        //???
        enum { EVENT_IGNORED = 0xFE, CANNOT_HAPPEN };

        unsigned char currentState;

        //generates an external event to the state machine 
        //arguments are the new state and the eventData if there is any
        void ExternalEvent(unsigned char, EventData* = nullptr);

        //generates an internal event using the same arguments as above
        void InternalEvent(unsigned char, EventData* = nullptr);

        //returns a StateMap (array of states) instance by the state engine
        virtual const StateStruct* GetStateMap() = 0;

    private:
        const unsigned char _maxStates;
        bool _eventGenerated;
        EventData* _pEventData;
        void StateEngine(void);
};
 
typedef void (StateMachine::*StateFunc)(EventData *);

struct StateStruct 
{
    StateFunc pStateFunc;    
};









 //-----------MACROS FOR EASE OF USABILITY IN FUTURE-----------------
 //ima be honest i got no clue how any of this macro shit works but it works so dont touch it
    #define BEGIN_STATE_MAP \
    public:\
    const StateStruct* GetStateMap() {\
        static const StateStruct StateMap[] = { 
    
    #define STATE_MAP_ENTRY(stateFunc)\
        { reinterpret_cast<StateFunc>(stateFunc) },
    
    #define END_STATE_MAP \
        }; \
        return &StateMap[0]; }
    
    #define BEGIN_TRANSITION_MAP \
        static const unsigned char TRANSITIONS[] = {\
    
    #define TRANSITION_MAP_ENTRY(entry)\
        entry,
    
    #define END_TRANSITION_MAP(data) \
        0 };\
        ExternalEvent(TRANSITIONS[currentState], data);
 
#endif //_STATE_MACHINE_H
