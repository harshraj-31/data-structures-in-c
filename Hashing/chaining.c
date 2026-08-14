/*
 * Chaining - Hashing
 */

#include <stdio.h>

#define SIZE 5

int main()
{
    int hashTable[SIZE][5];
    int count[SIZE] = {0};
    int values[] = {10, 15, 7, 20, 12, 17};
    int n = 6;
    int i, index;

    // Initialize the hash table
    for(i = 0; i < SIZE; i++)
    {
        count[i] = 0;
    }

    // Insert values using chaining
    for(i = 0; i < n; i++)
    {
        index = values[i] % SIZE;

        // Store multiple values at the same index
        hashTable[index][count[index]] = values[i];
        count[index]++;
    }

    // Display the hash table
    printf("Hash Table using Chaining:\n");

    for(i = 0; i < SIZE; i++)
    {
        printf("%d -> ", i);

        if(count[i] == 0)
        {
            printf("NULL");
        }
        else
        {
            int j;

            for(j = 0; j < count[i]; j++)
            {
                printf("%d -> ", hashTable[i][j]);
            }

            printf("NULL");
        }

        printf("\n");
    }

    return 0;
}
