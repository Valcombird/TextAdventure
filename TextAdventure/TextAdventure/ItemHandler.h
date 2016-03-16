#pragma once
class ItemHandler
{
public:
	ItemHandler();
	~ItemHandler();
	//Inventory Items
	int inventoryMax = 25;
	int hpPotsMax = 5;
	/*
		Equipped Items
	*/
	int bodyEquipped;
	bool hasBodyEquipped;
	int legsEquipped;
	bool hasLegsEqupped;
	int weaponEquipped;
	bool hasWeaponEquipped;
	int helmetEquipped;
	bool hasHelmetEquipped;
	int shieldEquipped;
	bool hasShieldEquipped;

	bool dualWielding;
	void foundItem();
	void hasEquipped();
	void inventory();
	void hasHpPots();
	void dropItem();
};

