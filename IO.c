#include <stdio.h>
#include <stdlib.h>

void IOWrite(int rc, char a[rc][rc]){
    FILE *text;
    text=fopen( "text.txt", "a" );
    fwrite(a,rc, sizeof(*a), text);
    fprintf(text, ".");
    fclose(text);
}
