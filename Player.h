#pragma once

#include <list>
#include <memory>
#include "Character.h"
#include "Dictionary.h"
#include "Item.h"
#include "Mappable.h"

class Player : public Character
{
private:

public:

	std::list<std::unique_ptr<Item>> Inventory;

	Player(std::string name, Race race, int maxHP, int maxMP, Vector2Int position);

	void Move(Dictionary<Vector2Int, Mappable>&map, Direction direction);

	void LookAndTryStep(const Vector2Int& target, Dictionary<Vector2Int, Mappable>& map);

	void Step(Dictionary<Vector2Int, Mappable>& map, const Vector2Int& movement);
};