#pragma once

#include <string>
#include "Mappable.h"

class Item : public Mappable
{
private:

public:
	std::string Name;

	Item(std::string name);
};

