#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>
#include <getopt.h>


const int BUFFER_CAP = 1000;


const struct option longopts[] = {
   { 0, 0, 0, 0 },
};


void insert(char* files[], const char *ptrName, int *cap);


int main(int argc, char* argv[]) {
   int c;
   bool asc = false;
   while ((c = getopt_long(argc, argv, ":a", longopts, NULL)) != -1) {
      switch (c) {
         case 'a':
            asc = true;
            break;
         case '?': default:
            break;
      }
   }

   char tgt_path[PATH_MAX];
   // Determine the path from the user
   const char* pathname = (optind == argc) ? NULL:argv[optind++];

   // Get the absolute path into tgt_path
   if (pathname) realpath(pathname, tgt_path);
   else {
      fprintf(stderr, "%s requires a valid pathname.\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   struct stat fs;

   // Print the filename if the pathname is a file
   if ((stat(tgt_path, &fs) == 0) && S_ISREG(fs.st_mode))
      printf("%s\n", basename(tgt_path));
   // If the pathname is a directory list and print the files
   else {
      DIR *dir = opendir(tgt_path);
      struct dirent *dp;
      char *files[BUFFER_CAP];
      int cap = 0;

      while ((dp=readdir(dir))) {
         if (cap == BUFFER_CAP) {
            printf("Buffer full.\n");
            break;
         }
         if (asc) insert(files, dp->d_name, &cap);
         else printf("%s\n", dp->d_name);
      }
      if (asc) {
         printf("Printing ascending.\n");
         for (int i = 0; i < cap; i++) printf("%s\n", files[i]);
      }
      // Cleanup memory and close directory
      for (int i = 0; i < cap; i++) free(files[i]);
      closedir(dir);
   }
   exit(EXIT_SUCCESS);
}

void insert(char* files[], const char* ptrName, int *cap) {
   int len = strlen(ptrName);
   char *filename = (char *) malloc(sizeof(char) * len);
   strncpy(filename, ptrName, len);

   // Find insert point
   int i = 0;
   while ((i < *cap) && (strcasecmp(files[i], filename) < 0)) i++;
   // Shift right and insert
   for (int e = ++(*cap); e > i; e--) files[e] = files[e - 1];
   files[i] = filename;
}

