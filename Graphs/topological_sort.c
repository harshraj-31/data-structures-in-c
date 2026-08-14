/*
 * Topological Sort
 */

#include <stdio.h>

int main()
{
    int graph[5][5] =
    {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };

    int indegree[5] = {0};
    int visited[5] = {0};
    int i, j, count = 0;

    // Find the indegree of each vertex
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(graph[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }

    printf("Topological Sort: ");

    // Pick vertices with indegree 0
    while(count < 5)
    {
        int vertex = -1;

        for(i = 0; i < 5; i++)
        {
            if(!visited[i] && indegree[i] == 0)
            {
                vertex = i;
                break;
            }
        }

        // No vertex with indegree 0 means a cycle exists
        if(vertex == -1)
        {
            printf("\nCycle detected! Topological sort not possible.");
            return 0;
        }

        printf("%d ", vertex);
        visited[vertex] = 1;
        count++;

        // Remove the selected vertex's outgoing edges
        for(j = 0; j < 5; j++)
        {
            if(graph[vertex][j] == 1)
            {
                indegree[j]--;
            }
        }
    }

    return 0;
}
