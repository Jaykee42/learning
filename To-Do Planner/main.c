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

    if ((file_pointer = fopen(DEFAULT_FILE_NAME, "a")) == NULL) {
        printf("Error while opening the file\n");
        exit(1);
    }

    while (1) {
        printf("Enter a task: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (input[0] == '\0') {
            break;
        }

        fprintf(file_pointer, "%s\n", input);

        // Очистка буфера ввода
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    fclose(file_pointer);
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

        // Очистка буфера ввода
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    } else {
        printf("No tasks to remove.\n");
    }
}

void showTasks() {
    if (task_index == 0) {
        printf("Task list is empty\n");
    } else {
        printf("List of tasks:\n");
        for (int i = 0; i < task_index; i++) {
            printf("Task %d: %s\n", task_array[i].index, task_array[i].name);
        }
    }
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
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }

        // Очистка буфера ввода
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    return 0;
}
