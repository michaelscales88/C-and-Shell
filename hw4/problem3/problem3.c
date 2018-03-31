#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
   if (argc != 3) {
      fprintf(stderr, "Error: %s needs 2 arguments x and y.\n", argv[0]);
      exit(1);
   }
   int x = atoi(argv[1]),
       y = atoi(argv[2]);
   int** twoDarr = (int **) malloc(x * sizeof(int *));
   for (int i = 0; i < x; i++) {
      twoDarr[i] = (int *) malloc(y * sizeof(int));
      for (int i2 = 0; i2 < y; i2++)
         twoDarr[i][i2] = -1;
   }

   for (int i = 0; i < x; i++)
      free(twoDarr[i]);
   free(twoDarr);
   exit(0);
}
