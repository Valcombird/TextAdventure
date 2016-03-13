#pragma once
#include <string>
class Classes
{
public:
	Classes();
	~Classes();
	int classAtt;
	int classHp;
	int classDef;
	std::string name;
	int& playerAtt = classAtt;
	int& playerHp = classHp;
	int& playerDef = classDef;
	int maxHp;
	int& classNum;
	void chooseClass(int numClass);
	void theQuestion();
	void beginAdventure();
	void displayInfo();
	void levelUp();
private:
	std::string theAnswer;
};

