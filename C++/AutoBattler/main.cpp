#include <iostream>
using namespace std;

void mainMenu() {
    int playerInput;
    cout << "Welcome to game!\n";
    cout << "1.New Game\n";
    cout << "2.Continue\n";
    cout << "3.Settings\n";
    cout << "4.Quit\n";

    cin >> playerInput;

    switch (playerInput)
    {
    case 1:
        cout << "New Game!\n";
        break;
    
    default:
        break;
    }

}

class Hero {
    public:
    string name;
    int hitPoints;
    int basicAttack;
    int basicArmor;
};

int main() {
    Hero James;
    James.name = "James Cock";
    James.basicArmor = 13;
    James.basicAttack = 12;
    James.hitPoints = 30;

    mainMenu();
}