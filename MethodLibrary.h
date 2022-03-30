#pragma once
#include <list>
#include <string>
#include <iostream>
#include <random>
#include "Vector2Int.h"
#include "Mappable.h"
#include "Dictionary.h"

class Player;

namespace MethodLibrary
{
	constexpr int MAP_CONSTRAINT_Y = 15;
	constexpr int MAP_CONSTRAINT_X = 30;

	

	void PrintMap(Dictionary<Vector2Int, Mappable>& map);

	void ReplaceAtPosition(Dictionary<Vector2Int, Mappable>& map, const Vector2Int& position, const Mappable& value);

	bool HasObstacle(Dictionary<Vector2Int, Mappable>& map, const Vector2Int& position);

	bool IsOutsideMap(const Vector2Int& position);

	void HandleInput(char input, Dictionary<Vector2Int, Mappable>& map, Player& player);

	void MakeTrees(Dictionary<Vector2Int, Mappable>& map, int amount);
}

