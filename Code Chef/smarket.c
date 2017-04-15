#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long int lint;
lint* getSubArray(lint *str,lint from,lint to);
void getInput();
lint* getScrOp(lint);
void compute(lint *str,lint **questions,lint);
void find(lint *sub,lint cnt,lint size);
lint* getQues();

int main(){
  short cases = 0;
  scanf("%hd",&cases);
  while (cases > 0) {
    getInput();
    cases--;
  }

  return 0;
}
void getInput(){
  lint *str = NULL;lint **questions = NULL;
  lint stock = 0,ques = 0, i = 0;
  scanf("%lld %lld",&stock,&ques);
  str = getScrOp(stock);
  questions = malloc(ques *sizeof(lint));
  while(i < ques){
    questions[i] = getQues();
    //printf("\ni-->%lld\n",i);
    i++;
  }

  compute(str,questions,ques);
//printf("#0\n" );
  free(questions);
  free(str);
}
lint* getQues(){
  lint a = 0,b = 0,c = 0;
  lint *t = NULL;
  t = malloc(3*sizeof(lint));
  //printf("#-1\n" );
  scanf("%lld %lld %lld",&a,&b,&c);
  t[0] = a;
  t[1] = b;
  t[2] = c;
  //printf("%lld %lld %lld",t[0],t[1],t[2]);
  return t;
}
lint* getScrOp(lint stock){
  lint i = 0;
  lint* str = NULL;
    str = (lint*)malloc(stock*sizeof(lint));
    while( i < stock && (scanf(" %lld",&str[i])==1)) {
        i++;
		}
  return str;
}
void compute(lint *str,lint **questions,lint ques){
    lint *sub = NULL, i = 0;
    while(i < ques){
      sub = getSubArray(str,questions[i][0],questions[i][1]);
      //printf("#3\n" );
      find(sub,questions[i][2],((questions[i][1]-questions[i][0])+1));
      //printf("i-->%lld\n",i);
      i++;
    }
}
void find(lint *sub,lint cnt,lint size){
  lint i = 0, j = 0,a = 0,b = 0,c = 0,d = -1;
  //printf("#4\n" );
  for(;i<size;i++){
    a = sub[i];
    b = 0;
    if(d != a){
    for(;j<size;j++){
      if(a == sub[j]){
        b++;
      }
      if(a != sub[j])
        break;
      }
    }
    if(b >= cnt)
      c++;
    d = a;
  }
  printf("\n%lld\n",c);

}
lint* getSubArray(lint *str,lint from,lint to){
//printf("#5.1\n" );
  lint i = 0,j = 0,k = ((to - from)+1);
  lint* sub = malloc(k*sizeof(lint));
  while(j < k){
    //printf("\nj=%lld,k=%lld",j,k);
    if(i >= from-1 && i < to){
        sub[j++] = str[i];
      }
      i++;
  }
  //printf("#5.2\n" );
  //printf("#2\n" );
  return sub;
}
