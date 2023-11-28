#include <stdio.h>

int testarr[1000] = {67, 556, 345, 77, 989, 56, 33, 456, 23, 656565, 9898, 99, 6778, 7, 55656};

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

int main() {
    int n = sizeof(testarr) / sizeof(testarr[0]);

    quickSort(testarr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", testarr[i]);
    }

    return 0;
}
