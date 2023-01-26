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
        Motor() : StateMachine(MOTOR_MAX_STATES){}

        //external events
        void StopM();
        void SetSpeed(MotorData*);



        //a state map to define the state functions order
        //state map logic:
        // BEGIN_STATE_MAP
        //     STATE_MAP_ENTRY(&Motor::ST_Idle)
        //     STATE_MAP_ENTRY(&Motor::ST_Stop)
        //     STATE_MAP_ENTRY(&Motor::ST_Start)
        //     STATE_MAP_ENTRY(&Motor::ST_ChangeSpeed)
        // END_STATE_MAP // return start of it

        const StateStruct* GetStateMap() { 
            static const StateStruct StateMap[] = {
                reinterpret_cast<StateFunc>(&Motor::ST_F_Idle),
                reinterpret_cast<StateFunc>(&Motor::ST_F_Stop),
                reinterpret_cast<StateFunc>(&Motor::ST_F_Start),
                reinterpret_cast<StateFunc>(&Motor::ST_F_ChangeSpeed)
            };

            return &StateMap[0];
        }
        

    private:   

        // state enumeration order MUST match the order of state
        // function entries in the state map
        //maybe use these in the state map instead of typedef to avoid the weird ARM64 error
        enum Motor_States { 
            STATE_IDLE = 0,
            STATE_STOP,
            STATE_START,
            STATE_CHANGE_SPEED,
            MOTOR_MAX_STATES
        };

        //state functions
        void ST_F_Idle(EventData*);
        void ST_F_Stop(EventData*);
        void ST_F_Start(MotorData*);
        void ST_F_ChangeSpeed(MotorData*);



};








#endif // MOTOR_HPP
