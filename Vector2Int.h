#pragma once

class Vector2Int
{
private:

public:
	int x;
	int y;

	Vector2Int();
	Vector2Int(int x, int y);

	double Magnitude();
	double Distance(Vector2Int& a, Vector2Int& b);
	Vector2Int DirectionVector(Vector2Int& a, Vector2Int& b);
};

struct Vector2Comp
{
	bool operator() (const Vector2Int& lhs, const Vector2Int& rhs);
};

