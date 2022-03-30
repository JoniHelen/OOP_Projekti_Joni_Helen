#include "Item.h"

Item::Item(std::string name) : Mappable(name[0], true), Name(name) { }
