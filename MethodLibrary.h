#pragma once
#include <list>
#include <string>
#include <iostream>
#include <optional>
#include "Vector2Int.h"
#include "Mappable.h"

namespace MethodLibrary
{
	constexpr int MAP_CONSTRAINT_Y = 15;
	constexpr int MAP_CONSTRAINT_X = 30;

	void PrintMap(std::list<std::pair<Vector2Int, Mappable>>& map);

	void ReplaceAtPosition(std::list<std::pair<Vector2Int, Mappable>>& list, const Vector2Int& position, Mappable& value);

	bool HasObstacle(std::list<std::pair<Vector2Int, Mappable>>& list, const Vector2Int& position);

	std::optional<Mappable> ObjectAt(std::list<std::pair<Vector2Int, Mappable>>& list, const Vector2Int& position);

	bool IsOutsideMap(const Vector2Int& position);

	enum class Direction { North, East, South, West };
}

