/*realese stack. main array and two func: pop and push*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

int *tos, *p1, stack[SIZE];

int main(void) {
    int value;

    tos = stack;
    p1 = stack;
}

void push(int i) {

    p1++;
    if (p1 == (tos+SIZE)) {
        printf("Stack overflow.\n");
    }
    *p1 = i;
}