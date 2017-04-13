#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long int lint;

void getInput();
void compute(char *str);
char* getScrOp();
lint swap(char *str, lint count);
short check(char *str);


int main(){
  short cases = 0;
  scanf("%hd",&cases);
  cases = cases+1;
  while(cases> 0){
    getInput();
    cases--;
  }
  return 0;
}
void getInput(){
  char *str = NULL;
  str = getScrOp();
  compute(str);
}
void compute(char *str){
  lint count = 0;
  if(strlen(str) != 0){
    while(check(str)){
      count = swap(str,count);
    }
    printf("\n%lld\n",count);
  }
  free(str);
}
char* getScrOp(){
	char* temp = NULL; char* str = NULL;
	int i = 0,c = 0, buff = 1;
	str = (char*)malloc(buff);
	while((c = getchar()) != '\n' && (c != EOF || c != 13)){
      str[i++] = c;
      str = (char*)realloc(str,(strlen(str))+2);
				if(str == NULL)
					printf("Problem in reallocating\n" );
		}
    str[i++] = '\0';
	return str;
}
short check(char *str){
  short f = 0;
  lint len = strlen(str), i = 0;
  for(;i < len;i++){
    if(str[i] == '1' && str[i+1] == '0'){
      f = 1;
      break;
    }
  }
  //printf("-->%hd\n",f);
  return f;
}
lint swap(char *str,lint count){
  lint len = strlen(str), i = 0,j = 0;
  char temp;
  for(;i < len;i++){
      if(str[i] == '1' && str[i+1] == '0'){
        temp = str[i+1];
        str[i+1] = str[i];
        str[i] = temp;
        count++;
        if(str[i+2]!='0')
          break;
    }
  }
  return count+1;
}
