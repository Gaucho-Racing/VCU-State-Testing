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
        Motor() : StateMachine(ST_MAX_STATES){}

        //external events
        //stop, set speed
    private:   

        // state enumeration order must match the order of state
        // function entries in the state map
        //maybe use these in the state map instead of typedef to avoid the weird ARM64 error
        enum Motor_States { 
            ST_IDLE = 0,
            ST_STOP,
            ST_START,
            ST_CHANGE_SPEED,
            ST_MAX_STATES
        };

        //state functions


        //a state map to define the state functions order




};








#endif // MOTOR_HPP
