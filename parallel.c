#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *populate(int *row, int *col, char a[*row][*col]);
void transCell(int *rc, char a[*rc][*rc], char b[*rc][*rc], int startRow,
               int startCol, int endRow, int endCol);

long thread_count;

int main(int argc, char *argv[]) {
  time = atoi(argv[1]);
  row = atoi(argv[2]);
  col = atoi(argv[2]);
  rc = atoi(argv[2]);
  thread_count = atoi(argv[3]);
  char a[rc][rc], b[row][col];

  // populate cell dimension
  populate(&row, &col, a);

  long thread;
  pthread_t *thread_handles;

  thread_handles = (pthread_t *)malloc(thread_count * sizeof(pthread_t));

  for (thread = 0; thread < thread_count; thread++)
        pthread_create(&thread_handles[thread], NULL,
                       populate, /* PARAMETER(ONLY ONE WE NEED LIKE 900 PARAMETERS) */;

    for (thread = 0; thread < thread_count; thread++)
        pthread_join(thread_handles[thread], NULL, /*FUNCTION*/, /* PARAMETER (ONLY ONE PARAMETER WE NEED LIKE 900 PARAMETERS)*/);

    //Iterate time
    for (int gen = 1; gen < time; gen++) {
      // iterate through cells and assign to future array
      transCell(&rc, a, b, 0, 0, row, col);

      // dump here

      // assign present array as future array
      memcpy(a, b, sizeof(*a));
    }
    return 0;
}

return 0;
}
