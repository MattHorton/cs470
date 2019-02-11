// File: zombie.cpp
// Program that creates zombie processes

#include <iostream>
#include <unistd.h>
using namespace std;

int main ()
{
   for (int i = 0; i < 3; i++) {
      if (fork() == 0) {
	 cout << "Child process " << getpid() << " exiting" << endl;
	 return 0;
      }
   }
   while (1);
   cout << "Parent exiting" << endl;
}
