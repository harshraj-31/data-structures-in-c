#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100

int a[MAX], n;

/* ---------- FUNCTION DECLARATIONS ---------- */
void input();
void display();
void insertionSort();
void selectionSort();
void quickSort(int[], int, int);
int partition(int[], int, int);
void shellSort();
void heapSort();
void heapify(int[], int, int);
void radixSort();
void mergeSort(int[], int, int);
void merge(int[], int, int, int);
void binarySearch();

/* ---------- MAIN ---------- */
void main()
{
    int ch;
    clrscr();

    do
    {
        printf("\n\n===== MENU =====");
        printf("\n1. Input Array");
        printf("\n2. Display Array");
        printf("\n3. Insertion Sort");
        printf("\n4. Selection Sort");
        printf("\n5. Quick Sort");
        printf("\n6. Shell Sort");
        printf("\n7. Heap Sort");
        printf("\n8. Radix Sort");
        printf("\n9. Merge Sort");
        printf("\n10. Binary Search");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: input(); break;
            case 2: display(); break;
            case 3: insertionSort(); break;
            case 4: selectionSort(); break;
            case 5: quickSort(a,0,n-1);
                    printf("\nSorted using Quick Sort"); break;
            case 6: shellSort(); break;
            case 7: heapSort(); break;
            case 8: radixSort(); break;
            case 9: mergeSort(a,0,n-1);
                    printf("\nSorted using Merge Sort"); break;
            case 10: binarySearch(); break;
            case 0: exit(0);
            default: printf("\nInvalid choice!");
        }

    } while(ch!=0);
}

/* ---------- INPUT ---------- */
void input()
{
    int i;
    printf("\nEnter number of elements: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }
}

/* ---------- DISPLAY ---------- */
void display()
{
    int i;
    printf("\nArray: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

/* ---------- INSERTION SORT ---------- */
void insertionSort()
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    printf("\nSorted using Insertion Sort");
}

/* ---------- SELECTION SORT ---------- */
void selectionSort()
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
            if(a[j]<a[min])
                min=j;

        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    printf("\nSorted using Selection Sort");
}

/* ---------- QUICK SORT ---------- */
void quickSort(int a[], int low, int high)
{
    int p;
    if(low<high)
    {
        p = partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}

int partition(int a[], int low, int high)
{
    int pivot=a[low], i=low+1, j=high, temp;

    while(i<=j)
    {
        while(i<=high && a[i]<=pivot) i++;
        while(a[j]>pivot) j--;

        if(i<j)
        {
            temp=a[i]; a[i]=a[j]; a[j]=temp;
        }
    }

    temp=a[low];
    a[low]=a[j];
    a[j]=temp;

    return j;
}

/* ---------- SHELL SORT ---------- */
void shellSort()
{
    int gap,i,j,temp;

    for(gap=n/2; gap>0; gap/=2)
    {
        for(i=gap;i<n;i++)
        {
            temp=a[i];
            for(j=i; j>=gap && a[j-gap]>temp; j-=gap)
                a[j]=a[j-gap];

            a[j]=temp;
        }
    }
    printf("\nSorted using Shell Sort");
}

/* ---------- HEAP SORT ---------- */
void heapify(int a[], int n, int i)
{
    int largest=i, l=2*i+1, r=2*i+2, temp;

    if(l<n && a[l]>a[largest]) largest=l;
    if(r<n && a[r]>a[largest]) largest=r;

    if(largest!=i)
    {
        temp=a[i]; a[i]=a[largest]; a[largest]=temp;
        heapify(a,n,largest);
    }
}

void heapSort()
{
    int i,temp;

    for(i=n/2-1;i>=0;i--)
        heapify(a,n,i);

    for(i=n-1;i>0;i--)
    {
        temp=a[0]; a[0]=a[i]; a[i]=temp;
        heapify(a,i,0);
    }
    printf("\nSorted using Heap Sort");
}

/* ---------- RADIX SORT ---------- */
void radixSort()
{
    int bucket[10][MAX], count[10];
    int i,j,k,div=1,max=a[0];

    for(i=1;i<n;i++)
        if(a[i]>max) max=a[i];

    while(max/div>0)
    {
        for(i=0;i<10;i++) count[i]=0;

        for(i=0;i<n;i++)
        {
            int digit=(a[i]/div)%10;
            bucket[digit][count[digit]++] = a[i];
        }

        k=0;
        for(i=0;i<10;i++)
            for(j=0;j<count[i];j++)
                a[k++] = bucket[i][j];

        div*=10;
    }
    printf("\nSorted using Radix Sort");
}

/* ---------- MERGE SORT ---------- */
void mergeSort(int a[], int low, int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void merge(int a[], int low, int mid, int high)
{
    int i=low,j=mid+1,k=low;
    int temp[MAX];

    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }

    while(i<=mid)
        temp[k++]=a[i++];

    while(j<=high)
        temp[k++]=a[j++];

    for(i=low;i<=high;i++)
        a[i]=temp[i];
}

/* ---------- BINARY SEARCH ---------- */
void binarySearch()
{
    int beg=0,end=n-1,mid,val,found=0,i,j,temp;

    /* AUTO SORT */
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }

    printf("\nSorted array:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\nEnter value to search: ");
    scanf("%d",&val);

    while(beg<=end)
    {
        mid=(beg+end)/2;

        if(a[mid]==val)
        {
            printf("\n%d found at position %d",val,mid+1);
            found=1;
            break;
        }
        else if(a[mid]>val)
            end=mid-1;
        else
            beg=mid+1;
    }

    if(!found)
        printf("\nElement not found!");
}