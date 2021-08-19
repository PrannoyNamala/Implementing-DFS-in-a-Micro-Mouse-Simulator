#include "api.h" // Include API's header file

//This project uses an open source simulator MMS (https://github.com/mackorone/mms) to visualize path planning algorithms.

// Libraries to be included
#include <cstdlib> // General purpose library
#include <iostream> // Enables the use of the standard input/output library to read/write from/to the terminal

int fp::API::mazeWidth() { // Definition of mazeWidth Function
	std::cout << "mazeWidth" << std::endl; // Prompt for the width of the maze
	std::string response; // Generate string to handle response
	std::cin >> response; // MMS inputs the width of the maze
	return atoi(response.c_str()); // Convert MMS to integer
}

int fp::API::mazeHeight() { // Definition of mazeHeight Function
	std::cout << "mazeHeight" << std::endl; // Prompt for the height of the maze
	std::string response; // Generate string to handle response
	std::cin >> response; // MMS inputs the height of the maze
	return atoi(response.c_str()); // Convert MMS to integer
}

bool fp::API::wallFront() { // Definition of wallFront Function
	std::cout << "wallFront" << std::endl; // Prompt for if wall is in front of robot
	std::string response; // Generate string to handle response
	std::cin >> response; // MMS tells if there is a wall to the front
	return response == "true"; // true if there is a wall in front of the robot, else false
}

bool fp::API::wallRight() { // Definition of wallRight Function
	std::cout << "wallRight" << std::endl; // Prompt for is wall is to the right of the robot
	std::string response; // Generate string to handle response
	std::cin >> response; // MMS tells if there is a wall to the right
    return response == "true"; // true if there is a wall to the right of the robot, else false
}

bool fp::API::wallLeft() { // Definition of wallLeft Function
	std::cout << "wallLeft" << std::endl; // Prompt for is wall is to the left of the robot
	std::string response; // Generate string to handle response
	std::cin >> response; // MMS tells if there is a wall to the left
    return response == "true"; // true if there is a wall to the left of the robot, else false
}

void fp::API::moveForward() { // Definition of moveForward Function
	std::cout << "moveForward" << std::endl; // Prompt to move robot forward 1 space
	std::string response; // Generate string to handle response
	std::cin >> response; // MMS inputs the command to move forward
	if (response != "ack") {
		std::cerr << response << std::endl; // display input received
		throw; // throw an error if unexpected response
	}
	// moves the robot forward by one cell
}

void fp::API::turnRight() { // Definition of turnRight Function
	std::cout << "turnRight" << std::endl; // Prompt to turn robot right 90 degrees
	std::string ack; // Generate string to handle response
	std::cin >> ack; // MMS inputs the command to turn right
}

void fp::API::turnLeft() { // Definition of turnLeft Function
	std::cout << "turnLeft" << std::endl; // Prompt to turn robot left 90 degrees
	std::string ack; // Generate string to handle response
	std::cin >> ack; // MMS inputs the command to turn left
}

void fp::API::setWall(int x, int y, char direction) { // Definition of setWall Function
	std::cout << "setWall " << x << " " << y << " " << direction << std::endl; // Prompt that wall has been set at node (x,y) in direction (direction)
}

void fp::API::clearWall(int x, int y, char direction) { // Definition of clearWall Function
	std::cout << "clearWall " << x << " " << y << " " << direction << std::endl; // Prompt that wall has been cleared at node (x,y) in direction (direction)
}

void fp::API::setColor(int x, int y, char color) { // Definition of setColor Function
	std::cout << "setColor " << x << " " << y << " " << color << std::endl; // Prompt that color of node has been set at node (x,y) to color (color)
}

void fp::API::clearColor(int x, int y) { // Definition of clearColor Function
	std::cout << "clearColor " << x << " " << y << std::endl; // Prompt that color of node has been cleared at node (x,y)
}

void fp::API::clearAllColor() { // Definition of clearAllColor Function
	std::cout << "clearAllColor" << std::endl; // Prompt that color of all nodes have been cleared
}

void fp::API::setText(int x, int y, const std::string& text) { // Definition of mazeWidth Function
	std::cout << "setText " << x << " " << y << " " << text << std::endl; // Prompt that the text of node at (x,y) has been set to (text)
}

void fp::API::clearText(int x, int y) { // Definition of clearText Function
	std::cout << "clearText " << x << " " << y << std::endl; // Prompt that text of node at (x,y) has been cleared
}

void fp::API::clearAllText() { // Definition of clearAllText Function
	std::cout << "clearAllText" << std::endl; // Prompt that text of all nodes has been cleared
}

bool fp::API::wasReset() { // Definition of wasReset Function
	std::cout << "wasReset" << std::endl; // Prompt whether or not simulation was reset
	std::string response; // Generate string to handle response
	std::cin >> response; // MMS inputs if maze has been reset
	return response == "true"; // returns true if the simulation has been reset
}

void fp::API::ackReset() { // Definition of ackReset Function
	std::cout << "ackReset" << std::endl; // Prompts for reset of the simulation
	std::string ack; // create string to handle reseting of the simulation
	std::cin >> ack; // reset the simulation based on contents of ack
}
