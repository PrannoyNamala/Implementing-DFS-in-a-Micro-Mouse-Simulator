/** \file maze.h
 * FP -Group#7
 */

#pragma once
#include <iostream>

#ifndef FP_GROUP_7_MAZE_H
#define FP_GROUP_7_MAZE_H

namespace fp {
    class Maze{
    public:
        Maze(int width = 16, int height= 16): width_{width}, height_{height} {}
        void GetDimension(); // Gets dimensions of array
        void SetGoal(int goal_x, int goal_y);
        void SetVisited(int cellx, int celly);
        void ClearVisited(int cellx, int celly);
        void SetBorder(Maze maze);
        bool GetVisited(int cellx, int celly);
        bool GetGoal(int cellx, int celly);
        bool GetWall(int cellx, int celly, char direction);
        void SetWall(int wallx, int wally, char direction, char facing);
    protected:
        int width_; // Width of maze
        int height_; // Height of maze
        struct cells{
            bool wallNorth = false, wallSouth = false, wallEast = false, wallWest = false, visited = false, goal = false;
        } loaded_maze[16][16];
    };
}//--namespace fp

#endif //FP_GROUP_7_MAZE_H
