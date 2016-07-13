#include "stdafx.h"
#include "NPCSkills.h"
#include "NPC.h"
#include "CombatHandler.h"
#include "Classes.h"

#include <iostream>
#include <time.h>

extern Classes gameClasses;
CombatHandler combat;
NPC npc;

NPCSkills::NPCSkills()
{
}


NPCSkills::~NPCSkills()
{
}

void NPCSkills::npcHeal() {
	srand(static_cast<unsigned int>(time(NULL)));
	if (npc.npcHp != npc.npcMaxHp) {
		npc.npcHp += 10;
		if (npc.npcHp >= npc.npcMaxHp)
			npc.npcHp = npc.npcMaxHp;
		std::cout << "The " << npc.npcName << " healed for 10 HP!" << "\n";
		std::cout << npc.npcName << " now has " << npc.npcHp << " HP\n";
		combat.playerTurn = true;
		combat.nextTurn();
	}
	else
		combat.npcAttack(rand() % 101);
}

void NPCSkills::npcSmash() {
	srand(static_cast<unsigned int>(time(NULL)));
	combat.npcDmg = npc.npcAtt + rand() % (npc.npcAtt * 2);
	gameClasses.playerHp -= combat.npcDmg;
	std::cout << "The " << npc.npcName << " used smash and dealt " << combat.npcDmg << " damage!\n";
	std::cout << "You now have " << gameClasses.playerHp << " HP left.";
	combat.playerTurn = true;
	combat.nextTurn();
}
