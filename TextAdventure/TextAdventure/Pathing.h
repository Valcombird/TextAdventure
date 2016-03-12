#pragma once
#include <string>
class Pathing
{
public:
	Pathing();
	~Pathing();
	void branchingPath(int path);
	void branchingPath(int path, int trapPercent);
	void choosePath(int i);
	void choosePath2();
	std::string theAnswer;
};

