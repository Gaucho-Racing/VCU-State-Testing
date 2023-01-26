#include <iostream>
using namespace std;
#include "Motor.h"

int main(void)
{
	Motor motor;

	MotorData* data = new MotorData();
	data->speed = 100;
	motor.SetSpeed(data);

	MotorData* data2 = new MotorData();
	data2->speed = 200;
	motor.SetSpeed(data2);

	motor.Halt();
	motor.Halt();

	return 0;
}

