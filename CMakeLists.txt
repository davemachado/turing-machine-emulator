cmake_minimum_required(VERSION 3.7)
project(turingMachine)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp State.cpp State.h)
add_executable(turingMachine ${SOURCE_FILES})