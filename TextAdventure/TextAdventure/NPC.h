#pragma once
#include <string>
class NPC
{
public:
	NPC();
	~NPC();
	int npcHp;
	int npcMaxHp;
	int npcAtt;
	int npcDef;
	int xpGiven;
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

