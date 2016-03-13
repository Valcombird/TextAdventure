#include "stdafx.h"
#include "DoorHandler.h"
#include "RoomHandler.h"
#include "Entity.h"

#include <iostream>
#include <string>

extern RoomHandler room;
extern Entity misc;


DoorHandler::DoorHandler()
{
}


DoorHandler::~DoorHandler()
{
}

void DoorHandler::door() {
	std::cout << "You come across a door" << std::endl;
	std::cout << "Do you open the door? ";
	getline(std::cin, theAnswer);
	if (theAnswer == "Yes" || theAnswer == "yes")
		room.room();
	else if (theAnswer == "No" || theAnswer == "no")
		misc.pit();
	else {
		std::cout << "Something went wrong" << std::endl;
		door();
	}
}
