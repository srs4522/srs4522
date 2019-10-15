#include <stdio.h>
int partition (long int arr[],int start,int end)
{
	int pivot=arr[end];//pivot initially set as last element
	int p_Index=start;//partition index initially set as first index
	for(int i=start;i<end;i++)//logic to set the partition and move all elements larger than pivot to its right and smaller ones to its left
	{
		if(arr[i]<pivot)
		{
			long int temp;
			temp=arr[i];
			arr[i]=arr[p_Index];
			arr[p_Index]=temp;
			p_Index++;
		}
	} 
	int temp=arr[p_Index];//logic to put pivot in its right place
	arr[p_Index]=arr[end];
	arr[end]=temp;
	return p_Index;//returning the index of partition
}
void quick_sort (long int arr[],int p,int q)
{
	if(p<q)//this will act as terminating case for recursion
	{
		int p_Index=partition(arr,p,q);//calling the partition function
		quick_sort(arr,p,p_Index-1);//recursive call
		quick_sort(arr,p_Index+1,q);//recursive call
	}
}
int main()
{
	int n, index;//index is for the index of pivot for first pass
	scanf("%d",&n);
	long int a[n];
	for(int i=0;i<n;i++)//taking input of elements in array seperared by ','
		scanf("%ld,",&a[i]);
	index=partition(a,0,n-1);//this is for index of pivot for first pass
	quick_sort(a,0,n-1);//calling quick_sort function
	for(int i=0;i<n;i++)//printing sorted array
		printf("%ld ",a[i]);
	printf("\n%d",index);
	return 0;
}
