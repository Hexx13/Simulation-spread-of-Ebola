#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *populate(int *row, int *col, char a[*row][*col]){
    int i;
    int j;
    for (i = 0; i < row; i++) {
        printf(":");
        for (j = 0; j < col; j++) {
            printf("  %c  :", a[i][j]);
        }
    }
    return a;
}

