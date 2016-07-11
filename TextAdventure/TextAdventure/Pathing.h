#pragma once
#include <string>
class Pathing
{
public:
	Pathing();
	~Pathing();
	int dungeonNumber;
	std::string theAnswer;
	void chosenPath(int path, int trapPercent);
	void pathQuestion();
	void pathQuestion2();
};

