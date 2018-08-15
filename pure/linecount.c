#include <stdio.h>

#define FILENAME "./factorial.c"

int main ()
{
    FILE *file;
    file = fopen(FILENAME, "r");
    long charCount = 0;
    long lineCount = 0;
    
    int c;
    while ((c = fgetc(file)) != EOF) {
        ++charCount;
        if (c == '\n') ++lineCount;
    }
    printf("your file is %ld lines\nit is %ld characters\n", lineCount, charCount);
} 
