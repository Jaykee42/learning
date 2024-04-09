#include <iostream>
using namespace std;

class Hero {
    public:
    string name;
    int hitPoints;
    int basicAttack;
    int basicArmor;

    /*string setName (string Name) {
        name = Name;
    }

    int setHP (int HP) {
        hitPoints = HP;
    }

    int setBasicAttack (int BasicAttack) {
        basicAttack = BasicAttack;
    }

    int setBasicArmor (int BasicArmor) {
        basicArmor = BasicArmor;
    }*/
    

};

int main() {
    Hero James;
    James.name = "James Cock";
    James.basicArmor = 13;
    James.basicAttack = 12;
    James.hitPoints = 30;

    cout << "James basic armor is " << James.basicArmor << endl;
}