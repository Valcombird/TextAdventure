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
	void playerAttack();
	void npcAttack(int i);
	void battle();
	void nextTurn();
	void heal();
	void flee();
};

