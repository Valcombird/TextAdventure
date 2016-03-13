#pragma once
#include <string>
class Classes
{
public:
	Classes();
	~Classes();
	int classAtt;
	int classHp;
	std::string name;
	int& playerAtt = classAtt;
	int& playerHp = classHp;
	int maxHp;
	void chooseClass(int numClass);
	void theQuestion();
	void beginAdventure();
	void displayInfo();
private:
	std::string theAnswer;
};

