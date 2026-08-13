// Find the sum of each row and column of a 3x3 matrix

#include <stdio.h>
#include <conio.h>

int main()
{
    int arr[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int i, j, r = 0, c = 0;
    int csum[3], rsum[3];

    clrscr();

    // Calculate sum of each row
    for(i = 0; i < 3; i++)
    {
        r = 0;

        for(j = 0; j < 3; j++)
        {
            r = r + arr[i][j];
        }

        rsum[i] = r;
    }

    // Calculate sum of each column
    for(j = 0; j < 3; j++)
    {
        c = 0;

        for(i = 0; i < 3; i++)
        {
            c = c + arr[i][j];
        }

        csum[j] = c;
    }

    // Print array with row sums
    for(i = 0; i < 3; i++)
    {
        printf("\n");

        for(j = 0; j < 3; j++)
        {
            printf("\t%d", arr[i][j]);
        }

        printf("\t= %d", rsum[i]);
    }

    // Print column sums
    printf("\n\t=\t=\t=");
    printf("\n");

    for(j = 0; j < 3; j++)
    {
        printf("\t%d", csum[j]);
    }

    getch();
    return 0;
}
