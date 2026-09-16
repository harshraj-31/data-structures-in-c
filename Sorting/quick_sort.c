/*
 * Quick Sort
 * Author: Harshrajsinh Zala
 * Description: Quick sort.
 */
#include <stdio.h>

int partition(int a[], int low, int high) {
    int pivot = a[low], i = low + 1, j = high, temp;

    while (i <= j) {
        // Find element greater than pivot
        while (i <= high && a[i] <= pivot) i++;
        
        // Find element smaller than or equal to pivot
        while (a[j] > pivot) j--;

        // Swap if pointers have not crossed
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // Place pivot in its correct sorted position
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main() {
    int a[100], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quickSort(a, 0, n - 1);

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    
    printf("\n");

    return 0;
}
