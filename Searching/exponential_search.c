#include <stdio.h>

// Standard Binary Search used as a helper function
int binarySearch(int a[], int beg, int end, int val)
{
    int mid;

    while (beg <= end)
    {
        mid = (beg + end) / 2;

        if (a[mid] == val)
        {
            return mid;
        }
        else if (a[mid] > val)
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
    }

    return -1;
}

int exponentialSearch(int a[], int n, int val)
{
    int i = 1, end;

    // Check if the element is present at the very first position
    if (n > 0 && a[0] == val)
    {
        return 0;
    }

    // Find the range for binary search by doubling the index
    while (i < n && a[i] <= val)
    {
        i = i * 2;
    }

    // Set the correct upper bound for the binary search
    if (i < n)
    {
        end = i;
    }
    else
    {
        end = n - 1;
    }

    // Call binary search for the identified range [i / 2, end]
    return binarySearch(a, i / 2, end, val);
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

    result = exponentialSearch(a, n, val);

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
