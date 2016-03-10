#include "stdafx.h"
#include "DoorHandler.h"
#include "RoomHandler.h"
#include "Entity.h"

#include <iostream>
#include <string>

RoomHandler room;
Entity misc;


DoorHandler::DoorHandler()
{
}


DoorHandler::~DoorHandler()
{
}

void DoorHandler::doorGo() {
	std::cout << "You come across another door." << "\n";
	std::cout << "What do you do? ";
}
