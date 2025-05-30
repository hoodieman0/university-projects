cmake_minimum_required(VERSION 3.23)
project(Sudoku-Project-Master)

set(CMAKE_CXX_STANDARD 14)

include_directories(P1-KorideMok
        P2-KorideMok
        P3-KorideMok)

add_executable(P1-KorideMok
        P1-KorideMok/SudokuMain-KorideMok.cpp
        P1-KorideMok/tools.cpp
        P1-KorideMok/tools.hpp
        P1-KorideMok/UnitTests-KorideMok.cpp
        P1-KorideMok/UnitTests-KorideMok.hpp
        P1-KorideMok/State-KorideMok.hpp
        P1-KorideMok/State-KorideMok.cpp)

add_executable(P2-KorideMok
        P2-KorideMok/Square-KorideMok.cpp
        P2-KorideMok/Square-KorideMok.hpp
        P2-KorideMok/SudokuMain-KorideMok.cpp
        P2-KorideMok/tools.cpp
        P2-KorideMok/tools.hpp
        P2-KorideMok/UnitTests-KorideMok.cpp
        P2-KorideMok/UnitTests-KorideMok.hpp
        P2-KorideMok/State-KorideMok.hpp
        P2-KorideMok/State-KorideMok.cpp)

add_executable(P3-KorideMok
        P3-KorideMok/Square-KorideMok.cpp
        P3-KorideMok/Square-KorideMok.hpp
        P3-KorideMok/SudokuMain-KorideMok.cpp
        P3-KorideMok/tools.cpp
        P3-KorideMok/tools.hpp
        P3-KorideMok/UnitTests-KorideMok.cpp
        P3-KorideMok/UnitTests-KorideMok.hpp
        P3-KorideMok/State-KorideMok.hpp
        P3-KorideMok/State-KorideMok.cpp
        P3-KorideMok/Game-KorideMok.hpp
        P3-KorideMok/Game-KorideMok.cpp)