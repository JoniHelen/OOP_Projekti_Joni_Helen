#include "Player.h"
#include "MethodLibrary.h"
#include <iostream>
#include <typeinfo>
#include <conio.h>

using namespace MethodLibrary;

Player::Player(std::string name, Race race, int maxHP, int maxMP, Vector2Int position) : Character(name, race, maxHP, maxMP, position)
{

}

void Player::Move(Dictionary<Vector2Int, Mappable>& map, Direction direction)
{
	switch (direction) {
	case Direction::North:
		LookAndTryStep(Vector2Int::Down(), map);
		break;
	case Direction::East:
		LookAndTryStep(Vector2Int::Right(), map);
		break;
	case Direction::South:
		LookAndTryStep(Vector2Int::Up(), map);
		break;
	case Direction::West:
		LookAndTryStep(Vector2Int::Left(), map);
		break;
	default:
		break;
	}
}

void Player::LookAndTryStep(const Vector2Int& dirV2, Dictionary<Vector2Int, Mappable>& map)
{
	Vector2Int target = Position + dirV2;

	if (!IsOutsideMap(target)) {
		if (HasObstacle(map, target)) {
			Item* item = dynamic_cast<Item*>(map.ValueAt(target).get());
			if (item) {
				Inventory.push_back(std::make_unique<Item>(*item));
				map.TrySetValue(target, new Mappable());
				Step(map, dirV2);
				SpawnNewItem(map);
			}
		}
		else {
			Step(map, dirV2);
		}
	}
}

void Player::Step(Dictionary<Vector2Int, Mappable>& map, const Vector2Int& movement)
{
	map.TrySwapValues(Position, Position + movement);
	Position = Position + movement;
}
