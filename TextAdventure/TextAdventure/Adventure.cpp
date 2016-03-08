#include "stdafx.h"
#include "Adventure.h"
#include "Classes.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Classes gameClasses;

string chosenClass; 
string& playerClass = chosenClass;

Adventure::Adventure()
{
}


Adventure::~Adventure()
{
}

void Adventure::startAdvent() {
	chooseClass();
	cout << playerClass << endl;
	cout << chosenClass << endl;
}

void Adventure::chooseClass() {
	cout << "Which class? (Warrior or Archer) ";
	getline(cin, playerClass);
	if (playerClass == "warrior" || playerClass == "Warrior") {
		cout << "You have chosen " << playerClass << endl;
		numClass = 0;
		cout << numClass << endl;
		cout << gameClasses.playerClassHP << endl;
		cout << gameClasses.playerClassAtt << endl;
		cout << gameClasses.playerClassName << endl;
	}	else if (playerClass == "archer" || playerClass == "Archer") {
		cout << "You have chosen " << playerClass << endl;
		numClass = 1;
		cout << gameClasses.playerClassHP << endl;
		cout << gameClasses.playerClassAtt << endl;
		cout << gameClasses.playerClassName << endl;
		cout << numClass << endl;
	}	else {
		cout << "Something went wrong" << endl;
		chooseClass();
	}
	
}
