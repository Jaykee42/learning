#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10000
#define DEFAULT_FILE_NAME "mainfile.txt"
#define MAX_STRING_SIZE 80

// Struct for a task
struct task {
    char taskNameinArray[MAX_STRING_SIZE];
    int taskIndex;
};

int numberOfTaskInArray;
struct task allTaskArray[MAX_TASKS];

// Function to add a task
void addTask() {
    FILE *mainFilePointer;
    char nameOfNewTask[MAX_STRING_SIZE];

    if (!(mainFilePointer = fopen(DEFAULT_FILE_NAME, "a"))) {
        perror("Error while opening the file");
        exit(EXIT_FAILURE);
    }

    do {
        printf("Enter a task name: ");
        fgets(nameOfNewTask, sizeof(nameOfNewTask), stdin);
        fputs(nameOfNewTask, mainFilePointer);
        
    } while (nameOfNewTask[0] == '\n');
        fclose(mainFilePointer);
}

// Function to remove a task
void removeTask() {
    if (numberOfTaskInArray > 0) {
        int indexToRemove;
        printf("Enter the index of the task to remove: ");
        scanf("%d", &indexToRemove);

        if (indexToRemove >= 1 && indexToRemove <= numberOfTaskInArray) {
            for (int i = indexToRemove - 1; i < numberOfTaskInArray - 1; i++) {
                strcpy(allTaskArray[i].taskNameinArray, allTaskArray[i + 1].taskNameinArray);
            }
            numberOfTaskInArray--;
            printf("Task removed.\n");
        } else {
            printf("Invalid task index. No task removed.\n");
        }

        while (getchar() != '\n'); // Clear input buffer
    } else {
        printf("No tasks to remove.\n");
    }
}

// Function to show tasks
void showTasks() {
    FILE *filepointer;
    char string[MAX_STRING_SIZE];

    if (!(filepointer = fopen(DEFAULT_FILE_NAME, "r"))) {
        perror("Error while opening the file");
        exit(EXIT_FAILURE);
    }

    printf("Tasks:\n");
    numberOfTaskInArray = 0;

    while (fgets(string, sizeof(string), filepointer) && numberOfTaskInArray < MAX_TASKS) {
        printf("%s", string);
        strcpy(allTaskArray[numberOfTaskInArray++].taskNameinArray, string);
    }

    fclose(filepointer);
}

int main() {
    char nameOfNewTask;

    while (1) {
        printf("Enter the action: \na - add task;\ns - remove;\nd - show tasks;\n0 - exit. ");
        scanf(" %c", &nameOfNewTask);

        switch (nameOfNewTask) {
            case 'a': addTask(); break;
            case 's': removeTask(); break;
            case 'd': showTasks(); break;
            case '0': exit(EXIT_SUCCESS);
            default: printf("Invalid choice. Try again.\n"); break;
        }
    }

    return 0;
}
