#include "MethodLibrary.h"

void MethodLibrary::PrintMap(std::list<std::pair<Vector2Int, Mappable>>& map) {

	std::string result;

	for (auto& spot : map) {
		if (spot.first.x == 0) result += '\n';

		result += spot.second.MapKey;
	}

	std::cout << result << std::endl;
}

void MethodLibrary::ReplaceAtPosition(std::list<std::pair<Vector2Int, Mappable>>& list, const Vector2Int& position, Mappable& value)
{
	for (auto& item : list) {
		if (item.first == position) {
			item.second = value;
			return;
		}
	}
}

bool MethodLibrary::HasObstacle(std::list<std::pair<Vector2Int, Mappable>>& map, const Vector2Int& position)
{
	for (auto& tile : map) {
		if (tile.first == position) return tile.second.IsObstacle;
		else if (IsOutsideMap(position)) return true;
	}
	return false;
}

std::optional<Mappable> MethodLibrary::ObjectAt(std::list<std::pair<Vector2Int, Mappable>>& list, const Vector2Int& position)
{
	for (auto& tile : list) {
		if (tile.first == position) return tile.second;
	}
	return false;
}

bool MethodLibrary::IsOutsideMap(const Vector2Int& position)
{
	return position.x >= MAP_CONSTRAINT_X || position.y >= MAP_CONSTRAINT_Y || position.x < 0 || position.y < 0;
}
