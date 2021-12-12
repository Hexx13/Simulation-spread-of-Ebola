#include <stdio.h>
#include <stdlib.h>

void IoWrite(int *rc, char *a[*rc][*rc]){
    FILE *text;
    text=fopen( "text.txt", "w" );
    fwrite(a,1, sizeof(*a), text);
    fclose(text);
}
/*
code from test branch
---------------------------------
 #include <stdio.h>
#include <stdlib.h>

void IoWrite(int *rc, char a[*rc][*rc]){
    FILE *text;
    text=fopen( "text.txt", "a" );
    fwrite(a,*rc, sizeof(a), text);
    fclose(text);
}
 ---------------------------------
*/