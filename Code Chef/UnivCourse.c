#include <stdlib.h>
#include <stdio.h>
typedef long long lint;
//Method_Definitions
void add(lint *p,lint cnt,lint req);
lint count(lint *p, lint cnt);
void find(lint cnt);
void getInput();
lint getCases();

lint *a = NULL;
int main(){
    lint c = getCases();
    while(c > 0){
      getInput();
      c--;
    }
    return 0;
  }
void getInput(){
    lint i = 0,cnt = getCases();
    a = malloc(cnt*sizeof(lint));
    while(i < cnt){
      a[i] = getCases();
      i++;
    }
    find(cnt);
  }
void find(lint cnt){
  lint max = cnt, i = 0,req = 0;
  lint *pre = malloc(cnt*sizeof(lint));
  for(i = 0;i<cnt;i++)
    pre[i] = -1;
  for(i = 0;i < cnt; i++){
    lint x = a[i];
    if(x-count(pre,cnt)>0){
      max -= 1;
      add(pre,cnt,req);
      req = x;
    }
  }
  printf("\n%lld\n",max);
}
lint count(lint *p, lint cnt){
  lint i =0, c = 0;
  for(i = 0;i<cnt;i++){
    if(p[i] != -1)
      c++;
  }
  return c;
}
void add(lint *p,lint cnt,lint req){
  lint i = 0;
  for(i = 0;i<cnt;i++){
    if(p[i] == -1){
      p[i] = req;
      break;
    }
  }
}
lint getCases(){
    int c;
    lint sum = 0;
    c = getchar();
    while(c > 47 && c < 59){
        sum = sum*10+ (c - '0');
        c = getchar();
    }
    return  sum;
  }
