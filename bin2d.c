#include <stdio.h>
#include<stdlib.h>
 
int main(void) {
	// your code goes here
	int high,low,mid,n,m,i,j,x,flag=0;
	printf("Enter size of array\n");
	scanf("%d %d",&n,&m);
	int arr[n][m];
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		scanf("%d",&arr[i][j]);
	printf("Enter element to be searched in the list\n");
	scanf("%d",&x);	
	low=0;
	high=(n*m)-1;
 
//	k-th element = A[k/M][k % M] 
 
	while(high>=low){
		mid=(low+high)/2;
		if(arr[mid/m][mid % m] == x)
			{
				flag=1;
				break;
			}
		else if(arr[mid/m][mid % m]<x) // since the array is sorted
			low=mid+1;
		else
			high=mid-1;
	}
	if(flag==0)
		printf("The element could not be found\n");
	else
		printf("The row index is %d and column index is %d\n",mid/m,mid%m);
	return 0;
}