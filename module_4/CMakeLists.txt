cmake_minimum_required(VERSION 3.17)
project(cpp_04)

set(CMAKE_CXX_STANDARD 14)

include_directories(ex00)

add_executable(cpp_04
        ex00/main.cpp
        ex00/Sorcerer.cpp
        ex00/Sorcerer.hpp
        ex00/Victim.cpp
        ex00/Victim.hpp)
