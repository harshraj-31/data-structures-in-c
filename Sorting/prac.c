#include<stdio.h>

void insertionSort(int a[], int n)
{
    int i,j,key;
    for(i=1; i<n; i++)
    {
        key=a[i];
        j = i-1;
        while(j>=0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void bubbleSort(int a[], int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void selectionSort(int a[],int n)
{
    int i,j,temp,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j] < a[min])
            {
                min=j;
            }
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

void display(int a[], int n)
{
    int i;
    printf("\nArray: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

int main()
{
    int a[100],i,ch,n;
    printf("\nEnter the size: ");
    scanf("%d",&n);

    printf("\nEnter %d elements: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    while(1)
    {
        printf("\nSorting Menu");
        printf("\n1.Insertion Sort: ");
        printf("\n2.Bubble Sort: ");
        printf("\n3. Selection Sort: ");
        printf("\0.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:insertionSort(a,n);break;
            case 2:bubbleSort(a,n);break;
            case 3:selectionSort(a,n);break;
            case 0:printf("Exiting code..");return 0;
            default:printf("Invalid choice, try again");
        }

        printf("\nSorted Array: ");
        display(a,n);
    }
}