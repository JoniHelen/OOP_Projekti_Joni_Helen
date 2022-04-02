#include "Mappable.h"

Mappable::Mappable() : MapKey('.'), IsObstacle(false) { }

Mappable::Mappable(char mapKey) : MapKey(mapKey), IsObstacle(false) { }

Mappable::Mappable(char mapKey, bool isObstacle) : MapKey(mapKey), IsObstacle(isObstacle) { }

Mappable::~Mappable() { }
