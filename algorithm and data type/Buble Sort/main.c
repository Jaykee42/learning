#include <stdio.h>
#include <stdbool.h>

int testarr[10000];
int n;

void swap(int* first, int* second) {
    int tmp = *first;
    *first = *second;
    *second = tmp;
}

int inputArr() {
    printf("Enter the size of arr:\n");
    scanf("%d", &n);
    printf("Enter each element of arr: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &testarr[i]);
    }
    return n;
}

void bubbleSort() {
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (testarr[j] > testarr[j + 1]) {
                swap(&testarr[j], &testarr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void printArr() {
    for (int i = 0; i < n; i++) {
        printf("%d ", testarr[i]);
    }
}

int main() {
    inputArr();
    printf("Unsorted arr: \n");
    printArr();
    bubbleSort();
    printf("\nSorted arr: \n");
    printArr();

    return 0;
}
