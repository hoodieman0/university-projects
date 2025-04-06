cmake_minimum_required(VERSION 3.23)
project(Sudoku-Project-Master)

set(CMAKE_CXX_STANDARD 14)

include_directories(P8-KorideMok)

add_executable(P8-KorideMok
        P8-KorideMok/Square-KorideMok.cpp
        P8-KorideMok/Square-KorideMok.hpp
        P8-KorideMok/SudokuMain-KorideMok.cpp
        P8-KorideMok/tools.cpp
        P8-KorideMok/tools.hpp
        P8-KorideMok/UnitTests-KorideMok.cpp
        P8-KorideMok/UnitTests-KorideMok.hpp
        P8-KorideMok/State-KorideMok.hpp
        P8-KorideMok/State-KorideMok.cpp
        P8-KorideMok/Game-KorideMok.hpp
        P8-KorideMok/Game-KorideMok.cpp
        P8-KorideMok/Board-KorideMok.hpp
        P8-KorideMok/Board-KorideMok.cpp
        P8-KorideMok/Cluster-KorideMok.hpp
        P8-KorideMok/Cluster-KorideMok.cpp
        P8-KorideMok/DiagBoard-KorideMok.hpp
        P8-KorideMok/DiagBoard-KorideMok.cpp
        P8-KorideMok/Exceptions.hpp
        P8-KorideMok/Exceptions.cpp)