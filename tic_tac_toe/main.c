#include <stdio.h>
#include <stdlib.h>

char matrix[3][3];


void create_matrix(void){
    int i, j;
    for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++) matrix[i][j] = ' '; //create game matrix
}

void player_input(void) {
    int x, y;
    printf("Please, input your turn (x, y): \n");
    scanf("%d%*c %d", &x, &y);
    if (matrix[x][y] != ' ') { 
    printf("Error, chose another cell\n");
    player_input();
  }
  else matrix[x][y] = 'X';
}

void print_matrix() {
    int i;

    for (i=0; i < 3; i++) {
    printf(" %c | %c | %c ", matrix[i][0], matrix[i][1], matrix[i][2]);
        if (i!=2) printf("\n---|---|---\n");
    }
    printf("\n");
}

char win_check (void) {
  int i;
  for (i = 0; i < 3; i++) 
    if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2])
      return matrix[i][0];
      
   for (i = 0; i < 3; i++) 
    if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i])
      return matrix[0][i];
  
 for (i = 0; i < 3; i++) 
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
      return matrix[0][0];
   for (i = 0; i < 3; i++) 
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
      return matrix[0][2];
  return ' ';
}

void comp_move(void) {
  int i,j;
  for (i = 0; i < 3; i++){ 
    for (j = 0; j < 3; j++) 
      if (matrix[i][j] == ' ') break;
      if (matrix[i][j] == ' ') break;
  }
  if (i*j == 9) {
    printf("Game Over. \n");
    exit(0);
  }
  else
  matrix[i][j] = 'O';
}

int main () {
    char done;

    printf("This is the game tic tac toe! Lets start!\n");

    done = ' ';
    create_matrix();

    do {
      print_matrix();
      player_input();
      done = win_check();
      if (done != ' ') break;
      comp_move();
      done = win_check();
    } while (done == ' ');

    if (done == 'X') printf("You win!\n");
    else printf("Computer win :(\n");
    print_matrix();
    
}
