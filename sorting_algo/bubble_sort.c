#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>


void exch(int arr[],int j)
{
        int temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
}

void bubble_sort(int arr[],int n)
{
   for(int i=0;i<n;i++)
    {
      for(int j=0;j<n-i-1;j++)
       {
          if(arr[j+1]<arr[j])
            exch(arr,j);
       }
    }

}
void test_sample()
{
  int in[]={3,5,1,7,2,4};
  int out[]={1,2,3,4,5,7};
  bubble_sort(in,6);
  int n=6;
  for(int i=0;i<n;i++)
  {
     assert(in[i]==out[i]);
  }
}
int main()
{
  test_sample();
  return 0;
}