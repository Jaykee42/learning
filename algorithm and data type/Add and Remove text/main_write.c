#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DEFAULT_FILE_NAME "mainfile.txt"

int main() {

    FILE *file_pointer;
    char input[90];

    if ((file_pointer = fopen(DEFAULT_FILE_NAME, "w")) == NULL) {
        printf("Error while opening the file\n");
        exit(1);
    }

    do {
        printf("Enter a string: ");
        fgets(input, sizeof(input), stdin);
        fputs(input, file_pointer);
    } while (*input != '\n');

    fclose(file_pointer);

    return 0;
}
