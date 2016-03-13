#pragma once
class CombatHandler
{
public:
	CombatHandler();
	~CombatHandler();
	bool playerTurn = true;
	bool npcTurn = false;
	void fight();
	void nextTurn();
	void heal();
	void flee();
};

