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
	void chooseClass(int numClass);
	void theQuestion();
private:

};

