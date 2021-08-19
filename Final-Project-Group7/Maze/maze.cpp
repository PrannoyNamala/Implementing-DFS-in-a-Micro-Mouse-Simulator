/** \file maze.cpp
 * FP -Group#7
 */

#include "maze.h"
#include "../API/api.h"
#include <iostream>

namespace fp {
    /**
     * @brief Getting that returns the dimensions of the maze
     * @param void
     */
    void Maze::GetDimension(){
        std::cout <<"Maze::GetDimension is called\n";
        int mazeWidth = API::mazeWidth(); // Calls the maze by pointer for Width
        int mazeHeight = API::mazeHeight(); // Calls the maze by pointer for Height
        std::cout << "Maze is " <<mazeWidth << "x "<< mazeHeight;
    }

    /**
     *  @brief Function that sets the borders of the walls
     *  @param void
     */

    void Maze::SetBorder(Maze maze){
        for (int i = -1; i<16; i++){
            maze.loaded_maze[0][i].wallWest = true;
            API::setWall(0,i,'w');
        }
        for (int j = -1; j<16; j++){
            maze.loaded_maze[j][0].wallSouth = true;
            API::setWall(j,0,'s');
        }
        for (int k = -1; k<16; k++){
            maze.loaded_maze[15][k].wallEast = true;
            API::setWall(15,k,'e');
        }
        for (int l = -1; l<16; l++){
            maze.loaded_maze[l][15].wallNorth = true;
            API::setWall(l,15,'n');
        }
        maze.loaded_maze[0][0].wallSouth = true;
    }

    /**
     * @brief Sets the goal locations of the maze cell
     * @param goal_x X location of cell to set to goal
     * @param goal_y Y Location of cell to set to goal
     */

    void Maze::SetGoal(int goal_x, int goal_y) { // Set goal location
        std::cout <<"Maze:SetGoal is called\n";
        loaded_maze[goal_x][goal_y].goal = true;
    }

    /**
     * @brief Sets the target cell as visited
     * @param cellx
     * @param celly
     */

    void Maze::SetVisited(int cellx, int celly) {
        loaded_maze[cellx][celly].visited = true;
    }
/**
 * @brief Getter to determine if cell has been visited
 * @param cellx
 * @param celly
 * @return Returns true if cell has been visited
 */
    bool Maze::GetVisited(int cellx, int celly) {
        return loaded_maze[cellx][celly].visited;
    }
    void Maze::ClearVisited(int cellx, int celly) {
        loaded_maze[cellx][celly].visited = false;
    }


    bool Maze::GetGoal(int cellx, int celly) {
        return loaded_maze[cellx][celly].goal;
    }

    bool Maze::GetWall(int cellx, int celly, char direction) {
        if (direction == 'n'){
            return loaded_maze[cellx][celly].wallNorth;
        }
        else if (direction == 'e'){
            return loaded_maze[cellx][celly].wallEast;
        }
        else if (direction == 's'){
            return loaded_maze[cellx][celly].wallSouth;
        }
        else
            return loaded_maze[cellx][celly].wallWest;
    }
/**
 * @brief Sets wall depending on the direction the robot is facing, and which side the wall is on.
 * @param cellx  X location to set wall at.
 * @param celly  Y location to set wall at.
 * @param direction Cardinal direction robot is pointing
 * @param side Which side relative to the robot the wall is on
 */
    void Maze::SetWall(int cellx, int celly, char direction, char side) {
        std::cout <<"Maze::SetWall is called" <<std::endl;
        if (direction == 'n'){
            if (side == 'f') {
                loaded_maze[cellx][celly].wallNorth = true;
                API::setWall(cellx,celly,'n');
            }
            else if (side == 'r'){
                loaded_maze[cellx][celly].wallEast = true;
                API::setWall(cellx,celly,'e');
            }
            else{
                loaded_maze[cellx][celly].wallWest = true;
                API::setWall(cellx,celly,'w');
            }
        }
        else if (direction == 'e'){
            if (side == 'f') {
                loaded_maze[cellx][celly].wallEast = true;
                API::setWall(cellx,celly,'e');
            }
            else if (side == 'r'){
                loaded_maze[cellx][celly].wallSouth = true;
                API::setWall(cellx,celly,'s');
            }
            else{
                loaded_maze[cellx][celly].wallNorth = true;
                API::setWall(cellx,celly,'n');
            }
        }
        else if (direction == 's'){
            if (side == 'f') {
                loaded_maze[cellx][celly].wallSouth = true;
                API::setWall(cellx,celly,'s');
            }
            else if (side == 'r'){
                loaded_maze[cellx][celly].wallWest = true;
                API::setWall(cellx,celly,'w');
            }
            else{
                loaded_maze[cellx][celly].wallEast = true;
                API::setWall(cellx,celly,'e');
            }
        }
        else { // Robot pointing west
            if (side == 'f') {
                loaded_maze[cellx][celly].wallWest = true;
                API::setWall(cellx,celly,'w');
            }
            else if (side == 'r') {
                loaded_maze[cellx][celly].wallNorth = true;
                API::setWall(cellx,celly,'n');
            }
            else {
                loaded_maze[cellx][celly].wallSouth = true;
                API::setWall(cellx,celly,'s');
            }
        }
    }
}//--namespace fp