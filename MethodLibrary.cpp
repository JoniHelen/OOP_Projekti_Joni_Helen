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
