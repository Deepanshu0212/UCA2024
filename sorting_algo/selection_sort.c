#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>
void swap(int *arr,int i,int min)
{

     int t=arr[i];
     arr[i]=arr[min];
     arr[min]=t;
}
void selection_sort(int * arr,int n){
  int min;
  for(int i=0;i<n;i++)
  {
     min=i;
     for(int j=i+1;j<n;j++)
     {
        if(arr[j]<arr[min])
         min=j;
     }
     swap(arr,i,min);
  }
}

void test()
{
   clock_t start,end;
   double cpu_time;
   int n;
   printf("Enter number of terms:");
   scanf("%d",&n);
   int *arr=(int*)malloc(n*sizeof(int));
   for(int  i=0;i<n;i++)
   {
      arr[i]=rand()%50;
   }

   start=clock();

   selection_sort(arr,n);

   end=clock();
   cpu_time=(double)(end-start)/(CLOCKS_PER_SEC);

   for(int i=0;i<n;i++)
   {
     printf("%d ",arr[i]);
   }
   printf("\n");

   printf("Execution time : %f seconds\n",cpu_time);
   free(arr);
}
int main()
{
   test();
   return 0;
}