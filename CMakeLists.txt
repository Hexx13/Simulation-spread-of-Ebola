cmake_minimum_required(VERSION 3.21)
project(Simulation_spread_of_Ebola C)

set(CMAKE_C_STANDARD 11)

add_executable(Simulation_spread_of_Ebola
        stateFunc.c
        serial.c cmake-build-debug
        Io.c
        )
