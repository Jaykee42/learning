#include <stdio.h>



void partision(int* arr[], int* low, int* high) {
    int pivot = arr[*high];
    int i = *low - 1;
    for (int j = *low; j < *high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
}

int quickSort() {

}

int swap() {

}

int main() {

}