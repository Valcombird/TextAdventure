#include "stdafx.h"
#include "Entity.h"
#include "Classes.h"
#include "RoomHandler.h"
#include "NPC.h"

#include <iostream>
#include <string>


extern Entity misc;
extern Classes gameClasses;
extern RoomHandler room;
extern NPC npc;

int main()
{
	npc.loadNPCs();
	gameClasses.theQuestion();
	return 0;
}

