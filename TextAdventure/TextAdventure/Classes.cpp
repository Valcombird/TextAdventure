#include "stdafx.h"
#include "Classes.h"
#include "Entity.h"
#include "Skills.h"
#include "ItemHandler.h"

#include <iostream>
#include <string>
#include <vector>

extern Entity misc;
extern Skills skills;
extern ItemHandler item;

std::string chosenClass;
std::string& playerClassName = chosenClass;

Classes::Classes()
{
}


Classes::~Classes()
{
}

void Classes::displayInfo() {
	std::cout << "HP: " << playerHp << " MP: " << playerMp << "\n";
	std::cout << "Attack: " << playerAtt << " Defence: " << playerDef << "\n";
	std::cout << "Exp needed to level: " << xpForLevel - totalXp << "\n";
	misc.takeAction();
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
		//maxHp = 100;
		maxHp = 9999;
		//classHp = 100;
		classHp = 9999;
		//maxMp = 20;
		maxMp = 9999;
		//classMp = 20;
		classMp = 9999;
		classAtt = 9999;
		//classAtt = 6;
		classDef = 10;
		name = "Warrior";
		hasStrike = true;
		break;
	case 1: //archer
		maxHp = 80;
		classHp = 80;
		maxMp = 40;
		classMp = 28;
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
			maxMp += 10;
			playerAtt++;
			playerDef += 2;
		}
		else if (classNum == 1) {
			maxHp += 15;
			maxMp += 8;
			playerAtt += 2;
			playerDef++;
		}
		playerLevel++;
		xpForLevel += 10 + totalXp;
		std::cout << "You have leveled up!" << "\n";
		std::cout << "You are now level " << playerLevel << "!\n";
	}
}

