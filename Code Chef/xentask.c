#include <stdlib.h>
#include <stdio.h>

long long int* getInput(long long int arr_size);
void calcMinTime(long long int *x, long long int *y,long long int arr_size);
int main(){
	long long int cases = 0, arr_size = 0;
	long long int *x = NULL, *y = NULL;
	scanf("%lld",&cases);
	while(cases != 0 && cases <= 10){
			//printf("\n #tasks : ");
			scanf("%lld",&arr_size);
			//printf("\n x arr \n");
			x = getInput(arr_size);
			//printf("\n y arr \n");
			y = getInput(arr_size);
			calcMinTime(x,y,arr_size);
			cases--;
	}
	return 0;
}
long long int* getInput(long long int arr_size){
	long long int *input = NULL;
	int index = 0;
	input = (long long int*)malloc(arr_size*sizeof(long long int));
		while((scanf(" %lld",&input[index])==1) && index!= (arr_size-1)) {
        index++;
		}
		return input;
}
void calcMinTime(long long int *x,long long int *y,long long int arr_size){
	long long int sum = 0,temp_sum = 0,i = 0,j = 0,index = 2;
	long long int *tmp = NULL;
	while(index > 0){
		temp_sum = 0;i = 0;j = arr_size;
		while(j > 0){
				if(i%2 == 0){
					temp_sum += x[i];
				}else{
					temp_sum += y[i];
				}
				i++;
				j--;
		}
		index--;
		if(index == 1){
			sum = temp_sum;
			tmp = x;
			x = y;
			y = tmp;
		}
	}
	sum = sum > temp_sum ?temp_sum : sum;
	printf("\n%lld\n",sum);
}
