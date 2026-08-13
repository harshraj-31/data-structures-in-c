#include <stdio.h>
#include <conio.h>

int main()
{
    int a[5] = {10,20,30,40,50};
    int i, *p;

    clrscr();

    // Store address of the first array element
    p = a;

    // Access array elements using pointer
    for(i = 0; i < 5; i++)
    {
        printf("%d %d\n", i, *(p + i));
    }

    getch();
    return 0;
}
