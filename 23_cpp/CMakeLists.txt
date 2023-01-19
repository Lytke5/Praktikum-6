cmake_minimum_required(VERSION 3.5)

project(23_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(23_cpp main.cpp point.h point.cpp circle.h circle.cpp)

install(TARGETS 23_cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
