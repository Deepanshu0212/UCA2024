#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>

int N=0;
int *arr=NULL;
int max_size=1;
int i=0;

void resize(int arr[],int n)
{
   int *n2=(int*)malloc(n*sizeof(int));
   for(int i=0;i<n;i++)
    {
	n2[i]=arr[i];
    }
   arr=n2;
   free(n2);
   i=0;
	  
}

void push(int d)
{
   if(max_size==1)
    { 
      resize(arr,max_size*=2);
    }
   else if(max_size==N)
      resize(arr,max_size*=2);
   arr[N++]=d;
}
int size()
{
  return N;
}
int pop()
{
   if(size()==0)
      return INT_MIN;
   int item=arr[i];
   i++;
   N--;
   if(N==max_size/4)
      resize(arr,max_size/=4);
   return item;
}

int front()
{
   return arr[i];
}
bool isEmpty()
{
   return (size()==0);
}
void test()
{
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  assert(pop()==1);
  assert(size()==4);
  assert(pop()==2);
  assert(size()==3);
  assert(pop()==3);
  assert(size()==2);
  assert(pop()==2);
  assert(size()==1);
  assert(pop()==1);
  assert(isEmpty()==1);
 

}

int main()
{

  return 0;
}