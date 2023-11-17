#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// This is test message

#define SIZE 9

int main_arr[SIZE][SIZE];

void create_game() {
    srand(time(NULL));

    for (int x = 0; x < SIZE; x++)
        for (int y = 0; y < SIZE; y++)
            main_arr[x][y] = rand() % 9 + 1;
}

void numberCheck(int main_arr[][SIZE], int rows, int columns, int checknum) {
    int i,j;
    int rowStart = (rows/3) * 3;
    int columnStart = (columns/3) * 3;

    for (i = 0; i < SIZE; ++i) {
        if (main_arr[rows][i] == checknum) return 0;
        if (main_arr[i][columns] == checknum) return 0;
        if (main_arr[rowStart + (i%3)][columnStart + (i/3)] == checknum) return 0;
    }
    return 1

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
    checkunicnumbers(main_arr);
    print_field();
    return 0;
}
