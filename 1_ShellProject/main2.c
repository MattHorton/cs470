#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE 80 //the maximum length command

int main(void) {
    char* args[MAX_LINE/2 + 1]; //command line arguments
    int should_run = 1; //flag to determine when to exit program
    char input[MAX_LINE]; //user input string

    while(should_run) {
        //input tokenizer
        printf("osh>");
        fflush(stdout);
        scanf("%[^\n]%*c", input);
        int i = 0;
        args[i] = strtok(input," ");
        printf("args[%d] = \"%s\"\n", i, args[i]);
        while (args[i] != NULL) {
          i++;
          args[i] = strtok(NULL, " ");
          printf("args[%d] = \"%s\"\n", i, args[i]);
        }


        //after reading user input
        //  fork a child process using fork
        //  the child process will invoke execvp
        //  if command included &, parent will invoke wait

        if(strcmp(args[0], "exit") == 0)
          should_run = 0;
        if(strcmp(args[i-1], "&") != 0) {
            printf("ampersand NOT detected entering branch w/ wait\n");
            pid_t pid = fork(); // fork a child process
            if(pid < 0) { // error occurred
                fprintf(stderr, "Fork Failed");
                return 1;
            }
            else if(pid == 0) { // child process
                //execvp(char* command, char* params[]);
                execvp(args[0], args);
                //printf("This is printed from child process");
                for(int j = 0; j < i; j++) { //clear out arguments
                    args[j] = NULL;
                }
            }
            else/* if(args[0] == "&") */{ // parent process must invoke wait
                wait(NULL);
                //printf("Child Complete\n");
            }
        }
        else {
            printf("ampersand WAS detected entering branch w/out wait\n");//won't work because of behavior w/ &
            pid_t pid = fork(); // fork a child process
            if(pid < 0) { // error occurred
                fprintf(stderr, "Fork Failed");
                return 1;
            }
            else if(pid == 0) { // child process
                //execvp(char* command, char* params[]);
                args[i-1] = NULL;
                execvp(args[0], args);
                //printf("This is printed from child process");
            }
            else {
            //    wait(NULL);
            printf("\n\n");
            }
        }
    }


    return 0;
}