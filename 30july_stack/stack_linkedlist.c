# include <stdio.h>
# include <stdbool.h>
# include <assert.h>
# include <stdlib.h>

struct Node{
    int val;
    struct Node* next;
};

typedef struct Node Node;

Node* head = NULL;
int n =0;

void push( int item){
    
    Node * oldhead = head;
    head = (Node*) malloc( sizeof(Node));
    head->val = item;
    head->next = oldhead;
    n++;
}

int pop(){
   
   int val = head->val;
   Node* temp = head;
   head = head->next;
   free(temp);
   return val;
}

int size(){
   return n;
}

bool empty(){
    return n==0;
}

int teststack(){
    push(3);
    push(10);
    push(19);

    assert(empty() == false);

    assert(size() == 3);

    assert(pop() == 19);

    assert(size() == 2);

    assert(pop() == 10);

    assert(size() == 1);

    assert(pop() == 3);

    assert(size() == 0);

    assert(empty());

}


int main(){

    teststack();

    return 0;
}
