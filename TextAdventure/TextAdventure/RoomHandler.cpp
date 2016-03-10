#include "stdafx.h"
#include "RoomHandler.h"
#include "Entity.h"
#include "DoorHandler.h"

#include <iostream>
#include <string>
#include <vector>

DoorHandler door;
extern Entity misc;

std::vector<int> optionsNum;
std::vector<std::string> options;

RoomHandler::RoomHandler()
{
}


RoomHandler::~RoomHandler()
{
}

void RoomHandler::search(int i) {
	/*int& optionsHandler = optionsNum[i];
	options.push_back("Search");
	options.push_back("Move on");*/
	switch (i) {
	case 0:
		std::cout << "Case 0";
		room();
		break;
	case 1:
		std::cout << "Case 1";
		room();
		break;
	case 2:
		std::cout << "Case 2";
		room();
		break;
	}
}

void RoomHandler::moveOn() {
	door.door();
}

void RoomHandler::room() {
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

