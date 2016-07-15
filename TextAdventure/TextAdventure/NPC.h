#pragma once
#include <vector>
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
	int npcXpGiven;
	int npcNum;
	int playerLevel;
	int totalNpcs;
	std::string npcName;
	std::vector<std::string> npcNameHolder;
	std::vector<int> npcAttHolder;
	std::vector<int> npcDefHolder;
	std::vector<int> npcXpGivenHolder;
	std::vector<int> npcHpHolder;
	std::vector<int> npcNumber;
	void displayInfo();
	void setStats(int i);
	void npcSkillPicker(int i);
	void death();
	void loadNPCs();
	void setHp(int i);
	void setAtt(int i);
	void setDef(int i);
	void setName(int i);
	void setXpGiven(int i);
};

