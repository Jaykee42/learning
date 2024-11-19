#include <stdio.h>

int userInputFunc(void)
{
     int userInput;

    printf("Please, enter a command number: \n");
    scanf("%d", &userInput);

    switch (userInput) 
    {
        case 1:
            printf("UserInput - 1");
            break;
        case 2:
            printf("UserInput - 2");
            break;

    }

}


int main(void)
{
   userInputFunc(); 
}
