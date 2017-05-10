#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long int lint;
//Method_Definitions
void getScrOp();
void markVisited(char *a);
int subcheck(char *a);
void check();
void getStr();
lint getCases();

char arr[100000];
int main(){
  lint cases = getCases();
  //scanf("%lld",&cases);
  while(cases > 0){
    getStr();
    cases--;
  }
  return 0;
}
lint getCases(){
  int c;
  lint sum = 0;
  c = getchar();
  while(c > 47 && c < 59){
      sum = sum*10+ (c - '0');
      c = getchar();
  }
  return sum;
}
void getStr(){
  // int c;
  // lint sum = 0;
  // c = getchar();
  // while((c > 64 && c < 91) /*|| (c > 97 && c < 123))*/){
  //     arr[sum++] = c;
  //     c = getchar();
  // }
  // // while(fgets(arr,100000,stdin) != NULL && arr[sum] !='\n'){
  // //   sum++;
  // // }
  // arr[sum++] = '\0';
  scanf("%s",&arr);
  check();
}
// void getScrOp(){
// 	char* temp = NULL;
// 	int i = 0,c = 0, buff = 1;
// 	arr = (char*)malloc(buff);
// 	while((c = getchar()) && (c != EOF || c != 13)){
//     if(c != '\n'){
//       arr[i++] = c - '0';
//       arr = (char*)realloc(arr,(strlen(arr))+2);
// 				if(arr == NULL)
// 					printf("Problem in reallocating\n" );
// 		      }
//     }
//     arr[i++] = '\0';
// 	check();
// }
void check(){
  char *t = strchr(arr,'s');
  if(t!= NULL && strlen(t)>1)
    printf("\nno\n");
  else{
    char *t2 = NULL;
    if(arr!= NULL && arr[0] == 'e'){
        t2 = strstr(arr,"c");
        if(t2!= NULL && strlen(t2) > 0)
          printf("\nno\n");
        else
          printf("\nyes\n");
      }else{
      if(subcheck(arr))
        printf("\nyes\n");
      else
        printf("\nno\n");
      }
  }
}
int subcheck(char *a){
  if(a!=NULL){
    int sum = 0,i = 0,prev = 0,l = 0,f = 0;
    l = strlen(a);
    char *b = strchr(a,'e');
    if(l > 1 && b != NULL && strlen(b)>0)
    for(i = 0;i < l && a[i]!= 's';i++){
      //if(a[i] != p){
        if(a[i] == 'c' && prev != 1){
          sum += 1;
          prev = 1;
          //p = 'C';
        }else if(a[i] == 'e' && prev != -1){
          sum += -1;
          prev = -1;
        //  p = 'E';
      }else if((prev == -1 || prev == 1) && (a[i] == 'e' || a[i] == 'c')){
          f = 1;
          break;
        }
    //  }
    }
    if(f == 1)
      return 0;
    else{
      if(sum == 0 || abs(sum) == l)
        return 1;
      else
        return 0;
    }
  }
}
