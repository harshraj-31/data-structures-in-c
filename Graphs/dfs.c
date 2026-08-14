/*
 * DFS - Depth First Search
 */

#include <stdio.h>

int graph[5][5] =
{
    {0, 1, 1, 0, 0},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 0, 1},
    {0, 1, 0, 0, 1},
    {0, 0, 1, 1, 0}
};

int visited[5] = {0};

// Visit one vertex and then go deeper
void dfs(int vertex)
{
    int i;

    printf("%d ", vertex);
    visited[vertex] = 1;

    // Visit all unvisited neighbours
    for(i = 0; i < 5; i++)
    {
        if(graph[vertex][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    // Start DFS from vertex 0
    printf("DFS Traversal: ");

    dfs(0);

    return 0;
}
