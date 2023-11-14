#include <stdio.h>
#include <stdlib.h>

#define SIZE 9


int main_arr[SIZE][SIZE];

void create_game() {
    int x, y;

    for (x = 0; x < SIZE; x++)
        for (y = 0; y < SIZE; y++)
            main_arr[x][y] = rand() % 9 + 1;
}

void checkunicnumbers(int main_arr[][SIZE]) {
    int i, j, k, l;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = i + 1; k < SIZE; k++) {
                int start = (k == i) ? j + 1 : 0; {
                for (int l = start; l < SIZE; l++) {
                    if (main_arr[i][j] == main_arr[k][l]) {
                        main_arr[k][l] = (main_arr[i][j] + 1) % 9 + 1;
                        }
                    }
                }
            }
        }
    }
}

void print_field() {
    int x, y;
    for (x = 0; x < SIZE; x++) {
        for (y = 0; y < SIZE; y++)
            printf("%d ", main_arr[x][y]);
        printf("\n");
    }
}

int main() {
    create_game();
    print_field();
    checkunicnumbers(main_arr);
    printf("\nAfter checking and modifying:\n");
    print_field();
    return 0;
}
