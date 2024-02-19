#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int x, y, width = 30, gameover = 0;
int height = 60, input_id = 0;
int x_snake = 4, y_snake = 4;


int main() {
    
    while (gameover == 0) {
        draw();
        input();
        sleep(0,1);
        
    }
    
    
    return 0;
}
void draw() {
    system("cls");
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++)
            if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                printf("#");
            }
            else {if (x == x_snake && y == y_snake) 
                    printf("@");
                else
                    printf(" ");
            }
        printf("\n");
         
    }
}


void input() 
{   
    if (kbhit()) { 
        switch (getch()) { 
        case 'a': 
            y_snake--; 
            break; 
        case 's': 
            x_snake++; 
            break; 
        case 'd': 
            y_snake++; 
            break; 
        case 'w': 
            x_snake--; 
            break; 
        case 'x': 
            gameover = 1; 
            break; 
        } 
    } 
} 

void gamelogic() {

}