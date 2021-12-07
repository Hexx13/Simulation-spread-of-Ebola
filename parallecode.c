#include <stdio.h>
#include <stdlib.h>

//change row and column value to set the canvas size
int row = 5;
int col = 4;
//creates row boundary
int row_line(){
    printf("\n");
    for(int i=0; i<col; i++){printf(" -----");}
    printf("\n");
}
 
//returns the count of alive neighbours
int count_live_neighbour_cell(int a[row][col], int r, int c){
    int i, j, count=0;
    for(i=r-1; i<=r+1; i++){
        for(j=c-1;j<=c+1;j++){
            if((i==r && j==c) || (i<0 || j<0) || (i>=row || j>=col)){
                continue;
            }
            if(a[i][j]==1){
                count++;
            }
        }
    }
    return count;
}
 
int main(){
       int a[row][col], b[row][col];
    int i,j;
    int neighbour_live_cell;
 
    //generate matrix canvas with random values (live and dead cells)
    for(i=0; i<row; i++){
        for(j=0;j<col;j++){
            a[i][j] = rand() % 2;
        }
    }
     
    //print array matrix
    printf("Initial Stage:");
    row_line();
    for(i=0; i<row; i++){
        printf(":");
        for(j=0;j<col;j++){
            printf("  %d  :",a[i][j]);
        }
        row_line();
    }
 
    //next canvas values based on live neighbour count
    for(int fanny = 10; fanny<20; fanny++){
    for(i=0; i<row; i++){
        for(j=0;j<col;j++){
            neighbour_live_cell = count_live_neighbour_cell(a,i,j);
            if(a[i][j]==1 && (neighbour_live_cell==2 || neighbour_live_cell==3)){
                b[i][j]=1;
            }
 
            else if(a[i][j]==0 && neighbour_live_cell==3){
                b[i][j]=1;
            }
 
            else{
                b[i][j]=0;
            }
        }
    }
 
    //print next generation
    printf("\nNext Generation:");
     row_line(row);
    for(i=0; i<row; i++){
        printf(":");
        for(j=0;j<col;j++){
            printf("  %d  :",b[i][j]);
        }
        row_line(row);
    }
    }
    return 0;
    
}
