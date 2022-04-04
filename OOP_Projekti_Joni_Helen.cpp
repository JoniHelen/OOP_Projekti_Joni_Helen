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

    for (int i = 0; i < 5; i++) {
        Map.TrySetValue(Vector2Int(i + 3, 7), new Item("Banana"));
    }

    MakeTrees(Map, 25);

    string inName;
    int inMaxHP;

    cout << "Give a name for your character: ";
    getline(cin, inName);

    system("cls");

    while (true) {
        cout << "Enter the amount of max HP you'd like: ";
        cin >> inMaxHP;

        if (!cin.fail()) {
            try {
                if (inMaxHP < 1) {
                    throw "Max HP cannot be less than 1.";
                }
                else {
                    break;
                }
            }
            catch (const char* msg) {
                cout << msg;
                _getch();
                system("cls");
            }
        }
    }

    Player* player = new Player(inName, Character::Race::Human, inMaxHP, 50, Vector2Int(0, 0));

    Map.TrySetValue(player->GetPosition(), player);

    char in;

    PrintMap(Map);
    cout << "Bananas collected: " << player->Inventory.size() << "/30" << endl;

    while (true) {
        in = _getch();

        if (player->Inventory.size() >= 30 && in == 'q') {
            break;
        }

        HandleInput(in, Map, *player);
        system("cls");
        PrintMap(Map);
        
        if (player->Inventory.size() >= 30) cout << "Bananas collected: " << player->Inventory.size() << "/30 - press q to quit." << endl;
        else cout << "Bananas collected: " << player->Inventory.size() << "/30" << endl;
        
    }
}