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
    showTasks();
    addTask();
    showTasks();
    removeTask();
    showTasks();
}