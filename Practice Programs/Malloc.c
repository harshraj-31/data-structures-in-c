// WAP to allocate memory using malloc()

#include <stdio.h>      // Used for printf() and scanf()
#include <conio.h>     // Used for clrscr() and getch()


int main()
{
    int *a;             // Pointer to store the address of allocated memory
    int i;              // Used as a loop counter

    clrscr();           // Clears the screen


    // -------------------------------------------------------
    // ALLOCATE MEMORY USING malloc()
    // -------------------------------------------------------
    // malloc() dynamically allocates memory at runtime.
    //
    // Here, we need memory for 5 integers.
    // sizeof(int) gives the size of one integer.
    //
    // So:
    // 5 * sizeof(int)
    // means memory for 5 integer values.

    a = malloc(5 * sizeof(int));


    // -------------------------------------------------------
    // TAKE 5 ELEMENTS FROM THE USER
    // -------------------------------------------------------

    printf("\nEnter 5 elements:\n");

    for(i = 0; i < 5; i++)
    {
        // Store each entered value in the allocated memory.

        scanf("%d", &a[i]);
    }


    // -------------------------------------------------------
    // DISPLAY THE ELEMENTS
    // -------------------------------------------------------

    printf("\nThe elements are: ");

    for(i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }


    // Wait for the user to press a key.
    getch();


    return 0;           // End the program successfully
}
