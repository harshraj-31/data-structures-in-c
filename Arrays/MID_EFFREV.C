#include<stdio.h>
#include<conio.h>
int main()
{
    int arr[10];
    int i,n,temp;
    clrscr();
    printf("\n\tEnter the array size :");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
	    printf("\n\tEnter the array %d:",i);
	    scanf(" %d",&arr[i]);
    }

        printf("\n\tArray before reverse : ");
    for(i=0;i<n;i++)
    {
	    printf(" %d",arr[i]);
    }
    
    for(i=0;i<n/2;i++)
    {
    	temp=arr[i];
	    arr[i]=arr[n-i-1];
	    arr[n-i-1]=temp;
    }

    printf("\n\tArray after reverse : ");
    
    for(i=0;i<n;i++)
    {
	    printf(" %d",arr[i]);
    }
    getch();
    return 0;
}
