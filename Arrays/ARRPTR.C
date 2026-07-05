// Q1. wap to acces array elements using pointer.
// Q2. wap to allocate memeory using malloc()

#include<stdio.h>
#include<conio.h>
int main()
{
	int arr[5],i;
	int *ptr;
	clrscr();
	ptr = arr;
	printf("Enter 5 elements: \n");flushall();
	for(i=0;i<5;i++)
	{
		scanf("\n%d",ptr[i]);
	}
	for(i=0;i<5;i++)
	{
		printf("\n %d ",ptr[i]);
	}
	getch();
	return 0;
}