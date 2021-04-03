#include <stdio.h>
#include <stdlib.h>

#define UNKNOWN -1

struct _board_t {
  int ** board;
  int width;
  int height;
  int totalMines;
};

typedef struct _board_t board_t;

board_t * makeBoard(int w, int h)
{
  // malloc for struct
  board_t * b = malloc(sizeof(*b));
  size_t y = 0;
  size_t x = 0;

  int * row = NULL; // store each *row
  b->board = malloc(w * sizeof(*b->board));
  row = malloc(h * sizeof(*row));
  while(y < w) {
    while(x < h) {
      row[x] = UNKNOWN;
      b->board[y] = row[x];
      row = NULL;
      x++;
    }
    x = 0;
    y++;
     
  // addRandomMine(b);
  return b;
}

void printRow(board_t * r, int w, int h)
{
  for (size_t i = 0; i < w; i++) {
      for (size_t j = 0; j < h; j++) {
	printf("%d ", r->board[i][j]);
      }
  }
}
  
int main()
{
  int rows = 10;
  int cols = 10;
  board_t * r = makeBoard(rows, cols);
  printRow(r, rows, cols);
  
  return EXIT_SUCCESS;
}
