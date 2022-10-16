cmake_minimum_required(VERSION 3.23)
project(Sudoku-Project-Master)

set(CMAKE_CXX_STANDARD 14)

include_directories(P1-KorideMok
        P2-KorideMok
        P3-KorideMok
        P4-KorideMok
        P5-KorideMok)

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

add_executable(P4-KorideMok
        P4-KorideMok/Square-KorideMok.cpp
        P4-KorideMok/Square-KorideMok.hpp
        P4-KorideMok/SudokuMain-KorideMok.cpp
        P4-KorideMok/tools.cpp
        P4-KorideMok/tools.hpp
        P4-KorideMok/UnitTests-KorideMok.cpp
        P4-KorideMok/UnitTests-KorideMok.hpp
        P4-KorideMok/State-KorideMok.hpp
        P4-KorideMok/State-KorideMok.cpp
        P4-KorideMok/Game-KorideMok.hpp
        P4-KorideMok/Game-KorideMok.cpp
        P4-KorideMok/Board-KorideMok.hpp
        P4-KorideMok/Board-KorideMok.cpp)

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
        P5-KorideMok/Board-KorideMok.cpp
        P5-KorideMok/Cluster-KorideMok.hpp
        P5-KorideMok/Cluster-KorideMok.cpp)