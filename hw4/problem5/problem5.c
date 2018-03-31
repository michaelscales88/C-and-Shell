#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
   FILE *fp;
   char path[1035];

   pid_t child_pid = fork();

   if (child_pid > 0) sleep(10);

   /* Open the command for reading. */
   fp = popen("ps", "r");
   if (fp == NULL) {
      printf("Failed to run command\n" );
      exit(1);
   }

   printf("Printing ps for pid: %d\n", getpid());
   /* Read the output a line at a time - output it. */
   while (fgets(path, sizeof(path)-1, fp) != NULL) {
      printf("%s", path);
   }

   /* close */
   pclose(fp);
   exit(0);
}
