/*
 * Radix Sort
 * Starter template
 */
#include <stdio.h>

#define MAX 100

void radixSort(int a[], int n) {
    int bucket[10][MAX], count[10];
    int i, j, k, div = 1, max = a[0];

    // Find the maximum number to know the number of digits
    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    // Loop for each digit (ones, tens, hundreds, etc.)
    while (max / div > 0) {
        // Initialize bucket counts to 0
        for (i = 0; i < 10; i++)
            count[i] = 0;

        // Scatter elements into buckets based on the current digit
        for (i = 0; i < n; i++) {
            int digit = (a[i] / div) % 10;
            bucket[digit][count[digit]++] = a[i];
        }

        // Gather elements back into the original array
        k = 0;
        for (i = 0; i < 10; i++)
            for (j = 0; j < count[i]; j++)
                a[k++] = bucket[i][j];

        // Move to the next significant digit
        div *= 10;
    }
}

int main() {
    int a[MAX], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    radixSort(a, n);

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    
    printf("\n");

    return 0;
}
