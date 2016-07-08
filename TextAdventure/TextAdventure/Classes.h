#pragma once
#include <string>
class Classes
{
public:
	Classes();
	~Classes();
	int classAtt;
	int classHp;
	int classMp;
	int classDef;
	std::string name;
	int& playerAtt = classAtt;
	int& playerHp = classHp;
	int& playerMp = classMp;
	int& playerDef = classDef;
	int maxHp;
	int maxMp;
	int classNum;
	int xpForLevel = 20;
	int totalXp;
	int playerLevel = 1;
	void chooseClass(int numClass);
	void theQuestion();
	void beginAdventure();
	void displayInfo();
	void levelUp();
	//attack
	bool hasStrike = false;
	bool hasStraightShot = false;
	//support
	bool hasHeal = true;
private:
	std::string theAnswer;
};

