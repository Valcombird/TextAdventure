#pragma once
#include <string>
class Pathing
{
public:
	Pathing();
	~Pathing();
	void chosenPath(int path);
	void chosenPath(int path, int trapPercent);
	void choosePath(int i);
	void choosePath2(int i);
	std::string theAnswer;
	void pathQuestion();
	void pathQuestion2();
};

