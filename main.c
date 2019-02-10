#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define MAX_LINE 80 /* The maximum length command */

int main(int argc, char** argv) {

    char *args[MAX_LINE/2 + 1]; /* command line arguments */

    int running = 1; /* flag to determine when to exit program */

    size_t len = 0;
    char* line = NULL;


    while (running) {

        printf("osh>");
        getline(&line, &len, stdin);
        fflush(stdout);
        printf("%s", line);

        #define LSH_TOK_BUFSIZE 64
        #define LSH_TOK_DELIM " \t\r\n\a"
        int bufsize = LSH_TOK_BUFSIZE, position = 0;
        char **args = malloc(bufsize * sizeof(char*));
        char *token;
        if (!args) {
            fprintf(stderr, "lsh: allocation error\n");
            exit(1);
        }
        token = strtok(line, LSH_TOK_DELIM);
        int i = 0;
        while (token != NULL) {
            i++;
            args[position] = token;
            position++;
            if (position >= bufsize) {
                bufsize += LSH_TOK_BUFSIZE;
                args = realloc(args, bufsize * sizeof(char*));
                if (!args) {
                    fprintf(stderr, "lsh: allocation error\n");
                    exit(1);
                }
            }
            token = strtok(NULL, LSH_TOK_DELIM);
        }
        args[position] = NULL;
        for(int x = 0; x < i; x++) {
            printf("\n%s\n", args[x]);
        }


        /**
        * After reading user input, the steps are:
        * (1) fork a child process using fork()
        * (2) the child process will invoke execvp()
        * (3) if command included &, parent will invoke wait() */
    }

    return 0;
}