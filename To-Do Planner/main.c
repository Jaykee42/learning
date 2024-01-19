#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10000
#define DEFAULT_FILE_NAME "mainfile.txt"
#define MAX_STRING_SIZE 80

int numberOfTaskInArray;

// Struct for a task
struct task {
    char name[MAX_STRING_SIZE];
    int taskIndex;
};

// Array to store tasks
struct task allTaskArray[MAX_TASKS];


// Function to add a task
void addTask() {
    FILE *mainFilePointer;
    char nameOfNewTask[MAX_STRING_SIZE];

    if ((mainFilePointer = fopen(DEFAULT_FILE_NAME, "a")) == NULL) {
        printf("Error while opening the file\n");
        exit(1);
    }

    do {
        printf("Enter a task name: ");
        fgets(nameOfNewTask, sizeof(nameOfNewTask), stdin);
        fputs(nameOfNewTask, mainFilePointer);
    } while (*nameOfNewTask != '9');

    fclose(mainFilePointer);

    return;
}

void rebuildTaskArray(int remove_index) {
    if (remove_index < 0 || remove_index >= numberOfTaskInArray) {
        return;
    }

    for (int i = remove_index; i < numberOfTaskInArray - 1; i++) {
        allTaskArray[i] = allTaskArray[i + 1];
    }

    numberOfTaskInArray--;
}

// Function to remove a task
void removeTask() {
    if (numberOfTaskInArray > 0) {
        int indexToRemove;
        printf("Enter the index of the task to remove: ");
        scanf("%d", &indexToRemove);

        if (indexToRemove >= 1 && indexToRemove <= numberOfTaskInArray) {
            for (int i = indexToRemove - 1; i < numberOfTaskInArray - 1; i++) {
                strcpy(allTaskArray[i].name, allTaskArray[i + 1].name);
            }
            numberOfTaskInArray--;
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
    numberOfTaskInArray = 0;  // Reset taskIndex
    while (fgets(string, sizeof(string), filepointer) != NULL && numberOfTaskInArray < MAX_TASKS) {
        printf("%s", string);
        // Copy task to allTaskArray
        strcpy(allTaskArray[numberOfTaskInArray++].name, string);
    }

    fclose(filepointer);
}

int main() {
    char nameOfNewTask;

    while (nameOfNewTask != '0') {
        printf("Enter the action: \na - add task;\ns - remove;\nd - show tasks;\n0 - exit. ");
        scanf(" %c", &nameOfNewTask);
        switch (nameOfNewTask) {
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
