#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   if (argc < 2) {
      fprintf(
         stderr,
         "Error: Too few arguments provided.\n%s requires an argument.\n",
         argv[0]
      );
      exit(EXIT_FAILURE);
   }
   int c;
   FILE* fp = fopen(argv[1], argv[2]);
   if (fp != NULL) {
      c = fgetc(fp);
      printf("Read char: %c\n", (char) c);
      fputc((int) 'x', fp);
      printf("Tried to write an x to %s.\n", argv[0]);
   }
   fclose(fp);
   exit(EXIT_SUCCESS);
}
