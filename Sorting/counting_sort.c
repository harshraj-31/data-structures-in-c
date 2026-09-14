#include <stdio.h>

#define MAX 50

int A[MAX], n;

void input()
{
    int i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }
}

void display()
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    
    printf("\n");
}

void countingSort()
{
    int output[MAX];
    int count[1000]; // Assuming max value won't exceed 1000 for practical exams
    int i, max = A[0];

    // Find the maximum element
    for (i = 1; i < n; i++)
        if (A[i] > max)
            max = A[i];

    // Initialize the count array with 0
    for (i = 0; i <= max; i++)
        count[i] = 0;

    // Store the count of each element
    for (i = 0; i < n; i++)
        count[A[i]]++;

    // Modify count array to store the cumulative sum (positions)
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Build the output array (looping backwards maintains stability)
    for (i = n - 1; i >= 0; i--)
    {
        output[count[A[i]] - 1] = A[i];
        count[A[i]]--;
    }

    // Copy the sorted elements back to original array
    for (i = 0; i < n; i++)
        A[i] = output[i];
}

int main()
{
    input();

    printf("\nBefore Sorting: ");
    display();

    countingSort();

    printf("\nAfter Sorting:  ");
    display();

    return 0;
}
