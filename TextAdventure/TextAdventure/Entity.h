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
private:
	std::string theAnswer;
};

