#include <stdio.h>

int main()
{
    int matrix[3][3] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int row, col;
    int rowSum, colSum;
    int highestSum = 0, secondHighestSum = 0;

    // Find highest and second-highest row sums
    for(row = 0; row < 3; row++)
    {
        rowSum = 0;

        for(col = 0; col < 3; col++)
        {
            rowSum += matrix[row][col];
        }

        if(rowSum > highestSum)
        {
            secondHighestSum = highestSum;
            highestSum = rowSum;
        }
        else if(rowSum > secondHighestSum && rowSum != highestSum)
        {
            secondHighestSum = rowSum;
        }
    }

    // Find highest and second-highest column sums
    for(col = 0; col < 3; col++)
    {
        colSum = 0;

        for(row = 0; row < 3; row++)
        {
            colSum += matrix[row][col];
        }

        if(colSum > highestSum)
        {
            secondHighestSum = highestSum;
            highestSum = colSum;
        }
        else if(colSum > secondHighestSum && colSum != highestSum)
        {
            secondHighestSum = colSum;
        }
    }

    printf("\nSecond highest sum among rows or columns is: %d\n",
           secondHighestSum);

    return 0;
}
