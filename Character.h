#pragma once
#include <string>
#include "Vector2Int.h"
#include "Mappable.h"

class Character : public Mappable
{
protected:
	int HP;
	int MaxHP;

	int MP;
	int MaxMP;
public:
	enum class Race { Dwarf, Elf, Human, Fairy, Goblin, Orc, Lizardfolk };

	std::string Name;
	Race CharacterRace;

	Character(std::string name, Race race, int maxHP, int maxMP);

	void TakeDamage(int amount);
	void Heal(int amount);
	bool IsDead();

	void UseMana(int amount);
	void ReplenishMana(int amount);

	int GetHP();
	int GetMP();

	void SetMaxHP(int num);
	void SetMaxMP(int num);
};

