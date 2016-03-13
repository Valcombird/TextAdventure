#include "stdafx.h"
#include "CombatHandler.h"
#include "NPC.h"
#include "Classes.h"
#include "Entity.h"

#include <iostream>
#include <time.h>

NPC npc;
Classes gameClasses;
Entity misc;

CombatHandler::CombatHandler()
{
}


CombatHandler::~CombatHandler()
{
}

void CombatHandler::battle() {

}

void CombatHandler::nextTurn() {
	srand(static_cast<unsigned int>(time(NULL)));
	if (gameClasses.playerHp >= 0 & npc.npcHp >= 0) {
		if (playerTurn != false) {
			std::cout << "What do you wish to do? (Attack, Heal, Flee) ";
			getline(std::cin, theAnswer);
			if (theAnswer == "attack" || theAnswer == "Attack")
				playerAttack();
			else if (theAnswer == "Heal" || theAnswer == "heal")
				heal();
			else if (theAnswer == "Flee" || theAnswer == "flee")
				flee();
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

void CombatHandler::playerAttack() {

}

void CombatHandler::npcAttack(int i) {
	srand(static_cast<unsigned int>(time(NULL)));
	if (i >= 10) {
		gameClasses.playerHp -= rand() % npc.npcAtt;
		npcTurn = false;
		nextTurn();
	} else
		heal();
}

void CombatHandler::heal() {

}

void CombatHandler::flee() {

}