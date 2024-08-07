# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <assert.h>
# include "stack.h"

int * arr;
int n = 0;
int max_size = 1;

void initialise(int size){
     
     int * newarr = (int*)malloc( size* sizeof(*int));

     for(int i=0;i<n;i++){
         newarr[i] = arr[i];
     }

     int * temp = arr;
     arr = newarr;

     free( temp);
}
void push ( int item){
    
     if(n==0) initialise(max_size);

     else if(n==max_size){
          initialise( 2*max_size)
	  max_size*=2;
     }

     arr[n++] = item;

}

int pop(){
    
    if(n==0) return INT_MIN;

    int item = arr[--n];

    if( size()>0 && size() == max_size/4){
        
	max_size/=4;
	initialise( max_size );
    }

    return item;
}


int size(){
    return n;
}

bool isEmpty(){
    return n==0;
}

int testStack() {
	
        push(3);
	push(10);
	push(19);

	assert(isEmpty() == false);

	assert(size() == 3);

	assert(pop() == 19);

	assert(size() == 2);

	assert(pop() == 10);

	assert(size() == 1);

	assert(pop() == 3);

	assert(size() == 0);

	assert(isEmpty());
}

int main() {
	
	testStack();

	return 0;
}
