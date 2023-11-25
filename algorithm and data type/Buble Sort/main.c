#include <stdio.h>
#include <stdbool.h>

void swap (int* first, int* second) {
    int tmp = *first;
    *first = *second;
    *second = tmp;
}

void bubbleSort(int arr[], int n) {
    
    bool swappted;

    for (int i = 0; i < n - 1; i++) {
        swappted = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swappted = true;
            }
            
        }
        if (swappted == false)
            break; 
    }
}

void printArr(int arr[], int n) {

    for ( int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int testarr[] = {676,445,7878,445444,787878,7676334,23,5554,234,111,23,4433442,2342,342,34545,4346,45};
    int n = sizeof(testarr) / sizeof(testarr[0]);
    printf("Unsorted arr: \n");
    printArr(testarr, n);
    bubbleSort(testarr, n);
    printf("\nSorted arr: \n");
    printArr(testarr, n);

    return 0;
}