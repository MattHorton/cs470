#include<stdio.h>
#include<string.h>

#define MAX_LINE 64

int main(int argc, char** argv) {
    FILE* inputFile;
    printf("\n%s\n", argv[1]);
    inputFile = fopen(argv[1], /*(const char*)*/"r");
    
    char* line = NULL;
    size_t length = 0;

    while(getline(&line, &length, inputFile) != -1) {
        printf("%s\n", line);
        length = 0;
        line = NULL;
    }
    
    return 0;
}