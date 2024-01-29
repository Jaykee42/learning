#include <stdio.h>
#include <stdlib.h>

#define GAME_FIELD_X 40
#define GAME_FIELD_Y 20

struct character {
    int x;
    int y;
};

struct character MainHero = {20, 10};

void printGameField() {
    for (int y = 0; y < GAME_FIELD_Y; y++) {
        for (int x = 0; x < GAME_FIELD_X; x++) {
            if (x == 0 || x == GAME_FIELD_X - 1 || y == 0 || y == GAME_FIELD_Y - 1) {
                printf("#");
            } else if (x == MainHero.x && y == MainHero.y) {
                printf("H");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void mainHeroMovement() {

    char playerInput;
    playerInput = getch();

    switch (playerInput)
    {
    case 'a':
        MainHero.x--;
        break;
    case 'd':
        MainHero.x++;
    case 's':
        MainHero.y--;
    case 'w':
        MainHero.y++;
    
    default:
        break;
    }
    
}

int main() {
    int test = 1;
    while (test)
    {
        printGameField();
        mainHeroMovement();
        printGameField();
    }
    
    return 0;
}
