#include <stdlib.h>
#include <stdio.h>
//int* getInput(int arr_size);
int  connectivityCheck(int a, int b);
void checkRoad();
int main(){
	int queries = 0;
	scanf("%d",&queries);
	while(queries!=0 && queries <= 1000){
			checkRoad();
			queries--;
	}
	return 0;
}

void checkRoad(){
	int a , b;
	scanf("%d%d",&a,&b);
	if(connectivityCheck(a,b)){
		printf("\nYES");
	}else if(((a+2)==b) || ((b+2)==a)) {
		printf("\nYES");
	}else{
		printf("\nNO");
	}
}
int connectivityCheck(int a, int b){
	int i = 0,flag = 0,big = 0,small = 0;
	small = a > b?b:a;
	big = a > b?a:b;
	i = (small-1)/2;
	if((2*i)+2 == big)
		flag = 1;
	return flag;
}