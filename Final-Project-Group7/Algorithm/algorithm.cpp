/** \file algorithm.cpp
 * FP -Group#7
 */

#include "algorithm.h"
#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../API/api.h"
#include "../Maze/maze.h"
#include "../LandBasedRobot/landbasedrobot.h"
#include "../LandBasedTracked/landbasedtracked.h"

namespace fp {
    void Algorithm::Solve() {
        bool goal = false;  // Sets current goal to false, used for while loop in main code.
        Maze maze{16, 16}; // Initializes maze
        maze.SetGoal(7, 7); // Sets goal location to 7,7
        maze.SetGoal(8, 7); // Sets goal location to 8,7
        maze.SetGoal(7, 8); // Sets goal location to 7,8
        maze.SetGoal(8, 8); // Sets goal location to 8,8
        LandBasedTracked husky{"husky", 0, 0};
        maze.SetBorder(maze);
        while (!goal) { //Main while loop that conducts DFS, Drawing, and calls movement/turn commands from robot.
            API::clearAllColor(); // Clears all color from maze
            for (int i = 7; i < 9; i++) { // Sets color of goal cells
                for (int j = 7; j < 9; j++) {
                    API::setColor(i, j, 'r');
                }
            }
            int position_x = husky.GetX();  // Stores current x position from robot's current position
            int position_y = husky.GetY();  // Stores current y position from robot's current position
            char robot_direction = husky.GetDirection();  // Stores current direction from robot's current position
            if (API::wallFront()) { // Checks if there's a wall to the right of a robot, if so marks wall
                maze.SetWall(position_x, position_y, robot_direction, 'f');
            }
            if (API::wallRight()) { // Checks if there's a wall to the right of a robot, if so marks wall
                maze.SetWall(position_x, position_y, robot_direction, 'r');
            }
            if (API::wallLeft()) { // Checks if there's wall to the left of the robot, if so marks wall
                maze.SetWall(position_x, position_y, robot_direction, 'l');
            }

            struct Solution { // Creates struct Solution to store x and y positions
                int solution_x;
                int solution_y;
            };

            std::stack<Solution> solution; // Creates Solution stack to store data for mapping path
            solution.push({position_x, position_y}); // Pushes the current position of the robot into the stack

            bool search = true;  // Sets up the search while condition

            //
            // BEGIN DFS ALGORITHM
            //

            while (search) { // Create while loop to implement DFS search. Proceeds through a S, E, N, W pattern through entire maze
                int search_x = solution.top().solution_x;  // Looks at the top x position of solution stack to determine starting location for searching
                int search_y = solution.top().solution_y;  // Looks at the top y position of solution stack to determine starting location for searching
                if (maze.GetGoal(search_x, search_y)) {  // Checks if the current location is a goal location, if so break out of loop.
                    search = false;
                    continue;
                }
                if (!maze.GetWall(search_x, search_y, 's') && !maze.GetVisited(search_x, search_y-1) && search_y>0){  // Checks if the southern location is visited, if theres a wall to the south, or if cell is out of bounds
                    maze.SetVisited(search_x,search_y); // Sets current cell to visited before iterating
                    search_y--;  // Moves to the next southern cell
                    solution.push({search_x, search_y}); // Pushes new position onto stack
                    continue;
                }
                if (!maze.GetWall(search_x, search_y, 'e') && !maze.GetVisited(search_x+1, search_y) &&
                    search_x < 15) { // Checks if the eastern location is visited, if theres a wall to the east, or if cell is out of bounds
                    maze.SetVisited(search_x,search_y); // Sets current cell to visited before iterating
                    search_x++; // Moves to the next eastern cell
                    solution.push({search_x, search_y}); // Pushes new position onto stack
                    continue;
                }
                else if (!maze.GetWall(search_x, search_y, 'n') && !maze.GetVisited(search_x, search_y+1) &&
                           search_y < 15) { // Checks if the northern location is visited, if theres a wall to the north, or if cell is out of bounds
                    maze.SetVisited(search_x,search_y); // Sets current cell to visited before iterating
                    search_y++; // Moves to the next northern cell
                    solution.push({search_x, search_y}); // Pushes new position onto stack
                    continue;
                }
                if (!maze.GetWall(search_x, search_y, 'w') && !maze.GetVisited(search_x-1, search_y) &&
                    search_x > 0) { // Checks if the western location is visited, if theres a wall to the west, or if cell is out of bounds
                    maze.SetVisited(search_x,search_y); // Sets current cell to visited before iterating
                    search_x--; // Moves to the next western cell
                    solution.push({search_x, search_y}); // Pushes new position onto stack
                    continue;
                }
                maze.SetVisited(search_x,search_y); // In case of no viable movements, sets current position to visited, and pops current cell off solution list
                solution.pop();
            }
            if (solution.empty()) { // If stack is empty after attempting to find a path, robot is unable to find a solution and maze is invalid
                std::cout << "No solution exists, maze is unsolvable" << std::endl;
                goal = true; // Takes code out of loop
            }
            struct Movement { // Creates struct to reverse solution struct for robot movement
                int movement_x;
                int movement_y;
            };
            std::stack<Movement> movement; // Creates Movement stack to store all required robot movements
            while (!solution.empty()) { // While loop builds movement stack out of solution stack reversing the stack
                API::setColor(solution.top().solution_x,solution.top().solution_y, 'c');
                movement.push({solution.top().solution_x,
                               solution.top().solution_y}); // Adds top of solution stack to movement stack
                solution.pop(); // Pops top of solution stack
            }
            movement.pop(); // Removes start position from stack
            while (!movement.empty()) { // While loop to trigger movements for the robot
                int robot_y = husky.GetY(); // Updates y position with current location each iteration
                int robot_x = husky.GetX(); // Updates x position with current location each iteration
                char wall_robot_direction = husky.GetDirection(); // Updates robot's direction each iteration
                if (API::wallFront()) { // Checks if there's a wall to the front of the robot, if so marks wall
                    maze.SetWall(robot_x, robot_y, wall_robot_direction, 'f');
                }
                if (API::wallRight()) { // Checks if there's a wall to the right of a robot, if so marks wall
                    maze.SetWall(robot_x, robot_y, wall_robot_direction, 'r');
                }
                if (API::wallLeft()) { // Checks if there's wall to the left of the robot, if so marks wall
                    maze.SetWall(robot_x, robot_y, wall_robot_direction, 'l');
                }
                if ((movement.top().movement_y < robot_y) && !maze.GetWall(robot_x, robot_y,'s')) { // Compares current robot position to DFS solution pathing, ensures no wall exists
                    if (husky.GetDirection() == 's') {  // If Robot is facing south, tells robot go south, pop movement request off stack
                        husky.MoveForward();
                        movement.pop();
                        continue;
                    } else if (husky.GetDirection() == 'w') { // If Robot is facing west, turns robot left, tells robot to go forward, pop movement request off stack
                        husky.TurnLeft();
                        husky.MoveForward();
                        movement.pop();
                        continue;
                    } else if (husky.GetDirection() == 'e') { // If Robot is facing east, turns robot right, tells robot to go forward, pop movement request off stack
                        husky.TurnRight();
                        husky.MoveForward();
                        movement.pop();
                        continue;
                    } else {  // If Robot is facing north, turns robot right twice, tells robot to go forward, pop movement request off stack
                        husky.TurnRight();
                        husky.TurnRight();
                        husky.MoveForward();
                        movement.pop();
                        continue;
                    }
                }
                if ((movement.top().movement_x > robot_x) &&
                    !maze.GetWall(robot_x, robot_y, 'e')) { // Compares current robot position to DFS solution pathing, ensures no wall exists
                    if (husky.GetDirection() == 'e') { // If robot is facing east, moves robot forward, pops movement off stack
                        husky.MoveForward();
                        movement.pop();
                        continue;
                    } else if (husky.GetDirection() == 'n') { // If robot is facing north, turns robot right, moves robot forward, pops movement off stack
                        husky.TurnRight();
                        husky.MoveForward();
                        movement.pop();
                        continue;
                    } else if (husky.GetDirection() == 'w') { // If robot is facing west, turns robot right twice, moves robot forward, pops movement off stack
                        husky.TurnRight();
                        husky.TurnRight();
                        husky.MoveForward();
                        movement.pop();
                        continue;
                    } else { // If robot is facing south, turns robot left once, moves robot forward, pops movement off stack
                        husky.TurnLeft();
                        husky.MoveForward();
                        movement.pop();
                        continue;
                    }
                }
                if ((movement.top().movement_y > robot_y) &&
                    !maze.GetWall(robot_x, robot_y, 'n')) { // Compares current robot position to DFS solution pathing, ensures no wall exists
                    if (husky.GetDirection() == 'n') { // If robot is facing north, moves robot forward, pops movement off stack
                        husky.MoveForward();
                        movement.pop();
                        continue;
                    } else if (husky.GetDirection() == 'w') { // If robot is facing west, turns robot right once, moves robot forward, pops movement off stack
                        husky.TurnRight();
                        husky.MoveForward();
                        movement.pop();
                        continue;
                    } else if (husky.GetDirection() == 's') { // If robot is facing south, turns robot right twice, moves robot forward, pops movement off stack
                        husky.TurnRight();
                        husky.TurnRight();
                        husky.MoveForward();
                        movement.pop();
                        continue;
                    } else { // If robot is facing east, turns robot left once, moves robot forward, pops movement off stack
                        husky.TurnLeft();
                        husky.MoveForward();
                        movement.pop();
                        continue;
                    }
                }
                if ((movement.top().movement_x < robot_x) &&
                    !maze.GetWall(robot_x, robot_y, 'w')) { // Compares current robot position to DFS solution pathing, ensures no wall exists
                    if (husky.GetDirection() == 'w') { // If robot is facing west, moves robot forward, pops movement off stack
                        husky.MoveForward();
                        movement.pop();
                        continue;
                    } else if (husky.GetDirection() == 's') { // If robot is facing south, turns robot right, moves robot forward, pops movement off stack
                        husky.TurnRight();
                        husky.MoveForward();
                        movement.pop();
                        continue;
                    } else if (husky.GetDirection() == 'e') { // If robot is facing east, turns robot right twice, moves robot forward, pops movement off stack
                        husky.TurnRight();
                        husky.TurnRight();
                        husky.MoveForward();
                        movement.pop();
                        continue;
                    } else { // If robot is facing north, turns robot left once, moves robot forward, pops movement off stack
                        husky.TurnLeft();
                        husky.MoveForward();
                        movement.pop();
                        continue;
                    }
                }
                break; // Breaks while loop if unable to do any more movements
            }

            if (maze.GetGoal(husky.GetX(), husky.GetY())) { // If solution is found, and husky at goal location, annouce position and return out of while loop
                std::cerr << "Solution found!" << std::endl;
                goal = true;
            }
            for (int m = 0; m < 17; m++) { // Clears all visited cells, to prepare for the next iteration of DFS
                for (int n = 0; n < 17; n++) {
                    maze.ClearVisited(m,n);
                }
            }
        }
    }
}//--namespace fp