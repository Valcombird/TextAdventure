#include "stdafx.h"
#include "Entity.h"
#include "Classes.h"

#include <iostream>



extern Entity misc;
Classes gameClasses;

int main()
{
	//gameClasses.theQuestion();
	int x;
	std::cin >> x;
	misc.path(x);
    return 0;
}

