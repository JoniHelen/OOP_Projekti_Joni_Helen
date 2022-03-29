#pragma once
#include <list>
#include <string>
#include <iostream>
#include "Vector2Int.h"
#include "Mappable.h"

namespace MethodLibrary
{
	void PrintMap(std::list<std::pair<Vector2Int, Mappable>>& map);

	void ReplaceAtPosition(std::list<std::pair<Vector2Int, Mappable>>& list, const Vector2Int& position, Mappable& value);
}

