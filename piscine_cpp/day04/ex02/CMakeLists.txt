cmake_minimum_required(VERSION 3.7)
project(ex02)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp AssaultTerminator.cpp Squad.cpp TacticalMarine.cpp ISpaceMarine.hpp ISquad.hpp)
add_executable(ex02 ${SOURCE_FILES})