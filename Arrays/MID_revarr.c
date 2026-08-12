// WAP to reverse an array and store it in another array

#include <stdio.h>
#include <conio.h>

int main()
{
    int arr[10];
    int rev[10];
    int i, n;

    clrscr();

    printf("\n\tEnter the array size : ");
    scanf("%d", &n);

    // Take array elements
    for(i = 0; i < n; i++)
    {
        printf("\n\tEnter the array %d: ", i);
        scanf("%d", &arr[i]);
    }

    // Store elements in reverse order
    for(i = 0; i < n; i++)
    {
        rev[i] = arr[n - i - 1];
    }

    // Display original array
    printf("\n\tArray before reverse : ");

    for(i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    // Display reversed array
    printf("\n\tArray after reverse : ");

    for(i = 0; i < n; i++)
    {
        printf(" %d", rev[i]);
    }

    getch();
    return 0;
}
