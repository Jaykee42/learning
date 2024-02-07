#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define GAME_FIELD_X 20
#define GAME_FIELD_Y 10

struct character {
    int x;
    int y;
    int health;
    char name;
};

int test = 1;

struct character MainHero = {GAME_FIELD_X/2, GAME_FIELD_Y/2, 100, 'H'};
struct character Enemy = {GAME_FIELD_X - 3, GAME_FIELD_Y - 3, 100, 'E'};

void battleWithEnemy() {
    printf("What do you want to do?\n");
    char playerBattleInput = getch();

    switch (playerBattleInput)
    {
    case 'a':
        printf("Attack!\n");
        Enemy.health--;
        getch();
        break;
    
    case 'd':
        printf("Defense!\n");
        getch();
        break;
    
    case '0':
        test = 0;
    }
}


void printGameField() {
    system("cls");

    for (int y = 0; y < GAME_FIELD_Y; y++) {
        for (int x = 0; x < GAME_FIELD_X; x++) {
            if (x == 0 || x == GAME_FIELD_X - 1 || y == 0 || y == GAME_FIELD_Y - 1) {
                printf("#");
            } else if (x == MainHero.x && y == MainHero.y) {
                printf("%c", MainHero.name);
            } else if (x == Enemy.x && y == Enemy.y) {
                printf("%c", Enemy.name);
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
    printf("%d HP        %d Enemy\n", MainHero.health, Enemy.health);
}

void mainHeroMovement() {

    char playerInput;
    playerInput = getch();

    if (MainHero.x == Enemy.x && MainHero.y == Enemy.y)
    {
        battleWithEnemy();
    }
    

    switch (playerInput)
    {
    case 'a':
        MainHero.x--;
        break;
    case 'd':
        MainHero.x++;
        break;
    case 's':
        MainHero.y++;
        break;
    case 'w':
        MainHero.y--;
        break;
    case '0':
        test = 0;
        break;
    }
    
}

int main() {
    
    while (test)
    {
        printGameField();
        mainHeroMovement();
    }
    
    return 0;
}
