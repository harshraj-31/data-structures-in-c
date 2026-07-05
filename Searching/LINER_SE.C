#include <stdio.h>
#include <conio.h>

int main()
{
    int a[50], n, i, search, found = 0;

    clrscr();

    printf("ENTER THE NUMBER OF ELEMENTS => ");
    scanf("%d", &n);

    printf("ENTER THE ELEMENTS => ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("ENTER THE ELEMENT TO SEARCH => ");
    scanf("%d", &search);

    for (i = 0; i < n; i++)
    {
        if (a[i] == search)
        {
            printf("\nELEMENT FOUND AT POSITION => %d", i + 1);
            found = 1;
            /* break;  // use this if you want only first position */
        }
    }

    if (found == 0)
    {
        printf("\nELEMENT NOT FOUND");
    }

    getch();
    return 0;
}
