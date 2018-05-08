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


void printDateTime(const char* valueName, const time_t val);


int main(int argc, char* argv[]) {
   if (argc != 2) {
      fprintf(stderr, "%s takes exactly 1 argument.\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   // Determine the path
   const char* pathname = (char * ) argv[0];

   struct stat fs;

   if (lstat(pathname, &fs) == 0) {
      printf("Target name: %s\n", basename(pathname));
      printf("Device ID: %lu\n", fs.st_dev);
      printf("Device Number (if applicable): %lu\n", fs.st_rdev);
      printf("File Serial Number: %lu\n", fs.st_ino);
      printf("File Mode: %d\n", fs.st_mode);
      printf("Hard Links: %lu\n", fs.st_nlink);                  // # of hard links
      printf("Owner Name: %s\n", getpwuid(fs.st_uid)->pw_name);   // Owner name
      printf("Owner Group: %s\n", getgrgid(fs.st_gid)->gr_name);  // Owner group
      printf("File Size: %ld B\n", fs.st_size);                   // file size
      printf("Optimal Block Size: %ld\n", fs.st_blksize);
      printf("Number of blocks allocated: %ld\n", fs.st_blocks);
      printDateTime("Last access time", (time_t) fs.st_atime);
      printDateTime("Last modification time", (time_t) fs.st_mtime);
      printDateTime("Last status change", (time_t) fs.st_ctime);
   } else fprintf(stderr, "Could not read information for %s.\n", pathname);

   exit(EXIT_SUCCESS);
}


void printDateTime(const char* valueName, const time_t val) {
   char dateTime[80];
   struct tm *info = localtime(&val);  // convert to struct tm
   strftime(dateTime, 80, "%H:%M:%S, %D", info);
   printf("%s: %s\n", valueName, dateTime);
}

