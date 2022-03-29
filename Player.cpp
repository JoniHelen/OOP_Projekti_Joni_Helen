#include "Player.h"

Player::Player(std::string name, Race race, int maxHP, int maxMP) : Character(name, race, maxHP, maxMP)
{

}

std::optional<Mappable> Player::Move(std::list<std::pair<Vector2Int, Mappable>>& map, MethodLibrary::Direction direction)
{
	switch (direction) {
	case MethodLibrary::Direction::North:
		if (MethodLibrary::HasObstacle(map, Position + Vector2Int(0, 1)))
			return MethodLibrary::IsOutsideMap(Position + Vector2Int(0, 1)) ?
			false :
			MethodLibrary::ObjectAt(map, Position + Vector2Int(0, 1));
		else
			MethodLibrary::ReplaceAtPosition(map, Position + Vector2Int(0, 1), *this);
			MethodLibrary::ReplaceAtPosition(map, Position, MethodLibrary::ObjectAt(map, Position + Vector2Int(0, 1)));
			return false;
	case MethodLibrary::Direction::East:
		break;
	case MethodLibrary::Direction::South:
		break;
	case MethodLibrary::Direction::West:
		break;
	default:
		break;
	}
}
