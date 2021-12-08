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

int count_infect_neighbour_cell(int a[row][col], int r, int c){
    int i, j, count=0;
    for(i=r-1; i<=r+1; i++){
        for(j=c-1;j<=c+1;j++){
            if((i==r && j==c) || (i<0 || j<0) || (i>=row || j>=col)){
                continue;
            }
            if(a[i][j]==2){
                count++;
            }
        }
    }
    return count;
}

int count_recovered_neighbour_cell(int a[row][col], int r, int c){
    int i, j, count=0;
    for(i=r-1; i<=r+1; i++){
        for(j=c-1;j<=c+1;j++){
            if((i==r && j==c) || (i<0 || j<0) || (i>=row || j>=col)){
                continue;
            }
            if(a[i][j]==3){
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
    int neighbour_infect_cell;
    int neighbour_recovered_cell;
      printf("0 = dead\n");
    printf("1 = alive\n");
    printf("2 = infected\n");
      printf("3 = recovered\n");

 
    //generate matrix canvas with random values (live and dead cells)
    for(i=0; i<row; i++){
        for(j=0;j<col;j++){
            a[i][j] = rand() % 4;
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
    for(int gen = 1; gen<10; gen++){
    for(i=0; i<row; i++){
        for(j=0;j<col;j++){
            neighbour_live_cell = count_live_neighbour_cell(a,i,j);
            neighbour_infect_cell = count_infect_neighbour_cell(a, i, j);
            neighbour_recovered_cell = count_recovered_neighbour_cell(a, i, j);
            if(a[i][j]==1 && (neighbour_live_cell==2 || neighbour_live_cell==3)){
                b[i][j]=1;
                a[i][j]=b[i][j];
            }
 
            else if(a[i][j]==0 && neighbour_live_cell==3){
                b[i][j]=1;
                a[i][j]=b[i][j];
            }
 
            else{
                b[i][j]=0;
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
            printf("  %d  :",b[i][j]);
        }
        row_line(row);
    }
    }
    return 0;
    
}
