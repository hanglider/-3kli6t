cmake_minimum_required(VERSION 3.26)
project(Dynamic)

set(CMAKE_CXX_STANDARD 23)

add_executable(Dynamic main.cpp
        vector.h
        vector.cpp
        templates.cpp)
