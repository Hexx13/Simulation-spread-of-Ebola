#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//change row and column value to set the canvas size
int row;
int col;
int rc;
int time;
char *populate(int *row, int *col, char a[*row][*col]);
void transCell(int *rc,char a[*rc][*rc], char b[*rc][*rc], int startRow, int startCol, int endRow, int endCol);

int main(int argc, char *argv[]) {
    time = atoi(argv[1]);
    row = atoi(argv[2]);
    col = atoi(argv[2]);
    rc = atoi(argv[2]);
    char a[rc][rc], b[row][col];

    //populate cell dimension
    populate(&row,&col,a);


    //Iterate time
    for (int gen = 1; gen < time; gen++) {
        //iterate through cells and assign to future array
        transCell(&rc, a, b, 0,0 ,row, col);

        //dump here

        //assign present array as future array
        memcpy(a, b, sizeof(*a));
    }
    return 0;
}
