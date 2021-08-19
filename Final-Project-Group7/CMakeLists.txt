cmake_minimum_required(VERSION 3.17)
project(FP_Group_7)

set(CMAKE_CXX_STANDARD 17)

add_executable(FP_Group_7 main.cpp LandBasedRobot/landbasedrobot.cpp LandBasedRobot/landbasedrobot.h
        LandBasedTracked/landbasedtracked.cpp LandBasedTracked/landbasedtracked.h LandBasedWheeled/landbasedwheeled.cpp
        LandBasedWheeled/landbasedwheeled.h Maze/maze.cpp Maze/maze.h Algorithm/algorithm.cpp Algorithm/algorithm.h
        API/api.cpp API/api.h)