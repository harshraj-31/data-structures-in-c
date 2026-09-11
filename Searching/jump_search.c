/*
 * Jump Search
 * Author: Harshrajsinh Zala
 * Description: Jump search.
 */
#include <stdio.h>
#include <math.h>

int jumpSearch(int a[], int n, int val)
{
    // The optimal step size is the square root of the array size
    int step = sqrt(n);
    int prev = 0;

    // Jump ahead by 'step' until we find a block that could contain the value
    while (a[(step < n ? step : n) - 1] < val)
    {
        prev = step;
        step = step + sqrt(n);
        
        // If we have jumped past the end of the array, the element is not here
        if (prev >= n)
        {
            return -1;
        }
    }

    // Perform a standard Linear Search within the identified block
    while (a[prev] < val)
    {
        prev++;
        
        // If we reach the end of the block or the array without finding it
        if (prev == (step < n ? step : n))
        {
            return -1;
        }
    }

    // If the element is found
    if (a[prev] == val)
    {
        return prev;
    }

    return -1;
}

int main()
{
    int a[50], n, i, val, result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements in sorted order:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the value to search: ");
    scanf("%d", &val);

    result = jumpSearch(a, n, val);

    if (result != -1)
    {
        printf("\nELEMENT FOUND AT POSITION => %d\n", result + 1);
    }
    else
    {
        printf("\nELEMENT NOT FOUND\n");
    }

    return 0;
}
