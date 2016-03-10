#include "stdafx.h"
#include "RoomHandler.h"
#include "Entity.h"
#include "DoorHandler.h"

#include <iostream>
#include <string>

DoorHandler door;
Entity misc;

RoomHandler::RoomHandler()
{
}


RoomHandler::~RoomHandler()
{
}

void RoomHandler::search() {

}

void RoomHandler::moveOn() {
	door.doorGo();
}