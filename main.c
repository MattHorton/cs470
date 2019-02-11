#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define MAX_LINE 80 /* The maximum length command */
#define LSH_TOK_DELIM " \t\r\n\a"

void getCommand(char** args, int* numArgs);






int main(int argc, char** argv) {

    char *args[MAX_LINE/2 + 1]; /* command line arguments */

    int running = 1; /* flag to determine when to exit program */

    


    while (running) {

        char *args[MAX_LINE/2 + 1];


        /**
        * After reading user input, the steps are:
        * (1) fork a child process using fork()
        * (2) the child process will invoke execvp()
        * (3) if command included &, parent will invoke wait() */
    }

    return 0;
}


void getCommand(char** args, int* numArgs) {
    size_t len = 0;
    char* line = NULL;
    int position = 0;
    char *token;
    int i = 0;

    printf("osh>");
    getline(&line, &len, stdin);
    fflush(stdout);
    printf("%s", line);

    token = strtok(line, LSH_TOK_DELIM);
    while (token != NULL) {
        i++;
        args[position] = token;
        position++;
        token = strtok(NULL, LSH_TOK_DELIM);
    }
    args[position] = NULL;

    for(int x = 0; x < i; x++) {
        printf("\n%s\n", args[x]);
    }
}