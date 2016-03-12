#include "stdafx.h"
#include "RoomHandler.h"
#include "Entity.h"
#include "DoorHandler.h"
#include "Pathing.h"

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

DoorHandler door;
extern Entity misc;
Pathing path;

std::vector<int> optionsNum;
std::vector<std::string> options;

RoomHandler::RoomHandler()
{
}


RoomHandler::~RoomHandler()
{
}

void RoomHandler::search(int i) {
	srand(static_cast<unsigned int>(time(NULL)));
	/*int& optionsHandler = optionsNum[i];
	options.push_back("Search");
	options.push_back("Move on");*/
	switch (i) {
	case 0:
		std::cout << "You found nothing -- Case 0" << "\n";
		//door.door();
		room();
		break;
	case 1:
		std::cout << "You found something -- Case 1" << "\n";
		path.choosePath(rand() % 7);
		break;
	case 2:
		std::cout << "You found everything -- Case 2" << "\n";
		//door.door();
		room();
		break;
	}
}

void RoomHandler::moveOn() {
	door.door();
}

void RoomHandler::room() {
	srand(static_cast<unsigned int>(time(NULL)));
	std::cout << "You walk into the room" << std::endl;
	std::cout << "What do you wish to do? (Search, Move on) ";
	getline(std::cin, theAnswer);
	if (theAnswer == "Search" || theAnswer == "search")
		search(rand() % 3);
	else if (theAnswer == "Move on" || theAnswer == "move on" || theAnswer == "Move On")
		misc.pit();
	else {
		std::cout << "Something went wrong" << std::endl;
		room();
	}
}

