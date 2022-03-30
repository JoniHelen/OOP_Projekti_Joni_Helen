#include "Player.h"
#include "MethodLibrary.h"

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
		if (HasObstacle(map, target))
			Inventory.emplace_back(static_cast<Item*>(map.TryGetValue(target)));

		Step(map, dirV2);
	}
}

void Player::Step(Dictionary<Vector2Int, Mappable>& map, const Vector2Int& movement)
{
	ReplaceAtPosition(map, Position + movement, *this);
	ReplaceAtPosition(map, Position, Mappable());
	Position = Position + movement;
}
