cmake_minimum_required(VERSION 3.29)
project(sample_cpp_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(sample_cpp_project main.cpp
        my_add.hpp
        my_add.cpp)
