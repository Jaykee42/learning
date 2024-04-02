#include <iostream>
using namespace std;

int main() {
    int firstNumber, secondNumber;
    char algebraSight;

    cout << "Please enter the first number: ";
    cin >> firstNumber;

    cout << "Pick the action: ";
    cin >> algebraSight;

    cout << "Please enter the second number: ";
    cin >> secondNumber;


    switch (algebraSight) {
        case '+':
            cout << firstNumber + secondNumber << endl;
            break;
        case '-':
            cout << firstNumber - secondNumber << endl;
            break;
        case '*':
            cout << firstNumber * secondNumber << endl;
            break;
        case '/':
            cout << firstNumber / secondNumber << endl;
            break;

    }
    
}