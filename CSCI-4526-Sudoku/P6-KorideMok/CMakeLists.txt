cmake_minimum_required(VERSION 3.23)
project(Sudoku-Project-Master)

set(CMAKE_CXX_STANDARD 14)

include_directories(P6-KorideMok)

add_executable(P6-KorideMok
        P6-KorideMok/Square-KorideMok.cpp
        P6-KorideMok/Square-KorideMok.hpp
        P6-KorideMok/SudokuMain-KorideMok.cpp
        P6-KorideMok/tools.cpp
        P6-KorideMok/tools.hpp
        P6-KorideMok/UnitTests-KorideMok.cpp
        P6-KorideMok/UnitTests-KorideMok.hpp
        P6-KorideMok/State-KorideMok.hpp
        P6-KorideMok/State-KorideMok.cpp
        P6-KorideMok/Game-KorideMok.hpp
        P6-KorideMok/Game-KorideMok.cpp
        P6-KorideMok/Board-KorideMok.hpp
        P6-KorideMok/Board-KorideMok.cpp)