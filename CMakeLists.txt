cmake_minimum_required(VERSION 3.17)
project(Filter)

set(CMAKE_CXX_STANDARD 11)

add_executable(Filter
        main.cpp
        Filter.cpp
        Filter.h
        FIR_Filter.cpp
        FIR_Filter.h
        Alpha_Beta_Filter.h
        Alpha_Beta_Filter.cpp)