#include <stdio.h>

int decomposeRomanToInteger(char roman_number) {
    switch (roman_number)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}


int rebuildRomanToInteger(char *RomanInteger) {
    int i, decomposedInteger;

    for (i = 1; RomanInteger[i] != "\0"; i++) {
        int previosRomanNumber = decomposeRomanToInteger(RomanInteger[i - 1]);
        int currentRomanNuber = decomposeRomanToInteger(RomanInteger[i]);
    }

}
int main () {

}