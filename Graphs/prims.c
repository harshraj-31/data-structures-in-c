/*
 * Prim's Algorithm - Minimum Spanning Tree
 */

#include <stdio.h>

#define INF 9999

int main()
{
    int graph[5][5] =
    {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int visited[5] = {0};
    int edges = 0;
    int total = 0;
    int i, j;
    int min, u, v;

    // Start from vertex 0
    visited[0] = 1;

    printf("Edges in Minimum Spanning Tree:\n");

    // MST needs exactly n-1 edges
    while(edges < 4)
    {
        min = INF;
        u = -1;
        v = -1;

        // Find the smallest edge connecting
        // a visited vertex to an unvisited vertex
        for(i = 0; i < 5; i++)
        {
            if(visited[i])
            {
                for(j = 0; j < 5; j++)
                {
                    if(!visited[j] && graph[i][j] != 0)
                    {
                        if(graph[i][j] < min)
                        {
                            min = graph[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }
        }

        // Add the selected edge
        printf("%d - %d : %d\n", u, v, min);

        total += min;
        visited[v] = 1;
        edges++;
    }

    printf("Minimum Cost = %d\n", total);

    return 0;
}
