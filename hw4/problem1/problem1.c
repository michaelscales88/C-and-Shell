#include <stdlib.h>
#include <stdio.h>
#include <time.h>

static char status;

void foo() {
   printf("%s\n", status == 'A' ? "aaa":"bbb");
}

int main(int argc, char* argv[]) {
   srand(time(0));
   status = (char)(64 + (rand() % 2) + 1);
   printf("Program status: %c\n", status);
   atexit(foo);
   exit(0);
}
