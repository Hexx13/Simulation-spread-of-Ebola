#include <stdio.h>
#include <stdlib.h>


//change row and column value to set the canvas size
int row = 10;
int col = 10;
int rc = 10;

void stateFunc(char *cell, int *rc, char *(*)array[*rc][*rc], int *r, int *c);

//creates row boundary
int row_line(){
    printf("\n");
    for(int i=0; i<col; i++){printf(" -----");}
    printf("\n");
}
 

int main(){
       char a[rc][rc], b[row][col];
    int i,j;
    int neighbour_live_cell;
    int neighbour_infect_cell;
    int neighbour_recovered_cell;
    int vector_infect_cell;
    int total_infect_cell;
    int total_dead_cell;
    int total_cell;
      printf("D = dead\n");
    printf("A = alive\n");
    printf("C = infected\n");
      printf("Y = immune\n");

 
    //generate matrix canvas with random values (live and dead cells)
    for(i=0; i<row; i++){
        for(j=0;j<col;j++){
            //test code
            int r = rand() % 100;
            if (r > 50){
                a[i][j] = 'C';
            }
            else{a[i][j]='A';}


           // a[i][j] = 'A'; gen All healthy matrix

        }
    }
     
    //print array matrix
    printf("Initial Stage:");
    row_line();
    for(i=0; i<row; i++){
        printf(":");
        for(j=0;j<col;j++){
            printf("  %c  :",a[i][j]);
        }
        row_line();
    }
 
    //next canvas values based on live neighbour count
    for(int gen = 1; gen<5; gen++){
    for(i=0; i<row; i++){
        for(j=0;j<col;j++){
	 	  stateFunc(&a[i][j], &rc,&a, &i, &j);
        }
    }

    //print next generation
    printf("\nNext Generation:");
     row_line(row);
    for(i=0; i<row; i++){
      
        printf(":");
        for(j=0;j<col;j++){
            printf("  %c  :",b[i][j]);
        }
        row_line(row);
    }
    }
    return 0;
    
}
