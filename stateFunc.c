#include <stdio.h>
#include <stdlib.h>
#include "counters.h"
void *stateFunc(char *cell, int *rc, char *array[*rc][*rc], int *r, int *c){
    if (*cell != 'B') {
        if (*cell == 'A') {
	  int neighbors = count_infect_total_cell(rc, array, r, c);
            

            if (neighbors < 1) {
                //Generate rndom int between 0 - 1000
                int chance = rand() % 1000;
                if (chance < 1) {
                    *cell =  'C';
                }
            } else if (neighbors > 0) {
                //calcualte chance from available neighbors
	      int direct= count_infect_neighbor_cell(rc, array, r, c); 
                int vector= count_infect_vector_cell(rc, array, r, c);


                int multiplier = (direct * 15) + (vector * 8);
                int chance = rand() % (100 - chance);
                if (multiplier > 100) {
                    *cell = 'C';

                } else if (multiplier < 1) {
                    *cell = 'C';
                }
            } else if (*cell == 'D') {
	      int totalNeighbors = count_cells(rc, r, c);
              int deadNeighbors= count_dead_total_cell(rc, array, r, c);
                

                if (deadNeighbors >= totalNeighbors) {
                    *cell = 'B';
                }
            } else if (*cell == 'C') {
                int chance = rand() % 100;

                if (chance >= 50) {
                    *cell = 'Y';
                } else if (chance < 50) {
                    *cell = 'D';
                }
            } else if (*cell >= 70 || *cell <= 89) {
                if (*cell > 70)
                    *cell = *cell++;
            } else {
                *cell = 'A';
            }
        }
    }
}
