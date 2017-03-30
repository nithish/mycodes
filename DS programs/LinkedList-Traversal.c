/**************************************************************************************************************
 *
 * File    : LinkedList-Traversal.c
 *
 * Purpose : Console mode (command line) program.
 *
 * History : Date      				Reason
 *           07/03/2017 			Linked list Practice
 *
 * Issues: No. 										Description 												Solution
			 			#1	Usage of relloc() threw segementation 		Before using relloc() the value
			 					fault.																		must be have been initialized with
 																													malloc();			**ref : #122

			 			#2	Returning struct pointer from f#9					i. Removed the return stmnt inside the
			 					threw segmentation fault.				   					blocking clause of the recusive func
														 															   and added at the end. **ref : #141
														 															ii.Removed static keyword from reply and
														 															   returned reply.
						#3 prevptr was not updating properly.					It was declared as a static variable, so it didn't
																													re initialize during a new function call. Sol:
																													Used a global varible instead of local variable.
 **************************************************************************************************************/
/* Headers */
#include <stdio.h>
#include <stdlib.h>

/* Function declarations */
struct node* createNode(int value);
void insert();
void InsertBegin();
void InsertAnywhere();
int getInput();
void display();
void deleteNode();
void countIteratively();
void countRecursively();
void searchIteratively();//f#9
struct reply* searchRecursively();
void swapByLinks();
int checkHead(int n);
void getNth();

struct node{
	int data;
	struct node *next;
};
struct reply{
	int response;
	int data;
	struct node *ptr;
	struct node *prevptr;
};
struct node *head = NULL;
struct node *tail = NULL;
struct node *temp = NULL;
int main(){
	int option = 999;
	while(option!=11){
		printf("\n#1 Insert at the end\n#2 Insert at the beginning\n#3 Insert anywhere");
		printf("\n#4 Delete a node\n#5 Count iteratively\n#6 Get-Nth Node");
		printf("\n#7 Search iteratively\n#8 Search recursively\n#9 Swap Links\n#10  Print\n#11  Exit\nEnter the option :");
		scanf("%d",&option);
		switch(option){
			case 1:
				insert();
				break;
			case 10:
				display();
				break;
			case 2:
				InsertBegin();
				break;
			case 3:
				InsertAnywhere();
				break;
			case 11:
				printf("Exited.");
				break;
			case 4:
				deleteNode();
				break;
			case 5:
				countIteratively();
				break;
			case 6:
				getNth();
				break;
			case 7:
				searchIteratively();
				break;
			case 8:
				searchRecursively(head,getInput());
				break;
			case 9:
				swapByLinks();
				break;
			default :
				printf("Enter an valid option");
		}
	}
	return 0;
}
struct node* createNode(int value){
	struct node* temp1 = (struct node*)malloc(sizeof(struct node));
	temp1->data = value;
	temp1->next = NULL;
	return temp1;
}
void getNth(){
	int n = getInput();
	int index = 1 ;
	temp = head;
	while(temp!= NULL && index != n){
		temp = temp->next;
		index++;
	}
	if(temp != NULL)
		printf("\nNode at index %d is %d\n",n,temp->data);
	else
		printf("\nIndex out of range\n");
temp = NULL;
}
void searchIteratively(){
	int n = getInput();
	temp = head;
	while(temp!=NULL){
		if(temp->data == n)
			break;
		temp = temp->next;
	}
	if(temp == NULL)
		printf("\nKey is NOT present.\n");
	else
		printf("\nKey is present\n");
}
struct reply* searchRecursively(struct node* head, int n){
	static int index = 0;
	//static struct node *t = NULL;
	struct reply *r = NULL;
		index++;
	if(head == NULL || head->data == n ){
		free(r);
		r = (struct reply*)malloc(sizeof(struct reply));
		if(head!=NULL){
			r->response = 1;
			r->data = index;
			r->ptr = head;
			r->prevptr = temp;
		}
		else{
			r->response = 0;
			r->data = 0;
			r->ptr = NULL;
			r->prevptr = NULL;
		}
	}else{
		temp = head;
		r = searchRecursively(head->next,n);
	}
	index = 0;
	return r;
}
void swapByLinks(){
	struct reply *r = NULL,*r1 = NULL;
	temp = NULL;
	struct node *temp1 = NULL;
	int x = getInput();
	int y = getInput();
	r = searchRecursively(head,x);
	r1 = searchRecursively(head,y);
	if(r->response == 1 && r1->response == 1){
		temp = r1->ptr->next;
		temp1 = r1->prevptr;
		if(abs(r->data - r1->data) > 1){
			r1->ptr->next = r->ptr->next;
			r->ptr->next = temp;
			if(r->prevptr != NULL)
				r->prevptr->next = r1->ptr;
			if(temp1!=NULL)
				temp1->next = r->ptr;
			if(checkHead(x))
				head = r1->ptr;
			else if(checkHead(y))
				head = r->ptr;
		}else if(abs(r->data - r1->data) == 1){
			r1->ptr->next = r->ptr;
			r->ptr->next = temp;
			if(r->prevptr != NULL)
				r->prevptr->next = r1->ptr;
			/*if(temp1!=NULL)
				temp1->next = r->ptr;*/
			if(checkHead(x))
				head = r1->ptr;
			else if(checkHead(y))
				head = r->ptr;
		}
		else{
			printf("\n1st element should appear before 2nd element in LL.\n");
		}
	}else{
		printf("\nElement not found.\n");
	}
	display();
}
int checkHead(int n){
	if(head->data == n)
		return 1;
	else
		return 0;
}
void insert(){
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
void InsertBegin(){
	int n  = getInput();
	if(head == NULL){
		head = createNode(n);
		tail = head;
	}
	else{
		temp = NULL;
		temp = createNode(n);
		temp->next = head;
		head = temp;
		temp =NULL;
	}
	display();
}
void InsertAnywhere(){
	int n = getInput();
	int x;
	struct node* temp1 = NULL;
	printf("\nEnter the position to be inserted: ");
	scanf("%d",&x);
	if(head == NULL){
		head = createNode(n);
		tail = head;
	}
	else{
		temp = head;
		while(temp->next!=NULL && temp->data!=x){
			temp = temp->next;
		}
		temp1 = createNode(n);
		temp1->next = temp->next;
		temp->next = temp1;
		temp = NULL;
	}
	display();
}
void deleteNode(){
	int n = getInput();
	struct node* prev = NULL;
	printf("\nentered the function\n");
	if(head == NULL){
		printf("\nList is empty\n");
	}
	else{
		temp = head;
		if(head->data == n){
			head = head->next;
		}
		else{
			while(temp!=NULL && temp->data!=n){
				prev = temp;
				temp = temp->next;
			}
			prev->next = temp->next;
			}
		display();
		free(temp);
	}
}
void countRecursively(struct node* head){
	static int count = 0;
	if(head == NULL){
		printf("\nRecursive Count : %d\n",count);
		count = 0;
		return;
	}else{
		++count;
		countRecursively(head->next);
	}
}
void countIteratively(){
	int count = 0;
	temp = head;
	while(temp!=NULL){
		++count;
		temp = temp->next;
	}
	printf("\nIterative count : %d\n",count);
}
int getInput(){
	int n;
	printf("\nEnter the value: ");
	scanf("%d",&n);
	return n;
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
