#include <stdio.h>

int tesarr[10] = {5,7,3,34,65,78,2524,1,65,897};

void linearSearh(int arr[], int to_search) {
    for (int i = 0; i < 10; i++) {
        if (arr[i] == to_search) {
            printf("Value is founded:\n");
            printf("%d ", arr[i-1]);
            printf("[%d] ", arr[i]);
            printf("%d ", arr[i+1]);
        }
    }
}

int main() {
    linearSearh(tesarr, 2524);
}