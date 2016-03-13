#include "stdafx.h"
#include "Entity.h"
#include "Classes.h"
#include "RoomHandler.h"

#include <iostream>
#include <string>


extern Entity misc;
extern Classes gameClasses;
extern RoomHandler room;

int main()
{
	gameClasses.theQuestion();
	//room.room();
	//room.moveOn(3);
	return 0;
}

