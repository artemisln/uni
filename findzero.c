#include <stdio.h>

int find_zero(double* list){
  int index=0;
  while(1){
    if(*list==0){
       printf("%d\n", index);
       return index;
     }
     index++; 
     list++;
  }
  printf("-1\n");
  return -1;
}

int main(){
    double list[] = {50, 4.3, 76, 0, 2};
    find_zero(list);
    return 0;
}