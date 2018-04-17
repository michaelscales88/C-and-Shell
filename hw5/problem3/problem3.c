#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
   if (argc != 2) {
      fprintf(stderr, "Error: %s takes exactly 1 argument.\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   int fd = open(argv[1], O_RDWR|O_APPEND);
   char c;

   if (fd < 0) {
      fprintf(stderr, "Error: Could not open file %s.\n", argv[1]);
      exit(EXIT_FAILURE);
   }

   // Test reading
   lseek(fd, 0, SEEK_SET);
   while (read(fd, &c, 1)) printf("%c", c);

   // Test writing
   lseek(fd, 0, SEEK_SET);
   char test[5];
   sprintf(test, "%c%c%c%c%c", 't', 'e', 's', 't', '\n');
   write(fd, test, 5);

   close(fd);
   exit(EXIT_SUCCESS);
}
