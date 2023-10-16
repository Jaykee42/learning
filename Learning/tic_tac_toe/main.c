#include <stdio.h>

char matrix[2][2];
int game_status = 0;
int createMatrix(){
    int i, y;
    for (i = 0; i <= 2; i++)
    for (y = 0; y <= 2; y++) matrix[i][y] = ' '; //create game matrix
}

int playerInput() {
    int x, y;
    printf("Please, input your turn (x, y): \n");
    scanf("%d, %d", &x, &y);
    if (matrix[x][y] != ' ') { 
    printf("Error, chose another cell\n");
  }
  else matrix[x][y] = 'x';
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

int winCheck () {
  int i;
  for (i=0; i<=2; i++) {
    if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2])
    printf("Test");
  }
}

int compMove() {
  int i,j;
  for (i = 0; i <= 2; i++) 
    for (j = 0; j <= 2; j++) 
      if (matrix[i][j] != ' ') printf("There is no space to move"); 
  
}

int main () {
  
  while (game_status == 0) {
    printf("This is the game. Lets start!\n");
    createMatrix();
    printMatrix();
    playerInput();
    printMatrix();
    compMove();
  }
    return 0;
}
