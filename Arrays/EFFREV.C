// Reverse an array without using another array

#include <stdio.h>
#include <conio.h>

int main()
{
    int arr[10];
    int i, n, temp;

    clrscr();

    // Ask how many elements the user wants
    printf("\n\tEnter the array size : ");
    scanf("%d", &n);

    // Take array elements from the user
    for(i = 0; i < n; i++)
    {
        printf("\n\tEnter the array %d: ", i);
        scanf("%d", &arr[i]);
    }

    // Display the original array
    printf("\n\tArray before reverse : ");

    for(i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    // Swap first with last, second with second-last, etc.
    for(i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }

    // Display the reversed array
    printf("\n\tArray after reverse : ");

    for(i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    getch();
    return 0;
}
