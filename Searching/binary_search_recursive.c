#include <stdio.h>

int binarySearchRecursive(int a[], int beg, int end, int val)
{
    int mid;

    // Base condition: if the search space is valid
    if (beg <= end)
    {
        mid = (beg + end) / 2;

        if (a[mid] == val)
        {
            return mid; // Element found
        }
        else if (a[mid] > val)
        {
            // Search in the left half
            return binarySearchRecursive(a, beg, mid - 1, val);
        }
        else
        {
            // Search in the right half
            return binarySearchRecursive(a, mid + 1, end, val);
        }
    }

    return -1; // Element not found
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

    // Call the recursive function
    result = binarySearchRecursive(a, 0, n - 1, val);

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
