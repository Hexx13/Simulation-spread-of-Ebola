#include <stdio.h>
#include <stdlib.h>

void test(char* a){
  if(*a == 'b'){
    *a = 'a';
  }
}

int main(){
  char nice = 'b';

  test(&nice);

  return 0;
}
