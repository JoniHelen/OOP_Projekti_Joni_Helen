#include "MethodLibrary.h"
#include "Player.h"


std::uniform_int_distribution<int> DistributionX(0, MethodLibrary::MAP_CONSTRAINT_X);
std::uniform_int_distribution<int> DistributionY(0, MethodLibrary::MAP_CONSTRAINT_Y);

std::random_device rndEngine;

void MethodLibrary::PrintMap(Dictionary<Vector2Int, Mappable>& map) {

	std::string result;

	map.ForEach([&result](std::pair<Vector2Int, Mappable>& kvp) {
		if (kvp.first.x == 0) result += '\n';
		result += kvp.second.MapKey;
	});

	std::cout << result << std::endl;
}

void MethodLibrary::ReplaceAtPosition(Dictionary<Vector2Int, Mappable>& map, const Vector2Int& position, const Mappable& value)
{
	auto r = map.TryGetValue(position);
	if (r != nullptr) *r = value;
}

bool MethodLibrary::HasObstacle(Dictionary<Vector2Int, Mappable>& map, const Vector2Int& position)
{
	return map.TryGetValue(position)->IsObstacle;
}

bool MethodLibrary::IsOutsideMap(const Vector2Int& position)
{
	return position.x >= MAP_CONSTRAINT_X || position.y >= MAP_CONSTRAINT_Y || position.x < 0 || position.y < 0;
}

void MethodLibrary::HandleInput(char input, Dictionary<Vector2Int, Mappable>& map, Player& player)
{
	switch (input) {
	case 'w':
		player.Move(map, Character::Direction::North);
		break;
	case 'd':
		player.Move(map, Character::Direction::East);
		break;
	case 's':
		player.Move(map, Character::Direction::South);
		break;
	case 'a':
		player.Move(map, Character::Direction::West);
		break;
	default:
		break;
	}
}

void MethodLibrary::MakeTrees(Dictionary<Vector2Int, Mappable>& map, int amount)
{
	for (int i = 0; i < amount; i++) {
		ReplaceAtPosition(map, Vector2Int(DistributionX(rndEngine), DistributionY(rndEngine)), Mappable('A', true));
	}
}
