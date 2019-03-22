#include<stdio.h>

// max difference of two elements in the array
// s.t. larger element appears after the smallest
// element in the array
   int n1,n2;
int maxDiff(int arr[],int size) {
   int i;
   int max_diff = arr[1]-arr[0];
   int min_element = arr[0];
   for (i=1;i<size;i++) {
      if (arr[i] > min_element) {
         // diff of current and min element
         int diff = arr[i]-min_element;

         if (diff > max_diff) {
            // update max diff
            max_diff = diff;
            n1=arr[i];
            n2=min_element;

            
         }
      }
      else {
         // update the min element in the array
         min_element = arr[i];
      }
   }
   return max_diff;
}

// main
int main() {
   int arr[] =  { 3, 2, 6, 9, 5 };
   int size = sizeof(arr)/sizeof(arr[0]);
   int max_diff = maxDiff(arr,size);
   printf("%d",max_diff);
   printf("%d",n1);
   printf("%d",n2);
   return 0;
}
