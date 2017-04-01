#include<stdlib.h>
#include<stdio.h>
void insert();
int getInput(char* str);
struct node* insertPoint(struct node *root, int option);
struct node{
	int data;
	struct node *left;
  struct node *right;
};
struct node *root = NULL;
int main(){
  int option = 99;
  while(option != 11){
    printf("\n**** Complete Binary Tree ****\n");
    printf("\n#1 Insert into tree\n#2 Print Tree\n#11 Exit \n");
		printf("\nEnter option :");
	  scanf("%d",&option);
    switch (option) {
      case 1:
        insert();
        break;
      case 2:
      	insertPoint(root,1);
        break;
			case 11:
				break;
      default :
        printf("\nEnter a valid option\n");
    }
  }
  return 0;
}
int getInput(char *str){
  int n = 0;
  printf("%s ",str);
  scanf("%d",&n);
  return n;
}
void insert(){
  int n = getInput("\nEnter value for the node: ");
  struct node *temp = NULL,*newNode = (struct node*)malloc(sizeof(struct node));
  if(root == NULL){
    root = (struct node*)malloc(sizeof(struct node));
    root->data = n;
    root->left = NULL;
    root->right = NULL;
  }else{
    temp = insertPoint(root,0);
		newNode->data = n;
		newNode->left = NULL;
		newNode->right = NULL;
    if(temp->left == NULL)
			temp->left = newNode;
		else
			temp->right = newNode;
		}
}
/*
	This function is used for both finding the insertPoint and printing the tree
*/
struct node* insertPoint(struct node *root, int option){
    if(option == 0 && (root->left == NULL || root->right == NULL)){
			if(option == 1)
				printf("-- > %d\n",root->data);
      return root;
    }else if(option == 1 && root == NULL){
			return root;
		}else{
			if(option == 1)
				printf("-- > %d",root->data);
	      insertPoint(root->left,option);
	      insertPoint(root->right,option);
    }
}
