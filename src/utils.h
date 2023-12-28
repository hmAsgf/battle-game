#include <iostream>
#include <iomanip>

using namespace std;

string player[5];   //[NAME, RACE, CLASS, TOTAL HP, TOTAL AP]
string races[3][3] = {
        // RACE, HP, AP
        {"Elf",   "100", "9"},
        {"Human", "150", "7"},
        {"Orc",   "200", "5"}
};
string classes[3][3] = {
        // CLASS, BONUS HP, BONUS AP
        {"Fighter", "100", "3"},
        {"Wizard",  "50",  "5"},
        {"Ranger",  "80",  "4"}
};
string monsters[3][3] = {
        // MONSTER, HP, AP
        {"Aboleth",             "100", "12"},
        {"Death Slaad",         "300", "10"},
        {"Red Dragon Wyrmling", "500", "15"}
};
string farmingData[5][5] = {
        //Terrain Name, HP Obtain, AP Obtain, Req HP, Req AP
        { "Gehenna", "100", "8", "150", "8" },
        { "Pandemonium", "150", "12", "400", "20" },
        { "Atra-hasis", "200", "15", "700", "50"  },
        { "Inazuma", "300", "25", "1500", "100" },
        { "Eridu City", "500", "40", "3500", "200" },
};

void createCharacter() {
    int race, _class;

    cout << "=== CREATE CHARACTER ===" << endl;
    cout << "CHARACTER NAME: ";
    getline (cin, player[0]);

    cout << "--------- RACES --------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "[" << i + 1 << "] " << setw (5) << left << races[i][0] << "\tSTATS: (Health Points: " << races[i][1]
             << " | Attack Power: " << races[i][2] << ")" << endl;
    }
    cout << "------------------------" << endl;
    do {
        cout << "CHOOSE YOUR RACE: ";
        cin >> race;
    } while (race < 0 || race > 3);

    cout << "-------- CLASSES -------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "[" << i + 1 << "] " << classes[i][0] << "\tSTATS: (Health Points: +" << classes[i][1]
             << " | Attack Power: +" << classes[i][2] << ")" << endl;
    }
    cout << "------------------------" << endl;
    do {
        cout << "CHOOSE YOUR CLASS: ";
        cin >> _class;
    } while (_class < 0 || _class > 3);

    player[1] = races[race - 1][0];   // RACE
    player[2] = classes[_class - 1][0];   // CLASS
    player[3] = to_string (stoi (races[race - 1][1]) + stoi (classes[_class - 1][1]));   // TOTAL HP
    player[4] = to_string (stoi (races[race - 1][2]) + stoi (classes[_class][2]));   // TOTAL AP
}

void viewCharacter() {
    cout << "=== VIEW CHARACTER ===" << endl;
    if (!player[0].empty ()) {
        cout << "NAME   : " << player[0] << endl;
        cout << "RACE   : " << player[1] << endl;
        cout << "CLASS  : " << player[2] << endl;
        cout << "HP     : " << player[3] << endl;
        cout << "AP     : " << player[4] << endl;
    } else {
        cout << "CHARACTER HAS NOT BEEN CREATED" << endl;
    }
}

bool checkRequiredFarming(int reqHP, int reqAP) {
    return stoi(player[3]) >= reqHP && stoi(player[4]) >= reqAP;
}
void entryFarming(int terrain) {
    player[3] = to_string(stoi(player[3]) + stoi(farmingData[terrain][1]));
    player[4] = to_string(stoi(player[4]) + stoi(farmingData[terrain][2]));
}
void farming() {
    string terrainInput;
    do {
        cout << "<= Select your Farming Terrain =>" << endl;
        for (int i = 0; i < sizeof(farmingData)/sizeof(farmingData[0]) ; i++) {
            cout << "[" << i + 1 << "] " << farmingData[i][0] << endl;
            cout << "Obtained HP: " << farmingData[i][1] << endl;
            cout << "Obtained AP: " << farmingData[i][2] << endl;
            cout << "Required HP: " << farmingData[i][3] << endl;
            cout << "Required AP: " << farmingData[i][4] << endl;
            if (i < sizeof (farmingData) - 2  ) {
                for (int j = 0; j < 25; j++) {
                    cout << "=";
                }
                cout << endl;
            }
        }
        cout << "[0]" << "Exit Menu" << endl;
        cout << "Terrain: ";
        cin >> terrainInput;
        int terrainIndex = stoi(terrainInput) - 1;
        if (checkRequiredFarming(stoi(farmingData[terrainIndex][3]), stoi(farmingData[terrainIndex][4]))) {
            entryFarming(terrainIndex);
        } else {
            cout << "Required HP or AP Not met";
        }
    } while (terrainInput != "0");
}


void battleFight(int monsterType) {
    string playerName = player[0], monsterName = monsters[monsterType - 1][0];
    int playerHP = stoi (player[3]), playerAP = stoi (player[4]);
    int monsterHP = stoi (monsters[monsterType - 1][1]), monsterAP = stoi (monsters[monsterType - 1][2]);
    int turn = 1;

    while (playerHP > 0 && monsterHP > 0) {
        cout << "=== TURN " << turn << " ===" << endl;
        cout << "- " << playerName << " ATTACKING " << monsterName << " -" << endl;
        monsterHP -= playerAP;
        (monsterHP <= 0) ? monsterHP = 0 : monsterHP = monsterHP;
        cout << playerName << "'s HP: " << playerHP << endl;
        cout << monsterName << "'s HP: " << monsterHP << endl;

        cout << "- " << monsterName << " ATTACKING " << playerName << " -" << endl;
        playerHP -= monsterAP;
        (playerHP <= 0) ? playerHP = 0 : playerHP = playerHP;
        cout << playerName << "'s HP: " << playerHP << endl;
        cout << monsterName << "'s HP: " << monsterHP << endl << endl;

        turn++;
    }

    if (playerHP <= 0) {
        cout << "YOU LOSE" << endl;
    } else if (monsterHP <= 0) {
        cout << "YOU WIN" << endl;
    }
}

void battle() {
    int monster;

    cout << "=== BATTLE ===" << endl;
    if (!player->empty ()) {
        for (int i = 0; i < 3; i++) {
            cout << "[" << i + 1 << "] " << monsters[i][0] << endl;
        }
        cout << "--------------" << endl;
        cout << "CHOOSE MONSTER TO FIGHT: ";
        cin >> monster;

        if (monster > 0 && monster < 4) {
            battleFight (monster);
        } else {
            cout << "MONSTER NOT FOUND" << endl;
        }
    } else {
        cout << "CHARACTER HAS NOT BEEN CREATED" << endl;
    }
}

