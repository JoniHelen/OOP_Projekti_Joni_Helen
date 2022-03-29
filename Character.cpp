#include "Character.h"
#include <algorithm>

Character::Character(std::string name, Race race, int maxHP, int maxMP, Vector2Int position) : Mappable(name[0])
{ 
	Name = name;
	CharacterRace = race;
	MaxHP = maxHP;
	MaxMP = maxMP;
	HP = maxHP;
	MP = maxMP;
	Position = position;
}

void Character::TakeDamage(int amount) { HP = std::max(HP - amount, 0); }
void Character::Heal(int amount) { HP = std::min(HP + amount, MaxHP); }
bool Character::IsDead() { return HP == 0; }

void Character::UseMana(int amount) { MP = std::max(MP - amount, 0); }
void Character::ReplenishMana(int amount) { MP = std::min(MP + amount, MaxMP); }

int Character::GetHP() { return HP; }
int Character::GetMP() { return MP; }

Vector2Int Character::GetPosition() { return Position; }

void Character::SetMaxHP(int num) { MaxHP = num; }
void Character::SetMaxMP(int num) { MaxMP = num; }
