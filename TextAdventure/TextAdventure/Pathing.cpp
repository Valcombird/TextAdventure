#include "stdafx.h"
#include "Pathing.h"
#include "Classes.h"
#include "RoomHandler.h"

#include <iostream>
#include <time.h>

extern Classes gameClasses;
RoomHandler room;


Pathing::Pathing()
{
}


Pathing::~Pathing()
{
}

void Pathing::pathQuestion() {
	srand(static_cast<unsigned int>(time(NULL)));
	std::cout << "Which pathway do you choose? (Path 1, Path 2) ";
	getline(std::cin, theAnswer);
	if (theAnswer == "Path 1" || theAnswer == "path 1")
		chosenPath(rand() % 6, 0);
	else if (theAnswer == "path 2" || theAnswer == "Path 2")
		chosenPath(rand() % 6, 0);
	else {
		std::cout << "Something went wrong" << std::endl;
		pathQuestion();
	}
}

void Pathing::pathQuestion2() {
	srand(static_cast<unsigned int>(time(NULL)));
	std::cout << "Which pathway do you choose? (Path 1, Path 2, Path 3) ";
	getline(std::cin, theAnswer);
	if (theAnswer == "Path 1" || theAnswer == "path 1")
		chosenPath(rand() % 6, 0);
	else if (theAnswer == "path 2" || theAnswer == "Path 2")
		chosenPath(rand() % 6, 0);
	else if (theAnswer == "path 3" || theAnswer == "Path 3")
		chosenPath(rand() % 6, 0);
	else {
		std::cout << "Something went wrong" << std::endl;
		pathQuestion2();
	}
}

void Pathing::chosenPath(int path, int trapPercent) {
	switch (path) {
	case 0:
		std::cout << "Case 0" << "\n";
		std::cout << gameClasses.playerHp << "\n";
		room.moveOn(rand() % 4);
		break;
	case 1:
		std::cout << "Case 1" << "\n";
		std::cout << gameClasses.playerHp << "\n";
		room.moveOn(rand() % 4);
		break;
	case 2:
		std::cout << "Case 2" << "\n";
		std::cout << gameClasses.playerHp << "\n";
		room.moveOn(rand() % 4);
		break;
	case 3:
		std::cout << "Case 3" << "\n";
		std::cout << gameClasses.playerHp << "\n";
		room.moveOn(rand() % 4);
		break;
	case 4:
		std::cout << "Case 4" << "\n";
		std::cout << gameClasses.playerHp << "\n";
		room.moveOn(rand() % 4);
		break;
	case 5:
		std::cout << "Case 5" << "\n";
		std::cout << gameClasses.playerHp << "\n";
		room.moveOn(rand() % 4);
		break;
	}
}
