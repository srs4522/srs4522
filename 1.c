#include<stdio.h>
int bubble_sort()
{
	long int a[20];int cmp=0;int swap=0;
	for(int i=0;i<20;i++)
		scanf("%ld,", &a[i]);//taking input in array separated by ‘,’
	for(int i=19;i>0;i--)
	{
		for(int j=0;j<i;j++)
		{
			cmp++;long int temp=0;//cmp is for number of comparisions
			if(a[j]>a[j+1])//if previous number greater then swap
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				swap++;//swap is for number of swaps
			}
		}
	}
	for(int i=0;i<20;i++)//printing the sorted array
		printf("%ld ",a[i]);
	printf("\n%d %d",swap,cmp);
	return 0;
}
int main()
{
	bubble_sort();//calling the sort function
	return 0;
}
