#include "stdafx.h"
#include "NPC.h"
#include "Classes.h"
#include "CombatHandler.h"
#include "Entity.h"
#include "NPCSkills.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>

extern Classes gameClasses;
extern CombatHandler combat;
extern Entity misc;
NPCSkills npcSkills;

NPC::NPC()
{
}

NPC::~NPC()
{
}

void NPC::setStats(int i) {
	npcAtt = npcAttHolder[i];
	npcDef = npcDefHolder[i];
	npcMaxHp = npcHpHolder[i];
	npcHp = npcHpHolder[i];
	npcName = npcNameHolder[i];
	npcXpGiven = npcXpGivenHolder[i];
	npcNum = npcNumber[i];
}

void NPC::displayInfo() {
	std::cout << npcAtt << "\n";
	std::cout << npcDef << "\n";
	std::cout << npcHp << "\n";
}

void NPC::death() {
	std::cout << "You have killed the " << npcName << "\n";
	std::cout << "You have gained " << npcXpGiven << " xp\n";
	gameClasses.totalXp += npcXpGiven;
	gameClasses.levelUp();
	combat.playerTurn = true;
	combat.npcTurn = false;
	misc.takeAction();
}

void NPC::loadNPCs() {
	std::ifstream inFile;
	std::string line;
	inFile.open("NPC.txt");
	while (std::getline(inFile, line)) {
		std::stringstream ss(line);
		std::string name;
		int num, hp, att, def, xp;
		if (ss >> num >> name >> hp >> att >> def >> xp) {
			npcNameHolder.push_back(name);
			npcHpHolder.push_back(hp);
			npcAttHolder.push_back(att);
			npcDefHolder.push_back(def);
			npcXpGivenHolder.push_back(xp);
			npcNumber.push_back(num);
		}
	}
	inFile.close();
}

void NPC::npcSkillPicker(int i) {
	srand(static_cast<unsigned int>(time(NULL)));
	switch (npcNumber[i]) {
	case 1:
		if (rand() % 101 >= 51)
			npcSkills.npcHeal();
		else
			npcSkills.npcSmash();
		break;
	default:
		combat.npcAttack(rand() % 101);
		break;
	}
}