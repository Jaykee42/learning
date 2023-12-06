#include <stdio.h>

int task_index[100];

void addTask() {
    task_index[0] = 1;
}

void removeTask() {
    task_index[0] = 0;
}

void showTasks() {
    printf("%d\n", task_index[0]);
}

int main() {
    char input;

    while (input != '0')
    {   printf("Enter the action: ");
        scanf(" %c", &input);  
        switch (input) {
        case 'a':
            showTasks();
            addTask();
            showTasks();
            break;
        case 's':
            showTasks();
            removeTask();
            showTasks();
            break;
        case 'd':
            break;
        case '0':
            break;
        default:
            break;
        }

    }
    
    
}