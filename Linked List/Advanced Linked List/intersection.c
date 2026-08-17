/*
 * Intersection of Two Arrays
 */

#include <stdio.h>

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {3, 4, 5, 6, 7};

    int n1 = 5, n2 = 5;
    int i, j;

    printf("Intersection: ");

    // Compare each element of first array with second
    for(i = 0; i < n1; i++)
    {
        for(j = 0; j < n2; j++)
        {
            if(a[i] == b[j])
            {
                printf("%d ", a[i]);
                break;
            }
        }
    }

    return 0;
}
