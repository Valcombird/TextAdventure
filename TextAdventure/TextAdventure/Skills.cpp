#include "stdafx.h"
#include "Skills.h"
#include "Classes.h"
#include "CombatHandler.h"
#include "Entity.h"
#include "NPC.h"

#include <time.h>
#include <iostream>

Classes gameClasses;
extern CombatHandler combat;
Entity misc;
extern NPC npc;

Skills::Skills()
{
}


Skills::~Skills()
{
}

void Skills::strike() {
	srand(static_cast<unsigned int>(time(NULL)));
	if (gameClasses.hasStrike != true) {
		std::cout << "You don't know this skill!" << "\n";
		combat.skillMenu();
	}
	else {
		if (combat.playerTurn == true) {
			if (gameClasses.playerMp >= 3) {
				gameClasses.playerMp -= 3;
				combat.playerDmg = gameClasses.playerAtt + rand() % (gameClasses.playerAtt * 2);
				npc.npcHp -= combat.playerDmg;
				std::cout << "You use strike and deal " << combat.playerDmg << " damage\n";
				std::cout << "The " << npc.npcName << " has " << npc.npcHp << " HP left\n";
				std::cout << "You have " << gameClasses.playerMp << " MP left.\n";
				combat.playerTurn = false;
				combat.nextTurn();
			}
			else {
				std::cout << "You don't have enough MP!" << "\n";
				combat.nextTurn();
			}
		}
	}
}

void Skills::straightShot() {
	if (gameClasses.hasStraightShot != true) {
		std::cout << "You don't know this skill!" << "\n";
		combat.skillMenu();
	}
	else {
		if (combat.playerTurn == true) {

		}
	}
}

void Skills::protect() {

}

void Skills::combatHeal() {
	if (combat.playerTurn == true) {
		if (gameClasses.playerHp != gameClasses.maxHp) {
			if (gameClasses.playerMp >= 5) {
				gameClasses.playerHp += 15;
				gameClasses.playerMp -= 5;
				if (gameClasses.playerHp >= gameClasses.maxHp)
					gameClasses.playerHp = gameClasses.maxHp;
				std::cout << "You now have " << gameClasses.playerHp << " hp\n";
				combat.playerTurn = false;
				combat.nextTurn();
			}
			else {
				std::cout << "You don't have enough MP!" << "\n";
				combat.nextTurn();
			}
		}
		else {
			std::cout << "You already have full hp!";
			combat.nextTurn();
		}		
	}
}

void Skills::heal() {
	int i = 0;
	do {
		if (gameClasses.playerHp != gameClasses.maxHp && gameClasses.playerMp >= 5) {
			gameClasses.playerHp += 15;
			gameClasses.playerMp -= 5;
			if (gameClasses.playerHp >= gameClasses.maxHp) 
				gameClasses.playerHp = gameClasses.maxHp;
			std::cout << "You now have " << gameClasses.playerHp << "\n";
			misc.takeAction();
		}
		else {
			std::cout << "You already have full hp!" << "\n";
			misc.takeAction();
		}
		i++;
	} while (i <= 0);
}
