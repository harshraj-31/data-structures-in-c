/*
 * Dijkstra - Shortest Path Algorithm
 */

#include <stdio.h>

#define INF 9999

int main()
{
    int graph[5][5] =
    {
        {0, 10, 3, 0, 0},
        {10, 0, 1, 2, 0},
        {3, 1, 0, 8, 2},
        {0, 2, 8, 0, 7},
        {0, 0, 2, 7, 0}
    };

    int distance[5];
    int visited[5] = {0};
    int i, j, min, vertex;

    // Start with the first vertex
    for(i = 0; i < 5; i++)
    {
        distance[i] = INF;
    }

    distance[0] = 0;

    // Find the shortest distance to every vertex
    for(i = 0; i < 5; i++)
    {
        min = INF;
        vertex = -1;

        // Find the unvisited vertex with smallest distance
        for(j = 0; j < 5; j++)
        {
            if(visited[j] == 0 && distance[j] < min)
            {
                min = distance[j];
                vertex = j;
            }
        }

        if(vertex == -1)
            break;

        visited[vertex] = 1;

        // Update distances of neighbouring vertices
        for(j = 0; j < 5; j++)
        {
            if(graph[vertex][j] != 0 &&
               visited[j] == 0 &&
               distance[vertex] + graph[vertex][j] < distance[j])
            {
                distance[j] =
                    distance[vertex] + graph[vertex][j];
            }
        }
    }

    // Display shortest distances from vertex 0
    printf("Shortest distances from vertex 0:\n");

    for(i = 0; i < 5; i++)
    {
        printf("0 -> %d = %d\n", i, distance[i]);
    }

    return 0;
}
