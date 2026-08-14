/*
 * Floyd Warshall - All Pairs Shortest Path
 */

#include <stdio.h>

#define INF 9999

int main()
{
    int graph[4][4] =
    {
        {0,   5,   9, INF},
        {5,   0,   2,   6},
        {9,   2,   0,   3},
        {INF, 6,   3,   0}
    };

    int i, j, k;

    // Try every vertex as an intermediate vertex
    for(k = 0; k < 4; k++)
    {
        for(i = 0; i < 4; i++)
        {
            for(j = 0; j < 4; j++)
            {
                // Update if a shorter path is found
                if(graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] =
                        graph[i][k] + graph[k][j];
                }
            }
        }
    }

    // Display shortest distances between all vertices
    printf("Shortest Distance Matrix:\n");

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(graph[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", graph[i][j]);
        }

        printf("\n");
    }

    return 0;
}
