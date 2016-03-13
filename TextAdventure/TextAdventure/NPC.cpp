#include "stdafx.h"
#include "NPC.h"

#include <iostream>
#include <map>

class Goblin : public NPC {
public:
	int goblinHp = 40;
	int goblinAtt = 5;
	int goblinDef = 2;
	int xpGiven;
	std::string goblinName = "Goblin";
private:
};

class Orc : public NPC {
public:
	int orcHp = 0;
	int orcAtt = 0;
	int OrcDef = 0;
	int xpGiven;
	std::string orcName = "Orc";
};

class Shaman : public NPC {
public:
	int shamanHp = 0;
	int shamanAtt = 0;
	int shamanDef = 0;
	int xpGiven;
	std::string shamanName = "Shaman";
};

class Skeleton : public NPC {
public:
	int skeletonHp = 0;
	int skeletonAtt = 0;
	int skeletonDef = 0;
	int xpGiven;
	std::string skeletonName = "Skeleton";
};

Goblin goblin;



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
}

void NPC::setHp(int i) {
	std::map<int, int> statsHp;
	statsHp[0] = goblin.goblinHp;

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

void NPC::displayInfo() {
	std::cout << npcAtt << "\n";
	std::cout << npcDef << "\n";
	std::cout << npcHp << "\n";
}



//void Goblin::displayStats() {
//
//}
//
//void Goblin::grabStats() {
//
//}