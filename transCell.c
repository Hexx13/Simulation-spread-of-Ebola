#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char stateFunc(char *cell, int *rc, char array[*rc][*rc], int *r, int *c);
void transCell(int *rc, char a[*rc][*rc], char b[*rc][*rc], int startRow,
               int startCol, int endRow, int endCol) {
  int i, j;
  for (i = startRow; i < endRow; i++) {
    for (j = startCol; j < endCol; j++) {
      printf("row: %d, col: %d", i, j);
      b[i][j] = stateFunc(&a[i][j], rc, a, &i, &j);
      printf("%c \n", b[i][j]);
    }
  }
}