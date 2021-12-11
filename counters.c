#include <stdio.h>
#include <stdlib.h>


int count_infect_total_cell(int *rc, char a[*rc][*rc], int *r, int *c){
    int i, j, count=0;
    for(i=*r-1; i<=*r+1; i++){
        for(j=*c-1;j<=*c+1;j++){
            if((i==*r && j==*c) || (i<0 || j<0) || (i>=*rc || j>=*rc)){
                continue;
            }
            if(a[i][j]=='C'){
                count++;
            }
        }
    }

    return count;
}

//returns the count of infected vector
int count_infect_vector_cell(int *rc  ,char a[*rc][*rc], int *r, int *c){
    int i, j, count=0;
    for(i=*r-1; i<=*r+1; i++){
        for(j=*c-1;j<=*c+1;j++){
            if((i==*r && j==*c) || (i<0 || j<0) || (i>=*rc || j>=*rc) || i == 0  || j == 0){
                continue;
            }
            if(a[i][j]=='C'){
                count++;
            }
        }
    }
    return count;
}


//returns the count of infected neighbors
int count_infect_neighbor_cell(int *rc  ,char a[*rc][*rc], int *r, int *c){
    int i, j, count=0;
    for(i=*r-1; i<=*r+1; i++){
        for(j=*c-1;j<=*c+1;j++){
            if((i==*r && j==*c) || (i<0 || j<0) || (i>=*rc || j>=*rc) || (i == -1 && j == -1) || (i == 1 && j == -1) || (i == -1 && j ==1) || (i == 1 && j==1)){
                continue;
            }
            if(a[i][j]=='C') {

                count++;
            }
        }
    }
    return count;
}
// counts dead cells, used for cell removal
int count_dead_total_cell(int *rc  ,char a[*rc][*rc], int *r, int *c){
    int i, j, count=0;
    for(i=*r-1; i<=*r+1; i++){
        for(j=*c-1;j<=*c+1;j++){
            if((i==*r && j==*c) || (i<0 || j<0) || (i>=*rc || j>=*rc)){
                continue;
            }
            if(a[i][j]=='D'|| a[i][j]=='B'){
                count++;
            }
        }
    }
    return count;
}

int count_cells(int *rc, int *r, int *c){
    int i, j, count=0;
    for(i=*r-1; i<=*r+1; i++){
        for(j=*c-1;j<=*c+1;j++){
            if((i==*r && j==*c) || (i<0 || j<0) || (i>=*rc || j>=*rc)){
                continue;
            }
            else{
                count++;
            }
        }
    }

    return count;
}

//int count_recovered_neighbour_cell(int a[rc][rc], int r, int c){
//    int i, j, count=0;
//    for(i=r-1; i<=r+1; i++){
//        for(j=c-1;j<=c+1;j++){
//            if((i==r && j==c) || (i<0 || j<0) || (i>=rc || j>=rc)){
//                continue;
//            }
//            if(a[i][j]==3){
//                count++;
//            }
//        }
//    }
//    return count;
//}
