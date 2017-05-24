#include <stdio.h>

typedef struct{
  int key;
}record;

typedef unsigned short index;

int main(){
  record a[] = {44,55,12,42,94,18,6,67};
  index i,j,k;
  record x;

  for(i = 0; i < 8; ++i){
    k = i;
    x = a[i];
    for(j = i+1; j <= 8; ++j){
      if(a[j].key < x.key){
	k = j;
	x = a[j];
      }
    }
    a[k] = a[i];
    a[i] = x;
    }
  for(i = 0; i < 8; ++i){
    printf("%d ", a[i].key);
  }
  printf("\n");
}
