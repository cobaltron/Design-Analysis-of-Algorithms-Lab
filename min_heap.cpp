#include<stdio.h> 
void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
void minHeapify(int a[], int size, int i)
{
    int l = 2*i;
    int r = 2*i+1;
    int smallest = i;
    if(l<=size && a[l]<a[smallest])
        smallest = l;
    if(r<=size && a[r]<a[smallest])
        smallest = r;
    if(smallest!=i)
    {
        swap(&a[i],&a[smallest]);
        minHeapify(a,size,smallest);
    }    
} 
void buildMinHeap(int a[], int size) 
{
    for(int i=size/2;i>0;i--)
    {
		minHeapify(a,size,i);
}
}  
void heapsort(int arr[],int n)
{
    buildMinHeap(arr, n);
	for (int i=n; i>=1; i--) 
    { 
        printf("%d-",arr[1]);
		// Move current root to end 
        swap(&arr[1], &arr[i]); 
        
        // call max heapify on the reduced heap 
        minHeapify(arr, i, 1); 
    } 
} 
int main() 
{
    int a[100],size;
    printf("Enter the array size:");
    scanf("%d",&size);
    printf("Enter the array elements:\n");
    for(int i=1;i<=size;i++)
    {
    	scanf("%d",&a[i]);
	}
    
    heapsort(a,size);
    printf("The min heap is:\n");
    for(int i=1;i<=size;i++)
    {
    		printf("%d.",a[i]);
	}
    return 0;
}
