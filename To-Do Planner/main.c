#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10000
#define DEFAULT_FILE_NAME "mainfile.txt"

struct task {
    int index;
    char name[30];
};

struct task task_array[MAX_TASKS];
int task_index = 0;

void addTask() {
    
    FILE *file_pointer;
    char input[90];

    if ((file_pointer = fopen(DEFAULT_FILE_NAME, "w")) == NULL) {
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

void removeTask() {
    if (task_index > 0) {
        int indexToRemove;
        printf("Enter the index of the task to remove: ");
        scanf("%d", &indexToRemove);

        if (indexToRemove >= 1 && indexToRemove <= task_index) {
            rebuildTaskArray(indexToRemove - 1);
            printf("Task removed.\n");
        } else {
            printf("Invalid task index. No task removed.\n");
        }
    } else {
        printf("No tasks to remove.\n");
    }
}

void showTasks() {
    
    FILE *filepointer;
    char string[80];

    if ((filepointer=fopen("mainfile.txt", "r"))==NULL) {
        printf("Error while open file\n");
        exit(1);
    }

    fscanf(filepointer, "%s", string);
    fprintf(stdout, "%s", string);

    return 0;
}

int main() {
    char input;

    while (input != '0') {
        printf("Enter the action: \na - add task;\ns - remove;\nd - show tasks;\n0 - exit. ");
        scanf(" %c", &input);
        switch (input) {
        case 'a':
            addTask();
            showTasks();
            break;
        case 's':
            removeTask();
            showTasks();
            break;
        case 'd':
            showTasks();
            break;
        case '0':
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }

    return 0;
}
