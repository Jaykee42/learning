#include <iostream>
#include <stdlib.h>
using namespace std;

string playerCharacterName;

class Hero {
public:
    string name;
    int hitPoints;
    int basicAttack;
    int basicArmor;
};

class Enemy {
public:
    string name;
    int hitPoints;
    int basicAttack;
    int basicArmor;
};

Hero Player;
Enemy Scamp;

void printGameField() {
    int screenX = 10;
    int screenY = 20;
    for (int x = 0; x < screenX; x++) {
        for (int y = 0; y < screenY; y++) {
            if (x == 1 || x == screenX - 1 || y == 1 || y == screenY - 1)
                cout << "#";
            else
                cout << " ";
        }
        cout << endl;
    }
}

void newGameStart() {
    cout << "Welcome to new game!\nPlease enter your character name:\n";
    cin >> playerCharacterName;
    system("clear");
}

void initialisationSettings() {
    Player.name = playerCharacterName;
    Player.basicArmor = 13;
    Player.basicAttack = 12;
    Player.hitPoints = 30;

    Scamp.name = "Scamp";
    Scamp.basicArmor = 4;
    Scamp.basicAttack = 5;
    Scamp.hitPoints = 50;
}

void battleFunc() {
    bool EndBattle = true;
    while (EndBattle) {
        int playerHit, monsterHit;

        cout << playerCharacterName << ": " << Player.hitPoints << "      " << Scamp.name << ": " << Scamp.hitPoints << endl;
        playerHit = Player.basicAttack - 2 - Scamp.basicArmor;
        monsterHit = Scamp.basicAttack + 1 / Player.basicArmor;
        Player.hitPoints -= monsterHit;
        Scamp.hitPoints -= playerHit;
        system("sleep 2");
        system("clear");
        if (Player.hitPoints <= 0 || Scamp.hitPoints <= 0)
            EndBattle = false;
    }
}

void mainMenu() {
    int playerInput;
    cout << "Welcome to game!\n";
    cout << "1. New Game\n";
    cout << "2. Continue\n";
    cout << "3. Settings\n";
    cout << "4. Quit\n";

    cin >> playerInput;

    switch (playerInput) {
    case 1:
        cout << "New Game!\n";
        newGameStart();
        initialisationSettings();
        battleFunc();
        break;
    case 2:
        cout << "Continue!\n";
        break;
    case 3:
        cout << "Setting!\n";
        break; // Don't forget to add break statements after each case
    case 4:
        cout << "Quit!\n";
        break;
    default:
        cout << "Invalid option!\n";
        break;
    }
}

int main() {
    mainMenu();
    return 0;

}
