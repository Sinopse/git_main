#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "kv.h"
#include "kv.c"

int main() {
  kvarray_t * array = readKVs("test.txt");
  printf("Printing all keys\n\n");
  printKVs(array);

  return EXIT_SUCCESS;
}
