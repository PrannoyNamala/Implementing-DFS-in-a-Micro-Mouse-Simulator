#pragma once // Ensure API is not "redefined"

// Libraries to be included
#include <string> // Enables the use of the string library for literal strings

/**
 * Header for API Class
 * Scenario: A robot navigates through a maze to reach the center of the maze.
 * This project uses an open source simulator (https://github.com/mackorone/mms) to visualize
 * path planning algorithms.
 * The interaction between this program and the simulator can be performed using built-in methods
 * from the API class. These methods can be found at https://github.com/mackorone/mms and have
 * been implemented in the function definitions below.
*/


namespace fp {  // All functions/classes need to be in fp namespace
	class API { // Define API Class
        public: // Methods
            /**
            * A function that returns the width of the maze.
            * @param void
            */
            static int mazeWidth();//--return the width of the maze
            /**
            * A function that returns the height of the maze.
            * @param void
            */
            static int mazeHeight();//--return the height of the maze
            /**
            * A function that returns true if there is a wall in front of the robot, else false.
            * @param void
            */
            static bool wallFront();//--true if there is a wall in front of the robot, else false
            /**
            * A function that returns true if there is a wall to the right of the robot, else false
            * @param void
            */
            static bool wallRight();//--true if there is a wall to the right of the robot, else false
            /**
            * A function that returns true if there is a wall to the left of the robot, else false
            * @param void
            */
            static bool wallLeft();//--true if there is a wall to the left of the robot, else false
            /**
            * A function that moves the robot forward by one cell
            * @param void
            */
            static void moveForward();//--move the robot forward by one cell
            /**
            * A function that turns the robot 90 degrees to the right
            * @param void
            */
            static void turnRight();//--turn the robot 90 degrees to the right
            /**
            * A function that turns the robot 90 degrees to the left
            * @param void
            */
            static void turnLeft();//--turn the robot 90 degrees to the left
            /**
            * A function that displays a wall in maze.
            * @param x the x location of the wall, where x=0 is the left-most size of the maze and x increases to the right
            * @param y the y location of the wall, where y=0 is the bottom-most size of the maze and y increases upwards
            * @param direction the direction of the wall which borders the cell (n,s,e, or w)
            */
            static void setWall(int x, int y, char direction);//--display a wall in maze
            /**
            * A function that clears a wall from maze
            * @param x the x location of the cell, where x=0 is the left-most size of the maze and x increases to the right
            * @param y the y location of the cell, where y=0 is the bottom-most size of the maze and y increases upwards
            * @param direction the direction of the wall which borders the cell (n,s,e, or w)
            */
            static void clearWall(int x, int y, char direction);//--clear a wall from maze
            /**
            * A function that sets the color of a cell
            * @param x the x location of the cell, where x=0 is the left-most size of the maze and x increases to the right
            * @param y the y location of the cell, where y=0 is the bottom-most size of the maze and y increases upwards
            * @param color the color of the cell
            */
            static void setColor(int x, int y, char color);//--set the color of a cell
            /**
            * A function that clears the color of a cell
            * @param x the x location of the cell, where x=0 is the left-most size of the maze and x increases to the right
            * @param y the y location of the cell, where y=0 is the bottom-most size of the maze and y increases upwards
            */
            static void clearColor(int x, int y);//--clear the color of a cell
            /**
            * A function that clear the color of all cells
            * @param void
            */
            static void clearAllColor();//--clear the color of all cells
            /**
            * A function that sets the text of a cell
            * @param x the x location of the cell, where x=0 is the left-most size of the maze and x increases to the right
            * @param y the y location of the cell, where y=0 is the bottom-most size of the maze and y increases upwards
            * @param text the text to be displayed in the cell
            */
            static void setText(int x, int y, const std::string& text);//--set the text of a cell
            /**
            * A function that clears the text of a cell
            * @param x the x location of the cell, where x=0 is the left-most size of the maze and x increases to the right
            * @param y the y location of the cell, where y=0 is the bottom-most size of the maze and y increases upwards
            */
            static void clearText(int x, int y);//--clear the text of a cell
            /**
            * A function that clears the text of all cells
            * @param void
            */
            static void clearAllText();//--clear the text of all cells
            /**
            * A function that returns true if the reset button was pressed, else false
            * @param void
            */
            static bool wasReset();//--true if the reset button was pressed, else false
            /**
            * A function that resets the simulation
            * @param void
            */
            static void ackReset();//--reset simulation
	}; //--class API
}//--namespace fp
