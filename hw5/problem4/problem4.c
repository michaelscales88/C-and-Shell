#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

bool eof(int fd);

int main(int argc, char* argv[]) {
   if (argc != 2) {
      fprintf(stderr, "Error: %s requires exactly 1 argument.\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   int fd = open(argv[1], O_RDONLY);
   if (fd < 0) {
      fprintf(stderr, "Error: Could not open file: %s\n", argv[1]);
      exit(EXIT_FAILURE);
   }

   char c;
   while (!eof(fd)) {
      read(fd, &c, 1);
      printf("%c", c);
   }
   close(fd);
   exit(EXIT_SUCCESS);
}

bool eof(int fd) {
   char c;
   bool atEof = false;
   int bRead = read(fd, &c, 1);
   if (bRead < 1) atEof = true;
   else lseek(fd, -1, SEEK_CUR);
   return atEof;
}
