#include<stdio.h>
#include<stdlib.h>
#define MAX 5000

void createarray(int no[])
{
    int i;
    for(i=0;i<MAX;i++)
    {
	no[i] = i + 1;
    }
}

void displayarray(int no[])
{
    int i;
    for(i=0;i<MAX;i++)
    {
        printf("\t%d", no[i]);
    }
}
void binarysearch(int no[], int val)
{
    int beg = 0, end = MAX - 1, mid, iteration = 0;

    while(beg <= end)
    {
        mid = (beg + end) / 2;
	iteration++;
	printf("\nbeg=%d \tmid=%d \tend=%d", beg, mid, end);
        if(no[mid] == val)
        {
            printf("\n%d FOUND \t ITERATION=%d", val, iteration);
            return;
        }
        else if(no[mid] > val)
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
    }

    printf("\n%d NOT FOUND", val);
}

int main()
{
    int no[MAX],val;
    clrscr();
    createarray(no);
    displayarray(no);

    printf("\n\nENTER THE VALUE FOR SEARCH => ");
    scanf("%d", &val);

    binarysearch(no, val);
	getch();
    return 0;
}