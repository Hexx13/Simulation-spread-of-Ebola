#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// change size and column value to set the canvas size
int size;
int size;
int size;
int time;
void IOWrite(int rc, char a[rc][rc]);
char *populate(int *row, int *col, char a[*row][*col]);
void transCell(int *rc, char a[*rc][*rc], char b[*rc][*rc], int startRow,
               int startCol, int endRow, int endCol);

int main(int argc, char *argv[]) {
  time = atoi(argv[1]);
  size = atoi(argv[2]);

  char a[size][size], b[size][size];

  // populate cell dimension
  populate(&size, &size, a);

  // Iterate time
  for (int gen = 1; gen <= time; gen++) {
    // write current generation
    IOWrite(size, a);
    // iterate through cells and assign to future array
    transCell(&size, a, b, 0, 0, size, size);
    printf("%d\n", gen);


    // assign present array as future array
    memcpy(a, b, sizeof(*a));
  }
  return 0;
}
