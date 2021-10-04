cmake_minimum_required(VERSION 3.19)
project(Task_31_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Task_31_1
        main.cpp
        src/SharedToyPtr.cpp src/Toy.cpp src/Dog.cpp include/Dog.h)