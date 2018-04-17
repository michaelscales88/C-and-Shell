#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>


int foo_system(const char *command);

int main(int argc, char* argv[]) {
   if (argc < 2) {
      fprintf(stderr, "%s takes at least one argument.", argv[0]);
      exit(1);
   }

   pid_t pid = fork();

   char cmd[500];

   if (pid == -1) {
    // error, failed to fork()
   } else if (pid > 0) {
      wait(NULL);
   } else {
      // we are the child
      strcpy(cmd, argv[1]);
      for (int i = 2; i < argc - 2; i++) {
         strcat(cmd, " ");
         strcat(cmd, argv[i]);
      }
      foo_system(cmd);
      // Failure on execl failure
      _exit(EXIT_FAILURE);
   }
   // Exit from the parent process
   exit(EXIT_SUCCESS);
}

int foo_system(const char *command) {
   execl( "/bin/sh", "sh", "-c", command, (char *) 0);
   fprintf(stderr, "Return not expected. Must be an execl() error.\n");
   return 1;
}
