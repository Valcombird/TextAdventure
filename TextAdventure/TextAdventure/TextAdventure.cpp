#include "stdafx.h"
#include "Entity.h"
#include "Classes.h"
#include "RoomHandler.h"
#include <time.h>

#include <iostream>

extern Entity misc;
extern Classes gameClasses;
extern RoomHandler room;

int main()
{
	//gameClasses.theQuestion();
	gameClasses.playerHp = 100;
	room.room();
    return 0;
}

