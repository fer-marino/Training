cmake_minimum_required(VERSION 2.8.4)
project(Training)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES problem12.cpp)
add_executable(Training ${SOURCE_FILES})