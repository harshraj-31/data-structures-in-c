//WAP to allocate memory using malloc()

#include<stdio.h>
#include<conio.h>
int main()
{
	int *a;
	int i;
	clrscr();
	a = malloc(5 * sizeof(int));
	printf("\nEnter 5 elemnets: \n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nThe elements are: ");
	for(i=0;i<5;i++)
	{
		printf("%d ",a[i]);
	}
	getch();
	return 0;
}