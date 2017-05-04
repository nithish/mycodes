/*
Enter the heap size first and then the elements of the array.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef long long int lint;


//Method_Definitions
void Decrease_Key(lint i, lint key);
lint Heap_Min(lint heap_size);
lint Extract_Max(lint heap_size);
lint Heap_Max(lint heap_size);
lint Extract_Min(lint heap_size);
lint Heap_Max(lint heap_size);
void Build_Min_Heap(lint *arr,lint heap_size);
void Min_Heapify(lint *a, lint i, lint heap_size);
void print(lint heap_size);
lint left(lint i);
lint right(lint i);
lint parent(lint i);
void Max_Heapify(lint *a, lint i, lint heap_size);
void Build_Max_Heap(lint *arr,lint heap_size);
lint getLint();
void allocate(lint heap_size);
void fill(lint heap_size);

lint heap_size = 0;
lint *heap = NULL;
lint left(lint i){
  return 2*i+1;
}
lint right(lint i){
  return 2*i+2;
}
lint parent(lint i){
  return floor(i/2);
}
void Max_Heapify(lint *a, lint i, lint heap_size){
  static lint largest = 0;
  lint l = left(i);
  lint r = right(i);
  if(l < heap_size && a[l] > a[i]){
    largest = l;
  }else{
    largest = i;
  }
  if(r < heap_size && a[r] > a[largest]){
    largest = r;
  }
  //printf("One\n");
  if(largest != i){
    lint temp = a[largest];
    a[largest] = a[i];
    a[i] = temp;
    //printf("\nTwo : %lld",largest);
    Max_Heapify(a,largest,heap_size);
  }
}
void Min_Heapify(lint *a, lint i, lint heap_size){
  static lint largest = 0;
  lint l = left(i);
  lint r = right(i);
  if(l < heap_size && a[l] < a[i]){
    largest = l;
  }else{
    largest = i;
  }
  if(r < heap_size && a[r] < a[largest]){
    largest = r;
  }
  //printf("One\n");
  if(largest != i){
    lint temp = a[largest];
    a[largest] = a[i];
    a[i] = temp;
    //printf("\nTwo : %lld",largest);
    Min_Heapify(a,largest,heap_size);
  }
}
void Build_Max_Heap(lint *arr,lint heap_size){
  lint i = 0;
  for(i = floor(heap_size/2); i >=0 ;i--){
    Max_Heapify(arr,i,heap_size);
  }
}
void Build_Min_Heap(lint *arr,lint heap_size){
  lint i = 0;
  for(i = floor(heap_size/2); i >=0 ;i--){
    Min_Heapify(arr,i,heap_size);
  }
}
int main(){
  lint heap_size = getLint();
  allocate(heap_size);
  fill(heap_size);
  Build_Min_Heap(heap,heap_size);
  print(heap_size);
  return 0;
}
lint getLint(){
  int c;
  lint sum = 0;
  //printf("\nEnter String :");
  c = getchar();
  while(c > 47 && c < 59){
      sum = sum*10+ (c - '0');
      c = getchar();
  }
  return sum;
}
void allocate(lint heap_size){
  heap = (lint*)malloc(heap_size *sizeof(lint));
}
void fill(lint heap_size){
  lint i = 0;
  for(i = 0;i<heap_size;i++){
    heap[i] = getLint();
  }
}
void print(lint heap_size){
  for (size_t i = 0; i < heap_size; i++) {
    printf("%lld ",heap[i]);
  }
}
lint Heap_Max(lint heap_size){
  return heap[0];
}
lint Heap_Min(lint heap_size){
  return heap[0];
}
lint Extract_Max(lint heap_size){
  lint max = 0;
  if(heap_size <= 0)
    printf("\n Heap Under flow");
  else{
    max = heap[0];
    heap[0] = heap[heap_size-1];
    heap_size = heap_size-1;
    Max_Heapify(heap,0,heap_size);
  }
  return max;
}
lint Extract_Min(lint heap_size){
  lint max = 0;
  if(heap_size <= 0)
    printf("\n Heap Under flow");
  else{
    max = heap[0];
    heap[0] = heap[heap_size-1];
    heap_size = heap_size-1;
    Min_Heapify(heap,0,heap_size);
  }
  return max;
}
void Increase_Key(lint i, lint key){
  if(key < heap[i])
    printf("\nKey is smaller than the current value");
  else{
    heap[i] = key;
    while(i > 0 && heap[i] > heap[parent(i)]){
      lint temp = heap[parent(i)];
      heap[parent(i)] = heap[i];
      heap[i] = temp;
      i = parent(i);
    }
  }
}
void Decrease_Key(lint i, lint key){
  if(key > heap[i])
    printf("\nKey is greater than the current value");
  else{
    heap[i] = key;
    while(i > 0 && heap[i] > heap[parent(i)]){
      lint temp = heap[parent(i)];
      heap[parent(i)] = heap[i];
      heap[i] = temp;
      i = parent(i);
    }
  }
}
