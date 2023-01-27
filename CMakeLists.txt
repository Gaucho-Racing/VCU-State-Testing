cmake_minimum_required(VERSION 3.24)
project(VCU_State_Testing)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(test_restored)

add_executable(VCU_State_Testing
        test_restored/Motor.cpp
        test_restored/Motor.hpp
        test_restored/StateMachine.cpp
        test_restored/StateMachine.hpp
        test_restored/testrun.cpp)
