/** \file landbasedtracked.h
 * FP -Group#7
 */

#ifndef RWA3_GROUP7_LANDBASEDTRACKED_H
#define RWA3_GROUP7_LANDBASEDTRACKED_H

#include <memory>
#include "../LandBasedRobot/landbasedrobot.h"

namespace fp {
    class LandBasedTracked: public LandBasedRobot {
    public:
        explicit LandBasedTracked(std::string name = "LandRobot", int x = 0, int y = 0, char direction = 'n') : LandBasedRobot(name, x, y, direction){}
        virtual ~LandBasedTracked(){}
        virtual char GetDirection() override;
        virtual void MoveForward() override;
        virtual int GetX() override;
        virtual int GetY() override;
        virtual void TurnLeft() override;
        virtual void TurnRight() override;

    protected:
        std::string track_type_;//Type of track mounted on the robot.


    };//--class LandBasedTracked
}//--namespace fp

#endif //FP_GROUP7_LANDBASEDTRACKED_H
