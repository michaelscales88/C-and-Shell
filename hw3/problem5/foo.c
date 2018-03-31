#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum { false, true } bool;

static struct option long_options[] = {
   {"a", no_argument, 0, 'a'},
   {"c", required_argument, 0, 'c'},
   {0, 0, 0, 0}
};


int main(int argc, char *argv[]) {
   int c;
   int option_index = 0;
   bool a_flag = false,
        b_flag = false,
        c_flag = false,
        error_flag = false;
   char b_value[50],
        c_value[50];

   if (argc < 2) {
      fprintf(stderr, "Error: %s requires at least one argument.\n", argv[0]);
      error_flag = true;
   }

   while (
      !error_flag
      && ((c = getopt_long(argc, argv, "b:a", long_options, &option_index)) != -1)
      ) {
      switch (c) {
         case 'a':
            a_flag = true;
            break;

         case 'b':
            b_flag = true;
            strncpy(b_value, optarg, sizeof(b_value));
            break;

         case 'c':
            c_flag = true;
            strncpy(c_value, optarg, sizeof(c_value));
            break;

         case '?':
            error_flag = true;
            break;

         default:
            printf("?? getopt returned character code 0%o ??\n", c);
      }
   }

   // Verify that the -a and -b options were not both provided.
   if ((a_flag ||  b_flag) && (a_flag && b_flag)) {
      fprintf(stderr, "Error: Option a and option b cannot be set together.\n");
      error_flag = true;
   }

   // Check that at least one argument was provided.
   if (!error_flag) {
      printf("Arguments: ");
      while (optind < argc)
         printf("%s ", argv[optind++]);
      printf("\n");
   }

   if (!error_flag) {
      if (a_flag)
         printf("with option a set.\n");
      if (b_flag)
         printf("with option b set with value '%s'.\n", b_value);
      if (c_flag)
         printf("with option c set with value '%s'.\n", c_value);
   }
   exit(EXIT_SUCCESS);
}
