/*
 * Linear Probing
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

    // Insert each value into the hash table
    for(i = 0; i < n; i++)
    {
        index = values[i] % SIZE;

        // If the position is occupied, move to the next one
        while(hash[index] != -1)
        {
            index = (index + 1) % SIZE;
        }

        hash[index] = values[i];
    }

    // Display the hash table
    printf("Hash Table using Linear Probing:\n");

    for(i = 0; i < SIZE; i++)
    {
        printf("%d -> %d\n", i, hash[i]);
    }

    return 0;
}
