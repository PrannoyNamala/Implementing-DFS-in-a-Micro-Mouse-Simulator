/** \file landbasedrobot.h
 * FP -Group#7
 */

#include <iostream>
#include <utility>

#ifndef RWA3_GROUP7_LANDBASEDROBOT_H
#define RWA3_GROUP7_LANDBASEDROBOT_H

namespace fp {
    class LandBasedRobot {
    public:
        explicit LandBasedRobot(std::string name = "LandRobot", int x = 0, int y = 0, char direction = 'n') : name_{name}, x_{x}, y_{y}, direction_(direction){} // Default constructor with robot pointing north at 0, 0
        virtual ~LandBasedRobot(){}

    protected:
        std::string name_;//Name of the robot.
        double speed_;//Driving speed of the robot.
        double width_;//Width of the base of the robot.SS
        double length_;//Length of the base of the robot.
        double height_;//Height of the base of the robot
        double capacity_;//Payload of the arm.
        int x_;//X-coordinate of the robot in the maze.
        int y_;//Y-coordinate of the robot in the maze.
        char direction_;//Direction that the robot is facing in the maze.

        virtual void MoveForward();
        virtual char GetDirection();
        virtual int GetX();
        virtual int GetY();
        virtual void TurnLeft();
        virtual void TurnRight();
    };//--class LandBasedRobot
}//--namespace fp


#endif //FP_GROUP7_LANDBASEDROBOT_H
