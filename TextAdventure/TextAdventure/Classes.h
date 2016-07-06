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
	int maxHp;
	int maxMp;
	int& playerDef = classDef;
	int classNum;
	int xpForLevel = 50;
	int totalXp;
	int playerLevel = 1;
	void chooseClass(int numClass);
	void theQuestion();
	void beginAdventure();
	void displayInfo();
	void levelUp();
	//attack
	bool hasStrike;
	bool hasStraightShot;
	//support
	bool hasHeal;
private:
	std::string theAnswer;
};

