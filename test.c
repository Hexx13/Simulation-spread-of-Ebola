#include <stdio.h>
#include <stdlib.h>
#include "counters.h"



int main(){
    int i, j;
    int r = 0;
    int c = 0;
    int rc= 10;
    char a [r][c];
    for(i=0; i<r; i++){
        for(j=0;j<c;j++){
            a[i][j] = 'A';
        }
    }

    //printf("%d \n", count_cells(&rc, &r, &c));
    
    //l
  return 0;
}
