#include <stdio.h>
#include <stdlib.h>
int row = 10;
int col = 10;
int count_infect_total_cell(char a[row][col], int r, int c){
    int i, j, count=0;
    for(i=r-1; i<=r+1; i++){
        for(j=c-1;j<=c+1;j++){
            if((i==r && j==c) || (i<0 || j<0) || (i>=row || j>=col)){
                continue;
            }
            if(a[i][j]=='C'){//replace with infect char
                count++;
            }
        }
    }

    return count;
}

//returns the count of infected vector
int count_infect_vector_cell(char a[row][col], int r, int c){
    int i, j, count=0;
    for(i=r-1; i<=r+1; i++){
        for(j=c-1;j<=c+1;j++){
            if((i==r && j==c) || (i<0 || j<0) || (i>=row || j>=col) || i == 0  || j == 0){
                continue;
            }
            if(a[i][j]=='C'){//replace with Infect char
                count++;
            }
        }
    }
    return count;
}


//returns the count of infected neighbors
int count_infect_neighbor_cell(char a[row][col], int r, int c){
    int i, j, count=0;
    for(i=r-1; i<=r+1; i++){
        for(j=c-1;j<=c+1;j++){
            if((i==r && j==c) || (i<0 || j<0) || (i>=row || j>=col) || (i == -1 && j == -1) || (i == 1 && j == -1) || (i == -1 && j ==1) || (i == 1 && j==1)){
                continue;
            }
            if(a[i][j]=='C') {//replace with infect char

                count++;
            }
        }
    }
    return count;
}
// counts dead cells, used for cell removal
int count_dead_total_cell(char a[row][col], int r, int c){
    int i, j, count=0;
    for(i=r-1; i<=r+1; i++){
        for(j=c-1;j<=c+1;j++){
            if((i==r && j==c) || (i<0 || j<0) || (i>=row || j>=col)){
                continue;
            }
            if(a[i][j]=='D'){//replace with dead char
                count++;
            }
        }
    }
    return count;
}

int count_cells(char a[row][col], int r, int c){
    int i, j, count=0;
    for(i=r-1; i<=r+1; i++){
        for(j=c-1;j<=c+1;j++){
            if((i==r && j==c) || (i<0 || j<0) || (i>=row || j>=col)){
                continue;
            }
            else{//replace with dead char
                count++;
            }
        }
    }
    printf("%d \n", count);
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

