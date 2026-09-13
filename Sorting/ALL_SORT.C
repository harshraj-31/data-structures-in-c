#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int a[MAX], n;

/* ---------- FUNCTION DECLARATIONS ---------- */
void input();
void display();
void swap(int *x, int *y);

void insertionSort();
void insertionSortRange(int arr[], int low, int high); // Helper for hybrids
void selectionSort();
void quickSort(int arr[], int low, int high);
void shellSort();
void heapSort();
void radixSort();
void mergeSort(int arr[], int temp[], int low, int high);
void runMergeSort(); // Wrapper for optimized Merge Sort
void binarySearch();

/* ---------- MAIN ---------- */
int main()
{
    int ch;
    
    do
    {
        printf("\n\n===== MENU =====");
        printf("\n1. Input Array");
        printf("\n2. Display Array");
        printf("\n3. Insertion Sort");
        printf("\n4. Selection Sort");
        printf("\n5. Quick Sort (Optimized)");
        printf("\n6. Shell Sort (Ciura's Gaps)");
        printf("\n7. Heap Sort (Iterative)");
        printf("\n8. Radix Sort (O(n) Space)");
        printf("\n9. Merge Sort (Optimized)");
        printf("\n10. Binary Search");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:  input(); break;
            case 2:  display(); break;
            case 3:  
                insertionSort(); 
                printf("\nSorted using Insertion Sort");
                display(); 
                break;
            case 4:  
                selectionSort(); 
                printf("\nSorted using Selection Sort");
                display(); 
                break;
            case 5:  
                quickSort(a, 0, n - 1);
                printf("\nSorted using Optimized Quick Sort"); 
                display(); 
                break;
            case 6:  
                shellSort(); 
                printf("\nSorted using Optimized Shell Sort");
                display(); 
                break;
            case 7:  
                heapSort(); 
                printf("\nSorted using Optimized Heap Sort");
                display(); 
                break;
            case 8:  
                radixSort(); 
                printf("\nSorted using Optimized Radix Sort");
                display(); 
                break;
            case 9:  
                runMergeSort();
                printf("\nSorted using Optimized Merge Sort"); 
                display(); 
                break;
            case 10: 
                binarySearch(); 
                break;
            case 0:  
                return 0;
            default: 
                printf("\nInvalid choice!");
        }
    } while(ch != 0);

    return 0;
}

/* ---------- UTILITIES ---------- */
void input()
{
    printf("\nEnter number of elements: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
}

void display()
{
    printf("\nArray: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

/* ---------- 1. INSERTION SORT ---------- */
// Optimal for small datasets and almost-sorted arrays
void insertionSort() {
    insertionSortRange(a, 0, n - 1);
}

void insertionSortRange(int arr[], int low, int high) {
    for(int i = low + 1; i <= high; i++) {
        int temp = arr[i];
        int j = i - 1;
        while(j >= low && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

/* ---------- 2. SELECTION SORT ---------- */
void selectionSort() {
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[min]) min = j;
        }
        if (min != i) swap(&a[i], &a[min]);
    }
}

/* ---------- 3. OPTIMIZED QUICK SORT ---------- */
// Uses Median-of-3, Tail-call elimination, and Insertion Sort threshold
int medianOf3(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid]) swap(&arr[low], &arr[mid]);
    if (arr[low] > arr[high]) swap(&arr[low], &arr[high]);
    if (arr[mid] > arr[high]) swap(&arr[mid], &arr[high]);
    return mid;
}

void quickSort(int arr[], int low, int high) {
    while (low < high) {
        // Fallback to insertion sort for small arrays
        if (high - low < 10) {
            insertionSortRange(arr, low, high);
            break;
        }
        
        int mid = medianOf3(arr, low, high);
        swap(&arr[mid], &arr[high]); 
        int pivot = arr[high];
        
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        int p = i + 1;

        // Tail Call Optimization (always recurse on smaller half)
        if (p - low < high - p) {
            quickSort(arr, low, p - 1);
            low = p + 1;
        } else {
            quickSort(arr, p + 1, high);
            high = p - 1;
        }
    }
}

/* ---------- 4. OPTIMIZED SHELL SORT ---------- */
// Uses Ciura's Gap Sequence (Mathematically fastest known sequence)
void shellSort() {
    int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1}; 
    int num_gaps = 8;
    
    for(int k = 0; k < num_gaps; k++) {
        int gap = gaps[k];
        if (gap > n) continue;
        
        for(int i = gap; i < n; i++) {
            int temp = a[i];
            int j;
            for(j = i; j >= gap && a[j - gap] > temp; j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}

/* ---------- 5. OPTIMIZED HEAP SORT ---------- */
// Uses Iterative Heapify to prevent recursive call overhead
void heapifyIterative(int arr[], int size, int i) {
    int temp = arr[i];
    while (2 * i + 1 < size) {
        int child = 2 * i + 1; 
        if (child + 1 < size && arr[child + 1] > arr[child]) {
            child++; 
        }
        if (temp >= arr[child]) break; 
        arr[i] = arr[child];
        i = child;
    }
    arr[i] = temp;
}

void heapSort() {
    for(int i = n / 2 - 1; i >= 0; i--)
        heapifyIterative(a, n, i);

    for(int i = n - 1; i > 0; i--) {
        swap(&a[0], &a[i]);
        heapifyIterative(a, i, 0);
    }
}

/* ---------- 6. OPTIMIZED RADIX SORT ---------- */
// Uses 1D Counting Arrays instead of massive 2D matrices for Cache efficiency
void radixSort() {
    if (n <= 0) return;
    int max = a[0];
    for(int i = 1; i < n; i++) 
        if(a[i] > max) max = a[i];

    int* output = (int*)malloc(n * sizeof(int));
    
    for (int exp = 1; max / exp > 0; exp *= 10) {
        int count[10] = {0};

        for (int i = 0; i < n; i++) count[(a[i] / exp) % 10]++;
        for (int i = 1; i < 10; i++) count[i] += count[i - 1];
        
        for (int i = n - 1; i >= 0; i--) {
            output[count[(a[i] / exp) % 10] - 1] = a[i];
            count[(a[i] / exp) % 10]--;
        }
        
        for (int i = 0; i < n; i++) a[i] = output[i];
    }
    free(output);
}

/* ---------- 7. OPTIMIZED MERGE SORT ---------- */
// Single allocation, insertion hybrid, and early exit check
void mergeSort(int arr[], int temp[], int low, int high) {
    if (high - low < 10) {
        insertionSortRange(arr, low, high);
        return;
    }
    
    int mid = low + (high - low) / 2;
    mergeSort(arr, temp, low, mid);
    mergeSort(arr, temp, mid + 1, high);
    
    if (arr[mid] <= arr[mid + 1]) return; // Early exit if already sorted

    int i = low, j = mid + 1, k = low;
    while(i <= mid && j <= high)
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
        
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= high) temp[k++] = arr[j++];
    
    for(i = low; i <= high; i++) arr[i] = temp[i];
}

void runMergeSort() {
    int* temp = (int*)malloc(n * sizeof(int));
    mergeSort(a, temp, 0, n - 1);
    free(temp);
}

/* ---------- 8. BINARY SEARCH ---------- */
void binarySearch() {
    int beg = 0, end = n - 1, mid, val;
    
    // Auto-sort efficiently before searching
    insertionSortRange(a, 0, n - 1); 

    printf("\nSorted array for Binary Search:\n");
    display();

    printf("\nEnter value to search: ");
    scanf("%d", &val);

    while(beg <= end) {
        mid = beg + (end - beg) / 2; // Prevents overflow

        if(a[mid] == val) {
            printf("\n%d found at position %d\n", val, mid + 1);
            return;
        } else if(a[mid] > val) {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }
    printf("\nElement not found!\n");
}
