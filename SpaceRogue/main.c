#include <stdio.h>

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

int main() {
    printGameField();
    return 0;
}
