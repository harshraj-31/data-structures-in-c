/*
 * Kruskal - Minimum Spanning Tree
 */

#include <stdio.h>

int parent[5];

/* Find the parent of a vertex */
int find(int vertex)
{
    while(parent[vertex] != vertex)
    {
        vertex = parent[vertex];
    }

    return vertex;
}

/* Join two different sets */
void unionSet(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);

    parent[rootB] = rootA;
}

int main()
{
    int edges[7][3] =
    {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    int i, j, temp;
    int count = 0;
    int total = 0;

    // Sort edges according to weight
    for(i = 0; i < 7; i++)
    {
        for(j = i + 1; j < 7; j++)
        {
            if(edges[i][2] > edges[j][2])
            {
                temp = edges[i][0];
                edges[i][0] = edges[j][0];
                edges[j][0] = temp;

                temp = edges[i][1];
                edges[i][1] = edges[j][1];
                edges[j][1] = temp;

                temp = edges[i][2];
                edges[i][2] = edges[j][2];
                edges[j][2] = temp;
            }
        }
    }

    // Initially, every vertex is its own set
    for(i = 0; i < 5; i++)
    {
        parent[i] = i;
    }

    printf("Edges in Minimum Spanning Tree:\n");

    // Pick the smallest edges without creating a cycle
    for(i = 0; i < 7 && count < 4; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        if(find(u) != find(v))
        {
            printf("%d - %d : %d\n", u, v, weight);

            total += weight;
            unionSet(u, v);
            count++;
        }
    }

    printf("Minimum Cost = %d\n", total);

    return 0;
}
