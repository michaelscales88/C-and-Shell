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


void printPermission(const struct stat* fs);


int main(int argc, char* argv[]) {
   if (argc != 2) {
      fprintf(stderr, "%s takes exactly 1 argument.\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   char tgt_path[PATH_MAX];

   // Determine the path
   const char* pathname = (optind == argc) ? NULL:argv[optind++];

   // Get the absolute path
   if (pathname) realpath(pathname, tgt_path);
   else {
      fprintf(stderr, "%s is not a real path.\n", pathname);
      exit(EXIT_FAILURE);
   }

   struct stat fs;

   if (stat(tgt_path, &fs) == 0) {
      printf("Target name: %s\n", basename(tgt_path));
      printf("Device: %lu\n", fs.st_dev);
      printf("File Serial Number: %lu\n", fs.st_ino);
      printf("Hard Links: %lu\n", fs.st_nlink);                  // # of hard links
      printf("Owner Name: %s\n", getpwuid(fs.st_uid)->pw_name);   // Owner name
      printf("Owner Group: %s\n", getgrgid(fs.st_gid)->gr_name);  // Owner group
      printf("File Size: %ld B\n", fs.st_size);                   // file size
      printPermission(&fs);
      printDateTime("Last access time", (time_t) fs.st_atime);
      printDateTime("Last modification time", (time_t) fs.st_mtime);
      printDateTime("Last status change", (time_t) fs.st_ctime);
   }

   exit(EXIT_SUCCESS);
}


void printDateTime(const char* valueName, const time_t val) {
   char dateTime[80];
   struct tm *info = localtime(&val);  // convert to struct tm
   strftime(dateTime, 80, "%H:%M:%S, %D", info);
   printf("%s: %s\n", valueName, dateTime);
}


void printPermission(const struct stat* fs) {
   printf("Permissions: ");
   printf( (S_ISDIR(fs->st_mode)) ? "d" : "");
   printf( (S_ISLNK(fs->st_mode)) ? "l" : "-");
   printf( (fs->st_mode & S_IRUSR) ? "r" : "-");
   printf( (fs->st_mode & S_IWUSR) ? "w" : "-");
   printf( (fs->st_mode & S_IXUSR) ? "x" : "-");
   printf( (fs->st_mode & S_IRGRP) ? "r" : "-");
   printf( (fs->st_mode & S_IWGRP) ? "w" : "-");
   printf( (fs->st_mode & S_IXGRP) ? "x" : "-");
   printf( (fs->st_mode & S_IROTH) ? "r" : "-");
   printf( (fs->st_mode & S_IWOTH) ? "w" : "-");
   printf( (fs->st_mode & S_IXOTH) ? "x" : "-");
   printf("\n");
}

