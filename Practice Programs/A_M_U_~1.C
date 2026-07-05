// WRITE A PROGRAM ALOCATED MEMARY USING MALLOC:
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p,n,i;

    clrscr();
    printf("ENTER THE NUMBER OF ELEMENTS =>");
    scanf("%d", &n);

    p = (int *) malloc(n * sizeof(int));
    if(p == NULL)
    {
        printf("Memory allocation failed");
        return 0;
    }
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("You entered:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }

    free(p);
	getch();
	return 0;
}

