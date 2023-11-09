#include <stdio.h>

int main_arr[9][9];

int create_game() {
    int x,y;

    for (x = 0; x < 9; x++)
        for (y = 0; y < 9; y++) main_arr[x][y] = 9;
            printf("%d", main_arr[1][1]);
}

int main() {
    create_game();
}