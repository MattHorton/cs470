/**
 * This program forks a separate process using the fork()/exec() 
 * system calls.
 *
 * Figure 3.10
 *
 * @author Gagne, Galvin, Silberschatz
 * Operating System Concepts  - Eighth Edition
 * Copyright John Wiley & Sons - 2008.
 * Annotated by Dr. Deborah Hwang
 */

#include <sys/types.h> // pid_t
#include <sys/wait.h>  // [added] wait()
#include <unistd.h>    // fork(), execlp()
#include <stdio.h>

int main()
{
   pid_t pid;
   
   /* fork a child process */
   pid = fork();
   
   if (pid < 0) { /* error occurred */
      fprintf(stderr, "Fork Failed\n");
      return 1;
   }

   if (pid == 0) { /* child process - run ls command */
      printf("I am the child %d\n",pid);   /* added */
      execlp("/bin/ls","ls", "-l", NULL);
      printf("Child - this should never execute\n");   /* added */
   }
   else { /* parent process - pid is PID of child*/
      /* parent will wait for the child to complete */
      printf("I am the parent %d\n",pid);  /* added */
      wait(NULL);
      printf("Child Complete\n");
   }

   return 0;
}
