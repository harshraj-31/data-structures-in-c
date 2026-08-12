// Q1. WAP to access array elements using pointer

#include <stdio.h>
#include <conio.h>

int main()
{
    int arr[5], i;
    int *ptr;

    clrscr();

    // Pointer stores the address of the first array element
    ptr = arr;

    printf("Enter 5 elements:\n");
    flushall();

    // Take input using pointer
    for(i = 0; i < 5; i++)
    {
        scanf("%d", &ptr[i]);
    }

    // Display array elements using pointer
    for(i = 0; i < 5; i++)
    {
        printf("\n%d", ptr[i]);
    }

    getch();
    return 0;
}
