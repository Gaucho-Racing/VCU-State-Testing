#include <iostream>
using namespace std;
#include "Motor.hpp"

void Motor::StopM() {
    
}

void Motor::SetSpeed(MotorData* mData){
    
}

void Motor::ST_F_Idle(EventData* eData){

}

void Motor::ST_F_Stop(EventData* eData){

    //transition to STATE_IDLE via internal event
    InternalEvent(STATE_IDLE);
}

void Motor::ST_F_Start(MotorData* mData){
    //inital motor speed proccessing
}

void Motor::ST_F_ChangeSpeed(MotorData* mData){
    cout << "changing data MotorRPM:" << mData->rpm << endl;
}