#include <stdio.h>

int userInputFunc(void)
{
    int userInput;
    FILE *main_file = fopen("/home/jaykee/Git_repos/learning/C/to_do_lister/main.file", "w");


    printf("Please, enter a command number: \n");
    scanf("%d", &userInput);

    switch (userInput) 
    {
        case 1:
            fprintf(main_file, "TEst");
            break;
        case 2:
            fprintf(main_file, "Fuuck!");
            break;

    }

           
}

int userActions(void) 
{
    
}

int main(void)
{
   userInputFunc(); 
}
