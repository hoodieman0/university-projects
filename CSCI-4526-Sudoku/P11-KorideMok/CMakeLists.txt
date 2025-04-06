cmake_minimum_required(VERSION 3.23)
project(Sudoku-Project-Master)

set(CMAKE_CXX_STANDARD 14)

include_directories(P9-KorideMok)

add_executable(P9-KorideMok
        P9-KorideMok/Square-KorideMok.cpp
        P9-KorideMok/Square-KorideMok.hpp
        P9-KorideMok/SudokuMain-KorideMok.cpp
        P9-KorideMok/tools.cpp
        P9-KorideMok/tools.hpp
        P9-KorideMok/UnitTests-KorideMok.cpp
        P9-KorideMok/UnitTests-KorideMok.hpp
        P9-KorideMok/State-KorideMok.hpp
        P9-KorideMok/State-KorideMok.cpp
        P9-KorideMok/Game-KorideMok.hpp
        P9-KorideMok/Game-KorideMok.cpp
        P9-KorideMok/Board-KorideMok.hpp
        P9-KorideMok/Board-KorideMok.cpp
        P9-KorideMok/Cluster-KorideMok.hpp
        P9-KorideMok/Cluster-KorideMok.cpp
        P9-KorideMok/DiagBoard-KorideMok.hpp
        P9-KorideMok/DiagBoard-KorideMok.cpp
        P9-KorideMok/Exceptions.hpp
        P9-KorideMok/Exceptions.cpp)