#include <iostream>
using namespace std;
#include "Motor.hpp"

void Motor::StopM() {
    //to stop the motor, you need to transition states
    //so you need to use a transition map, which is ordered 
    //and corresponds to the state map
    //for example, the EVENT_IGNORED state corresponds with the STATE_IDLE
    //because the motor is already not in motion

    static const unsigned char TRANSITION_MAP[] = {
                                //corresponding position in STATE_MAP (and enum MotorStates)
        EVENT_IGNORED,          //STATE_IDLE
        CANNOT_OCCUR,           //STATE_STOP
        STATE_STOP,             //STATE_START
        STATE_STOP,             //STATE_CHANGE_SPEED
        0                       
    }; 
    

    //execute the external event of the new state
    ExternalEvent(TRANSITION_MAP[current_state], nullptr);

}

void Motor::SetSpeed(MotorData* mData){
    //same thing as the stop function above, corrensponding pairs 
    //in the transition map with the state map

    static const unsigned char TRANSITION_MAP[] = {
                                //corresponding position in STATE_MAP (and enum MotorStates)
        EVENT_IGNORED,          //STATE_IDLE
        CANNOT_OCCUR,           //STATE_STOP
        STATE_STOP,             //STATE_START
        STATE_STOP,             //STATE_CHANGE_SPEED
        0                       
    }; 
     //execute the external event of the new state, passing in the motor data
    ExternalEvent(TRANSITION_MAP[current_state], mData);

}

void Motor::ST_F_Idle(EventData* eData){
    cout << "Motor is idle" << endl;
}

void Motor::ST_F_Stop(EventData* eData){

    cout << "Motor is stopping" << endl;

    //transition to STATE_IDLE via internal event
    InternalEvent(STATE_IDLE);
}

void Motor::ST_F_Start(MotorData* mData)    {
    //inital motor speed proccessing
    cout << "Motor is starting" << endl;

}

void Motor::ST_F_ChangeSpeed(MotorData* mData){
    cout << "changing data MotorRPM:" << mData->rpm << endl;
}