#include<stdio.h>
void main()
{
  int l =0,r = 9,x,i,n,arr[20];
  printf("Enter the size of the array\n");
  scanf("%d",&n);
  printf("Enter the elements of  array (max.10)\n");
  for ( i=0;i<n;i++)
	scanf("%d",&arr[i]);
  printf("Enter the sum\n");
  scanf("%d",&x);
  while (l<=r)
  {
	if (arr[l] + arr[r] == x) 
	{
		printf("The pairs are %d and %d\n",arr[l],arr[r]);
		l++;
	}
	else if (arr[l] + arr[r] > x) 
		r -- ;
	else
		l++;
	}
}
