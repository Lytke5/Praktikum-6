cmake_minimum_required(VERSION 3.5)

project(Minesweeper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Minesweeper main.cpp minesweepergame.h minesweepergame.cpp minesweeperfield.h minesweeperfield.cpp)

install(TARGETS Minesweeper
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
