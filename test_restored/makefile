all: Motor.o StateMachine.o testrun.o
	g++ Motor.o StateMachine.o testrun.o  -o test

Motor.o:
	g++ -c Motor.cpp

StateMachine.o:
	g++ -c StateMachine.cpp

testrun.o:
	g++ -c testrun.cpp -v 