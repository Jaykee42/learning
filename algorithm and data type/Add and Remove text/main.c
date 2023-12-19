#include <stdlib.h>
#include <stdio.h>


int main() {
    FILE *fp;
    fp = fopen("test.txt", "w");
    char ch = getchar();
    putc(ch, fp);
    fclose;
}


