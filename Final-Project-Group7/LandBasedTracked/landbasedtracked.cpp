/** \file landbasedtracked.cpp
 * FP -Group#7
 */

#include "landbasedtracked.h"
#include "../API/api.h"

namespace fp {
/**
* @brief Move the robot forward in the maze
* @param x an integer representing the x-coordinate of the robots current position.
* @param y an integer representing the y-coordinate of the robots current position.
*/
    void LandBasedTracked::MoveForward() {
        std::cout << "LandBasedTracked::MoveForward is called\n";
        API::moveForward();
        if (direction_ == 'n') { y_++; }  // If facing north, increase y-location by 1
        else if (direction_ == 'e') { x_++; } // If facing east, increase x-location by 1
        else if (direction_ == 'w') { x_--; } // If facing west, decrease x-location by 1
        else { y_--; } // If facing south, decrease y-location by 1
    }
/**
 * @brief Gets current y position of robot in maze
 * @return Current y position of robot in maze
 */
    int LandBasedTracked::GetX(){
        return x_;
    }


/**
 * @brief Gets current y position of robot in maze
 * @return Current y position of robot in maze
 */
    int LandBasedTracked::GetY(){
        return y_;
    }
/**
* @brief Get the current direction the robot is facing.
* @param x an integer representing the x-coordinate of the robots current position.
* @return return the current direction the robot is facing
*/
    char LandBasedTracked::GetDirection() {
        return direction_;
    }
/**
* @brief Turn the robot 90° counter-clockwise.
* @param x an integer representing the x-coordinate of the robots current position.
* @param y an integer representing the y-coordinate of the robots current position.
*/
    void LandBasedTracked::TurnLeft() {
        API::turnLeft();
        char new_direction;
        std::cout << "LandBasedTracked::TurnLeft is called\n";
        if (direction_ == 'n'){
            new_direction = 'w';   // Updates position to face west if facing north
        }
        else if (direction_ == 'w'){
            new_direction = 's';   // Updates position to face south if facing west
        }
        else if (direction_ == 's'){
            new_direction = 'e';   // Updates position to face east if facing south
        }
        else {new_direction = 'n';} // Updates position to face north if facing east
        direction_ = new_direction;  // Updates robot direction based on new direction
    }
/**
* @brief Turn the robot 90° clockwise.
* @param x an integer representing the x-coordinate of the robots current position.
* @param y an integer representing the y-coordinate of the robots current position.
*/
    void LandBasedTracked::TurnRight() {
        API::turnRight();
        char new_direction;
        std::cout << "LandBasedRobot::TurnRight is called\n";
        if (direction_ == 'n'){
            new_direction = 'e'; // Updates position to face east if facing north
        }
        else if (direction_ == 'w'){
            new_direction = 'n';  // Updates position to face north if facing west
        }
        else if (direction_ == 's'){
            new_direction = 'w'; // Updates position to face west if facing south
        }
        else {new_direction = 's';}
        direction_ = new_direction; // Updates position to face south if facing east
    }
}//--namespace fp