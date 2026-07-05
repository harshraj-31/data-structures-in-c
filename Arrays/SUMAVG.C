#include<stdio.h>
#include<conio.h>
int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int i,sum=0;
	float avg;
	clrscr();
	for(i=0;i<10;i++)
	{
		sum += arr[i];
	}
	avg=sum/10.0;
	printf("\n\tSum of array is : %d",sum);
	printf("\n\tAvg of array is : %.2f",avg);
	getch();
	return 0;
}