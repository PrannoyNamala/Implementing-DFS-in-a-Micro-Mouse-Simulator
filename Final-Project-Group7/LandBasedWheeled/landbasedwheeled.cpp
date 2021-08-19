/** \file landbasedwheeled.cpp
 * FP -Group#7
 */

#include "landbasedwheeled.h"
#include "../API/api.h"
namespace fp {
/**
* @brief Move the robot forward in the maze. Update position of robot based on direction moved
*/
    void LandBasedWheeled::MoveForward() {
        std::cout << "LandBasedRobot::MoveForward is called\n";
        API::moveForward();
        if (direction_ == 'n'){y_++;}
        else if (direction_ == 'e'){x_++;}
        else if (direction_ == 'w'){x_--;}
        else {y_--;}
    }
/**
* @brief Get the current direction the robot is facing.
* @return return the current direction the robot is facing
*/
    char LandBasedWheeled::GetDirection() {
        return direction_;
    }

/**
 * @brief Gets current x position of robot in maze
 * @return Current x position of robot in maze
 */
    int LandBasedWheeled::GetX() {
        return x_;
    }
/**
 * @brief Gets current y position of robot in maze
 * @return Current y position of robot in maze
 */
    int LandBasedWheeled::GetY(){
        return y_;
    }
/**
* @brief Turn the robot 90° counter-clockwise. Update direction robot is pointing
*/
    void LandBasedWheeled::TurnLeft() {
        API::turnLeft();
        char new_direction;
        std::cout << "LandBasedWheeled::TurnLeft is called\n";
        if (direction_ == 'n'){
            new_direction = 'w';
        }
        else if (direction_ == 'w'){
            new_direction = 's';
        }
        else if (direction_ == 's'){
            new_direction = 'e';
        }
        else {new_direction = 'n';}
        direction_ = new_direction;
    }
/**
* @brief Turn the robot 90° clockwise.
*/
    void LandBasedWheeled::TurnRight() {
        API::turnRight();
        char new_direction;
        std::cout << "LandBasedRobot::TurnRight is called\n";
        if (direction_ == 'n'){
            new_direction = 'e';
        }
        else if (direction_ == 'w'){
            new_direction = 'n';
        }
        else if (direction_ == 's'){
            new_direction = 'w';
        }
        else {new_direction = 's';}
        direction_ = new_direction;
    }
}//--namespace fp