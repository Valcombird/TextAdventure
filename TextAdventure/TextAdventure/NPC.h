#pragma once
#include <string>
class NPC
{
public:
	NPC();
	~NPC();
	NPC(int hp, int att, int def, std::string name, int xpGiven, int playerLevel);
	int npcHp;
	int npcMaxHp;
	int npcAtt;
	int npcDef;
	int npcXpGiven;
	int playerLevel;
	std::string npcName;
	void displayInfo();
	void setStats(int i);
	void setHp(int i);
	void setAtt(int i);
	void setDef(int i);
	void setName(int i);
	void setXpGiven(int i);
	void death();
};

