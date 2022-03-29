#include <iostream>
#include <list>
#include <algorithm>
#include "MethodLibrary.h"
#include "Player.h"
#include "Vector2Int.h"
#include "Mappable.h"

using namespace std;
using namespace MethodLibrary;

int main()
{
    list<pair<Vector2Int, Mappable>> Map;

    Player player("Hector", Character::Race::Human, 30, 50);

    for (int y = 0; y < MAP_CONSTRAINT_Y; y++) {
        for (int x = 0; x < MAP_CONSTRAINT_X; x++) {
            Map.push_back(pair<Vector2Int, Mappable>(Vector2Int(x, y), Mappable()));
        }
    }

    ReplaceAtPosition(Map, Vector2Int(15, 7), player);

    PrintMap(Map);
}