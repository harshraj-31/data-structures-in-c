/*
 * Adjacency List
 */

#include <stdio.h>

int main()
{
    // Each row stores the vertices connected to that vertex
    int graph[4][3] =
    {
        {1, 2, -1},
        {0, 2, 3},
        {0, 1, 3},
        {1, 2, -1}
    };

    int i, j;

    printf("Adjacency List:\n");

    // Display connected vertices
    for(i = 0; i < 4; i++)
    {
        printf("%d -> ", i);

        for(j = 0; j < 3; j++)
        {
            if(graph[i][j] != -1)
            {
                printf("%d ", graph[i][j]);
            }
        }

        printf("\n");
    }

    return 0;
}
