#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include <assert.h>

void copyKVs(char * destination, const char * target, int start, int end) {
  int i = 0;
  while(start < end) {
    destination[i] = target[start];
    start++;
    i++;
  }
}

long long int stripEqSign(char * line) {
  char * p = strchr(line, '=');
  // find the position of =
  if (p != NULL) {
    *p = '\0';
  }
  return p-line+1; // return position for split
}

void stripNewline(char * str) {
  char * p = strchr(str, '\n');
  if (p != NULL) {
    *p = '\0';
  }
}

kvpair_t * readAPair(char * line, ssize_t * len, size_t * sz) {
  kvpair_t * pair = malloc(sizeof(*pair)); // storing a single pair
  long long int epos = 0; //position of the equal sign
<<<<<<< HEAD
 
=======

>>>>>>> 8e2a6d0ef505cc81af4f9f5d1adde61cffe1d108
  epos = stripEqSign(line);
  stripNewline(line);

  pair->key = malloc(sizeof(*pair->key));
  pair->value = malloc(sizeof(*pair->value));

  copyKVs(pair->key, line, 0, epos); // copy till \0 incl
  copyKVs(pair->value, line, epos, *len);
  return pair;
}

kvarray_t * readKVs(const char * fname) {
  FILE *f = fopen(fname, "r");
  if (f == NULL) {
    return NULL; // could not open
  }
  char * line = NULL;
  ssize_t len = 0;
  size_t sz = 0;
  kvarray_t * answer = malloc(sizeof(*answer));
  answer->numPairs = 0;
  // read lines continuosly
  while ((len = getline(&line, &sz, f)) >= 0) {
    answer->pairs = realloc(answer->pairs,
			    (answer->numPairs+1) *sizeof(*answer->pairs));
    answer->pairs[answer->numPairs] = readAPair(line, &len, &sz); // use numPairs as index
    answer->numPairs++;
  }
  free(line); // correct?
  int result = fclose(f);
  assert(result == 0);
  return answer;
}

/* void freeKVs(kvarray_t * pairs) { */
/*   //WRITE ME */
/* } */

<<<<<<< HEAD
  void printKVs(kvarray_t * pairs) {
    int num = pairs->numPairs;
    for (int i = 0; i < num; i++) {
      printf("key = '%s' value = '%s'\n",  pairs->pairs[i]->key,
	     pairs->pairs[i]->value);
    }
=======
void printKVs(kvarray_t * pairs) {
  int num = pairs->numPairs;
  for (int i = 0; i < num; i++) {
    printf("key = '%s' value = '%s'\n",  pairs->pairs[i]->key,
	   pairs->pairs[i]->value);
>>>>>>> 8e2a6d0ef505cc81af4f9f5d1adde61cffe1d108
  }
}
