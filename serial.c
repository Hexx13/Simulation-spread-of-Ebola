#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//change row and column value to set the canvas size
int row = 10;
int col = 10;
int rc = 10;
char *populate(int *row, int *col, char a[*row][*col]);
void transCell(int *rc,char a[*rc][*rc], char b[*rc][*rc], int startRow, int startCol, int endRow, int endCol);

//creates row boundary
int row_line() {
    printf("\n");
    for (int i = 0; i < col; i++) { printf(" -----"); }
    printf("\n");
}


int main() {
    char a[rc][rc], b[row][col];
    int i, j;

    //generate matrix canvas with random values (live and dead cells)
    populate(&row,&col,a);

    //print array matrix
    printf("Initial Stage:");
    row_line();
    for (i = 0; i < row; i++) {
        printf(":");
        for (j = 0; j < col; j++) {
            printf("  %c  :", a[i][j]);
        }
        row_line();
    }

    //next canvas values based on live neighbour count
    for (int gen = 1; gen < 5000; gen++) {
        transCell(&rc, a, b, 0,0 ,row, col);

        //print next generation
        printf("\nNext Generation:");
        row_line(row);
        for (i = 0; i < row; i++) {

            printf(":");
            for (j = 0; j < col; j++) {
                printf("  %c  :", b[i][j]);
            }
            row_line(row);
        }
    }
    return 0;
}
