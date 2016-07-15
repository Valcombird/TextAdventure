#pragma once
#include <vector>
#include <string>
class ItemHandler
{
public:
	ItemHandler();
	~ItemHandler();
	//Inventory Items
	int hpPotCount;
	int mpPotCount;
	int helmEquipped;
	int bodyEquipped;
	int legsEquipped;
	int weaponEquipped;
	int shieldEquipped;
	int necklaceEquipped;
	int itemAtt;
	int itemDef;
	int itemID;
	int itemMP;
	int itemHP;
	int itemLevelReq;
	std::string itemName;
	void equipItem(int newItem);
	void unequipItem(int oldItem);
	void drinkPotion();
	void loadItems();
	void findItem(int itemNum);
	void dropItem(int itemNum);
	void displayStats(int itemNum);
	void setStats(int itemNum);
	/*
		Equipped Items
	*/
	std::vector<int> inventory;
	/*
		Item stats
	*/
	std::vector<int> itemIDHolder;
	std::vector<int> itemAttHolder;
	std::vector<int> itemDefHolder;
	std::vector<int> itemMPHolder;
	std::vector<int> itemHPHolder;
	std::vector<int> itemLevelReqHolder;
	std::vector<std::string> itemNameHolder;
};

