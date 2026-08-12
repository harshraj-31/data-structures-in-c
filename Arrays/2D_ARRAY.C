#include <stdio.h>

int main()
{
    int a[3][3] =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int i, j;
    int row, col;

    clrscr();

    // Calculate and print each row sum
    for(i = 0; i < 3; i++)
    {
        row = 0;

        for(j = 0; j < 3; j++)
        {
            printf(" %d", a[i][j]);
            row = row + a[i][j];
        }

        printf("\t%d", row);
        printf("\n");
    }

    // Calculate and print each column sum
    for(j = 0; j < 3; j++)
    {
        col = 0;

        for(i = 0; i < 3; i++)
        {
            col = col + a[i][j];
        }

        printf(" %d", col);
    }

    getch();
    return 0;
}
