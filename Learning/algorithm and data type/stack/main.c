/*realese stack. main array and two func: pop and push*/

#include <stdio.h>

int *pop1, *push1, stack[50];

void push(int i);

int main(){

    push1 = stack;
    push(5);
    printf("%d ", push1[0]);
}

void push(int i) {
    push1++;
    *push1 == i;
}