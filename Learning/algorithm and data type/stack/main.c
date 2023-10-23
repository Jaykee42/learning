/*realese stack. main array and two func: pop and push*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

void push(int i);
int pop(void);

int *tos, *p1, stack[SIZE];

int main(void) {
    int value;

    tos = stack;
    p1 = stack;

    do {
        printf("Insert a number: ");
        scanf("%d", &value);

        if (value != 0) push(value);
        else printf("Value on the top is %d\n", pop());
    } while (value != -1);
    return 0;
}

void push(int i) {

    p1++;
    if (p1 == (tos+SIZE)) {
        printf("Stack overflow.\n");
    }
    *p1 = i;
}

int pop(void) {

    if (p1 == tos) {
        printf("Stack is empty\n");
        exit(1);
    }
    p1--;
    return *(p1+1);
}