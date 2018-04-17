#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main() {
   pid_t pid;
   if ((pid=fork()) == 0) {
      printf("child\n");
   }
   else if (pid>0) {
      wait(NULL);
      printf("parent\n");
   }
   exit(EXIT_SUCCESS);
}
