/*
 * Merge Sorted Lists
 */

#include <stdio.h>

int main()
{
    int a[] = {1, 3, 5, 7};
    int b[] = {2, 4, 6, 8};

    int c[8];
    int n1 = 4, n2 = 4;
    int i = 0, j = 0, k = 0;

    // Compare elements and add the smaller one
    while(i < n1 && j < n2)
    {
        if(a[i] < b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }

        k++;
    }

    // Add remaining elements of first array
    while(i < n1)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    // Add remaining elements of second array
    while(j < n2)
    {
        c[k] = b[j];
        j++;
        k++;
    }

    // Display merged sorted array
    printf("Merged Sorted Array: ");

    for(i = 0; i < n1 + n2; i++)
    {
        printf("%d ", c[i]);
    }

    return 0;
}
