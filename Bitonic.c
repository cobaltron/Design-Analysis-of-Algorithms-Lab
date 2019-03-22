#include<stdio.h>
int bitonic(int a[],int low,int high)
{
	if(high <= low)
		return a[low];
	int mid = (low + high)/2;
	if(a[mid-1] < a[mid] && a[mid] > a[mid+1])
		return a[mid];
	else if(a[mid-1] > a[mid]) 
		return bitonic(a,low,mid);
	else
		return bitonic(a,mid+1,high);
}
void main()
{
	int n,i;
	printf("Enter size of array:");
	scanf("%d",&n);
	printf("Enter elments\n");
	int arr[n];
	for(i = 0;i < n;i ++)
		scanf("%d",&arr[i]);
	printf("Bitonic point is %d",bitonic(arr,0,n));
}

