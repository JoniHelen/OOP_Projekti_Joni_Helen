#include "Character.h"
#include <algorithm>

Character::Character(std::string name, Race race, int maxHP, int maxMP)
{ 
	Name = name;
	CharacterRace = race;
	MaxHP = maxHP;
	MaxMP = maxMP;
	HP = maxHP;
	MP = maxMP;
}

void Character::TakeDamage(int amount) { HP = std::max(HP - amount, 0); }
void Character::Heal(int amount) { HP = std::min(HP + amount, MaxHP); }
bool Character::IsDead() { return HP == 0; }

void Character::UseMana(int amount) { MP = std::max(MP - amount, 0); }
void Character::ReplenishMana(int amount) { MP = std::min(MP + amount, MaxMP); }

int Character::GetHP() { return HP; }
int Character::GetMP() { return MP; }

void Character::SetMaxHP(int num) { MaxHP = num; }
void Character::SetMaxMP(int num) { MaxMP = num; }
