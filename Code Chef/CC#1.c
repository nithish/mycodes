/*Ref : https://www.codechef.com/APRIL17/problems/SIMDISH*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check(char a[][13],char b[][13]);
void input();

int main(){
  short cases = 0,i = 0;
  scanf("%hd",&cases);
  for(i = 0;i<cases;i++) {
    input();
  }
  return 0;
}

void input(){
  char a[4][13],b[4][13];
  scanf("%10s %10s %10s %10s",&a[0],&a[1],&a[2],&a[3]);
  scanf("%10s %10s %10s %10s",&b[0],&b[1],&b[2],&b[3]);
  check(a,b);
}

void check(char a[][13],char b[][13]){
  short i = 0,j = 0,k = 0;
  for(i = 0;i < 4;i++){
    for(j = 0;j < 4;j++){
     //printf("\n%s - %s: %d",a[i],b[j],strcmp(a[i],b[j]));
      if(strcmp(a[i],b[j]) == 0){
        k++;
      }
    }
  }
  if(k >= 2)
    printf("\nsimilar\n");
  else
    printf("\ndissimilar\n");
}
