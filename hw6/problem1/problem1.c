#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char* argv[]) {
   pid_t pid1,
         pid2;
   int status1;
   int pp[2];
   if (pipe(pp) < 0) return 1;
   if ((pid1 = fork()) == 0) { // execute child1
      printf("Starting child1.\nPreparing to send output to child2.\n");
      dup2(pp[1], 1);
      close(pp[0]);
      close(pp[1]);
      printf("Printing inside child1 to send to child2.\n");
      exit(EXIT_SUCCESS);
   }

   // Prevent race condition between child2 and child1
   if ((waitpid(pid1, &status1, 0) == pid1) && (status1 != 0)) perror("Child1 process.\n");
   else printf("child exit status:0x %X\n", WEXITSTATUS(status1));

   if ((pid2 = fork()) == 0) { // execute child2
      printf("Starting child2.\nWaiting for input from child1.\n");
      dup2(pp[0], 0);
      close(pp[0]);
      close(pp[1]);
      printf("Printing output from child1 inside child2.\n");
      char buf[500];
      int len;
      while ((len=read(0, buf, 500)) > 0) write(1, buf, len);
      printf("Returning from child2.\n");
      exit(EXIT_SUCCESS);
   }
   close(pp[0]);
   close(pp[1]);
   exit(EXIT_SUCCESS);
}

