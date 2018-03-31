#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
   if (argc != 2) {
      fprintf(stderr,
               "Error: %s takes exactly 1 argument.\n", 
               argv[0]);
      exit(1);
   }
   printf("Parent process pid: %d\n", getpid());
   int N = atoi(argv[1]);
   // Create N number of processes
   for(int i = 0; i < N; i++) {
      if(fork() == 0)
      {
         printf("My pid is %d and my parents pid is %d.\n", 
               getpid(), getppid());
         exit(0);
      }
   }
   // Wait N number of times
   for(int i = 0; i < N; i++) wait(NULL);
   exit(0);
}
