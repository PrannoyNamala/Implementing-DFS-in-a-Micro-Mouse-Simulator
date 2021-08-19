/** \file landbasedwheeled.h
 * FP -Group#7
 */

#ifndef RWA3_GROUP7_LANDBASEDWHEELED_H
#define RWA3_GROUP7_LANDBASEDWHEELED_H

#include <memory>
#include "../LandBasedRobot/landbasedrobot.h"

namespace fp {
    class LandBasedWheeled: public LandBasedRobot {
    public:
        explicit LandBasedWheeled(std::string name = "LandRobot", int x = 1, int y = 4) : LandBasedRobot(name, x, y){}
        virtual ~LandBasedWheeled(){}
        virtual char GetDirection() override;
        virtual void MoveForward() override;
        virtual int GetX() override;
        virtual int GetY() override;
        virtual void TurnLeft() override;
        virtual void TurnRight() override;
    protected:
        int wheel_number_;//Number of wheels mounted on the robot.

    };//--class LandBasedWheeled
}//--namespace fp


#endif //FP_GROUP7_LANDBASEDWHEELED_H
