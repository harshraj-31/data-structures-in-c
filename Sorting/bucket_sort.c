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
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bucketSort()
{
    int i, j, k;
    int buckets[10][MAX]; // 10 buckets
    int count[10] = {0};  // To keep track of the number of elements in each bucket
    int max = A[0];

    // Find the maximum element to determine the mapping range
    for (i = 1; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }

    // Phase 1 (Scatter): Distribute elements into the 10 buckets
    for (i = 0; i < n; i++)
    {
        // Formula to evenly distribute values into index 0 to 9
        int bucketIndex = (10 * A[i]) / (max + 1);
        buckets[bucketIndex][count[bucketIndex]++] = A[i];
    }

    // Phase 2: Sort individual buckets (using simple Bubble Sort here)
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < count[i] - 1; j++)
        {
            for (k = 0; k < count[i] - j - 1; k++)
            {
                if (buckets[i][k] > buckets[i][k + 1])
                {
                    int temp = buckets[i][k];
                    buckets[i][k] = buckets[i][k + 1];
                    buckets[i][k + 1] = temp;
                }
            }
        }
    }

    // Phase 3 (Gather): Put sorted elements back into the main array
    int index = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < count[i]; j++)
        {
            A[index++] = buckets[i][j];
        }
    }
}

int main()
{
    input();

    printf("\nBefore Sorting: ");
    display();

    bucketSort();

    printf("\nAfter Sorting:  ");
    display();

    return 0;
}
