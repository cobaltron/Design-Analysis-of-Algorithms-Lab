#include<stdio.h>
int first(int arr[],int low,int high,int x,int n)
{
    int mid = (low+high)/2;
	if( ( mid == 0 || x > arr[mid-1]) && arr[mid] == x)
      return mid;
	else if(x > arr[mid])
      return first(arr, (mid + 1), high, x, n);
	else
     return first(arr, low, (mid -1), x, n);
 }
int last(int arr[],int low,int high,int x,int n)
 {
    int mid = (low+high)/2;
     if( ( mid == n-1 || x < arr[mid+1]) && arr[mid] == x )
		return mid;
	 else if(x < arr[mid])
		return last(arr, low, (mid -1), x, n);
	 else
		return last(arr, (mid + 1), high, x, n);
 }
int main()
{
  int l =0,r = 9,mid,i,x,a,b,n,arr[n];
  printf("Enter the size of the array\n");
   scanf("%d",&n);
  printf("Enter the elements of sorted array\n");
  for ( i=0;i<n;i++)
	scanf("%d",&arr[i]);
  printf("Enter the number to count the occurences of\n");
   scanf("%d",&x);
	a = first(arr,0,n-1,x,n);
	b = last(arr,0,n-1,x,n);
	printf("The no. of occurences is %d",b-a+1);
	return 0;
}
