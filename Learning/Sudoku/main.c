#include <stdio.h>
#include <stdlib.h>

int main_arr[9][9];

int create_game() {
    int x,y;

    for (x = 0; x < 10; x++)
        for (y = 0; y < 10; y++) main_arr[x][y] = rand() % 9 + 1;
        
}

int print_field() {
    int x,y;
    for (x = 0; x < 9; x++) {
        for (y = 0; y < 9; y++)
            printf("%d ", main_arr[x][y]);
        printf("\n");
    }
}
int main() {
    create_game();
    print_field();
}