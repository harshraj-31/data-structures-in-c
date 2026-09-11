#include <stdio.h>

// Helper function to find the minimum of two numbers
int min(int x, int y)
{
    return (x <= y) ? x : y;
}

int fibonacciSearch(int a[], int n, int val)
{
    // Initialize Fibonacci numbers
    int fib2 = 0;             // (m-2)'th Fibonacci Number
    int fib1 = 1;             // (m-1)'th Fibonacci Number
    int fib = fib2 + fib1;    // m'th Fibonacci Number

    // Find the smallest Fibonacci Number greater than or equal to n
    while (fib < n)
    {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    // Marks the eliminated range from front
    int offset = -1;

    // While there are elements to be inspected
    while (fib > 1)
    {
        // Check if fib2 is a valid index
        int i = min(offset + fib2, n - 1);

        // If val is greater than the value at index i, cut the subarray array from offset to i
        if (a[i] < val)
        {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        // If val is less than the value at index i, cut the subarray after i+1
        else if (a[i] > val)
        {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        // Element found
        else
        {
            return i;
        }
    }

    // Compare the last remaining element
    if (fib1 == 1 && a[offset + 1] == val)
    {
        return offset + 1;
    }

    // Element not found
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

    result = fibonacciSearch(a, n, val);

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
