# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <time.h>
# include <sys/time.h>

void swap( int arr[] , int i , int j){

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}
int  findpivot( int arr[] , int l , int u){
    
    int pivot = arr[l];

    int cnt=0;
    for(int i=l+1;i<=u;i++){
       if(arr[i] <=pivot) cnt++;
    }
    int pvtidx = l+cnt;

    swap(arr , l , pvtidx);
    int i=l,j=u;
   
    while(i<pvtidx && j>pvtidx){
         
	while(arr[i]<=pivot){
	     i++;
	}

	while(arr[j] > pivot){
             j--;
	}
        if( i<pvtidx && j>pvtidx)
	swap(arr, i++ , j--);
    }

    return pvtidx;


}

void quicksort( int arr[], int l , int u ){

    if(l>=u) return;

    int pi = findpivot(arr , l , u);

    quicksort(arr,l , pi-1);

    quicksort(arr,pi+1,u);
}

void testcase(){

    int arr[] = { 4 , 6 , 5 , 3 , 1 , 2};

    int newarr[] = { 1 , 2 , 3 , 4 , 5 , 6};


    quicksort(arr , 0 , 5);

   for(int i=0;i<=5;i++ ) assert( arr[i] == newarr[i]);

   printf("testcase passed");

}

int main(){

    testcase();

}	
