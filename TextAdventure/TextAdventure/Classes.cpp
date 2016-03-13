#include "stdafx.h"
#include "Classes.h"
#include "Entity.h"

#include <iostream>
#include <string>
#include <vector>

Entity misc;

std::string chosenClass;
std::string& playerClassName = chosenClass;

Classes::Classes()
{
}


Classes::~Classes()
{
}

void Classes::displayInfo() {
	std::cout << playerHp << std::endl;
	std::cout << playerAtt << std::endl;
	std::cout << name << std::endl;
}

void Classes::theQuestion() {
	std::cout << "Which class? (Warrior or Archer) ";
	getline(std::cin, chosenClass);
	if (chosenClass == "warrior" || chosenClass == "Warrior") {
		chooseClass(0);
		beginAdventure();
	}	
	else if (chosenClass == "archer" || chosenClass == "Archer") {
		chooseClass(1);
		beginAdventure();
	}
	else {
		std::cout << "Something went wrong" << std::endl;
		theQuestion();
	}
}

void Classes::beginAdventure() {
	std::cout << "Are you prepared to begin your adventure? ";
	getline(std::cin, theAnswer);
	if (theAnswer == "Yes" || theAnswer == "yes")
		misc.entrance();
	else if (theAnswer == "No" || theAnswer == "no")
		misc.pit();
	else {
		std::cout << "Something went wrong" << std::endl;
		beginAdventure();
	}
}

void Classes::chooseClass(int numClass) {
	switch (numClass) {
	case 0: //warrior
		std::cout << "You have chosen " << chosenClass << std::endl;
		maxHp = 100;
		classHp = 100;
		classAtt = 6;
		name = "Warrior";
		displayInfo();
		beginAdventure();
		break;
	case 1: //archer
		std::cout << "You have chosen " << chosenClass << std::endl;
		maxHp = 80;
		classHp = 80;
		classAtt = 9;
		name = "Archer";
		displayInfo();
		beginAdventure();
		break;
	}
}

//int classHP[] = { 100, 80 };
//int& playerClassHP = classHP[advent.numClass];
//int classAtt[] = { 70, 90 };
//int& playerClassAtt = classAtt[advent.numClass];
//string classNames[] = { "Warrior", "Archer" };
//string& playerClassName = classNames[advent.numClass];
