#include <stdio.h>
#include "mersenne.h"

int main()
{
  int j;

  sgenrand(4357); /*any nonzero integer can be used as a seed*/
  for(j = 0; j < 1000; ++j){
    printf("%ld\n", genrand());
    if(j%8 == 7) printf("\n");
  }
  printf("\n");

  return 0;
}
