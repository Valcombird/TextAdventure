#include "stdafx.h"
#include "CombatHandler.h"
#include "NPC.h"
#include "Classes.h"
#include "Entity.h"
#include "Skills.h"

#include <iostream>
#include <time.h>

NPC npc;
extern Classes gameClasses;
Skills skills;
extern Entity misc;

CombatHandler::CombatHandler()
{
}


CombatHandler::~CombatHandler()
{
}

void CombatHandler::nextTurn() {
	srand(static_cast<unsigned int>(time(NULL)));
	if (gameClasses.playerHp > 0 && npc.npcHp > 0) {
		if (playerTurn == true) {
			std::cout << "What do you wish to do? (Attack, Heal, Flee) ";
			getline(std::cin, theAnswer);
			if (theAnswer == "attack" || theAnswer == "Attack")
				playerAttack(rand() % 101);
			else if (theAnswer == "Heal" || theAnswer == "heal")
				skills.heal();
			else if (theAnswer == "Flee" || theAnswer == "flee")
				flee(rand() % 101);
			else {
				std::cout << "Something went wrong" << std::endl;
				nextTurn();
			}
		}
		else
			npcAttack(rand() % 101);
	}
	else if (gameClasses.playerHp <= 0)
		misc.death();
	else if (npc.npcHp <= 0)
		npc.death();
}

void CombatHandler::playerAttack(int i) {
	srand(static_cast<unsigned int>(time(NULL)));
	if (npc.npcDef >= gameClasses.playerAtt) {
		npc.npcHp -= 2;
		std::cout << "You hit the " << npc.npcName << " for 2 damage\n";
		std::cout << "The " << npc.npcName << " has " << npc.npcHp << " hp\n";
		playerTurn = false;
		nextTurn();
	}
	else {
		if (gameClasses.name == "Warrior" && i >= 90) {
			playerDmg = rand() % (gameClasses.playerAtt * 2);
			npc.npcHp -= playerDmg;
			std::cout << "You critically hit the " << npc.npcName << " for " << playerDmg << " damage!\n";
			std::cout << "The " << npc.npcName << " has " << npc.npcHp << " hp\n";
			playerTurn = false;
			nextTurn();
		}
		else if (gameClasses.name == "Archer" && i >= 85) {
			playerDmg = rand() % (gameClasses.playerAtt * 2);
			npc.npcHp -= playerDmg;
			std::cout << "You critically hit the " << npc.npcName << " for " << playerDmg << " damage!\n";
			std::cout << "The " << npc.npcName << " has " << npc.npcHp << " hp\n";
			playerTurn = false;
			nextTurn();
		}
		else {
			playerDmg = rand() % (gameClasses.playerAtt + 1);
			npc.npcHp -= playerDmg;
			std::cout << "You hit the " << npc.npcName << " for " << playerDmg << " damage\n";
			std::cout << "The " << npc.npcName << " has " << npc.npcHp << " hp\n";
			playerTurn = false;
			nextTurn();
		}
	}
}

void CombatHandler::npcAttack(int i) {
	srand(static_cast<unsigned int>(time(NULL)));
	if (i >= 10) {
		/*if (gameClasses.playerDef >= npc.npcAtt) {
			gameClasses.playerHp -= 2;
			std::cout << npc.npcName << " hit you for 2 damage" << "\n";
			std::cout << "You now have " << gameClasses.playerHp << "\n";
			npcTurn = false;
			playerTurn = true;
			nextTurn();
		}*/
		//else {
			if (i >= 85) {
				npcDmg = rand() % (npc.npcAtt * 2);
				gameClasses.playerHp -= npcDmg;
				std::cout << npc.npcName << " has hit hit you for a critical hit dealing " << npcDmg << " damage!\n";
				std::cout << "You now have " << gameClasses.playerHp << "\n";
				playerTurn = true;
				nextTurn();
			}
			else {
				npcDmg = rand() % npc.npcAtt;
				gameClasses.playerHp -= npcDmg;
				std::cout << npc.npcName << " hit you for " << npcDmg << " damage\n";
				std::cout << "You now have " << gameClasses.playerHp << "\n";
				playerTurn = true;
				nextTurn();
			}
		//}
	}
	else {
		skills.heal();
		playerTurn = true;
		nextTurn();
	}
}

void CombatHandler::flee(int i) {
	if (i >= 30)
		misc.takeAction();
	else {
		std::cout << "You failed to flee from combat!" << "\n";
		playerTurn = false;
		nextTurn();
	}
}

void CombatHandler::skillMenu() {

}
