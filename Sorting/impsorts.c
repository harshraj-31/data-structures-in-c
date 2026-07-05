#include <stdio.h>


// --------- Functions ---------

void insertionSort(int a[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) 
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void bubbleSort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1; j++) 
        {
            if (a[j] > a[j + 1]) 
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int a[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) 
    {
        min = i;
        for (j = i + 1; j < n; j++) 
        {
            if (a[j] < a[min])
            min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void shellSort(int a[], int n) 
{
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) 
    {
        for (i = gap; i < n; i++) 
        {
            temp = a[i];
            j = i;
            while (j >= gap && a[j - gap] > temp) 
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = temp;
        }
    }
}


// Quick Sort
int partition(int a[], int low, int high) {
    int pivot = a[low], i = low + 1, j = high, temp;

    while (1) {
        while (i <= high && a[i] <= pivot) i++;
        while (a[j] > pivot) j--;

        if (i < j) {
            temp = a[i]; a[i] = a[j]; a[j] = temp;
        } else break;
    }

    temp = a[low]; a[low] = a[j]; a[j] = temp;
    return j;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}


// Merge Sort
void merge(int a[], int l, int m, int r) {
    int temp[100], i = l, j = m + 1, k = 0;

    while (i <= m && j <= r) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

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

// Display
void display(int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

// --------- Main ---------

int main() {
    int a[100], n, choice, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    while(1){
    printf("\n1. Insertion Sort");
    printf("\n2. Bubble Sort");
    printf("\n3. Selection Sort");
    printf("\n4. Shell Sort");
    printf("\n5. Quick Sort");
    printf("\n6. Merge Sort");
    printf("\n0.Exit");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: insertionSort(a, n); break;
        case 2: bubbleSort(a, n); break;
        case 3: selectionSort(a, n); break;
        case 4: shellSort(a, n); break;
        case 5: quickSort(a, 0, n - 1); break;
        case 6: mergeSort(a, 0, n - 1); break;
        case 0: printf("Exiting Code...");return 0;
        default: printf("Invalid choice");
    }

    printf("\nSorted array:\n");
    display(a, n);
    }
    return 0;
}