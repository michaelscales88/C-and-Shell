#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <getopt.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>


void remFilesDir(const char* pathname);

int main(int argc, char* argv[]) {
   if (argc != 2) {
      fprintf(stderr, "%s requires at least one argument.\n",argv[0]);
      exit(EXIT_FAILURE);
   }

   // Determine the path from the user
   const char* pathname = (optind == argc) ? NULL:argv[optind++];
   remFilesDir(pathname);
   exit(EXIT_SUCCESS);
}

void remFilesDir(const char *pathname) {
   if (pathname == NULL) return;
   struct stat fs;

   // Base Case: File
   if ((stat(pathname, &fs) == 0) && S_ISREG(fs.st_mode)) {
      // Remove file
      if (remove(pathname) != 0) fprintf(stderr, "Could not delete %s.\n", basename(pathname));
      return;
   }

   DIR *dir = opendir(pathname);
   struct dirent *dp;

   while ((dp=readdir(dir))) {

      if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..")) continue;
      char *raw_path;
      char tgt_path[PATH_MAX];

      // Create the full path to the file or directory
      if (0 > asprintf(&raw_path, "%s/%s", pathname, dp->d_name)) {
         perror(dp->d_name);
         continue;
      }

      realpath(raw_path, tgt_path);
      remFilesDir(tgt_path);
   }
   closedir(dir);
   rmdir(pathname);
}
