#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) {

    FILE *file_pointer;
    char input[90];

    if(argc!=2) {
        printf("Error: Please input a file name");
        exit(1);
    }

    if((file_pointer=fopen(argv[1], "w")) == NULL) {
        printf("Error while open the file");
    }

    do {
        printf("Enter a string: ");
        gets(input);
        strcat(input, "\n");
        fputs(input, file_pointer);
    } while (*input!='\n');

    

    return 0;
}


