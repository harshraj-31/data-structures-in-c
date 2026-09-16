/*
 * Shell Sort
 * Starter template
 */
#include <stdio.h>

void shellSort(int a[], int n) {
    int gap, i, j, temp;

    // Start with a large gap, then reduce the gap by half each time
    for (gap = n / 2; gap > 0; gap /= 2)
        // Do a gapped insertion sort for this gap size
        for (i = gap; i < n; i++) {
            temp = a[i];
            j = i;

            // Shift earlier gap-sorted elements up until the correct location is found
            while (j >= gap && a[j - gap] > temp) {
                a[j] = a[j - gap];
                j -= gap;
            }

            // Put the temp variable in its correct location
            a[j] = temp;
        }
}

int main() {
    int a[100], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    shellSort(a, n);

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    
    printf("\n");

    return 0;
}
