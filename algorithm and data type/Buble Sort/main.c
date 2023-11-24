#include <stdio.h>

int bubleSort(int arr[]) {

    for (int i = 0; i < 6; i++) {
        if (arr[i] > arr[i++]) {
            arr[i] = arr[i++];
            arr[i++] = arr[i];
        }
    }
    return arr;
}

int main() {
    int test_arr[5] = {4,3,5,7,8};

    int output = bubleSort(test_arr);
    printf(output);
}