#include "Motor.hpp"

#include <iostream>
using namespace std;



int main() {
	Motor motor;

	MotorData* data = new MotorData();
	data->rpm = 1000;
	motor.SetSpeed(data);

	MotorData* data2 = new MotorData();
	data2->rpm = 2000;
	motor.SetSpeed(data2);

	motor.StopM();
	motor.StopM();

	return 0;
}

