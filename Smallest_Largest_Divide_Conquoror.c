#include<stdio.h>
struct maxpair
{
  int secmax;
  int max;
}; 
struct maxpair getMax(int arr[], int low, int high)
{
  struct maxpair maxes, mml, mmr;       
  int mid;
  if (low == high)
  {
     maxes.max = arr[low];
     maxes.secmax = arr[low];
     return maxes;
  }    
  if (high == low + 1)
  {  
     if (arr[low] > arr[high])  
     {
        maxes.max = arr[low];
        maxes.secmax = arr[high];
     }  
     else
     {
        maxes.max = arr[high];
        maxes.secmax = arr[low];
     }  
     return maxes;
  }
  mid = (low + high)/2;  
  mml = getMax(arr, low, mid);
  mmr = getMax(arr, mid+1, high);
  if (mml.max > mmr.max)
  {
    maxes.max = mml.max;
    if(mml.secmax > mmr.max)
	maxes.secmax = mml.secmax;
    else
	maxes.secmax = mmr.max;
  }
  else
  {
    maxes.max = mmr.max;
    if(mmr.secmax > mml.max)
        maxes.secmax = mmr.secmax;
    else
	maxes.secmax = mml.max;
  }  
  return maxes;
}
struct minpair
{
  int secmin;
  int min;
}; 
struct minpair getMin(int arr[], int low, int high)
{
  struct minpair mins, mml, mmr;       
  int mid;
  if (low == high)
  {
     mins.min = arr[low];
     mins.secmin = arr[low];
     return mins;
  }    
  if (high == low + 1)
  {  
     if (arr[low] < arr[high])  
     {
        mins.min = arr[low];
        mins.secmin = arr[high];
     }  
     else
     {
        mins.min = arr[high];
        mins.secmin = arr[low];
     }  
     return mins;
  }
  mid = (low + high)/2;  
  mml = getMin(arr, low, mid);
  mmr = getMin(arr, mid+1, high);
  if (mml.min < mmr.min)
  {
    mins.min = mml.min;
    if(mml.secmin < mmr.min)
	mins.secmin = mml.secmin;
    else
	mins.secmin = mmr.min;
  }
  else
  {
    mins.min = mmr.min;
    if(mmr.secmin < mml.min)
        mins.secmin = mmr.secmin;
    else
	mins.secmin = mml.min;
  }  
  return mins;
}
int main()
{
  int i,arr[100],arr_size;
  printf("Enter array size:");
  scanf("%d",&arr_size);
  printf("Enter elements\n");
  for(i = 0;i < arr_size;i ++)
	scanf("%d",&arr[i]);
  struct maxpair maxes = getMax(arr, 0, arr_size-1);
  struct minpair mins = getMin(arr, 0, arr_size-1);
  printf("Second maximum element is %d", maxes.secmax);
  printf("\nSecond minimum element is %d", mins.secmin);
  getchar();
}

