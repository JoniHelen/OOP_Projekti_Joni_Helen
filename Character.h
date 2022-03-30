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

	Vector2Int Position;
public:
	enum class Race { Dwarf, Elf, Human, Fairy, Goblin, Orc, Lizardfolk };

	enum class Direction { North, East, South, West };

	std::string Name;
	Race CharacterRace;

	Character(std::string name, Race race, int maxHP, int maxMP, Vector2Int position);

	void TakeDamage(int amount);
	void Heal(int amount);
	bool IsDead();

	void UseMana(int amount);
	void ReplenishMana(int amount);

	int GetHP();
	int GetMP();
	Vector2Int GetPosition();

	void SetMaxHP(int num);
	void SetMaxMP(int num);
};

