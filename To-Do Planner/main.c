#include <stdio.h>

int task_index[100];
char choice;

void action() {
    char input;
    scanf("%c", &input);
    switch (input)
    {
    case 'a':
        choice = 'a';
        break;
    
    default:
        break;
    }
}

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

    showTasks();
    addTask();
    showTasks();
    removeTask();
    showTasks();
}