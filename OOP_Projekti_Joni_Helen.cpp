#include <iostream>
#include <map>
#include "MethodLibrary.h"
#include "Vector2Int.h"
#include "Mappable.h"

using namespace std;
using namespace MethodLibrary;


int main()
{
    map<Vector2Int, Mappable> Map;

    for (int x = 0; x < 30; x++) {
        for (int y = 0; y < 15; y++) {
            Map.emplace(Vector2Int(x, y), Mappable());
        }
    }
}