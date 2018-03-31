#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   FILE* fp = fopen("foo.txt", "r");
   // Verify that the file opened
   if (fp == NULL) {
      fprintf(stderr, "%s could not locate foo.txt.\n", argv[0]);
      exit(EXIT_FAILURE);
   }
   int id,
       numPersons = 0;
   char name[50],
        gender;
   double weight,
          height,
          totWeight = 0.0,
          totHeight = 0.0;
   while(fscanf(fp,"%[^:]:%d:%lf:%lf:%c\n", &name, &id, &weight, &height, &gender) != EOF) {
      // Accumulate information for a valid line.
      totWeight += weight;
      totHeight += height;
      numPersons++;
   }
   // Check for div-0
   if (numPersons > 0) {
      fprintf(stdout, "The average weight : %11.2lf lb\n", totWeight / numPersons);
      fprintf(stdout, "The average height : %11.2lf ft\n", totHeight / numPersons);
   } else
      fprintf(stderr, "No information read from %s.\n", "foo.txt");
   // Ensure we close the file.
   fclose(fp);
   exit(EXIT_SUCCESS);
}
