#ifndef _MOTOR_H
#define _MOTOR_H
#include "StateMachine.h"

// struct to hold event data passed into state machine
struct MotorData : public EventData {
    int speed;
};

// the Motor class is derived from StateMachine Class
//this class uses quite a bit of macro support but i removed most of it for readability
class Motor : public StateMachine {
    public:
        Motor() : StateMachine(ST_MAX_STATES) {}

        // external events taken by this state machine
        void Halt();
        void SetSpeed(MotorData*);

    private:
        int m_currentSpeed;

        // state machine state functions
        //the state functions implement each state 
        void ST_Idle(EventData*);
        void ST_Stop(EventData*);
        void ST_Start(MotorData*);
        void ST_ChangeSpeed(MotorData*);


        
    public:
        //state map to define state function order
        const StateStruct* GetStateMap() { 
            static const StateStruct StateMap[] = {
                { reinterpret_cast<StateFunc>(&Motor::ST_Idle) },
                { reinterpret_cast<StateFunc>(&Motor::ST_Stop) },
                { reinterpret_cast<StateFunc>(&Motor::ST_Start) },
                { reinterpret_cast<StateFunc>(&Motor::ST_ChangeSpeed) },}; 
            return &StateMap[0]; 
        }
        //Alternate code using macro support
        /*
        BEGIN_STATE_MAP
            STATE_MAP_ENTRY(&Motor::ST_Idle)
            STATE_MAP_ENTRY(&Motor::ST_Stop)
            STATE_MAP_ENTRY(&Motor::ST_Start)
            STATE_MAP_ENTRY(&Motor::ST_ChangeSpeed)
        END_STATE_MAP
        */

        // ORDER MUST MATCH STATE MAP AND TRANSITION MAP CORRESPONDANCE
        enum E_States { 
            ST_IDLE = 0,
            ST_STOP,
            ST_START,
            ST_CHANGE_SPEED,
            ST_MAX_STATES
        };
};
#endif // _MOTOR_H
