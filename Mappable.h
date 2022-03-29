#pragma once
class Mappable
{
public:
	char MapKey;
	bool IsObstacle;

	Mappable();
	Mappable(char mapKey);
	Mappable(bool isObstacle);
	Mappable(char mapKey, bool isObstacle);
};

