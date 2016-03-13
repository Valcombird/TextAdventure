#include "stdafx.h"
#include "CombatHandler.h"
#include "NPC.h"
#include "Classes.h"
#include "Entity.h"

#include <iostream>
#include <time.h>

extern NPC npc;
extern Classes gameClasses;
extern Entity misc;

CombatHandler::CombatHandler()
{
}


CombatHandler::~CombatHandler()
{
}

//void CombatHandler::battle() {
//
//}

void CombatHandler::nextTurn() {
	srand(static_cast<unsigned int>(time(NULL)));
	if (gameClasses.playerHp > 0 && npc.npcHp > 0) {
		if (playerTurn != false) {
			std::cout << "What do you wish to do? (Attack, Heal, Flee) ";
			getline(std::cin, theAnswer);
			if (theAnswer == "attack" || theAnswer == "Attack")
				playerAttack(rand() % 101);
			else if (theAnswer == "Heal" || theAnswer == "heal")
				combatHeal();
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
		npcTurn = true;
		playerTurn = false;
		nextTurn();
	}
	else {
		if (gameClasses.name == "Warrior" && i >= 90) {
			playerDmg = rand() % (gameClasses.playerAtt * 2);
			npc.npcHp -= playerDmg;
			std::cout << "You critically hit the " << npc.npcName << " for " << playerDmg << " damage!\n";
			std::cout << "The " << npc.npcName << " has " << npc.npcHp << " hp\n";
			npcTurn = true;
			playerTurn = false;
			nextTurn();
		}
		else if (gameClasses.name == "Archer" && i >= 85) {
			playerDmg = rand() % (gameClasses.playerAtt * 2);
			npc.npcHp -= playerDmg;
			std::cout << "You critically hit the " << npc.npcName << " for " << playerDmg << " damage!\n";
			std::cout << "The " << npc.npcName << " has " << npc.npcHp << " hp\n";
			npcTurn = true;
			playerTurn = false;
			nextTurn();
		}
		else {
			playerDmg = rand() % gameClasses.playerAtt;
			npc.npcHp -= playerDmg;
			std::cout << "You hit the " << npc.npcName << " for " << playerDmg << " damage\n";
			std::cout << "The " << npc.npcName << " has " << npc.npcHp << " hp\n";
			npcTurn = true;
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
				npcTurn = false;
				playerTurn = true;
				nextTurn();
			}
			else {
				npcDmg = rand() % npc.npcAtt;
				gameClasses.playerHp -= npcDmg;
				std::cout << npc.npcName << " hit you for " << npcDmg << " damage\n";
				std::cout << "You now have " << gameClasses.playerHp << "\n";
				npcTurn = false;
				playerTurn = true;
				nextTurn();
			}
		//}
	}
	else {
		combatHeal();
		npcTurn = false;
		playerTurn = true;
		nextTurn();
	}
}

void CombatHandler::combatHeal() {
	if (playerTurn == true && npcTurn == false) {
		if (gameClasses.playerHp != gameClasses.maxHp) {
			gameClasses.playerHp += 15;
			if (gameClasses.playerHp >= gameClasses.maxHp)
				gameClasses.playerHp = gameClasses.maxHp;
			std::cout << "You now have " << gameClasses.playerHp << " hp\n";
			npcTurn = true;
			playerTurn = false;
			nextTurn();
		}
		else {
			std::cout << "You already have full hp!";
			nextTurn();
		}		
	}
	else if (playerTurn == false && npcTurn == true) {
		if (npc.npcHp != npc.npcMaxHp) {
			npc.npcHp += 10;
			if (npc.npcHp >= npc.npcMaxHp)
				npc.npcHp = npc.npcMaxHp;
			std::cout << "The " << npc.npcName << " healed for 10 hp!" << "\n";
			std::cout << npc.npcName << " now has " << npc.npcHp << " hp\n";
			npcTurn = false;
			playerTurn = true;
		}
		else {
			npcAttack(rand() % 101);
		}
	}

}

void CombatHandler::flee(int i) {
	if (i >= 30)
		misc.takeAction();
	else {
		std::cout << "You have failed to flee from combat!" << "\n";
		npcTurn = true;
		playerTurn = false;
		nextTurn();
	}
}

void CombatHandler::heal() {
	if (gameClasses.playerHp != gameClasses.maxHp) {
		gameClasses.playerHp += 15;
		if (gameClasses.playerHp >= gameClasses.maxHp)
			gameClasses.playerHp = gameClasses.maxHp;
		std::cout << "You now have " << gameClasses.playerHp << "\n";
	}
	else {
		std::cout << "You already have full hp!";
		nextTurn();
	}
}