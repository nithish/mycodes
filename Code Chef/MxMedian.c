#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include <string.h>
typedef long long int lint;
typedef struct res{
  lint *arr;
  lint med;
} Result;
//Method_Definitions
void sort(lint *b,lint k);
void storePermutations(lint *a, lint m, lint *c,lint n);
void computeMedian(lint *a, lint k, lint *c, lint n);
lint max(lint x, lint y);
void computeSubArray(lint *a,lint n);
void permute(lint *a, lint size,lint);
void swp(lint *a,lint i,lint j);
lint getCases();
void getInput();
lint z = -99;
lint *temp = NULL;
int main(){
  lint cases = getCases();
  while(cases > 0){
    getInput();
    cases--;
  }
  return 0;
}
void getInput(){
  lint n = getCases(), i = 0, j = 2*n;
  lint *a = malloc((j)*sizeof(lint));
  z = -99;
  while(i < j){
    a[i] = getCases();
    i++;
  }
  permute(a,j,j);
  printf("\n%lld\n",z);
  for(i = 0;i < j;i++){
    printf("%lld ",temp[i]);
  }
  printf("\n");
}
void permute(lint *a, lint size,lint n){
  if (size == 1){
        computeSubArray(a, n);
        return;
    }
    lint i =0;
    for (i =0; i<size; i++){
        permute(a,size-1,n);
        if (size%2==1)
            swp(a,0,size-1);
        else
            swp(a,i,size-1);
    }
}
void computeSubArray(lint *a,lint n){
  lint i = 0, h = 1,j= 0,k = (n/2);
  lint *b = malloc((k)*sizeof(lint));
  while(h<n){
      b[j++] = max(a[i],a[h]);
      //printf("\n max %lld",max(a[i],a[h]));
      i += 2;
      h += 2;
  }
  sort(b,k);
  //  for(i = 0;i < k;i++){
  //    printf("--> %lld ",b[i]);
  //       }
  //     printf("\n");

  computeMedian(b,k,a,n);
}
void sort(lint *b,lint k){
  lint temp = 0, i =0 ,j = 0;
  for(i = 0;i < k;i++)
    for(j = i+1;j < k;j++){
      if(b[i] > b[j]){
        temp = b[j];
        b[j] = b[i];
        b[i] = temp;
      }
    }
}
void computeMedian(lint *a, lint k, lint *c, lint n){
  lint x = 0, m =0;
  x = (k+1)/2;
  if(k == 1)
    m = a[0];
  else if(k%2==0){
    lint g = floor(x);
    lint h = ceil(x);
    m = a[((g+h)/2)-1];
  }else{
    m = a[x-1];
  }
  //printf("\nMed %lld\n",m);
  storePermutations(a,m,c,n);
}
void storePermutations(lint *a, lint m, lint *c,lint n){

  if(z == -99){
    z = m;
    temp = c;
  }else if(m > z){
    z = m;
    temp = NULL;
    temp = malloc(n*sizeof(lint));
    lint i = 0;
    for(i = 0;i< n;i++)
      temp[i] = c[i];
  }

  //printf("\n z %lld\n", z);
  //exit;
}
lint max(lint x, lint y){
  return x>y?x:y;
}
void swp(lint *a,lint i,lint j){
  lint temp = a[i];
  a[i] = a[j];
  a[j] = temp;
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
