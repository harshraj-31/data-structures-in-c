#include <stdio.h>

int interpolationSearch(int a[], int n, int val)
{
    int low = 0, high = n - 1, pos;

    // The array must be sorted, so val must be within the range of a[low] and a[high]
    while (low <= high && val >= a[low] && val <= a[high])
    {
        // If there is only one element left
        if (low == high)
        {
            if (a[low] == val)
            {
                return low;
            }
            return -1;
        }

        // Formula to find the position to probe
        pos = low + (((val - a[low]) * (high - low)) / (a[high] - a[low]));

        if (a[pos] == val)
        {
            return pos;
        }
        
        if (a[pos] < val)
        {
            low = pos + 1; // Search in the higher part
        }
        else
        {
            high = pos - 1; // Search in the lower part
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

    result = interpolationSearch(a, n, val);

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
