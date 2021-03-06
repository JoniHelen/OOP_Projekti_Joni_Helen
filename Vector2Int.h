#pragma once

class Vector2Int
{
private:

public:
	int x;
	int y;

	Vector2Int();
	Vector2Int(int x, int y);

	double Magnitude() const;
	double Distance(Vector2Int& a, Vector2Int& b);
	Vector2Int DirectionVector(Vector2Int& a, Vector2Int& b);

	static Vector2Int Up();
	static Vector2Int Down();
	static Vector2Int Left();
	static Vector2Int Right();

	friend bool operator==(const Vector2Int& lhs, const Vector2Int& rhs);
	friend Vector2Int operator+(const Vector2Int& lhs, const Vector2Int& rhs);
};

