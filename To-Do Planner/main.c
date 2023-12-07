#include <stdio.h>

#define MAX_TASKS 10000

int task_index[MAX_TASKS];
int task_count = 0;

void addTask() {
    if (task_count < MAX_TASKS) {
        task_index[task_count] = 1;
        task_count++;
        printf("Task added!\n");
    }
    else {
        printf("task limit reached. Can't add more tasks.\n");
    }
    
}

void removeTask() {
    if (task_count > 0) {
        task_index[task_count] = 0;
        task_count--;
        printf("Task removed.\n");
    }
    else {
        printf("No tasks to remove.\n");
    }
    

}

void showTasks() {
    
    for (int i = 0; i < task_count; i++) {
        printf("%d\n", task_index[i]);
    }
}

int main() {
    char input;
    
    while (input != '0')
    {
        printf("Enter the action: ");
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
            break;
        }

    }
     
}