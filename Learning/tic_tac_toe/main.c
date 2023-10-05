#include <stdio.h>

char matrix[2][2];

int createMatrix(){
    int i, y;
    for (i = 0; i <= 2; i++)
    for (y = 0; y <= 2; y++) matrix[i][y] = ' '; //create game matrix
}

void printMatrix() {
    int i;

    for (i=0; i <= 2; i++) {
    printf(" %c | %c | %c ", matrix[i][0], matrix[i][1], matrix[i][2]);
        if (i!=2) printf("\n---|---|---\n");
        matrix[1][1] = 'x'; 
    }
    printf("\n");
}

int main () {
    printf("Test!");
    createMatrix();
    printMatrix();
    return 0;
}
