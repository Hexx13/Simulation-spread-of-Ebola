#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//change row and column value to set the canvas size
int row = 10;
int col = 10;
int rc = 10;
char *populate(int *row, int *col, char a[*row][*col]);
void transCell(int *rc,char a[*rc][*rc], char b[*rc][*rc], int startRow, int startCol, int endRow, int endCol);

int main() {
    char a[rc][rc], b[row][col];

    //generate matrix canvas with random values (live and dead cells)
    populate(&row,&col,a);


    //next canvas values based on live neighbour count
    for (int gen = 1; gen < 5000; gen++) {
        transCell(&rc, a, b, 0,0 ,row, col);
    }
    return 0;
}
