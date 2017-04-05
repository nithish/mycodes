#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int maxOf(int m, int n);
int maxOf(int m, int n){
  return m>n ? m : n;
}
int main(){
  char *x = NULL,*y = NULL;
  int  **c;
  int m = 0,n = 0,max = 0,i = 0,j = 0;
  size_t sz = 5;
  getline(&x,&sz,stdin);
  getline(&y,&sz,stdin);
  m = strlen(x);
  n = strlen(y);
  c = (int **) malloc(sizeof(int *) * m);
  for (i = 0; i < m; i++) {
      c[i] = (int *) malloc(sizeof(int) * n);
  }
  for(i = 0;i<m;i++)
    for( j = 0;j<n;j++)
      c[i][j] = -1;
  for( i = 0;i < m; i++)
   {c[i][0] = 0;}
  for( i = 0;i < n; i++)
    {c[0][i] = 0;}
  for( i = 1; i<m; i++){
    for( j = 1; j<n; j++){
        //printf("X :%c y: %c\n",x[i-1],y[j-1]);
        if(x[i-1] == y[j-1]){
          c[i][j] = 1 + c[i-1][j-1];
        }else if(c[i-1][j]>=c[i][j-1])
          c[i][j] = c[i-1][j];
        else
          c[i][j] = c[i][j-1];
      }
  }
    for( i = 1; i<m; i++){
      for( j = 1; j<n; j++){
        //printf(" %d",c[i][j]);
        if(max < c[i][j])
          max = c[i][j];
      }
    //  printf("\n");
    }
    printf("\n%d",max);
    free(c);
    free(x);
    free(y);
  return 0;
}
