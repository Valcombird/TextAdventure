#pragma once
class CombatHandler
{
public:
	CombatHandler();
	~CombatHandler();
	void fight();
	void npcAttack();
	void playerAttack();
	void nextTurn();
};

