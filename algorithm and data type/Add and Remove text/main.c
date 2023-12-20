#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]) {

    FILE *file_pointer;
    char input;

    if(argc!=2) {
        printf("Error: Please input a file name");
        exit(1);
    }

    if((file_pointer=fopen(argv[1], "w")) == NULL) {
        printf("Error while open the file");
    }

    do {
        input = getchar();
        putc(input, file_pointer);
    } while (input!='$');

    fclose(file_pointer);

    return 0;
}


