#include "stdafx.h"
#include "RoomHandler.h"
#include "Entity.h"
#include "DoorHandler.h"
#include "Pathing.h"
#include "NPC.h"
#include "ItemHandler.h"

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

DoorHandler door;
extern Entity misc;
Pathing path;
extern NPC npc;
extern ItemHandler item;

RoomHandler::RoomHandler()
{
}


RoomHandler::~RoomHandler()
{
}

void RoomHandler::search(int i) {
	srand(static_cast<unsigned int>(time(NULL)));
	switch (i) {
	case 0:
		std::cout << "You found nothing -- Case 0" << "\n";
		item.inventory.push_back(3);
		misc.takeAction();
		break;
	case 1:
		std::cout << "You found something -- Case 1" << "\n";
		item.inventory.push_back(3);
		misc.takeAction();
		break;
	case 2:
		std::cout << "You found everything -- Case 2" << "\n";
		item.inventory.push_back(3);
		misc.takeAction();
		break;
	case 3:
		std::cout << "You found something -- Case 3" << "\n";
		item.inventory.push_back(3);
		misc.takeAction();
		break;
	}
}

void RoomHandler::moveOn(int i) {
	srand(static_cast<unsigned int>(time(NULL)));
	switch (i) {
	case 0: //2 path question
		path.pathQuestion();
		break;
	case 1: //3 path question
		path.pathQuestion2();
		break;
	case 2: //plain door
		door.door();
		break;
	case 3: //random enemy encounter
		misc.encounter(rand() % 3);
		break;
	case 4: //locked door
		break;
	}
}

void RoomHandler::room() {
	srand(static_cast<unsigned int>(time(NULL)));
	std::cout << "You walk into the room" << std::endl;
	std::cout << "What do you wish to do? (Search, Move on) ";
	getline(std::cin, theAnswer);
	if (theAnswer == "Search" || theAnswer == "search")
		search(rand() % 3);
	else if (theAnswer == "Move on" || theAnswer == "move on" || theAnswer == "Move On")
		moveOn(3);
		//moveOn(rand() % 4);
	else {
		std::cout << "Something went wrong" << std::endl;
		room();
	}
}

