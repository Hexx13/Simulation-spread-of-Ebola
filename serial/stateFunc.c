#include "counters.h"
#include <stdio.h>
#include <stdlib.h>

char stateFunc(char *cell, int rc, char array[rc][rc], int *r, int *c) {
  if (*cell != 'B') {
    if (*cell == 'A') {
      int neighbors = count_infect_total_cell(rc, array, r, c);

      if (neighbors < 1) {
        // Generate rndom int between 0 - 1000
        int chance = rand() % 1000;
        if (chance < 1) {
          return 'C';
        }
      } else if (neighbors > 0) {
        // calcualte chance from available neighbors
        int direct = count_infect_neighbor_cell(rc, array, r, c);
        int vectored = count_infect_vector_cell(rc, array, r, c);

        int multiplier = (direct * 15) + (vectored * 8);

        if (multiplier >= 100) {
          return 'C';
        }
        int chance = rand() % (100 - multiplier);

        if (chance < 1) {
          return 'C';
        } else
          return 'A';
      }
    } else if (*cell == 'D') {
      int totalNeighbors = count_cells(rc, r, c);
      int deadNeighbors = count_dead_total_cell(rc, array, r, c);

      if (deadNeighbors >= totalNeighbors) {
        return 'B';
      }
    } else if (*cell == 'C') {
      // If cell is infected run chance to recover or die
      int chance = rand() % 500;
      // make cell recover
      if (chance >= 499) {
        return 'Y';
      } // make cell die
      else if (chance < 1) {
        return 'D';
      }
    } else if (*cell > 70 && *cell <= 89) {
      if (*cell > 70) {
        char newcell = *cell - 1;
        printf("%d\n", newcell);
        return newcell;
      }

    } else {
      return 'A';
    }
  }
  return *cell;
}
