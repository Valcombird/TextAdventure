#include "stdafx.h"
#include "Entity.h"
#include <iostream>

using namespace std;


Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::door() {
	cout << "This is door" << endl;
}

void Entity::room() {
	cout << "This is room" << endl;
}
