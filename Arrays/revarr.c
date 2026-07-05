//wap to reverse an array and store in another
#include<stdio.h>
#include<conio.h>
int main()

{
    int arr[10];
    int rev[10];
    int i,j=0,n;
    clrscr();
    printf("\n\tEnter the array size :");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
	printf("\n\tEnter the array %d:",i);
	scanf(" %d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
	rev[i]=arr[n-i-1];
    }
    printf("\n\tArray before reverse : ");
    for(i=0;i<n;i++)
    {
	printf(" %d",arr[i]);
    }
    printf("\n\tArray after reverse : ");
    for(i=0;i<n;i++)
    {
	printf(" %d",rev[i]);
    }
    getch();
    return 0;
}