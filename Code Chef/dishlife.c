#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long int lint;

void getInput();
lint* convertToInt(lint *str,lint buff);
void getLine(lint **arr,short i);
lint ctoint(char a);
void processInput(lint **arr, lint islands,lint ing);
int contains(lint *v,lint i,lint size);
void add(lint *v,lint i,lint size);
int indcheck(lint **arr,lint islands,lint ing);

int main(){
  short cases = 0;
  scanf("%hd",&cases);
  while(cases > 0){
    getInput();
    cases--;
  }
  return 0;
}
void getInput(){
  lint islands = 0 , ing = 0,temp = 0;
  lint **arr  = NULL,j = 0;
  scanf("%lld %lld",&islands,&ing);
  temp = ing;
  arr = malloc(islands*sizeof(lint));
  lint* str = NULL;
  lint buff = temp;int a = 0;
  while(j < islands){
    str = (lint*)malloc(buff*sizeof(lint));
    lint i = 0;
    while((scanf(" %lld",&str[i])==1) && i < ing) {
        if(i == 0){
          ing = (str[i]);
        }
        i++;
		}
  	arr[j] = (lint*)malloc(buff*sizeof(lint));
    arr[j] = convertToInt(str,buff);
    j++;
  }
  processInput(arr,islands,temp);
}
lint* convertToInt(lint *str,lint buff){
  lint *a = NULL;
  a = malloc(buff * sizeof(lint));
  lint i = 0;
  while(i < buff){
    a[i] = str[i];
    i++;
  }
  return a;
}
void processInput(lint **arr,lint islands,lint ing){
  if(!indcheck(arr,islands,ing)){
    lint *visited = NULL,count = 0, i = 0,j = 0;
    visited = malloc(ing*sizeof(lint));
    int k = 0;
    //printf("Inseid\n" );
    while(k < ing){
      visited[k] = -1;
      k++;
    }
  while(i < islands){
    lint t = arr[i][0];
    lint count1 = 0;
    for(j = 1;j <= t; j++){
      if(arr[i][j] <= ing && !contains(visited,arr[i][j],ing)){
        count++;
        add(visited,arr[i][j],ing);
      }
    }
    if(count == ing)
      break;
    i++;
  }
  if(i+1 < islands && count == ing){
    printf("some\n");
  }else if((i+1 == islands || i == islands ) && count == ing)
    printf("all\n");
  else
    printf("sad\n");
  }
}
lint ctoint(char a){
  return a - '0';
}
int contains(lint *v,lint i,lint size){
  lint h = 0;short f = 0;
  for(h = 0;h < size;h++){
    if(v[h] == i)
          f = 1;
    }
  return f;
}
void add(lint *v,lint i,lint size){
  lint h = 0;
  while(v[h] > 0){
    h++;
  }
  v[h] = i;
}
int indcheck(lint **arr,lint islands,lint ing){
  lint i = 0,j = 0,count = 0,f = 0,g = 0,k = 0;
  while(i < islands){
    lint *v = malloc(ing * sizeof(lint));
    while(g < ing){
      v[g] = -1;
      g++;
    }
    k = arr[i][0];
    for(j = 1;j<=k;j++){
      if(!contains(v,arr[i][j],ing)){
        count++;
        add(v,arr[i][j],ing);
      }
    }

    if(count == ing){
      f = 1;
      if( i+1 == islands)
        printf("all\n");
      else if(i+1 < islands)
        printf("some\n");
      break;
    }
    count = 0;
    g = 0;
    i++;
  }
  return f;
}
