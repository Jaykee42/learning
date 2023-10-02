#include <stdio.h>

char arr[2][2];

int print(){
    int i, y;
    for (i = 0; i <= 2; i++)
        for (y = 0; y <= 2; y++) 
            printf("%d \n", arr[i][y]);
}

int main () {
    print();
    return 0;
}