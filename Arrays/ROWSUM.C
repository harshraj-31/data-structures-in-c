#include<stdio.h>
#include<conio.h>
int main()
{
	int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int i,j,r=0,c=0,csum[3],rsum[3];
	clrscr();
	for(i=0;i<3;i++)
	{
		r=0;
		for(j=0;j<3;j++)
		{
			r=r+arr[i][j];
		}
		rsum[i]=r;
	}
	for(j=0;j<3;j++)
	{
		c=0;
		for(i=0;i<3;i++)
		{
			c=c+arr[i][j];
		}
		csum[j]=c;
	}
	//prints sum of row and rows
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf("\t %d",arr[i][j]);
		}
		printf("\t = %d",rsum[i]);
	}
	//prints sum of column

	printf("\n\t =\t =\t =");
	printf("\n");
	for(j=0;j<3;j++)
		{
			printf("\t %d",csum[j]);
		}

	getch();
	return 0;
}