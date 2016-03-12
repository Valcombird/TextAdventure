#include "stdafx.h"
#include "Pathing.h"

#include <iostream>
#include <time.h>


Pathing::Pathing()
{
}


Pathing::~Pathing()
{
}

void Pathing::choosePath(int i) {
	srand(static_cast<unsigned int>(time(NULL)));
	switch (i) {
	case 0:
		std::cout << "Case 0" << "\n";
		branchingPath(rand() % 6, 0);
		break;
	case 1:
		std::cout << "Case 1" << "\n";
		branchingPath(rand() % 6, 0);
		break;
	case 2:
		std::cout << "Case 2" << "\n";
		branchingPath(rand() % 6, 0);
		break;
	case 3:
		std::cout << "Case 3" << "\n";
		branchingPath(rand() % 6, 0);
		break;
	case 4:
		std::cout << "Case 4" << "\n";
		branchingPath(rand() % 6, 0);
		break;
	case 5:
		std::cout << "Case 5" << "\n";
		branchingPath(rand() % 6, 0);
		break;
	case 6:
		std::cout << "Case 6" << "\n";
		branchingPath(rand() % 6, 0);
		break;
	}
	/*std::cout << "Which pathway do you choose? (Path 1, Path 2) ";
	getline(std::cin, theAnswer);
	if (theAnswer == "Path 1" || theAnswer == "path 1")
		branchingPath(1);
	else if (theAnswer == "path 2" || theAnswer == "Path 2")
		branchingPath(2);
	else {
		std::cout << "Something went wrong" << std::endl;
		choosePath();
	}*/
}

//void Pathing::choosePath2() {
//	std::cout << "Which pathway do you choose? (Path 1, Path 2, Path 3) ";
//	getline(std::cin, theAnswer);
//	if (theAnswer == "Path 1" || theAnswer == "path 1")
//		branchingPath(1);
//	else if (theAnswer == "path 2" || theAnswer == "Path 2")
//		branchingPath(2);
//	else if (theAnswer == "path 3" || theAnswer == "Path 3")
//		branchingPath(3, rand() % 21);
//	else {
//		std::cout << "Something went wrong" << std::endl;
//		choosePath2();
//	}
//}

void Pathing::branchingPath(int path, int trapPercent) {
	switch (path) {
	case 0:
		std::cout << "Case 0" << "\n";
		break;
	case 1:
		std::cout << "Case 1" << "\n";
		break;
	case 2:
		std::cout << "Case 2" << "\n";
		break;
	case 3:
		std::cout << "Case 3" << "\n";
		break;
	case 4:
		std::cout << "Case 4" << "\n";
		break;
	case 5:
		std::cout << "Case 5" << "\n";
		break;
	}
}

//void Pathing::branchingPath(int path, int trapPercent) {
//
//}
