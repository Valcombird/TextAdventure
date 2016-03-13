#include "stdafx.h"
#include "NPC.h"

#include <iostream>
#include <map>

class Goblin : public NPC {
public:
	int goblinHp = 40;
	int goblinAtt = 0;
	int goblinDef = 0;
	std::string goblinName = "Goblin";
private:
};

class Orc : public NPC {
public:
	virtual void grabStats();
	virtual void displayStats();
	int orcHp;
	int orcAtt;
	int OrcDef;
	std::string orcName = "Orc";
};

class Shaman : public NPC {
public:
	virtual void grabStats();
	virtual void displayStats();
	int shamanHp;
	int shamanAtt;
	int shamanDef;
	std::string shamanName = "Shaman";
};

class Skeleton : public NPC {
public:
	virtual void grabStats();
	virtual void displayStats();
	int skeletonHp;
	int skeletonAtt;
	int skeletonDef;
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