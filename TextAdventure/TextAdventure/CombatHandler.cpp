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
			std::cout << "What do you wish to do? (Attack, Skills, Flee) ";
			getline(std::cin, theAnswer);
			if (theAnswer == "attack" || theAnswer == "Attack")
				playerAttack(rand() % 101);
			else if (theAnswer == "Skills" || theAnswer == "skills" || theAnswer == "Skill" || theAnswer == "skill")
				skillMenu();
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
	if (i >= 90) {
		playerDmg = (gameClasses.playerAtt + rand() % (gameClasses.playerAtt * 2)) - (npc.npcDef * .05);
		if (playerDmg <= 0) {
			std::cout << "You dealt no damage!" << "\n";
			playerTurn = false;
			nextTurn();
		}
		else {
			npc.npcHp -= playerDmg;
			std::cout << "You critically hit the " << npc.npcName << " for " << playerDmg << " damage!\n";
			std::cout << "The " << npc.npcName << " has " << npc.npcHp << " HP\n";
			playerTurn = false;
			nextTurn();
		}
	}
	else {
		playerDmg = rand() % (gameClasses.playerAtt + 5) - (npc.npcDef * .1);
		if (playerDmg <= 0) {
			std::cout << "You dealt no damage!" << "\n";
			playerTurn = false;
			nextTurn();
		}
		else {
			npc.npcHp -= playerDmg;
			std::cout << "You hit the " << npc.npcName << " for " << playerDmg << " damage\n";
			std::cout << "The " << npc.npcName << " has " << npc.npcHp << " HP\n";
			playerTurn = false;
			nextTurn();
		}
	}
}

void CombatHandler::npcAttack(int i) {
	srand(static_cast<unsigned int>(time(NULL)));
	if (i >= 10) {
		if (i >= 90) {
			npcDmg = (npc.npcAtt +  rand() % (npc.npcAtt * 2)) - (gameClasses.playerDef * .05);
			if (npcDmg <= 0) {
				npcDmg = 0;
				std::cout << "They dealt no damage!" << "\n";
				playerTurn = true;
				nextTurn();
			}
			else {
				gameClasses.playerHp -= npcDmg;
				std::cout << npc.npcName << " has hit hit you for a critical hit dealing " << npcDmg << " damage!\n";
				std::cout << "You now have " << gameClasses.playerHp << " HP\n";
				playerTurn = true;
				nextTurn();
			}
		}
		else {
			npcDmg = (rand() % npc.npcAtt) - (gameClasses.playerDef * .1);
			if (npcDmg <= 0) {
				npcDmg = 0;
				std::cout << "They dealt no damage!" << "\n";
				playerTurn = true;
				nextTurn();
			}
			else {
				gameClasses.playerHp -= npcDmg;
				std::cout << npc.npcName << " hit you for " << npcDmg << " damage\n";
				std::cout << "You now have " << gameClasses.playerHp << " HP\n";
				playerTurn = true;
				nextTurn();
			}
		}
	}
	else {
		skills.combatHeal();
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
	std::cout << "Your available skills are: " << "\n";
	if (gameClasses.hasStrike == true) {
		std::cout << "Strike ";
	}
	if (gameClasses.hasStraightShot == true) {
		std::cout << "Straight Shot ";
	}
	if (gameClasses.hasHeal == true) {
		std::cout << "Heal ";
	}
	std::cout << "\n";
	std::cout << "Choose a skill to use or go back to original menu (Skill name or back)" << "\n";
	getline(std::cin, theAnswer);
	skillPicker(theAnswer);
}

void CombatHandler::skillPicker(std::string skillToUse) {
	if (theAnswer == "Back" || theAnswer == "back") nextTurn();
	else {
		if (theAnswer == "Strike" || theAnswer == "strike") skills.strike();
		if (theAnswer == "Straight Shot" || theAnswer == "Straight shot" || theAnswer == "straight shot" || theAnswer == "straight Shot") skills.straightShot();
		if (theAnswer == "Heal" || theAnswer == "heal") skills.combatHeal();
		else {
			std::cout << "Something went wrong" << "\n";
			skillMenu();
		}
		playerTurn = false;
		nextTurn();
	}
}
