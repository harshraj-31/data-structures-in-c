#include<stdio.h>
#include<conio.h>
void sum();
int main()
{
	clrscr();
	sum();
	getch();
	return 0;
}
void sum()
{
	int n,count=0,sum=0,temp,digit;
	printf("\nEnter the number :");
	scanf("%d",&n);
	temp=n;
	while(temp != 0)
	{
		       digit = temp % 10;
		       sum = sum + digit;
		       count++;
		       temp = temp / 10;
	}
	printf("\n Sum of digits is : %d",sum);
	printf("\n Count of digits is : %d",count);
}