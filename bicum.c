#include <stdio.h>
#include <stdlib.h>
void stateFunc(cell*){
  char cellC = (char) cell;
  if(cell != 'B' ){
     if (cellC == 'A'){
    int neighbors;
    //run function to check neighbors

       if(neighors < 1){
        //Generate random int between 0 - 1000
        int chance = rand()%1000;
            if(chance  < 1){
	       *cell = 'C';
            }
       }

    
     else if(neighbors > 0){
     //calcualte chance from available neighbors
     int direct; //pull from function
     int vector;
    
    
     int multiplier == (direct * 15) + (vector * 8);
     int chance = rand() % (100 - chance);
        if (multiplier > 100){
           *cell  = 'C';
      
        }else if(likelyhood < 1){
        *cell  = 'C';
        }    
  }else if(cellC == 'D'){
    int totalNeighbors;
    int deadNeighbors;
    //grab number of dead and total  neighbors

    if(deadNeighbors >= totalNeighbors){
      *cell = 'B'; 
    }
  }else if(cell == 'C'){
       int chance = rand()%100;

       if(chance >= 50){
	 *cell = 'Y';
       }else if(chance < 50){
	 *cell = 'D';
       }     
  } else if(cell >= 70 || cell <=89){
       if(cell > 70)
	 *cell = cell--;
     } else{
       *cell = 'A';
     }
      
 }
     return void;
}


