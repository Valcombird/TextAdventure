#pragma once
#include <string>
class CombatHandler
{
public:
	CombatHandler();
	~CombatHandler();
	std::string theAnswer;
	bool playerTurn = true;
	bool npcTurn = false;
	//int npcAttack;
	int npcDmg;
	int playerDmg;
	void playerAttack(int i);
	void npcAttack(int i);
	void battle();
	void nextTurn();
	void combatHeal();
	void heal();
	void flee(int i);
};

