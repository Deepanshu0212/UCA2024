# include <stdio.h>
# include <assert.h>
# include <stdlib.h>
# include <time.h>
# include <sys/time.h>

void merge( int arr[] , int l , int u , int mid){
    
   int l1 = mid-l+1;
   int l2 = u-mid;
   
   int *arr1  = (int*) malloc( l1*sizeof(int));
   int *arr2  = (int*) malloc( l2*sizeof(int));
   
   for(int i=0;i<l1;i++){
     arr1[i] = arr[l+i]; 
   }

   for( int j=0; j<l2 ;j++){
      arr2[j] = arr[mid+j+1];
   }

   int i =0 , j=0;
   
   int k = l;
   
   while( i < l1 && j <l2){
      if(arr1[i] < arr2[j]){
         arr[k] = arr1[i];
         k++;
         i++;
     }
     else{
        arr[k] = arr2[j];
        k++;
        j++;
     }
   }

   
   while(i<l1){
     arr[k++] = arr1[i++];
   }

   while(j<l2){
     arr[k++] = arr2[j++];
   }

   free(arr1);
   free(arr2);
 
}
void mergesort( int arr[] , int l , int u){
   
   if(l>=u){
      return ; 
   }
   int mid = l + (u-l)/2;
   
   mergesort( arr , l, mid);
   mergesort( arr , mid+1 ,u);
   
   merge( arr , l , u , mid);
}

int testcase(){
   
    int arr[] = { 4 , 6 , 5 , 3 , 1 , 2};

    int newarr[] = { 1 , 2 , 3 , 4 , 5 , 6};


    mergesort(arr , 0 , 5);

   for(int i=0;i<=5;i++ ) assert( arr[i] == newarr[i]);
}
int main(){
   
     testcase();

}
