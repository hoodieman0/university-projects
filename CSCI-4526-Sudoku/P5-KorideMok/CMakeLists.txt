cmake_minimum_required(VERSION 3.23)
project(Sudoku-Project-Master)

set(CMAKE_CXX_STANDARD 14)

include_directories(P5-KorideMok)

add_executable(P5-KorideMok
        P5-KorideMok/Square-KorideMok.cpp
        P5-KorideMok/Square-KorideMok.hpp
        P5-KorideMok/SudokuMain-KorideMok.cpp
        P5-KorideMok/tools.cpp
        P5-KorideMok/tools.hpp
        P5-KorideMok/UnitTests-KorideMok.cpp
        P5-KorideMok/UnitTests-KorideMok.hpp
        P5-KorideMok/State-KorideMok.hpp
        P5-KorideMok/State-KorideMok.cpp
        P5-KorideMok/Game-KorideMok.hpp
        P5-KorideMok/Game-KorideMok.cpp
        P5-KorideMok/Board-KorideMok.hpp
        P5-KorideMok/Board-KorideMok.cpp)