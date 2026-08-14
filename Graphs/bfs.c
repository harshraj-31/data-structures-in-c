/*
 * BFS - Breadth First Search
 */

#include <stdio.h>

int main()
{
    int graph[5][5] =
    {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int visited[5] = {0};
    int queue[5];
    int front = 0, rear = 0;
    int i, current;

    // Start BFS from vertex 0
    queue[rear++] = 0;
    visited[0] = 1;

    printf("BFS Traversal: ");

    while(front < rear)
    {
        // Remove the first vertex from queue
        current = queue[front++];

        printf("%d ", current);

        // Find all unvisited neighbours
        for(i = 0; i < 5; i++)
        {
            if(graph[current][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    return 0;
}
