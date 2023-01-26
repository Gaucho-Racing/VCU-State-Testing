#ifndef MOTOR_HPP
#define MOTOR_HPP
#include "StateMachine.hpp"

//MotorData derived class from EventData
struct MotorData : public EventData {
    //speed of the motor
    int rpm;
};

//main motor state machine class
class Motor : public StateMachine {
    public:
        //inline constructor
        Motor() : StateMachine(STATE_MAX_STATES){}

        //external events
        //stop, set speed
    private:   

        // state enumeration order must match the order of state
        // function entries in the state map
        //maybe use these in the state map instead of typedef to avoid the weird ARM64 error
        enum Motor_States { 
            STATE_IDLE = 0,
            STATE_STOP,
            STATE_START,
            STATE_CHANGE_SPEED,
            STATE_MAX_STATES
        };

        //state functions
        void STATE_Idle(EventData*);
        void STATE_Stop(EventData*);
        void STATE_Start(EventData*);
        void STATE_ChangeSpeed(EventData*);



        //a state map to define the state functions order
        //state map logic:
        // BEGIN_STATE_MAP
        //     STATE_MAP_ENTRY(&Motor::ST_Idle)
        //     STATE_MAP_ENTRY(&Motor::ST_Stop)
        //     STATE_MAP_ENTRY(&Motor::ST_Start)
        //     STATE_MAP_ENTRY(&Motor::ST_ChangeSpeed)
        // END_STATE_MAP



};








#endif // MOTOR_HPP
