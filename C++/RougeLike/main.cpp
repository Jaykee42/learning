#include <iostream>
using namespace std;

void printScreen() {
    int x = 10;
    int y = 10;

    for(int i = 0; i < x; i++) {

        cout << '#';
    }
    for(int o = 0; o < y; o++) {

        cout << '#' << endl;
    }
}

int main() {
    printScreen();
}