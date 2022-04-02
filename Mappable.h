#pragma once
class Mappable
{
public:
	char MapKey;
	bool IsObstacle;

	Mappable();
	Mappable(char mapKey);
	Mappable(char mapKey, bool isObstacle);

	virtual ~Mappable();
};

