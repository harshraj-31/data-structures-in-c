#include <stdio.h>
#include <conio.h>

int main()
{
    clrscr();

    int a[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int i, j, sum;
    int max = -1, second_max = -1;

    // Find row sums
    for(i = 0; i < 3; i++)
    {
        sum = 0;

        for(j = 0; j < 3; j++)
        {
            sum += a[i][j];
        }

        printf("Row %d sum = %d\n", i + 1, sum);

        // Update highest and second highest
        if(sum > max)
        {
            second_max = max;
            max = sum;
        }
        else if(sum > second_max && sum != max)
        {
            second_max = sum;
        }
    }

    // Find column sums
    for(j = 0; j < 3; j++)
    {
        sum = 0;

        for(i = 0; i < 3; i++)
        {
            sum += a[i][j];
        }

        printf("Column %d sum = %d\n", j + 1, sum);

        // Check again for highest values
        if(sum > max)
        {
            second_max = max;
            max = sum;
        }
        else if(sum > second_max && sum != max)
        {
            second_max = sum;
        }
    }

    printf("\nSecond highest of all row & column sums = %d", second_max);

    getch();
    return 0;
}
