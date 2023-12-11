#include <stdio.h>

#define MAX_TASKS 10000

struct task {
    int index;
    char name[30];
};

struct task task_array[MAX_TASKS];
int task_count = 0;

void addTask() {
    if (task_count < MAX_TASKS) {
        printf("Enter new task name: \n");
        scanf("%s", task_array[task_count].name);
        task_array[task_count].index = task_count + 1;
        task_count++;
        printf("Task added!\n");
    } else {
        printf("Task limit reached. Can't add more tasks.\n");
    }
}

void removeTask() {
    if (task_count > 0) {
        task_count--;
        printf("Task removed.\n");
    } else {
        printf("No tasks to remove.\n");
    }
}

void showTasks() {
    if (task_count == 0) {
        printf("Task list is empty\n");
    } else {
        printf("List of tasks:\n");
        for (int i = 0; i < task_count; i++) {
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
