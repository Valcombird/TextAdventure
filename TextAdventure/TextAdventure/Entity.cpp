#include "stdafx.h"
#include "Entity.h"
#include "Classes.h"
#include "DoorHandler.h"
#include "RoomHandler.h"
#include "NPC.h"

#include <iostream>
#include <vector>
#include <string>

extern Classes gameClasses;
extern DoorHandler door;
extern RoomHandler room;
NPC npc;

std::vector<int> aPath;
std::vector<std::string> pathName;

Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::entrance() {
	std::cout << "You come across the entrance to a dungeon. Do you enter? ";
	getline(std::cin, theAnswer);
	if (theAnswer == "Yes" || theAnswer == "yes") {
		std::cout << "You have successfully entered the dungeon" << "\n";
		door.door();
	}
	else if (theAnswer == "No" || theAnswer == "no")
		pit();
	else {
		std::cout << "Something went wrong" << std::endl;
		entrance();
	}
}

void Entity::pit() {
	std::cout << "You fall into a pit -- Game Over" << std::endl;
	std::cout << "Do you wish to start over? ";
	getline(std::cin, theAnswer);
	if (theAnswer == "Yes" || theAnswer == "yes")
		gameClasses.theQuestion();
	else if (theAnswer == "No" || theAnswer == "no")
		std::cout << "The game is now officially over" << std::endl;
	else {
		std::cout << "Something went wrong" << std::endl;
		pit();
	}
}

void Entity::encounter(int i) {
	npc.setStats(i);
	std::cout << "You have encounterd " << npc.npcName << "\n";
	npc.displayInfo();
	takeAction();
}

void Entity::takeAction() {
	srand(static_cast<unsigned int>(time(NULL)));
	std::cout << "Take an action: (Move on) ";
	getline(std::cin, theAnswer);
	if (theAnswer == "Move on" || theAnswer == "move on")
		room.moveOn(rand() % 4);
	else {
		std::cout << "Something went wrong" << std::endl;
		takeAction();
	}
}

void Entity::death() {
	std::cout << "You have died and your adventure is now over." << "\n";
	std::cout << "Do you wish to restart? ";
	getline(std::cin, theAnswer);
	if (theAnswer == "Yes" || theAnswer == "yes")
		gameClasses.theQuestion();
	else if (theAnswer == "No" || theAnswer == "no")
		std::cout << "The game is now officially over" << std::endl;
	else {
		std::cout << "Something went wrong" << std::endl;
		death();
	}
}
