#include <assert.h>
#include "Motor.h"
#include <iostream>

using namespace std;

// halt motor external event
void Motor::Halt(void)
{
    // given the Halt event, transition to a new state based upon 
    // the current state of the state machine

	//note that the location of each entry in the transition map matches the order of state functions defined within the state map.
   	//The maps values must correspond in terms of indices
	//for example, here if the current state is 0, or idle, the transition map will make sure that the even is ignored. 
	
	static const unsigned char TRANSITIONS[] = {
										// Current State in State Map	
		EVENT_IGNORED,					// ST_IDLE
		CANNOT_HAPPEN,					// ST_STOP
		ST_STOP,						// ST_START
		ST_STOP,						// ST_CHANGE_SPEED
	};

    ExternalEvent(TRANSITIONS[currentState], NULL); 
   

	// Alternate transition map using macro support
	/*
	BEGIN_TRANSITION_MAP			              			// - Current State -
		TRANSITION_MAP_ENTRY (EVENT_IGNORED)				// ST_IDLE
		TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)				// ST_STOP
		TRANSITION_MAP_ENTRY (ST_STOP)						// ST_START
		TRANSITION_MAP_ENTRY (ST_STOP)						// ST_CHANGE_SPEED
	END_TRANSITION_MAP(NULL)
	*/
}

// set motor speed external event
void Motor::SetSpeed(MotorData* pData)
{
	//note that the location of each entry in the transition map matches the order of state functions defined within the state map.
	//this works the same way as i did in Halt() with the ordered maps

	static const unsigned char TRANSITIONS[] = {
											//current:
		ST_START,							//idle
		CANNOT_HAPPEN,						//stop
		ST_CHANGE_SPEED,					//start
		ST_CHANGE_SPEED,					//changespeed
		0 
	}; ExternalEvent(TRANSITIONS[currentState], pData);


	//macro supported variation
	/*
    BEGIN_TRANSITION_MAP                      // - Current State -
        TRANSITION_MAP_ENTRY (ST_START)       // ST_Idle       
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)  // ST_Stop       
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)// ST_Start      
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)// ST_ChangeSpeed
    END_TRANSITION_MAP(pData)
	*/
}

// state machine stays here when motor is not running
void Motor::ST_Idle(EventData* pData) 
{
	cout << "The Motor is Idle" << endl;

}

// stop the motor 
void Motor::ST_Stop(EventData* pData)
{
	cout << "The Motor is Stop" << endl;

    // perform the stop motor processing here

    // transition to ST_Idle via an internal event
    InternalEvent(ST_IDLE);
}

// start the motor going
void Motor::ST_Start(MotorData* pData)
{
	cout << "Motor::ST_Start" << endl;
    // set initial motor speed processing here
}

// changes the motor speed once the motor is moving
void Motor::ST_ChangeSpeed(MotorData* pData)
{
	cout << "Motor::ST_ChangeSpeed" << endl;
    // perform the change motor speed to pData->speed here
	
}
