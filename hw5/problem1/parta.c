#include <stdlib.h>
#include <stdio.h>
//#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main() {
   pid_t pid;
   if ((pid=fork()) == 0) {
      sleep(1);
      printf("child\n");
   }
   else if (pid>0) {
      printf("parent\n");
   }
}
