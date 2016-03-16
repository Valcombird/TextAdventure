#include "stdafx.h"
#include "NPC.h"
#include "Classes.h"
#include "CombatHandler.h"
#include "Entity.h"

#include <iostream>
#include <map>

class Goblin : public NPC {
public:
	int goblinMaxHp = 40;
	int goblinHp = 40;
	int goblinAtt = 5;
	int goblinDef = 2;
	int xpGiven = 10;
	std::string goblinName = "Goblin";
};

class Orc : public NPC {
public:
	int orcHp = 0;
	int orcAtt = 0;
	int OrcDef = 0;
	int xpGiven = 20;
	std::string orcName = "Orc";
};

class Shaman : public NPC {
public:
	int shamanHp = 0;
	int shamanAtt = 0;
	int shamanDef = 0;
	int xpGiven = 25;
	std::string shamanName = "Shaman";
};

class Skeleton : public NPC {
public:
	int skeletonHp = 0;
	int skeletonAtt = 0;
	int skeletonDef = 0;
	int xpGiven = 15;
	std::string skeletonName = "Skeleton";
};

Goblin goblin;
Classes gameClasses;
CombatHandler combat;
Entity misc;


NPC::NPC()
{
}


NPC::~NPC()
{
}

void NPC::setStats(int i) {
	setHp(i);
	setDef(i);
	setAtt(i);
	setName(i);
	setXpGiven(i);
}

void NPC::setHp(int i) {
	std::map<int, int> statsHp;
	statsHp[0] = goblin.goblinMaxHp;

	npcMaxHp = statsHp[i];
	npcHp = statsHp[i];
}

void NPC::setAtt(int i) {
	std::map<int, int> statsAtt;
	statsAtt[0] = goblin.goblinAtt;

	npcAtt = statsAtt[i];
}

void NPC::setDef(int i) {
	std::map<int, int> statsDef;
	statsDef[0] = goblin.goblinDef;

	npcDef = statsDef[i];
}

void NPC::setName(int i) {
	std::map<int, std::string> statsName;
	statsName[0] = goblin.goblinName;

	npcName = statsName[i];
}

void NPC::setXpGiven(int i) {
	std::map<int, int> statsXp;
	statsXp[0] = goblin.xpGiven;

	xpGiven = statsXp[i];
}

void NPC::displayInfo() {
	std::cout << npcAtt << "\n";
	std::cout << npcDef << "\n";
	std::cout << npcHp << "\n";
}

void NPC::death() {
	std::cout << "You have killed the " << npcName << "\n";
	std::cout << "You have gained " << xpGiven << " xp\n";
	gameClasses.xpForLevel += xpGiven;
	gameClasses.levelUp();
	combat.playerTurn = true;
	combat.npcTurn = false;
	misc.takeAction();
}