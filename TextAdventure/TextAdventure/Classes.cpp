#include "stdafx.h"
#include "Classes.h"
#include "Entity.h"
#include "Skills.h"

#include <iostream>
#include <string>
#include <vector>

extern Entity misc;
extern Skills skills;

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
	classNum = numClass;
	switch (numClass) {
	case 0: //warrior
		maxHp = 100;
		classHp = 100;
		maxMp = 20;
		classMp = 20;
		classAtt = 6;
		classDef = 10;
		name = "Warrior";
		hasStrike = true;
		break;
	case 1: //archer
		maxHp = 80;
		classHp = 80;
		maxMp = 40;
		classMp = 40;
		classAtt = 11;
		classDef = 5;
		name = "Archer";
		hasStraightShot = true;
		break;
	}
	std::cout << "You have chosen " << chosenClass << "\n";
	beginAdventure();
}

void Classes::levelUp() {
	if (totalXp >= xpForLevel) {
		if (classNum == 0) {
			maxHp += 25;
			playerAtt++;
			playerDef += 2;
		}
		else if (classNum == 1) {
			maxHp += 15;
			playerAtt += 2;
			playerDef++;
		}
		playerLevel++;
		xpForLevel += 100;
		std::cout << "You have leveled up!" << "\n";
		std::cout << "You are now level " << playerLevel;
	}
}

