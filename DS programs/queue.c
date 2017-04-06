#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function declarations */
struct node* createNode(int value);
void enQueue();
int deQueue();
void display();
int getInput();
char* getScrOp();

struct node{
	int data;
	struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *temp = NULL;

struct node* createNode(int value){
	struct node* temp1 = (struct node*)malloc(sizeof(struct node));
	temp1->data = value;
	temp1->next = NULL;
	return temp1;
}
int getInput(){
	int n;
	printf("\nEnter the value: ");
	scanf("%d",&n);
	return n;
}
void enQueue(){
	int n = getInput();
	if(head == NULL){
		head = createNode(n);
		tail = head;
	}
	else{
		tail->next = createNode(n);
		tail = tail->next;
	}
	display();
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
int deQueue(){
	int n = 0;
	if(head == NULL){
		printf("\n Queue is Empty");
	}else{
		n = head->data;
		temp = head;
		head = head->next;
	  }
		return n;
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
int main(){
  int option = 99;
	char *menuStr = getScrOp();
  while(option != 11){
		printf("%sEnter an Option :",menuStr);
	  scanf("%d",&option);
    switch (option) {
      case 1:
        enQueue();
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
