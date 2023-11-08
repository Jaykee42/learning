#include <stdio.h>
#include <conio.h>

int x, y, width = 10, gameover = 0;
int height = 20, input_id = 0;
int x_snake = 4, y_snake = 4;


int main() {
    
    while (gameover == 0) {
        draw();
        input();
    }
    
    
    return 0;
}
void draw() {
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++)
            if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                printf("#");
            }
            else {if (x == x_snake && y == y_snake) 
                    printf("0");
                else
                    printf(" ");
            }
        printf("\n");
         
    }
}


void input() {
    if (kbhit()) {
        switch (getch())
        {
        case 'a':
            y_snake--;
            break;
        case 'd':
            y_snake++;
            break;
        case 's':
            x_snake--;
            break;
        case 'w':
            x_snake++;
            break;
        
        default:
            break;
        }
    }
}

void gamelogic() {

}