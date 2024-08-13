#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>

struct Node{
    int val;
    struct Node* next;
};

typedef struct Node Node;

Node* head = NULL;
Node* tail = NULL;
int n =0;

bool isEmpty(){
   return n==0;
}
void push(int val){
   Node* temp = (Node*)malloc(sizeof(Node));
   temp->val = val;

   if(isEmpty()){
       head = tail = temp;
   }
   else{
	tail->next=temp;
	tail = tail->next;
   }

   n++;
}

int pop(){
   if(n==0) return INT_MIN;

   int front = head->val;
   Node* temp = head;
   head=head->next;
   free(temp);
   n--;
   return front;
}

int size(){
   return n;
}

void testQueue() {
    push(3);
    push(10);
    push(20);

    assert(isEmpty() == false);
    assert(size() == 3);
    assert(pop() == 3);
    assert(size() == 2);
    assert(pop() == 10);
    assert(size() == 1);
    assert(pop() == 20);
    assert(size() == 0);
    assert(isEmpty());
}

int main() {
    testQueue();
    printf("All tests passed!!\n");
    return 0;
}
