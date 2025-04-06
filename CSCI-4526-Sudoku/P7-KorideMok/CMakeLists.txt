cmake_minimum_required(VERSION 3.23)
project(Sudoku-Project-Master)

set(CMAKE_CXX_STANDARD 14)

include_directories(P7-KorideMok)

add_executable(P7-KorideMok
        P7-KorideMok/Square-KorideMok.cpp
        P7-KorideMok/Square-KorideMok.hpp
        P7-KorideMok/SudokuMain-KorideMok.cpp
        P7-KorideMok/tools.cpp
        P7-KorideMok/tools.hpp
        P7-KorideMok/UnitTests-KorideMok.cpp
        P7-KorideMok/UnitTests-KorideMok.hpp
        P7-KorideMok/State-KorideMok.hpp
        P7-KorideMok/State-KorideMok.cpp
        P7-KorideMok/Game-KorideMok.hpp
        P7-KorideMok/Game-KorideMok.cpp
        P7-KorideMok/Board-KorideMok.hpp
        P7-KorideMok/Board-KorideMok.cpp
        P7-KorideMok/Cluster-KorideMok.hpp
        P7-KorideMok/Cluster-KorideMok.cpp
        P7-KorideMok/DiagBoard-KorideMok.hpp
        P7-KorideMok/DiagBoard-KorideMok.cpp
        P7-KorideMok/Exceptions.hpp
        P7-KorideMok/Exceptions.cpp)