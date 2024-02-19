#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 9

int main_arr[SIZE][SIZE];

void create_game() {
    srand(time(NULL));

    for (int x = 0; x < SIZE; x++)
        for (int y = 0; y < SIZE; y++)
            main_arr[x][y] = rand() % 9 + 1;
}


// Функция для печати судоку
void printSudoku(int main_arr[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", main_arr[i][j]);
        }
        printf("\n");
    }
}

// Функция для проверки, может ли число num быть размещено в позиции (row, col)
int isValid(int main_arr[SIZE][SIZE], int row, int col, int num) {
    // Проверка по строке
    for (int i = 0; i < SIZE; i++) {
        if (main_arr[row][i] == num) {
            return 0;
        }
    }

    // Проверка по столбцу
    for (int i = 0; i < SIZE; i++) {
        if (main_arr[i][col] == num) {
            return 0;
        }
    }

    // Проверка внутри квадрата 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (main_arr[i + startRow][j + startCol] == num) {
                return 0;
            }
        }
    }

    return 1;
}

// Функция для решения судоку
int solveSudoku(int main_arr[SIZE][SIZE]) {
    int row, col, isEmpty = 1;

    // Поиск пустой позиции в судоку (0 означает пустую позицию)
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (main_arr[row][col] == 0) {
                isEmpty = 0;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    // Если весь судоку заполнен, то решение найдено
    if (isEmpty) {
        return 1;
    }

    // Попытаться разместить числа от 1 до 9 в пустой позиции и проверить, является ли размещение допустимым
    for (int num = 1; num <= SIZE; num++) {
        if (isValid(main_arr, row, col, num)) {
            main_arr[row][col] = num;

            // Рекурсивно вызывать решение для следующей позиции
            if (solveSudoku(main_arr)) {
                return 1;
            }

            // Если текущее размещение не приводит к решению, то отменить его
            main_arr[row][col] = 0;
        }
    }

    // Вернуть 0, если решение не найдено
    return 0;
}

int main() {
    create_game(main_arr);
    printf("Исходное судоку:\n");
    printSudoku(main_arr);

    if (solveSudoku(main_arr)) {
        printf("\nРешенное судоку:\n");
        printSudoku(main_arr);
    } else {
        printf("\nРешение не найдено.\n");
    }

    return 0;
}
