#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//change row and column value to set the canvas size
int row = 10;
int col = 10;
int rc = 10;

char stateFunc(char *cell, int *rc, char array[*rc][*rc], int *r, int *c);

//creates row boundary
int row_line(){
    printf("\n");
    for(int i=0; i<col; i++){printf(" -----");}
    printf("\n");
}
 

int main(){
       char a[rc][rc], b[row][col];
    int i,j;
      printf("D = dead\n");
    printf("A = alive\n");
    printf("C = infected\n");
      printf("Y = immune\n");

 
    //generate matrix canvas with random values (live and dead cells)
    for(i=0; i<row; i++){
        for(j=0;j<col;j++){
            //test code
            
           a[i][j] = 'A';

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
    for(int gen = 1; gen<5000; gen++){
    for(i=0; i<row; i++){
        for(j=0;j<col;j++){
	 	 b[i][j]= stateFunc(&a[i][j], &rc,a, &i, &j);
        }
    }
    memcpy(a,b, sizeof(a));
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
