#include <stdio.h>
#include <time.h>

int tesarr[];

void testCreate(int arr[], int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000 + 1;
    }

}

void linearSearh(int arr[], int size, int to_search) {
    int founded = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == to_search) {
            printf("Value is founded:\n");
            printf("%d ", arr[i-1]);
            printf("[%d] ", arr[i]);
            printf("%d \n", arr[i+1]);
            founded = 1;
            break;
        }
        
    }
    if (!founded) {
        printf("Not founded.\n");
    }
}

int main() {
    int value, n;
    printf("Enter an array size: \n");
    scanf("%d", &n);
    testCreate(tesarr, n);
    printf("Enter the number to find: \n");
    scanf("%d", &value);
    linearSearh(tesarr, n, value);
    for (int i = 0; i < n; i++ ) {
        printf("%d ", tesarr[i]);
    }
    scanf("%d", n);
}