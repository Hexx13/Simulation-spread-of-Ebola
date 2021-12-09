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
int count_infect_total_cell(int a[row][col], int r, int c){
    int i, j, count=0;
    for(i=r-1; i<=r+1; i++){
        for(j=c-1;j<=c+1;j++){
            if((i==r && j==c) || (i<0 || j<0) || (i>=row || j>=col)){
                continue;
            }
            if(a[i][j]==1){//replace with infect char
                count++;
            }
        }
    }

    return count;
}

//returns the count of infected vector
int count_infect_vector_cell(int a[row][col], int r, int c){
    int i, j, count=0;
    for(i=r-1; i<=r+1; i++){
        for(j=c-1;j<=c+1;j++){
            if((i==r && j==c) || (i<0 || j<0) || (i>=row || j>=col) || i == 0  || j == 0){
                continue;
            }
            if(a[i][j]==1){//replace with Infect char
                count++;
            }
        }
    }
    printf("%d\n", count);
    return count;
}


//returns the count of infected neighbors
int count_infect_neighbor_cell(int a[row][col], int r, int c){
    int i, j, count=0;
    for(i=r-1; i<=r+1; i++){
        for(j=c-1;j<=c+1;j++){
            if((i==r && j==c) || (i<0 || j<0) || (i>=row || j>=col) || (i == -1 && j == -1) || (i == 1 && j == -1) || (i == -1 && j ==1) || (i == 1 && j==1)){
                continue;
            }
            if(a[i][j]==1) {//replace with infect char
                printf("vectored \n");
                count++;
            }
        }
    }
    printf("%d\n", count);
    return count;
}

int count_dead_total_cell(int a[row][col], int r, int c){
    int i, j, count=0;
    for(i=r-1; i<=r+1; i++){
        for(j=c-1;j<=c+1;j++){
            if((i==r && j==c) || (i<0 || j<0) || (i>=row || j>=col)){
                continue;
            }
            if(a[i][j]==0){//replace with dead char
                count++;
            }
        }
    }
    return count;
}

//int count_recovered_neighbour_cell(int a[row][col], int r, int c){
//    int i, j, count=0;
//    for(i=r-1; i<=r+1; i++){
//        for(j=c-1;j<=c+1;j++){
//            if((i==r && j==c) || (i<0 || j<0) || (i>=row || j>=col)){
//                continue;
//            }
//            if(a[i][j]==3){
//                count++;
//            }
//        }
//    }
//    return count;
//}


 
int main(){
       int a[row][col], b[row][col];
    int i,j;
    int neighbour_live_cell;
    int neighbour_infect_cell;
    int neighbour_recovered_cell;
    int vector_infect_cell;
    int total_infect_cell;
      printf("0 = dead\n");
    printf("1 = alive\n");
    printf("2 = infected\n");
      printf("3 = recovered\n");

 
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
    for(int gen = 1; gen<10; gen++){
    for(i=0; i<row; i++){
        for(j=0;j<col;j++){
            total_infect_cell = count_infect_total_cell(a,i,j);
            vector_infect_cell = count_infect_vector_cell(a,i,j);
            neighbour_infect_cell = count_infect_neighbor_cell(a, i, j);
            neighbour_recovered_cell = count_recovered_neighbour_cell(a, i, j);
            if(a[i][j]==1 && (total_infect_cell==2 || total_infect_cell==3)){
                b[i][j]=1;
                a[i][j]=b[i][j];
            }
 
            else if(a[i][j]==0 && total_infect_cell==3){
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
