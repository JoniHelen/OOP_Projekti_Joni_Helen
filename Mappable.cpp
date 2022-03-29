#include "Mappable.h"

Mappable::Mappable() : MapKey('.') { }

Mappable::Mappable(char mapKey) : MapKey(mapKey) { }

Mappable::Mappable(bool isObstacle) : IsObstacle(isObstacle) { }

Mappable::Mappable(char mapKey, bool isObstacle) : MapKey(mapKey), IsObstacle(isObstacle) { }
