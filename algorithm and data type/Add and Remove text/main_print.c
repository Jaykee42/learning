#include <stdio.h>
#include <io.h>
#include <stdlib.h>

int main () {
    FILE *filepointer;
    char string[80];

    if ((filepointer=fopen("mainfile.txt", "r"))==NULL) {
        printf("Error while open file\n");
        exit(1);
    }

    fscanf(filepointer, "%s", string);
    fprintf(stdout, "%s", string);

    return 0;
}