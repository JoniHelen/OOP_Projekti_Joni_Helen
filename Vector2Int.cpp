#include "Vector2Int.h"
#include <math.h>

Vector2Int::Vector2Int() { x = 0; y = 0; }

Vector2Int::Vector2Int(int x, int y) : x(x), y(y) { }

double Vector2Int::Magnitude() { return sqrt(pow(x, 2) + pow(y, 2)); }

double Vector2Int::Distance(Vector2Int& a, Vector2Int& b)
{
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

Vector2Int Vector2Int::DirectionVector(Vector2Int& a, Vector2Int& b)
{
	return Vector2Int(b.x - b.y, b.y - a.y);
}

bool Vector2Comp::operator()(const Vector2Int& lhs, const Vector2Int& rhs) const
{
	return lhs.Magnitude() < rhs.Magnitude();
}
