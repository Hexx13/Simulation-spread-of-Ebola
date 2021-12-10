#include <stdio.h>
#include <stdlib.h>

//change row and column value to set the canvas size
int row = 10;
int col = 10;
//creates row boundary
int row_line(){
    printf("\n");
    for(int i=0; i<col; i++){printf(" -----");}
    printf("\n");
}
 
//returns the count of infected vector and neighbors

 
int main(){
       char a[row][col], b[row][col];
    int i,j;
    int neighbour_live_cell;
    int neighbour_infect_cell;
    int neighbour_recovered_cell;
    int vector_infect_cell;
    int total_infect_cell;
    int total_dead_cell;
    int total_cell;
      printf("0 = dead\n");
    printf("1 = alive\n");
    printf("2 = infected\n");
      printf("3 = recovered\n");

 
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
            total_cell= count_cells(a,i,j);
            total_infect_cell = count_infect_total_cell(a,i,j);
            vector_infect_cell = count_infect_vector_cell(a,i,j);
            total_dead_cell = count_dead_total_cell(a,i,j);
            neighbour_infect_cell = count_infect_neighbor_cell(a, i, j);
            //neighbour_recovered_cell = count_recovered_neighbour_cell(a, i, j);
            if(a[i][j]=='C' && (total_infect_cell==2 || total_infect_cell==3)){
                b[i][j]='C';
                a[i][j]=b[i][j];
            }
 
            else if(a[i][j]=='A' && total_infect_cell==3){
                b[i][j]='C';
                a[i][j]=b[i][j];
            }
 
            else{
                b[i][j]='A';
                a[i][j]=b[i][j];
            }
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
