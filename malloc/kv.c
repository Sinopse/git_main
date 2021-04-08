#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include <assert.h>

void copyKVs(char * destination, const char * target, int start, int end) {
  while(start <= end) {
    destination[start] = target[start];
    start++;
  }
}

long long int stripEqSign(char * line) {
  char * p = strchr(line, '=');
  // find the position of the = sign
  if (p != NULL) {
    *p = '\n';
  }
  return p-line+1; // return position for splitting
}

kvarray_t * readKVs(const char * fname) {
  FILE *f = fopen(fname, "r");
  if (f == NULL) {
    return NULL; // could not open file
  }
  // all pairs are stored
  kvarray_t * answer = malloc(sizeof(*answer));
  answer->pairs = NULL; // **pairs array
  answer->numPairs = 0; // counting kv pairs
  
  char * line = NULL;
  ssize_t len = 0;
  size_t sz = 0;
  long long int epos = 0; //position of the equal sign

  while((len = getline(&line, &sz, f)) >= 0) {
    kvpair_t * pair = malloc(sizeof(*pair)); // storing a single pair
    epos = stripEqSign(line); 
    pair->key = malloc(sizeof(*pair->key));
    copyKVs(pair->key, line, 0, epos); // copy from the start till \0 inclusive
    
    pair->value = malloc(sizeof(*pair->value));
    copyKVs(pair->value, line, epos+1, len);

    answer->pairs = realloc(answer->pairs, (answer->numPairs+1) *sizeof(*answer->pairs));
    answer->numPairs++;
  }
  int result = fclose(f);
  assert(result == 0);
  return answer;
  }

/* void freeKVs(kvarray_t * pairs) { */
/*   //WRITE ME */
/* } */

void printKVs(kvarray_t * pairs) {
  int num = pairs->numPairs;
  for (int i = 0; i < num; i++) {
    printf("key = '%s' value = '%s'\n",  pairs->pairs[0]->key,
	   pairs->pairs[0]->value);
  }
}

/* char * lookupValue(kvarray_t * pairs, const char * key) { */
/*   //WRITE ME */
/* } */

 
