#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  const char * str = "The = sign";
  char * p = strchr(str, '=');
  printf("%I64d", p - str+1);

  return 0;
}
  
