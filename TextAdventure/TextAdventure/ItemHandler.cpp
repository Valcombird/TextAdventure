#include "stdafx.h"
#include "ItemHandler.h"
#include "Entity.h"
#include "Classes.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

extern Entity misc;
extern Classes gameClasses;

ItemHandler::ItemHandler()
{
}


ItemHandler::~ItemHandler()
{
}

void ItemHandler::equipItem(int itemType, int newItem) {
	switch (itemType) {
	case 1: //weapon
		if (gameClasses.playerLevel >= itemLevelReqHolder[newItem]) {
			unequipItem(itemType, weaponEquipped);
			weaponEquipped = newItem;
			deleteItem(newItem);
			gameClasses.playerAtt += itemAttHolder[newItem];
			gameClasses.playerDef += itemDefHolder[newItem];
			gameClasses.playerHp += itemHPHolder[newItem];
			gameClasses.maxMp += itemMPHolder[newItem];
		}
		else {
			std::cout << "You're level is too low to wear that!" << "\n";
		}
		break;
	case 2: //helm
		if (gameClasses.playerLevel >= itemLevelReqHolder[newItem]) {
			unequipItem(itemType, helmEquipped);
			helmEquipped = newItem;
			deleteItem(newItem);
			gameClasses.playerAtt += itemAttHolder[newItem];
			gameClasses.playerDef += itemDefHolder[newItem];
			gameClasses.playerHp += itemHPHolder[newItem];
			gameClasses.maxMp += itemMPHolder[newItem];
		}
		else {
			std::cout << "You're level is too low to wear that!" << "\n";
		}
		break;
	case 3: //body
		if (gameClasses.playerLevel >= itemLevelReqHolder[newItem]) {
			unequipItem(itemType, bodyEquipped);
			bodyEquipped = newItem;
			deleteItem(newItem);
			gameClasses.playerAtt += itemAttHolder[newItem];
			gameClasses.playerDef += itemDefHolder[newItem];
			gameClasses.playerHp += itemHPHolder[newItem];
			gameClasses.maxMp += itemMPHolder[newItem];
		}
		else {
			std::cout << "You're level is too low to wear that!" << "\n";
		}
		break;
	case 4: //legs
		if (gameClasses.playerLevel >= itemLevelReqHolder[newItem]) {
			unequipItem(itemType, legsEquipped);
			legsEquipped = newItem;
			deleteItem(newItem);
			gameClasses.playerAtt += itemAttHolder[newItem];
			gameClasses.playerDef += itemDefHolder[newItem];
			gameClasses.playerHp += itemHPHolder[newItem];
			gameClasses.maxMp += itemMPHolder[newItem];
		}
		else {
			std::cout << "You're level is too low to wear that!" << "\n";
		}
		break;
	case 5: //necklace
		if (gameClasses.playerLevel >= itemLevelReqHolder[newItem]) {
			unequipItem(itemType, necklaceEquipped);
			necklaceEquipped = newItem;
			deleteItem(newItem);
			gameClasses.playerAtt += itemAttHolder[newItem];
			gameClasses.playerDef += itemDefHolder[newItem];
			gameClasses.playerHp += itemHPHolder[newItem];
			gameClasses.maxMp += itemMPHolder[newItem];
		}
		else {
			std::cout << "You're level is too low to wear that!" << "\n";
		}
		break;
	case 6: //shield
		if (gameClasses.playerLevel >= itemLevelReqHolder[newItem]) {
			unequipItem(itemType, shieldEquipped);
			shieldEquipped = newItem;
			deleteItem(newItem);
			gameClasses.playerAtt += itemAttHolder[newItem];
			gameClasses.playerDef += itemDefHolder[newItem];
			gameClasses.playerHp += itemHPHolder[newItem];
			gameClasses.maxMp += itemMPHolder[newItem];
		}
		else {
			std::cout << "You're level is too low to wear that!" << "\n";
		}
		break;
	} 
}

void ItemHandler::unequipItem(int itemType, int oldItem) {
	switch (itemType) {
	case 1: //weapon
		gameClasses.playerAtt -= itemAttHolder[oldItem];
		gameClasses.playerDef -= itemDefHolder[oldItem];
		gameClasses.playerHp -= itemHPHolder[oldItem];
		gameClasses.maxMp -= itemMPHolder[oldItem];
		inventory.push_back(oldItem);
		break;
	case 2: //helm
		gameClasses.playerAtt -= itemAttHolder[oldItem];
		gameClasses.playerDef -= itemDefHolder[oldItem];
		gameClasses.playerHp -= itemHPHolder[oldItem];
		gameClasses.maxMp -= itemMPHolder[oldItem];
		inventory.push_back(oldItem);
		break;
	case 3: //body
		gameClasses.playerAtt -= itemAttHolder[oldItem];
		gameClasses.playerDef -= itemDefHolder[oldItem];
		gameClasses.playerHp -= itemHPHolder[oldItem];
		gameClasses.maxMp -= itemMPHolder[oldItem];
		inventory.push_back(oldItem);
		break;
	case 4: //legs
		gameClasses.playerAtt -= itemAttHolder[oldItem];
		gameClasses.playerDef -= itemDefHolder[oldItem];
		gameClasses.playerHp -= itemHPHolder[oldItem];
		gameClasses.maxMp -= itemMPHolder[oldItem];
		inventory.push_back(oldItem);
		break;
	case 5: //necklace
		gameClasses.playerAtt -= itemAttHolder[oldItem];
		gameClasses.playerDef -= itemDefHolder[oldItem];
		gameClasses.playerHp -= itemHPHolder[oldItem];
		gameClasses.maxMp -= itemMPHolder[oldItem];
		inventory.push_back(oldItem);
		break;
	case 6: //shield
		gameClasses.playerAtt += itemAttHolder[oldItem];
		gameClasses.playerDef += itemDefHolder[oldItem];
		gameClasses.playerHp += itemHPHolder[oldItem];
		gameClasses.maxMp += itemMPHolder[oldItem];
		inventory.push_back(oldItem);
		break;
	}
}

void ItemHandler::drinkPotion(int potion) {
	switch (potion) {
	case 0: //reg hp
		if (hpPotCount >= 1) {
			if (gameClasses.playerHp != gameClasses.maxHp) {
				if (gameClasses.playerHp >= gameClasses.maxHp - 10) {
					hpPotCount--;
					gameClasses.playerHp = gameClasses.maxHp;
					std::cout << "You now have " << gameClasses.playerHp << " HP and have " << hpPotCount << " HP potions left.\n";
				}
				else {
					hpPotCount--;
					gameClasses.playerHp += 10;
					std::cout << "You now have " << gameClasses.playerHp << " HP and have " << hpPotCount << " HP potions left.\n";
				}
				misc.takeAction();
			}
			else {
				std::cout << "You already have full HP!" << "\n";
				misc.takeAction();
			}
		}
		else {
			std::cout << "You don't have any HP potions!" << "\n";
			misc.takeAction();
		}
		break;
	case 1: //reg mp
		if (mpPotCount >= 1) {
			if (gameClasses.playerMp != gameClasses.maxMp) {
				if (gameClasses.playerMp >= gameClasses.maxMp - 10) {
					mpPotCount--;
					gameClasses.playerMp = gameClasses.maxMp;
					std::cout << "You now have " << gameClasses.playerMp << " MP and have " << mpPotCount << " MP potions left.\n";
				}
				else {
					mpPotCount--;
					gameClasses.playerMp += 10;
					std::cout << "You now have " << gameClasses.playerMp << " MP and have " << mpPotCount << " MP potions left.\n";
				}
				misc.takeAction();
			}
			else {
				std::cout << "You already have full MP!" << "\n";
				misc.takeAction();
			}
		}
		else {
			std::cout << "You don't have any MP potions!" << "\n";
			misc.takeAction();
		}
		break;
	}
}

void ItemHandler::drinkPotionMenu() {
	std::cout << "Type the hp or mp to drink the potion" << "\n";
	getline(std::cin, potName);
	if (potName == "hp") drinkPotion(0);
	if (potName == "mp") drinkPotion(1);
	else {
		std::cout << "Something went wrong" << "\n";
		drinkPotionMenu();
	}
}

void ItemHandler::checkInventory() {
	std::cout << "HP Potions: " << hpPotCount << "\n";
	std::cout << "MP Potions: " << mpPotCount << "\n";
	inventory.push_back(2);
	for (int i = 0; i < inventory.size(); i++)
		std::cout << itemNameHolder[inventory[i]] << "\n";
	std::cout << "Equip an item, unequip an item, or go back and take an action?" << "\n";
	getline(std::cin, theAnswer);
	if (theAnswer == "Equip an item" || theAnswer == "equip an item") equipItemDialogue();
	if (theAnswer == "Unequip an item" || theAnswer == "unequip an item") unequipItemDialogue();
	if (theAnswer == "Take an action" || theAnswer == "take an action") misc.takeAction();
	else {
		std::cout << "Something went wrong." << "\n";
		checkInventory();
	}
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

void ItemHandler::deleteItem(int itemNum) {
	std::vector<int>::iterator itemPosition = std::find(inventory.begin, inventory.end, itemNum);
	inventory.erase(itemPosition);
}

