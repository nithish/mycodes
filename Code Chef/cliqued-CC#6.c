/*Ref : https://www.codechef.com/APRIL17/problems/CLIQUED*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct node city;
typedef struct newRoad road;
typedef struct qnode Qnode;

/*Method definitions*/
void initializeMap(long int n,long int k,long int x);
city* createCity(int i);
void plotMap(city **map,long int k,long int x);
void print(int n);
void addRoads(road **roads,long int m);
int checkExists(int n);
void createRoad(road *path);
void calcShorestPath(long int,long int);
void InitilizeSS(long int *p,long long int *d,long int s,long int n);
Qnode* createQNode( struct node* value);
void enQueue(city *data,long int v);
city* deQueue();
int isQEmpty();
void InitializeQ(long int n, long long int *d);
void Relax(city *u, city *v,long long int *d,long int *p);
void updateQ(long int u,long int v,long int val);
/*structures declaration*/
struct node{
  int weight;
  int name;
  city *next;
  city *last;
};
struct newRoad{
  int src;
  int dest;
  int weight;
};
struct qnode{
	struct node *n;
	struct qnode *next;
  long int v;
};
/*Global Variables */
city **map = NULL;
road **roads = NULL;
Qnode *Qhead = NULL;
Qnode *Qtail = NULL;
Qnode *Qtemp = NULL;
int c = 0;int d = 0;
/*Queue Implementation starts*/
 Qnode* createQNode(city *value){
	Qnode* Qtemp1 = (Qnode*)malloc(sizeof(Qnode));
	Qtemp1->n = value;
	Qtemp1->next = NULL;
	return Qtemp1;
}
void enQueue(city *n,long int v){
	if(Qhead == NULL){
		Qhead = createQNode(n);
    Qhead->v = v;
		Qtail = Qhead;
	}
	else{
      Qtemp = Qhead;
      Qnode *Qprev = NULL;
      while(Qtemp != NULL && Qtemp->v <= v){
        Qprev = Qtemp;
        Qtemp = Qtemp->next;
      }
      Qnode *plhldr = createQNode(n);
      plhldr->v = v;
      if(Qprev == NULL){
        plhldr->next = Qhead;
        Qhead = plhldr;
      }else{
        plhldr->next = Qprev->next;
        Qprev->next = plhldr;
      }
	}
}
city* deQueue(){
  if(Qhead == NULL)
    return NULL;
  else{
    city *n = Qhead->n;
    Qtemp = Qhead;
    Qhead = Qhead->next;
    //free(Qtemp);
    return n;
  }
}
int isQEmpty(){
  if(Qhead == NULL)
    return 1;
  else
    return 0;
}
int isPresentQ(long int v){
  Qtemp = Qhead;
  int f = 0;
  while(Qtemp!=NULL){
    if(Qtemp->n->name == v)
      f = 1;
    Qtemp = Qtemp->next;
  }
  return f;
}
/*Queue Implementation ends*/
int main(){
  short cases = 0;
  long int n = 0, k = 0, m = 0, x = 0, s = 0 ,a = 0,b = 0,c = 0;
  scanf("%hd",&cases);
  while(cases > 0){
    int i = 1;
    scanf("%ld %ld %ld %ld %ld",&n,&k,&x,&m,&s);
    initializeMap(n,k,x);
    roads = malloc(m*sizeof(road*));
    while(i <= m){
      scanf("%d %d %d",&a,&b,&c);
      road *temp = malloc(sizeof(road));
      temp->src = a;
      temp->dest = b;
      temp->weight = c;
      roads[i] = temp;
      i++;
    }
    addRoads(roads,m);
    cases--;
    print(n);
    calcShorestPath(n,s);
  }
  return 0;
}
void initializeMap(long int n,long int k,long int x){
  long int i = 1;
  map = malloc(n*sizeof(city*));
  while(i <= n){
    map[i] = createCity(i);
    i++;
  }
  plotMap(map,k,x);
}
city* createCity(int i){
  city* temp = (city*)malloc(sizeof(city));
	temp->weight = 0;
  temp->name  = i;
	temp->next = NULL;
  temp->last = NULL;
	return temp;
}
void plotMap(city **map,long int k,long int x){
  long int i = 1;
  while(i <= k){
    long int j = 1;
    while(j <= k){
      if(map[i] && map[i]->name != j){
        if(map[i]->last == NULL){
          map[i]->next = createCity(j);
          map[i]->last = map[i]->next;
          map[i]->last->weight = x;
          map[i]->last->next = NULL;
        }else{
          city *temp = createCity(j);
          map[i]->last->next = temp;
          map[i]->last = temp;
          temp->weight = x;
          temp->last = NULL;
        }
      }
      j++;
    }
    i++;
  }
}
void print(int n){
  long int i = 1;
  while(i <= n){
    city *temp = map[i];
    while(temp != NULL){
      printf("-->[%d|%d]",temp->name, temp->weight);
      temp = temp->next;
    }
    printf("\n");
    i++;
  }
}
void addRoads(road **roads,long int m){
  long int i = 1;
  while(i <= m){
    road *path = roads[i];
    createRoad(path);
    i++;
  }
}
void createRoad(road *path){
  if(c == 2){
    c = 0;
    return;
  }
  city *src = map[path->src];
  city *temp = createCity((path->dest));
  if(src->last)
    src->last->next = temp;
  else{
    src->next  = temp;
  }
  src->last = temp;
  temp->weight = path->weight;
  int t = path->src;
  path->src = path->dest;
  path->dest = t;
  c++;
  createRoad(path);
}
void calcShorestPath(long int n,long int s){
  long int *p = malloc(n*sizeof(long int));
  long long int *d = malloc(n*sizeof(long int));
  long int i = 0;
  InitilizeSS(p,d,s,n);
  InitializeQ(n,d);
  while(!isQEmpty()){
    city *u = deQueue();
    city *v = u->next;
    //printf("\n [%ld|%ld]",u->name,u->weight);
    while(u != NULL && v != NULL){
      //if(isPresentQ(v->name))
        Relax(u,v,d,p);
      v = v->next;
    }
  }
  printf("\n");
  print(n);
  printf("\n");
  for(i = 1;i <= n;i++){
    printf("%d ",d[i]);
  }
}
void InitilizeSS(long int *p,long long int *d,long int s,long int n){
  long int i = 1;
  while(i <= n){
    p[i] = 0;
    d[i] = 1500000000;
    i++;
  }
  d[s] = 0;
}
void InitializeQ(long int n, long long int *d){
  long int i = 1;
  while(i <= n){
    enQueue(map[i],d[i]);
    // city *t = map[i]->next;
    // while(t != NULL){
    //   enQueue(t,d[i]);
    //   t= t->next;
    //}
    i++;
  }
  // Qnode *p = Qhead;
  // while(p!=NULL){
  //   printf("-->[%ld|%ld]",p->n->name,p->v);
  //   p = p->next;
  // }
  // printf("\n");
}
void Relax(city *u, city *v,long long int *d,long int *p){
  //printf("\n(%ld > %ld)",d[v->name],(d[u->name]+(v->weight)) );
    if(d[v->name] > (d[u->name]+(v->weight))){
      d[v->name] =  (d[u->name]+(v->weight));

      p[v->name] = u->name;
      updateQ(u->name,v->name,d[v->name]);
    }
}
void updateQ(long int u,long int v,long int val){
  if(d == 2){
    d = 0;
    return;
  }else{
    d++;
  Qtemp = Qhead;
  while(Qtemp != NULL){
    if(Qtemp->n->name == u){
      city *adj = Qtemp->n->next;
      while(adj != NULL){
        if(adj->name == v){
          adj->weight = val;
          break;
        }
        adj = adj->next;
      }
    }
    Qtemp = Qtemp->next;
  }
  updateQ(v,u,val);
  }
}
