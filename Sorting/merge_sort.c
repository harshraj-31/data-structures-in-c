/*
 * Merge Sort
 * Author: Harshrajsinh Zala
 * Description: Merge sort.
 */
#include <stdio.h>

void merge(int a[], int l, int m, int r) {
    int temp[100], i = l, j = m + 1, k = 0;

    // Compare and merge the two halves into temp[]
    while (i <= m && j <= r)
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];

    // Copy any remaining elements from the left half
    while (i <= m) temp[k++] = a[i++];
    
    // Copy any remaining elements from the right half
    while (j <= r) temp[k++] = a[j++];

    // Copy the sorted elements back into the original array
    for (i = l, k = 0; i <= r; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mergeSort(a, 0, n - 1);

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    
    printf("\n");

    return 0;
}
