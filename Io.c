//
// Created by jbust on 10/12/2021.
//
#include <stdio.h>
#include <stdlib.h>



void IoWrite(int rc, char a[rc][rc], int r, int c){
    FILE *text;
    text=fopen( "text.txt", "a" );
    for(int i=0; i<r; i++){
        for(int j=0;j<c;j++){
            fprintf(text,"%c \n",a[i][j]);
        }
    }

}

void IoDelete(){
    FILE *text;
    text=fopen( "text.txt", "w" );
    fclose(text);
}
