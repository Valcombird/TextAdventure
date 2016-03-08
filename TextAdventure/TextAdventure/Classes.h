#pragma once
#include <string>
class Classes
{
public:
	Classes();
	~Classes();
	int classAtt;
	int playerClassHP;
	int playerClassAtt;
	//std::string playerClassName;
	std::vector<int> playerHp;
	std::vector<int> playerAtt;
	std::vector<int> playerClassName;
};

