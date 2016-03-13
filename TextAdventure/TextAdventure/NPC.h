#pragma once
#include <string>
class NPC
{
public:
	NPC();
	~NPC();
	int npcHp;
	int npcAtt;
	int npcDef;
	std::string npcName;
	void displayInfo();
	void setStats(int i);
	void setHp(int i);
	void setAtt(int i);
	void setDef(int i);
	void setName(int i);
};

