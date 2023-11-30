#include <stdio.h>

int tesarr[10] = {5,7,3,34,65,78,2524,1,65,897};

void linearSearh(int arr[], int to_search) {
    int founded = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] == to_search) {
            printf("Value is founded:\n");
            printf("%d ", arr[i-1]);
            printf("[%d] ", arr[i]);
            printf("%d \n", arr[i+1]);
            founded = 1;
        }
        
    }
    if (!founded) {
        printf("Not founded.");
    }
}

int main() {
    int value, n;
    printf("Enter the number to find: \n");
    scanf("%d", &value);
    linearSearh(tesarr, value);
    scanf("%d", n);
}