#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9

int main_arr[SIZE][SIZE];

void create_game() {
    srand(time(NULL));

    for (int x = 0; x < SIZE; x++)
        for (int y = 0; y < SIZE; y++)
            main_arr[x][y] = rand() % 9 + 1;
}

void checkunicnumbers(int main_arr[][SIZE]) {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            for (int k = i + 1; k < SIZE; k++)
                for (int l = 0; l < SIZE; l++)
                    if (main_arr[i][j] == main_arr[k][l])
                    {
                        main_arr[k][l] = (main_arr[i][j] % 9) + 1;
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
    checkunicnumbers(main_arr);
    print_field();
    return 0;
}
