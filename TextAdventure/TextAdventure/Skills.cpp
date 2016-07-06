#include "stdafx.h"
#include "Skills.h"
#include "Classes.h"
#include "CombatHandler.h"
#include "Entity.h"
#include "NPC.h"

#include <time.h>
#include <iostream>

Classes gameClasses;
CombatHandler combat;
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
	if (combat.playerTurn == true) {
		if (gameClasses.playerMp >= 3) {
			gameClasses.playerMp -= 3;
			combat.playerDmg = rand() % (gameClasses.playerAtt * 2 + 10);
			npc.npcHp -= combat.playerDmg;
			std::cout << "You use strike and deal "  << combat.playerDmg << " \n";
			combat.playerTurn = false;
			combat.nextTurn();
		}
		else {
			std::cout << "You don't have enough MP!" << "\n";
			combat.nextTurn();
		}
	}
}

void Skills::protect() {

}

void Skills::combatHeal() {
	if (combat.playerTurn == true) {
		if (gameClasses.playerHp != gameClasses.maxHp && gameClasses.playerMp >= 5) {
			gameClasses.playerHp += 15;
			gameClasses.playerMp -= 5;
			if (gameClasses.playerHp >= gameClasses.maxHp)
				gameClasses.playerHp = gameClasses.maxHp;
			std::cout << "You now have " << gameClasses.playerHp << " hp\n";
			combat.playerTurn = false;
			combat.nextTurn();
		}
		else {
			std::cout << "You already have full hp!";
			combat.nextTurn();
		}		
	}
	else if (combat.playerTurn == false) {
		if (npc.npcHp != npc.npcMaxHp) {
			npc.npcHp += 10;
			if (npc.npcHp >= npc.npcMaxHp)
				npc.npcHp = npc.npcMaxHp;
			std::cout << "The " << npc.npcName << " healed for 10 hp!" << "\n";
			std::cout << npc.npcName << " now has " << npc.npcHp << " hp\n";
			combat.playerTurn = true;
		}
		else {
			combat.npcAttack(rand() % 101);
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
