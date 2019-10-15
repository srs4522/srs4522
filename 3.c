#include<stdio.h>
#include<stdlib.h>
int count=0;//count is for storing the number of times merge function is called
void merge(long int arr[],int start,int mid,int end)
{
	int i=0,j=0,k=0;long int l[mid+1],r[mid+1];
	while(i<(mid-start+1))//copying elements for left part
	{	
		l[i]=arr[start+i];
		i++;
	}
	while(j<(end-mid))//copying elements for right part
	{
		r[j]=arr[mid+1+j];
		j++;
	}
	i=0;j=0;k=start;
	while(i<(mid-start+1) && j<(end-mid))//merging left and right parts into array arr
	{
		if(l[i]<=r[j])
		{
			arr[k]=l[i];
			i++;
		}
		else
		{
			arr[k]=r[j];
			j++;
		}
		k++;
	}
	while(i<(mid-start+1))//this will execute if elements in right are over but not in left part
	{
		arr[k]=l[i];
		i++;
		k++;
	}
	while(j<(end-mid))//this will execute if elements in left part are over but not in right
	{
		arr[k]=r[j];
		j++;
		k++;
	}
}

void merge_sort(long int arr[],int p,int q)
{

	if(p<q)//this will act as the terminating case for recursion 
	{
		int mid=p+(q-p)/2;
		merge_sort(arr,p,mid);//recursive call for merge_sort function
		merge_sort(arr,mid+1,q);//recursive call for merge_sort function
		merge(arr,p,mid,q);//calling merge function
		count++;//count is for number of calls to merge function
	}
}

int main()
{
	int n;
	scanf("%d",&n);//taking input the number of elements in array
	long int a[n];
	for(int i=0;i<n;i++)//taking input in array seperated by ','
		scanf("%ld,",&a[i]);
	merge_sort(a,0,n-1);//calling merge_sort function 
	for(int i=0;i<n;i++)//printing sorted array
		printf("%ld ",a[i]);
	printf("\n%d",count);
	return 0;
}
