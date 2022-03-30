#include "Vector2Int.h"
#include <math.h>

Vector2Int::Vector2Int() { x = 0; y = 0; }

Vector2Int::Vector2Int(int x, int y) : x(x), y(y) { }

double Vector2Int::Magnitude() const { return sqrt(pow(x, 2) + pow(y, 2)); }

double Vector2Int::Distance(Vector2Int& a, Vector2Int& b)
{
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

Vector2Int Vector2Int::DirectionVector(Vector2Int& a, Vector2Int& b)
{
	return Vector2Int(b.x - b.y, b.y - a.y);
}

Vector2Int Vector2Int::Up()
{
	return Vector2Int(0, 1);
}

Vector2Int Vector2Int::Down()
{
	return Vector2Int(0, -1);
}

Vector2Int Vector2Int::Left()
{
	return Vector2Int(-1, 0);
}

Vector2Int Vector2Int::Right()
{
	return Vector2Int(1, 0);
}

bool operator==(const Vector2Int& lhs, const Vector2Int& rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

Vector2Int operator+(const Vector2Int& lhs, const Vector2Int& rhs)
{
	return Vector2Int(lhs.x + rhs.x, lhs.y + rhs.y);
}
