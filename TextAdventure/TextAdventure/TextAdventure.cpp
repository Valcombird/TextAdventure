// TextAdventure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Entity.h"
#include "Adventure.h"
#include "Classes.h"

using namespace std;

Entity misc;
extern Adventure advent;
extern Classes gameClasses;

int main()
{
	advent.startAdvent();
    return 0;
}

