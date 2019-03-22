#include <stdio.h> 
int findMin(int arr[], int low, int high)
{
    if (high < low)
	return arr[0];
    if (high == low)
	return arr[low];
    int mid = low + (high - low)/2;
    if (mid < high && arr[mid+1] < arr[mid])
       return arr[mid+1];
    if (mid > low && arr[mid] < arr[mid - 1])
       return arr[mid];
    if (arr[high] > arr[mid])
       return findMin(arr, low, mid-1);
    return findMin(arr, mid+1, high);
}
int main()
{
    int n,i;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements in a sorted and rotated order\n");
    for(i = 0;i < n;i ++)
	scanf("%d",&arr[i]);
    printf("The minimum element is %d",findMin(arr,0,n-1)); 
    return 0;
}

