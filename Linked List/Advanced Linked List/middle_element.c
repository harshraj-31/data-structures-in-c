/*
 * Find Middle Element of an Array
 */

#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int middle;

    // Find the middle index
    middle = n / 2;

    printf("Middle Element: %d", arr[middle]);

    return 0;
}
