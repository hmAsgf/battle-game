#include <iostream>
#include "utils.h"

using namespace std;

int main() {
    int opsi;

    createCharacter();
    do {
        viewCharacter();
        cout << "=== BATTLE GAME ===\n";
        cout << "[1] FARMING\n";
        cout << "[2] BATTLE\n";
        cout << "-------------------\n";
        cout << "MENU: ";
        cin >> opsi;
        cin.ignore();
        switch (opsi) {
            case 1:
                farming();
                break;
            case 2:
                battle();
                break;
        }
    } while (opsi > 0 && opsi < 5);
    return 0;
}
