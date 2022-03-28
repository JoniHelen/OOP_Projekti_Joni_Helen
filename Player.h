#pragma once

#include "Character.h"
#include "Item.h"
#include <list>
#include <memory>

class Player : public Character
{
private:

public:
	std::list<std::unique_ptr<Item>> Inventory;

	Player(std::string name, Race race, int maxHP, int maxMP, Vector2Int& pos);
};