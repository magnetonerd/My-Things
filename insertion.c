#include <stdio.h>

typedef struct {
  int key;
}Record;

typedef unsigned short index;

int main()
{
  Record a[] = {44,55,12,42,94,18,6,67};
  index i,j,k;
  Record x;

  for(i = 2; i < 8; ++i){
    for(k = 0; k < 8; ++k) printf("%d ",a[k].key);
    printf("\n\n");
    x = a[i];
    a[0] = x;
    j = i - 1;
    while (x.key < a[j].key){
      a[j+1] = a[j];
      j = j - 1;
    }
    a[j+1] = x;
  }
  for(i = 0; i < 8; ++i){
    printf("%d ", a[i].key);
  }
  printf("\n");
}

  
