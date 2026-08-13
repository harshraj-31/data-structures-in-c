#include <stdio.h>
#include <conio.h>

int main()
{
    int row, col, i, j;

    int a[3][3] =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    clrscr();

    // Find sum of each row
    for(i = 0; i < 3; i++)
    {
        row = 0;

        for(j = 0; j < 3; j++)
        {
            row = row + a[i][j];
            printf("%d ", a[i][j]);
        }

        printf("SUM IS %d\n", row);
    }

    // Find sum of each column
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
