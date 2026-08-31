// WRITE A PROGRAM TO ALLOCATE MEMORY USING MALLOC

#include <stdio.h>     // Used for input and output functions
#include <stdlib.h>    // Used for malloc() and free()


int main()
{
    int *p, n, i;
    // p -> pointer that will store the address of allocated memory
    // n -> number of elements the user wants
    // i -> loop counter

    clrscr();
    // Clears the screen
    // Note: clrscr() is mainly used in older Turbo C compilers.


    // -------------------------------------------------------
    // GET NUMBER OF ELEMENTS FROM THE USER
    // -------------------------------------------------------

    printf("ENTER THE NUMBER OF ELEMENTS =>");
    scanf("%d", &n);


    // -------------------------------------------------------
    // DYNAMIC MEMORY ALLOCATION USING malloc()
    // -------------------------------------------------------

    // malloc() allocates memory during program execution.
    //
    // n * sizeof(int)
    // means we are requesting enough memory to store
    // 'n' integer values.
    //
    // malloc() returns the address of the allocated memory,
    // which is stored in pointer p.

    p = (int *) malloc(n * sizeof(int));


    // -------------------------------------------------------
    // CHECK WHETHER MEMORY WAS ALLOCATED SUCCESSFULLY
    // -------------------------------------------------------

    // If malloc() cannot allocate memory,
    // it returns NULL.

    if(p == NULL)
    {
        printf("Memory allocation failed");
        return 0;
    }


    // -------------------------------------------------------
    // TAKE ELEMENTS FROM THE USER
    // -------------------------------------------------------

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        // Store each value directly inside
        // the dynamically allocated memory.

        scanf("%d", &p[i]);
    }


    // -------------------------------------------------------
    // DISPLAY THE ENTERED ELEMENTS
    // -------------------------------------------------------

    printf("You entered:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }


    // -------------------------------------------------------
    // RELEASE THE ALLOCATED MEMORY
    // -------------------------------------------------------

    // free() releases the memory that was allocated
    // using malloc().
    //
    // This is important because it prevents
    // unnecessary memory usage.

    free(p);


    getch();
    // Waits for a key press.
    // This is mainly used in older Turbo C compilers.

    return 0;
}
