#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int testarr[];

void testCreate(int arr[], int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000 + 1;
    }

}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printArr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void binarSearch(int arr[], int low, int high, int guess_int) {

     if (low <= high) {
        int middle = low + (high - low) / 2;

        if (arr[middle] == guess_int) {
            printf("Int found at index %d\n", middle);
            
            return;
        }

        if (arr[middle] < guess_int) {
            binarSearch(arr, middle + 1, high, guess_int);
        } else {
            binarSearch(arr, low, middle - 1, guess_int);
        }
    } else {
        printf("Int not found\n");
    }
}

int main() {
    int n;
    printf("Enter a size of arr: \n");
    scanf("%d", &n);
    testCreate(testarr, n);
    printf("Unsorted arr: \n");
    printArr(testarr, n);
    quickSort(testarr, 0, n - 1);
    printf("\nSorted arr: \n");
    printArr(testarr, n);
    int guess;
    printf("\nEnter a guess number: \n");
    scanf("%d", &guess);
    binarSearch(testarr, 0, n, guess);

    return 0;
}
