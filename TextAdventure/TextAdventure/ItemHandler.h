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
	int itemEquipNum;
	int itemEquipSlot;
	int WEAPON_SLOT = 1;
	int HELM_SLOT = 2;
	int BODY_SLOT = 3;
	int LEGS_SLOT = 4;
	int NECK_SLOT = 5;
	int SHIELD_SLOT = 6;
	static int newItem;
	std::string itemName;
	std::string potName;
	std::string theAnswer;
	void equipItem(int itemType, int newItem);
	void unequipItem(int itemType, int oldItem);
	void drinkPotion(int potion);
	void drinkPotionMenu();
	void checkInventory();
	void loadItems();
	void findItem(int itemNum);
	//void dropItem(int itemNum);
	void deleteItem(int itemNum); //deletes item from inventory once equipped
	void displayStats(int itemNum);
	void setStats(int itemNum);
	void equipItemDialogue();
	void unequipItemDialogue();
	void equipItemSlot(int itemEquipSlot);
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
	std::vector<int> itemSlotHolder; // holds item slots
	
};

