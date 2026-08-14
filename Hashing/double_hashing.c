/*
 * Double Hashing
 */

#include <stdio.h>

#define SIZE 10

int main()
{
    int hash[SIZE];
    int values[] = {23, 43, 13, 27, 33};
    int n = 5;
    int i, index, step;

    // Fill the table with -1 to show empty positions
    for(i = 0; i < SIZE; i++)
    {
        hash[i] = -1;
    }

    // Insert each value using double hashing
    for(i = 0; i < n; i++)
    {
        index = values[i] % SIZE;

        // Second hash decides how far to move
        step = 7 - (values[i] % 7);

        // Keep moving until an empty position is found
        while(hash[index] != -1)
        {
            index = (index + step) % SIZE;
        }

        hash[index] = values[i];
    }

    // Display the hash table
    printf("Hash Table using Double Hashing:\n");

    for(i = 0; i < SIZE; i++)
    {
        printf("%d -> %d\n", i, hash[i]);
    }

    return 0;
}
