#include "stdafx.h"
#include "Entity.h"
#include "Classes.h"
#include "DoorHandler.h"
#include "RoomHandler.h"

#include <iostream>
#include <vector>
#include <string>

Classes gameClasses;
extern DoorHandler door;
extern RoomHandler room;

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

void Entity::path(int i) {

	/*aPath.push_back(1);
	aPath.push_back(100);
	pathName.push_back("Test");
	int& truePath = aPath[i];
	switch (i) {
	case 0: 
		std::cout << aPath[i] << "\n";
		std::cout << pathName[i] << "\n";
		break;
	case 1:
		std::cout << aPath[i] << "\n";
		std::cout << pathName[i] << "\n";
		break;
	}*/
}
