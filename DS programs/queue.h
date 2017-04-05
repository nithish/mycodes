/* Function declarations */
struct node* createNode(int value);
void enQueue(struct node* data);
int deQueue();

struct node{
	struct node *data;
	struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *temp = NULL;

struct node* createNode(struct node* value){
	struct node* temp1 = (struct node*)malloc(sizeof(struct node));
	temp1->data = value;
	temp1->next = NULL;
	return temp1;
}
void enQueue(int n){
	if(head == NULL){
		head = createNode(n);
		tail = head;
	}
	else{
		tail->next = createNode(n);
		tail = tail->next;
	}
}
int deQueue(){
  int n = tail->data;
  temp = head;
  while(temp != NULL && temp->next != NULL && temp->next->next != NULL){
    temp = temp->next;
  }
  temp->next = NULL;
  tail = temp;
	if(head == temp){
		head = NULL;
		tail = NULL;
	}
  return n;
}
