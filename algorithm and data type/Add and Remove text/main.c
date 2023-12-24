#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DEFAULT_FILE_NAME "test.txt"

int main(int argc, char *argv[]) {

    FILE *file_pointer;
    char input[90];

    char *filename = (argc == 2) ? argv[1] : DEFAULT_FILE_NAME;

    if ((file_pointer = fopen(filename, "w")) == NULL) {
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
