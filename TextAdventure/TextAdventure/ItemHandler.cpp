#include "stdafx.h"
#include "ItemHandler.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>


ItemHandler::ItemHandler()
{
}


ItemHandler::~ItemHandler()
{
}

void ItemHandler::equipItem(int newItem) {

}

void ItemHandler::unequipItem(int oldItem) {

}

void ItemHandler::drinkPotion() {

}

void ItemHandler::loadItems() {
	std::ifstream inFile;
	std::string line;
	inFile.open("Item.txt");
	while (std::getline(inFile, line)) {
		std::stringstream ss(line);
		std::string name;
		int num, hp, att, def, mp, levelReq;
		if (ss >> num >> name >> hp >> att >> def >> mp >> levelReq) {
			itemIDHolder.push_back(num);
			itemNameHolder.push_back(name);
			itemHPHolder.push_back(hp);
			itemAttHolder.push_back(att);
			itemDefHolder.push_back(def);
			itemMPHolder.push_back(mp);
			itemLevelReqHolder.push_back(levelReq);
		}
	}
}

void ItemHandler::setStats(int itemNum) {
	itemAtt = itemAttHolder[itemNum];
	itemDef = itemDefHolder[itemNum];
	itemID = itemIDHolder[itemNum];
	itemHP = itemHPHolder[itemNum];
	itemMP = itemMPHolder[itemNum];
	itemLevelReq = itemLevelReqHolder[itemNum];
	itemName = itemNameHolder[itemNum];
}

void ItemHandler::displayStats(int itemNum) {
	setStats(itemNum);
	std::cout << "Item Name: " << itemName << "\n";
	std::cout << "Item Attack: " << itemAtt << "\n";
	std::cout << "Item Defence: " << itemDef << "\n";
	std::cout << "Item HP: " << itemHP << "\n";
	std::cout << "Item MP: " << itemMP << "\n";
	std::cout << "Item Level Req: " << itemLevelReq << "\n";
	std::getline(std::cin, itemName);
}


