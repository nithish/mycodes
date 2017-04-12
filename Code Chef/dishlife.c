#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long int lint;

void getInput();
lint* convertToInt(char *str);
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
  //printf("%lld\n",islands);
  arr = malloc(islands*sizeof(lint));
  char* str = NULL;
  lint buff = ing+2;int a = 0;
	str = (char*)malloc(buff);
  //printf("-->%lld %lld",islands, ing);
  while(j < islands){
    lint i = 0;
    printf("$%lld\n",j);
    while((scanf(" %c",&str[i])==1) && i < ing) {
        if(i == 0){
          ing = ctoint(str[i]);
        }
        i++;
		}
		str[i+1] = '\0';
  	arr[j] = malloc(sizeof(buff));
    arr[j] = convertToInt(str);
    j++;
  }
  processInput(arr,islands,temp);
  //free(arr);
}
lint* convertToInt(char *str){
  lint *a = NULL;
  lint len = strlen(str);
  a = malloc(len * sizeof(lint));
  lint i = 0;
  while(i < len){
    if(str[i] != ' ' && str[i] != '\n')
      a[i] = str[i] - '0';
    i++;
  }
  return a;
}
void processInput(lint **arr,lint islands,lint ing){
  lint *visited = NULL,count = 0, i = 0,j = 0;
  visited = malloc(ing*sizeof(lint));
  int k = 0;
  if(!indcheck(arr,islands,ing)){
    while(k < ing){
      visited[k] = -1;
      k++;
    }
  while(i < islands){

    lint t = arr[i][0];
    lint count1 = 0;
    //int * sub = malloc(ing*sizeof(lint));
    for(j = 1;j <= t; j++){
      if(arr[i][j] <= ing && !contains(visited,arr[i][j],ing)){
        count++;
        add(visited,arr[i][j],ing);
        //printf("%lld\n",count1);
      }
    }

    if(count == ing)
      break;
    i++;
  }
  //printf("\n%lld:%lld %lld:%lld\n",i,islands,count,ing);
  if(i+1 < islands && count == ing){
    printf("some\n");
  }else if((i+1 == islands || i == islands ) && count == ing)
    printf("all\n");
  else
    printf("sad\n");
    //free(visited);
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
  lint i = 0,j = 0,count = 0,f = 0,g = 0;
  while(i < islands){
    lint *v = malloc(ing * sizeof(lint));
    while(g < ing){
      v[g] = -1;
      g++;
    }
    lint k = arr[i][0];
    //printf("#%lld\n",v[0]);
    for(j = 1;j<=k;j++){
      if(!contains(v,arr[i][j],ing)){
        count++;
        add(v,arr[i][j],ing);
      }
    }

    if(count == ing){
      f = 1;
      printf("some\n");
      break;
    }
    count = 0;
    g = 0;
    free(v);
    i++;
  }
  return f;
}
