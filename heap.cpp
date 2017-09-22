#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "heap.h"
using namespace std;


#define LEFT(i) (2*i)
#define RIGHT(i) (2*(i)+1)
#define PARENT(i) (i/2)

void HEAPIFY(HEAP *H, int i)
{
  int l, r, largest, heap_size;
  data *tmp, **A;

  A = H->A;  heap_size = H->heap_size;

  l = LEFT(i);   r = RIGHT(i);
  if (l <= heap_size && A[l]->key > A[i]->key) largest = l; 
  else  largest = i;                              
  if (r <= heap_size && A[r]->key > A[largest]->key)        
    largest = r;
  if (largest != i) {                                                          
    tmp = A[i];  A[i] = A[largest];  A[largest] = tmp; 
    HEAPIFY(H, largest);
  }
}

void HEAPIFY2(HEAP *H, int i)
{
  int l, r, largest, heap_size;
  data *tmp, **A;

  A = H->A;  heap_size = H->heap_size;

  while (1) {
    l = LEFT(i);   r = RIGHT(i);
    if (l <= heap_size && A[l]->key > A[i]->key) largest = l; 
    else  largest = i;                              
    if (r <= heap_size && A[r]->key > A[largest]->key)       
      largest = r;
    if (largest == i) break;
    tmp = A[i];  A[i] = A[largest];  A[largest] = tmp; 
    i = largest;
  }
}

void BUILD_HEAP(HEAP *H, int n, data **A, int length)
{
  int i;
  H->length = length;
  H->heap_size = n;
  H->A = A;
  for (i = H->heap_size/2; i >= 1; i--) {
    HEAPIFY(H,i);
  }
}

void HEAPSORT(int n, data **A)
{
  int i;
  data *tmp;
  HEAP H;

  BUILD_HEAP(&H,n,A,n);
  for (i = n; i >= 2; i--) {
    tmp = A[1];  A[1] = A[i];  A[i] = tmp; 
    H.heap_size = H.heap_size - 1;
    HEAPIFY(&H,1);
  }
}

data* EXTRACT_MAX(HEAP *H)  // O(lg n) time
{
  data *MAX, **A;

  A = H->A;

  if (H->heap_size < 1) {
    printf("ERROR underflow\n");
    exit(1);
  }
  MAX = A[1];
  A[1] = A[H->heap_size];
  H->heap_size = H->heap_size - 1;
  HEAPIFY(H,1);
  return MAX;
}

void DOUBLE_HEAPSIZE(HEAP *H){
  H -> length *= 2;
  data **newA = new data*[H->length];
  for(int i=1; i< H -> heap_size; i++) newA[i]=H->A[i];
  //delete[] H->A;
  H->A=newA;
  return;
}

void INSERT(HEAP *H, data *node)  // O(lg n) ŽžŠÔ
{
  int i;
  data **A;

  H->heap_size = H->heap_size + 1;
  if (H->heap_size > H->length) {
    printf("ERROR overflow\n");
    //exit(1);
    DOUBLE_HEAPSIZE(H);

  }

  A = H->A;
  i = H->heap_size;
  while (i > 1 && A[PARENT(i)]->key < node->key) {
    A[i] = A[PARENT(i)];
    i = PARENT(i);
  }
  A[i] = node;
  cout<<"ed"<<endl;
}

void DELETE(HEAP *H, int i)  // O(lg n) ŽžŠÔ
{
  data **A;

  A = H->A;

  if (i < 1 || i > H->heap_size) {
    printf("ERROR of Range(%d,%d)\n",i,H->heap_size);
    exit(1);
  }

  while (i > 1) {
    A[i] = A[PARENT(i)];
    i = PARENT(i);
  }
  A[1] = A[H->heap_size];
  H->heap_size = H->heap_size - 1;
  HEAPIFY(H,1);
}

/*
int main()
{
  data *A[20];
  for(int j=0; j<20; j++){
    A[j]=new data;
    A[j]->key=20-j;
  }
  HEAP H;
  int i,n;
  BUILD_HEAP(&H,4,A,8);
  INSERT(&H,A[18]);
  DELETE(&H,2);
  n = H.heap_size+1;
  for (i=1; i<=n; i++) {
    printf("max = %f\n",EXTRACT_MAX(&H)->key);
    for (i=1;i<=H.heap_size;i++) printf("%f ",A[i]->key);
    printf("\n");
  }

}*/