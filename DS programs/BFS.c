#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"

void display();
struct node *createNode(int n);
char* getScrOp();

int main(){
  int option = 99;
    int n = 0;
	char *menuStr = getScrOp();
  while(option != 11){
		printf("%sEnter an Option :",menuStr);
	  scanf("%d",&option);
    switch (option) {
      case 1:
        printf("\nEnter the value :");
        scanf("%d",&n);
        enQueue(createNode(n));
        break;
      case 2:
				printf("\n%d\n",deQueue());
				display();
				break;
			case 3:
				display();
				break;
			case 11:
				break;
      default :
        printf("\nEnter a valid option\n");
    }
  }
	free(head);
	free(tail);
  free(temp);
  return 0;
}
void display(){
	printf("\n");
	temp = head;
	while(temp!=NULL){
		printf("%d ->",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}
struct node* createNode(int value){
	struct node* temp1 = (struct node*)malloc(sizeof(struct node));
	temp1->data = value;
	temp1->next = NULL;
	return temp1;
}
char* getScrOp(){
	FILE *f = fopen("input-queue.txt","r");
	char* temp = NULL; char* str = NULL;
	int i = 0; int buff = 30;
	str = (char*)malloc(buff);
	str[0] = '\0';
	if(f == NULL)
		str = "\nThere was a problem in opening file.\n";
	else{
		while((getline(&temp,&buff,f)) != -1){
				if((str = (char*)realloc(str,(strlen(temp)+strlen(str))+2)) && str == NULL)
					printf("Problem in reallocating\n" );
				else{
					if(str[0] == '\0')
						strcpy(str,temp);
					else
						strcat(str,temp);
					}
		}
	}
	return str;
}
