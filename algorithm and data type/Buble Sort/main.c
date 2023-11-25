#include <stdio.h>

int swap (int* first, int* second) {
    int tmp = *first;
    *first = *second;
    *second = tmp;
}

int main() {
    int fx = 3;
    int sy = 76;

    swap(&fx, &sy);

    printf("First now: %d, second now %d", fx, sy);
}