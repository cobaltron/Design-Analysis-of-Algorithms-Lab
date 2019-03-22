#include <stdio.h>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)


int median(int *a1, int *a2, int n){
	
	int med1, med2;
	/* return -1  for invalid input */
    if (n <= 0)
        return -1;
    if (n == 1)
        return (a1[0] + a2[0])/2;
    if (n == 2)
        return (max(a1[0], a2[0]) + min(a1[1], a2[1])) / 2;
	if (n%2 == 0){
        med1 = (a1[n/2] + a2[n/2-1])/2;
		med2 = (a1[n/2] + a2[n/2-1])/2;
	}
    else{
        med1 = a1[n/2];
        med2 = a2[n/2];
    }
    
	if(med1 == med2)
		return med1;
	else if(med1 < med2)
		{
			if (n % 2 == 0)
            		return median(a1 + n/2 - 1, a2, n - n/2 +1);
        	return median(a1 + n/2, a2, n - n/2);
		}
	else {
		if (n % 2 == 0)
        return median( a1, a2 + n/2 - 1,  n - n/2 + 1);
    return median( a1 ,a2 + n/2, n - n/2);
	}
}

int main(void) {
	// your code goes here
	int i,n,k;
	printf("Enter the number of elements in array\n");
	scanf("%d",&n);
	int a1[n];
	int a2[n];
	printf("Enter the elements in first array\n");
	for(i=0;i<n;i++)
	 scanf("%d",&a1[i]);
	 printf("Enter the elements in second array\n");
	for(i=0;i<n;i++)
	 scanf("%d",&a2[i]);
	k=median(a1,a2,n);
	printf("The median of the merged array is: %d",k);
	return 0;
}