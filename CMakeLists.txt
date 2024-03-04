cmake_minimum_required(VERSION 3.26)

project(TC2038-algoritmos-adv)

set(CMAKE_CXX_STANDARD 17)


add_executable(a01708119_Act0
        a01708119_Act0/main.cpp
        a01708119_Act0/res.h
)

add_executable(a01708119_Act1.1
        a01708119_Act1.1/main.cpp
        a01708119_Act1.1/dnc.h
)

add_executable(a01708119_Act1.2
        a01708119_Act1.2/main.cpp
        a01708119_Act1.2/greedyCoin.h
        a01708119_Act1.2/dynamicCoin.h
)

add_executable(a01708119_Act1.3
        a01708119_Act1.3/main.cpp
        a01708119_Act1.3/backtracking.h
        a01708119_Act1.3/branch&Bound.h
)