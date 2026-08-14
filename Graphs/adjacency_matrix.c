/*
 * Adjacency Matrix
 */

#include <stdio.h>

int main()
{
    int graph[4][4] =
    {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };

    int i, j;

    // Print the adjacency matrix
    printf("Adjacency Matrix:\n");

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d ", graph[i][j]);
        }

        printf("\n");
    }

    return 0;
}
