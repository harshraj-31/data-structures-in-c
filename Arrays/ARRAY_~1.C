// Access array elements using a pointer

#include <stdio.h>

int main()
{
    int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int *p, i;

    clrscr();

    // Store the address of the first array element
    p = a;

    // Access each element using pointer arithmetic
    for(i = 0; i < 10; i++)
    {
        printf("ELEMENT => %d = %d\n", i, *(p + i));
    }

    getch();
    return 0;
}
