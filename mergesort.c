#include<stdlib.h> 
#include<stdio.h> 
void merge(int A[ ] , int start, int mid, int end) 
{
    //stores the starting position of both parts in temporary variables.
    int p = start ,q = mid+1;
    int Arr[end-start+1] , k=0;
    for(int i = start ;i <= end ;i++) 
    {
        if(p > mid) 
        Arr[ k++ ] = A[ q++] ;
        else if ( q > end)   
        Arr[ k++ ] = A[ p++ ];
        else if( A[ p ] < A[ q ])   
        Arr[ k++ ] = A[ p++ ];
        else
        Arr[ k++ ] = A[ q++];
    }
    for (int p=0 ; p< k ;p ++) 
    {
        A[ start++ ] = Arr[ p ] ;                          
    }
}

void merge_sort (int A[ ] , int start , int end )
{
        if( start < end ) 
        {
            int mid = (start + end ) / 2 ;           // defines the current array in 2 parts .
            merge_sort (A, start , mid ) ;                 // sort the 1st part of array .
            merge_sort (A,mid+1 , end ) ;              // sort the 2nd part of array.
            merge(A,start , mid , end );   
        }                    
}
  
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    merge_sort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 
