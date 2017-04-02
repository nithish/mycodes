#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void insert();
int getInput(char* str);
char* getScrOp();
struct node* insertPoint(struct node *root, int option);
void inOrder(struct node* root);
void preOrder(struct node* root);
void postOrder(struct node* root);

struct node{
	int data;
	struct node *left;
  struct node *right;
};
struct node *root = NULL;
int main(){
  int option = 99;
	char *menuStr = getScrOp();
  while(option != 11){
		printf("%sEnter an Option :",menuStr);
	  scanf("%d",&option);
    switch (option) {
      case 1:
        insert();
        break;
      case 2:
				printf("\n");
				inOrder(root);
				printf("\n");
				break;
			case 3:
				printf("\n");
				preOrder(root);
				printf("\n");
				break;
			case 4:
				printf("\n");
				postOrder(root);
				printf("\n");
				break;
			case 5:
				printf("\n");
      	insertPoint(root,1);
				printf("\n");
        break;
			case 11:
				break;
      default :
        printf("\nEnter a valid option\n");
    }
  }
  return 0;
}
char* getScrOp(){
	FILE *f = fopen("input-tree.txt","r");
	char* temp = NULL; char* str = NULL;char* temp1 = NULL;
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
int getInput(char *str){
  int n = 0;
  printf("%s ",str);
  scanf("%d",&n);
  return n;
}
void inOrder(struct node* n){
	if(n != NULL){
		inOrder(n->left);
		printf("-->%d", n->data);
		inOrder(n->right);
	}
}
void preOrder(struct node* n){
	if(n != NULL){
		printf("-->%d", n->data);
		inOrder(n->left);
		inOrder(n->right);
	}
}
void postOrder(struct node* n){
	if(n != NULL){
		inOrder(n->left);
		inOrder(n->right);
		printf("-->%d", n->data);
	}
}
void insert(){
  int n = getInput("\nEnter value for the node :");
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
	      insertPoint(root->left,option);
				if(option == 1)
					printf("-->%d",root->data);
				insertPoint(root->right,option);
    }
}
