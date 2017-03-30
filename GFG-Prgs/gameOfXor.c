#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* getInput(int arr_size);
void  processInput(char* input);
void  genrateCombos(int* num_arr, int len);
int main(){
	int testCases = 0,arr_size = 0;
	char* input = NULL;
	printf("Enter the no of test cases : ");
	scanf("%d",&testCases);
	while(testCases!=0 && testCases <= 100){
		printf("\nEnter Array size : ");
		scanf("%d",&arr_size);
		if(arr_size >1000) 
			return 0;
		else{
			processInput(getInput(arr_size));
			testCases--;
		}
	}
	free(input);
	return 0;
}
/*	Always allocate extra space for '\0' character.
*	Always free the same size as allocated using malloc.
*/
char* getInput(int arr_size){
	char* input = NULL;int index = 0;
	printf("\nEnter the String : ");
	input = (char*)malloc(arr_size+2);
		while((scanf(" %c",&input[index])==1) && index!= arr_size-1) {
		    index++;
		}
		input[index+1] = '\0';
		//printf("\nInput : %s %d\n",input,strlen(input));
		return input;
}
void processInput(char* input){
	//printf("Final : %s\n",input);
	int len = strlen(input);
	int* num_arr = (int*)malloc(len*sizeof(int*));
	for (int i = 0; i < len; ++i){
		num_arr[i] = input[i] - '0';
		//printf("%d\n",num_arr[i]);
	}
	genrateCombos(num_arr,len);
	free(num_arr);
}
void genrateCombos(int* num_arr,int len){
	int window = 1, head = 0, tail = 0,index = 0;
	int* sub_arr = (int*)malloc(len*sizeof(int*)); 
	while(window <= len){
		tail = window-1;
		sub_arr[index] = num_arr[tail];
		printf("-> %d\n",sub_arr[index]);
		index++;
		if(abs(tail - head) > window-1){
			head++;
			window++;
			tail = head;
		}else{
			tail++;
		}
	}
}
