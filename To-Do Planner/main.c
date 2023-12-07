#include <stdio.h>

int task_index[100];
int task_adress;

void addTask() {
    task_index[task_adress] = 1;
    task_adress++;
}

void removeTask() {
    task_index[task_adress] = 0;
    task_adress--;
}

void showTasks() {
    printf("%d\n%d\n%d\n", task_index[0], task_index[1], task_index[2]);
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
        showTasks();
            break;
        case '0':
            break;
        default:
            break;
        }

    }
    
    
}