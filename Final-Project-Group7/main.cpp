/** \file main.cpp
 * FP -Group#7
 */

#include "LandBasedRobot/landbasedrobot.h"
#include "LandBasedTracked/landbasedtracked.h"
#include "LandBasedWheeled/landbasedwheeled.h"
#include "Algorithm/algorithm.h"
#include "Maze/maze.h"
#include <iostream>
#include <memory>
#include "API/api.h"

using namespace fp;

    int main() {
        std::shared_ptr<fp::LandBasedRobot> wheeled = std::make_shared<fp::LandBasedWheeled>("husky"); // Sets shared pointer to LandBasedRobot for polymorphism
        fp::Algorithm algo; // Creates algo object from Algorithm class
        algo.Solve(); // Calls solve function
        return 0;
    }
