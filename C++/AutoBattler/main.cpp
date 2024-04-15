#include <iostream>
using namespace std;

string playerCharacterName;

void printGameField () {
    int screenX = 10; 
    int screenY = 20;
    for (int x = 0; x < screenX; x++) {
        for (int y = 0; y < screenY; y++)
        {
            if (x == 1 || x == screenX - 1 || y == 1 || y == screenY + 1)
                {
                cout << "#";
            }

            else {
                cout << " ";
            }
            
           
            
        }
        cout << endl;
    }
    
}
void newGameStart() {
    cout << "Welcome to new game!\nPlease enter your character name:\n";
    cin >> playerCharacterName;
}
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
        newGameStart();
        break;
    case 2: 
        cout << "Continue!\n";
        break;
    case 3:
        cout << "Setting!\n";
    case 4:
        cout << "Qiut!\n";
    
    default:
        cout << "Invalid option!\n";
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
    mainMenu();
    Hero Player;
    Player.name = playerCharacterName;
    Player.basicArmor = 13;
    Player.basicAttack = 12;
    Player.hitPoints = 30;
    
    

    cout << "Your name is " << Player.name << endl;
    printGameField();
}