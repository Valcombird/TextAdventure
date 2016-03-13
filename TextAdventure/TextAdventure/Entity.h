#pragma once
#include <string>
class Entity
{
public:
	Entity();
	~Entity();
	void path(int i);
	void pit();
	void entrance();
	void encounter(int i);
private:
	std::string theAnswer;
};

