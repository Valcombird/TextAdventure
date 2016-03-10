#include "stdafx.h"
#include "Entity.h"

#include <iostream>
#include <vector>
#include <string>

std::vector<int> aPath;
std::vector<std::string> pathName;

Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::door() {
	std::cout << "This is door" << std::endl;
}

void Entity::room() {
	std::cout << "This is room" << std::endl;
}

void Entity::path(int i) {
	aPath.push_back(1);
	aPath.push_back(100);
	pathName.push_back("Test");
	int& truePath = aPath[i];
	switch (i) {
	case 0: 
		std::cout << aPath[i] << "\n";
		std::cout << pathName[i] << "\n";
		break;
	case 1:
		std::cout << aPath[i] << "\n";
		std::cout << pathName[i] << "\n";
		break;
	}
}
