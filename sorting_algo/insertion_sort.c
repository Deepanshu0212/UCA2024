#include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>
 #include <assert.h>
 #include <time.h>

 void insertion_sort(int arr[],int n)
 {
      for(int i=1;i<n;i++)
      {
          int j=i-1;
	  int k=arr[i];
	  while(j>=0 && arr[j]>k)
          {
	      arr[j+1]=arr[j];
	      j--;
	  }
	  arr[j+1]=k;
      }
 }

 void print(int arr[],int n)
 {
      for(int i=0;i<n;i++)
	  printf("%d ",arr[i]);
      printf("\n");
 }
 
 void test()
 {
      int inp[]={5,1,3,4,6,2};
      int n=6;
      
      int out[]={1,2,3,4,5,6};
      clock_t start,end;
      start=clock();
      
      insertion_sort(inp,n);

      end=clock();
      double diff=((double)(end-start))/(CLOCKS_PER_SEC);

      
      for(int i=0;i<6;i++)
      {
	   assert(out[i]==inp[i]);
      } 
      printf("Time in seconds: %f\n",diff);   
 }

 int main()
 {
      test();
      return 0;
 }