/* Bassed on Gray, Exercise 3-1, p. 55-56
   How many processes are created?
   How many lines of output will be produced?
   Is it possible for a "ho" to be produced before a "hee"?
*/

#include <stdio.h>
#include <unistd.h>

int main (void)
{
   fork();
   printf ("hee\n");
   fork();
   printf ("ha\n");
   fork();
   printf ("ho\n");
   sleep(1);  // just so shell prompt doesn't print out before output
   return 0;
}
