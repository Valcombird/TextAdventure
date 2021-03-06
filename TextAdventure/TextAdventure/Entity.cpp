#include "stdafx.h"
#include "Entity.h"
#include "Classes.h"
#include "DoorHandler.h"
#include "RoomHandler.h"
#include "NPC.h"
#include "CombatHandler.h"
#include "Skills.h"

#include <iostream>
#include <vector>
#include <string>
#include <time.h>

extern Classes gameClasses;
extern DoorHandler door;
extern RoomHandler room;
extern Skills skills;
extern NPC npc;
extern CombatHandler combat;

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
	std::cout << "You have encounterd a " << npc.npcName << "\n";
	combat.nextTurn();
}

void Entity::takeAction() {
	srand(static_cast<unsigned int>(time(NULL)));
	std::cout << "Take an action: (Move on, Check stats, or heal) ";
	getline(std::cin, theAnswer);
	if (theAnswer == "Move on" || theAnswer == "move on")
		room.moveOn(rand() % 4);
	if (theAnswer == "Check Stats" || theAnswer == "Check stats" || theAnswer == "check stats" || theAnswer == "check Stats")
		gameClasses.displayInfo();
	if (theAnswer == "Heal" || theAnswer == "heal")
		skills.heal();
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
