#include <stdio.h>
int selection_sort()
{
	long int a[20];int cmp=0;int swap=0;//cmp and swap are for number of comparisions and swap respectively
	for(int i=0;i<20;i++)
		scanf("%ld,",&a[i]);//taking input in array seperated by ','
	for(int i=0;i<19;i++)
	{
		long int temp=0;int index=i;//index will store the index of smallest number for each iteration
		for(int j=i+1;j<20;j++)
		{
			cmp++;
			if(a[j]<a[index])
				index=j;
		}
		swap++;
		temp=a[i];//putting the smallest number in its right place
		a[i]=a[index];
		a[index]=temp;
	}
	for(int i=0;i<20;i++)//printing the sorted array
		printf("%ld ",a[i]);
	printf("\n%d %d",swap,cmp);
	return 0;
}
int main()
{
	selection_sort();//calling the sorting function here
	return 0;
}
