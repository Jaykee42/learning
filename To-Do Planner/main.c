#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10000
#define DEFAULT_FILE_NAME "mainfile.txt"
#define MAX_STRING_SIZE 80

// Struct for a task
struct task {
    char name[MAX_STRING_SIZE];
};

// Array to store tasks
struct task task_array[MAX_TASKS];
int task_index = 0;

// Function to add a task
void addTask() {
    FILE *file_pointer;
    char input[MAX_STRING_SIZE];

    if ((file_pointer = fopen(DEFAULT_FILE_NAME, "a")) == NULL) {
        printf("Error while opening the file\n");
        exit(1);
    }

    do {
        printf("Enter a string: ");
        fgets(input, sizeof(input), stdin);
        fputs(input, file_pointer);
    } while (*input != '\n');

    fclose(file_pointer);

    return 0;
}

void rebuildTaskArray(int remove_index) {
    if (remove_index < 0 || remove_index >= task_index) {
        return;
    }

    for (int i = remove_index; i < task_index - 1; i++) {
        task_array[i] = task_array[i + 1];
        task_array[i].index = i + 1;
    }

    task_index--;
}

// Function to remove a task
void removeTask() {
    if (task_index > 0) {
        int indexToRemove;
        printf("Enter the index of the task to remove: ");
        scanf("%d", &indexToRemove);

        if (indexToRemove >= 1 && indexToRemove <= task_index) {
            for (int i = indexToRemove - 1; i < task_index - 1; i++) {
                strcpy(task_array[i].name, task_array[i + 1].name);
            }
            task_index--;
            printf("Task removed.\n");
        } else {
            printf("Invalid task index. No task removed.\n");
        }

        // Очистка буфера ввода
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    } else {
        printf("No tasks to remove.\n");
    }
}

// Function to show tasks
void showTasks() {
    FILE *filepointer;
    char string[MAX_STRING_SIZE];

    if ((filepointer = fopen(DEFAULT_FILE_NAME, "r")) == NULL) {
        printf("Error while opening the file\n");
        exit(1);
    }

    printf("Tasks:\n");
    task_index = 0;  // Reset task_index
    while (fgets(string, sizeof(string), filepointer) != NULL && task_index < MAX_TASKS) {
        printf("%s", string);
        // Copy task to task_array
        strcpy(task_array[task_index++].name, string);
    }

    fclose(filepointer);
}

int main() {
    char input;

    while (input != '0') {
        printf("Enter the action: \na - add task;\ns - remove;\nd - show tasks;\n0 - exit. ");
        scanf(" %c", &input);
        switch (input) {
        case 'a':
            addTask();
            break;
        case 's':
            removeTask();
            break;
        case 'd':
            showTasks();
            break;
        case '0':
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }

    return 0;
}
