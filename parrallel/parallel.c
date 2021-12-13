#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// change size and column value to set the canvas size
int size;
int iteration;
void IOWrite(int rc, char a[rc][rc]);
char *populate(int *row, int *col, char a[*row][*col]);
void transCell(int rc, char a[rc][rc], char b[rc][rc], int startRow,
               int startCol, int endRow, int endCol);


struct ThreadWork{
  int start;
  int end;
  int col;
  int row;
  int size;
  char *a;
};



int main(int argc, char *argv[]) {

  long thread;  /* Use long in case of a 64-bit system */
  pthread_t* thread_handles;
  thread_handles = (pthread_t*) malloc (thread_count*sizeof(pthread_t));



  iteration = atoi(argv[1]);
  size = atoi(argv[2]);
  thread = atoi(argv[3]);

  char a[size][size], b[size][size];

  // populate cell dimension
  populate(&size, &size, a);

  // Iterate time
  for (int gen = 1; gen <= iteration; gen++) {
    // write current generation
    IOWrite(size, a);

    // iterate through cells and assign to future array
    transCell(size, a, b, 0, 0, size, size);
    printf("%d\n", gen);
    int i , j;
    /*for (i = 0; i < size; i++) {
      for (j = 0; j < size; j++) {
        //printf("nooooo row: %d, col: %d", i, j);
        a[i][j] = b[i][j];
        //printf("%c \n", a[i][j]);
      }
    }*/

    // assign present array as future array
    memcpy(a, b, sizeof(a));

  }
  return 0;
}
