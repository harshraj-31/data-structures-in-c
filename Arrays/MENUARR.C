//wap to delete the element from array based on address
#include<stdio.h>
#include<conio.h>

int main()
{
	int a[100],i,n,ch,pos,ele;
	clrscr();
	printf("\nEnter the size of array :");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("\nEnter the element of a[%d] :",i);
		scanf("%d",&a[i]);
	}
	while(ch != 4)
	{
		printf("\nEnter your  choice....");
		printf("\n1.Print array.........");
		printf("\n2.Insert in array.....");
		printf("\n3.Delete in array.....");
		printf("\n4.Exit................");
		printf("\nEnter the your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nElements of array are :");
				for(i=0;i<n;i++)
				{
					printf("\n|%d|",a[i]);
				}
				break;
			case 2:
				printf("\nEnter the postion of element you want to insert :");
				scanf("%d",&pos);
				printf("\nEnter the element you want to insert :");
				scanf("%d",&ele);
				if(pos < 0 || pos > n)
				{
					printf("\nEnter  valid position!!!");
					break;
				}
				else
				{
					for(i=n;i>=pos;i--)
					{
						a[i]=a[i-1];
					}
					a[pos-1]=ele;
					n++;
					printf("\n Element inserted successfully...");
				}
				break;

			case 3:
				printf("\n\tEnter the postion:");
				scanf("%d",&pos);
				if(pos < 0 || pos > n)
				{
					printf("\n Invalid position ");
				}
				else
				{
					for(i=pos-1;i<n-1;i++)
					{
						a[i]=a[i+1];
					}
					n--;
					printf("\n Element deleted successfully...");
				}
				break;
				
			case 4:
				printf("\n\tExiting program");
				return 0;

			default:
				printf("\n\tEnter valid choice");
				break;
		}
	}
	getch();
	return 0;
}