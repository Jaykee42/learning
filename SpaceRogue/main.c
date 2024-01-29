#include <stdio.h>



#define SCREEN_WIDTH 20
#define SCREEN_HEIGHT 40


void printGameField() {

    for (int x = 0; x < SCREEN_WIDTH; x++) {
        for (int y = 0; y < SCREEN_HEIGHT; y++){
            if (x == 0 || x == SCREEN_WIDTH - 1 || y == 0 || y == SCREEN_HEIGHT - 1) {
                printf("#");
            }
            else printf(" ");
        }
        printf("\n");
    }
}

int main() {
    printGameField();
    
    return 0;
}