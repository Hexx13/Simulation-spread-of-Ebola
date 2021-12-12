#include <stdio.h>
#include <stdlib.h>
#include "counters.h"

char stateFunc(char *cell, int *rc, char array[*rc][*rc], int *r, int *c) {
    if (*cell != 'B') {
        if (*cell == 'A') {//if cell healty
            int neighbors = count_infect_total_cell(rc, array, r, c);


            if (neighbors < 1) {// if there is no infected neighbors
                //Generate rndom int between 0 - 1000
                int chance = rand() % 1000;
                if (chance < 100) {
                    return 'C';
                }
            } else if (neighbors > 0) {// if there is infected neighbors
                //calcualte chance from available neighbors
                int direct = count_infect_neighbor_cell(rc, array, r, c);
                int vectored = count_infect_vector_cell(rc, array, r, c);
               
                //calculate percent chance of infection based on number of neighbors
                int multiplier = (direct * 15) + (vectored * 8);
                //if infection percentage is more or equal to 100 infect
                if (multiplier >= 100) {
                    return 'C';

                }
                //run random chance to infect based on infection percentage
                int chance = rand() % (100 - multiplier);
                //if number is less than 1 infect
                if (chance < 1) {
                    return 'C';
                } else return *cell;
            }
        }else if (*cell == 'D') {
            int totalNeighbors = count_cells(rc, r, c);
            int deadNeighbors = count_dead_total_cell(rc, array, r, c);


            if (deadNeighbors >= totalNeighbors) {
                return 'B';
            }
        } else if (*cell == 'C') {
            //If cell is infected run chance to recover or die
            int chance = rand() % 100;
            //make cell recover
            if (chance >= 50) {
                return 'Y';
            } // make cell die
            else if (chance < 50) {
                return 'D';
            }
        } else if (*cell > 70 && *cell <= 89) {
	  if (*cell > 70){
	    	char newcell = *cell -1;
		printf("%d\n",newcell );
                return newcell;
	  }

        } else if(*cell == 'F'){
            return 'A';
        }
        
    }
    return *cell;
}
