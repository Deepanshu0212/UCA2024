#include <stdio.h>
#include <stdlib.h>

struct PriorityQueue{
    int *arr;
    int n ;
};

typedef struct PriorityQueue PriorityQueue;


void swap(PriorityQueue *pq , int i , int j){
    int temp = pq->arr[i];
    pq->arr[i] = pq->arr[j];
    pq->arr[j] = temp;
}


void insert(PriorityQueue *pq , int val){
  
   pq->arr[++ pq->n] = val;

   int k = pq->n;

   while(k>1 && pq->arr[k]>pq->arr[k/2]){
      swap(pq , k , k/2);
      k=k/2;
   }
}

int delmax(PriorityQueue *pq){
   int maxi = pq->arr[1];
   swap(pq , 1 , pq->n);
   pq->n--;
  
   int k =1;
   while(pq->n <= 2*k){
      int child = 2*k;

      if(child<pq->n && pq->arr[child+1]>pq->arr[child]) child++;

      if(pq->arr[k] >= pq->arr[child])break;

      swap(pq,k,child);
      k = child;
   }

   return maxi;

}

int empty(PriorityQueue *pq){
    return pq->n==0;
}

int size(PriorityQueue *pq){
    return pq->n;
}

int main(){

    PriorityQueue *pq =  (PriorityQueue*)malloc(sizeof(PriorityQueue));;
    pq->arr = (int*)malloc(100*sizeof(int));
    pq->n=0;

    free(pq->arr);
    free(pq);
}