#include <stdio.h>
#include <conio.h>
#define MAX 50

int A[MAX], n;
void input()

{
    int i;
    printf("ENTER THE ELEMENTS IN ARRAY =>");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
	printf("A[%d] = ", i);
	scanf("%d", &A[i]);
    }
}

// Function to display array
void display()
{
    int i;
    printf("\nARRAY IS ");
    for(i=0; i<n; i++)
    {
	printf("%d ", A[i]);
    }
}

// Bubble Sort
void bubble()
{
    int i, j, temp;
    for(i=0; i<n-1; i++)
    {
	for(j=0; j<n-i-1; j++)
	{
	    if(A[j] > A[j+1])
	    {
		temp = A[j];
		A[j] = A[j+1];
		A[j+1] = temp;
	    }
	}
    }
}

// Selection Sort
void selection()
{
    int i, j, min, temp;
    for(i=0; i<n-1; i++)
    {
	min = i;
	for(j=i+1; j<n; j++)
	{
	    if(A[j] < A[min])
		min = j;
		temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}
    }
}

// Insertion Sort
void insertion()
{
    int i, j, key;
    for(i=1; i<n; i++)
    {
	key = A[i];
	j = i - 1;
	while(j >= 0 && A[j] > key)
	{
	    A[j+1] = A[j];
	    j--;
	}
	A[j+1] = key;
    }
}

// Shell Sort
void shell()
{
    int i, j, gap, temp;
    for(gap=n/2; gap>0; gap/=2)
    {
	for(i=gap; i<n; i++)
	{
	    temp = A[i];
	    for(j=i; j>=gap && A[j-gap]>temp; j-=gap)
		A[j] = A[j-gap];
	    A[j] = temp;
	}
    }
}

// Quick Sort
void quick(int low, int high)
{
    int i=low, j=high, pivot=A[low], temp;
    if(low < high)
    {
	while(i < j)
	{
	    while(A[i] <= pivot && i < high) i++;
	    while(A[j] > pivot) j--;
	    if(i < j)
	    {
		temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	    }
	}
		temp = A[low];
		A[low] = A[j];
		A[j] = temp;
		quick(low, j-1);
		quick(j+1, high);
    }
}

// Merge Sort
void merge(int low, int mid, int high)
{
    int i=low, j=mid+1, k=low, b[MAX];
    while(i<=mid && j<=high)
    {
	if(A[i] < A[j])
	    b[k++] = A[i++];
	else
	    b[k++] = A[j++];
    }
    while(i<=mid) b[k++] = A[i++];
    while(j<=high) b[k++] = A[j++];

    for(i=low; i<=high; i++)
	A[i] = b[i];
}

void mergesort(int low, int high)
{
    int mid;
    if(low < high) {
	mid = (low + high) / 2;
	mergesort(low, mid);
	mergesort(mid+1, high);
	merge(low, mid, high);
    }
}

// Heap Sort
void heapify(int n, int i)
{
    int largest = i, l = 2*i+1, r = 2*i+2, temp;
    if(l<n && A[l] > A[largest]) largest = l;
    if(r<n && A[r] > A[largest]) largest = r;

    if(largest != i)
    {
	temp = A[i];
	A[i] = A[largest];
	A[largest] = temp;
	heapify(n, largest);
    }
}

void heap()
{
    int i, temp;
    for(i=n/2-1; i>=0; i--)
	heapify(n, i);

    for(i=n-1; i>=0; i--)
    {
	temp = A[0];
	A[0] = A[i];
	A[i] = temp;
	heapify(i, 0);
    }
}

// Radix Sort
void radix() {
    int i, max=A[0], exp=1, b[MAX];
    for(i=1; i<n; i++)
	if(A[i] > max)
	    max = A[i];

    while(max/exp > 0)
    {
	int bucket[10]={0};

	for(i=0; i<n; i++)
	    bucket[(A[i]/exp)%10]++;

	for(i=1; i<10; i++)
	    bucket[i] += bucket[i-1];

	for(i=n-1; i>=0; i--)
	{
	    b[--bucket[(A[i]/exp)%10]] = A[i];
	}
	for(i=0; i<n; i++)
	    A[i] = b[i];

	exp *= 10;
    }
}

// Main Menu
void main()
{
    int ch;
    clrscr();
    input();
    do {
	printf("\n\n ---> SORTING MENU <--- ");
	printf("\n1. BUBBLE SORT");
	printf("\n2. SELECATION SORT");
	printf("\n3. INSERTATION SORT");
	printf("\n4. SHELL SORT");
	printf("\n5. QUICK SORT");
	printf("\n6. MERGE SORT");
	printf("\n7. HEAP SORT");
	printf("\n8. RADIX SORT");
	printf("\n0. EXIT");
	printf("\nENTER THE OPRATION ==>");
	scanf("%d", &ch);

	switch(ch)
	{
	    case 1: bubble(); break;
	    case 2: selection(); break;
	    case 3: insertion(); break;
	    case 4: shell(); break;
	    case 5: quick(0,n-1); break;
	    case 6: mergesort(0,n-1); break;
	    case 7: heap(); break;
	    case 8: radix(); break;
	    case 0: exit(0);

	}
	display();

    } while(ch != 0);
      getch();
}