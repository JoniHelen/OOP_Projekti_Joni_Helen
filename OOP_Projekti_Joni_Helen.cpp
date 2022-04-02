#include <iostream>
#include <list>
#include <algorithm>
#include <conio.h>
#include "Dictionary.h"
#include "MethodLibrary.h"
#include "Player.h"
#include "Vector2Int.h"
#include "Mappable.h"

using namespace std;
using namespace MethodLibrary;

int main()
{
    Dictionary<Vector2Int, Mappable> Map;

    for (int y = 0; y < MAP_CONSTRAINT_Y; y++) {
        for (int x = 0; x < MAP_CONSTRAINT_X; x++) {
            Map.Add(Vector2Int(x, y), Mappable());
        }
    }

    Player player("Hector", Character::Race::Human, 30, 50, Vector2Int(0, 0));

    for (int i = 0; i < 5; i++) {
        ReplaceAtPosition(Map, Vector2Int(i + 3, 7), new Item("Banana"));
    }

    ReplaceAtPosition(Map, player.GetPosition(), &player);

    MakeTrees(Map, 10);

    char in;

    PrintMap(Map);
    cout << "Bananas collected: " << player.Inventory.size() << endl;

    while (true) {
        in = _getch();
        HandleInput(in, Map, player);
        system("cls");
        PrintMap(Map);

        cout << "Bananas collected: " << player.Inventory.size() << endl;
    }
}