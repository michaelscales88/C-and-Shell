#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[]) {
   const char* path = getenv("PATH");
   printf("Current path: %s\n", path);
   char pathname[10] = "/opt/bin";
   printf("Checking for: %s\n", pathname);
   // Don't need to add the path variable if it exists
   if (strstr(path, pathname))
      printf("/opt/bin already exists in the path.\n");
   else {
      // Append the variable to the current path and set
      printf("Adding /opt/bin to path.\n");
      int pathnameLen = strlen(pathname),
          pathLen = strlen(path);
      char* newPath = malloc((pathnameLen + pathLen + 1) * sizeof(char));
      strncpy(newPath, path, pathLen);
      strcat(newPath, ":");
      strncat(newPath, pathname, pathnameLen);
      setenv("PATH", newPath, 1);
      path = getenv("PATH");
      printf("Path after adding: %s\n", path);
      free(newPath);
   }
   exit(0);
}
