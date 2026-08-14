/*
 * Quadratic Probing
 */

#include <stdio.h>

#define SIZE 10

int main()
{
    int hash[SIZE];
    int values[] = {23, 43, 13, 27, 33};
    int n = 5;
    int i, index;

    // Mark all positions as empty
    for(i = 0; i < SIZE; i++)
    {
        hash[i] = -1;
    }

    // Insert values using quadratic probing
    for(i = 0; i < n; i++)
    {
        index = values[i] % SIZE;

        // If collision occurs, jump using i^2
        int j = 1;

        while(hash[index] != -1)
        {
            index = (index + j * j) % SIZE;
            j++;
        }

        hash[index] = values[i];
    }

    // Display the hash table
    printf("Hash Table using Quadratic Probing:\n");

    for(i = 0; i < SIZE; i++)
    {
        printf("%d -> %d\n", i, hash[i]);
    }

    return 0;
}
