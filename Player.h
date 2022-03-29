#pragma once

#include "Character.h"
#include "Item.h"
#include "Mappable.h"
#include "MethodLibrary.h"
#include <list>
#include <memory>

class Player : public Character
{
private:

public:

	std::list<std::unique_ptr<Item>> Inventory;

	Player(std::string name, Race race, int maxHP, int maxMP);

	std::optional<Mappable> Move(std::list<std::pair<Vector2Int, Mappable>>& map, MethodLibrary::Direction direction);
};