/*
 * Tower of Hanoi
 * Author: Harshrajsinh Zala
 * Description: Recursive solution.
 */
#include <stdio.h>

void towerOfHanoi(int n, char source, char destination, char auxiliary)
{
    // Base case: If there is only 1 disk, move it directly from source to destination
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Step 1: Move n-1 disks from source to auxiliary peg
    towerOfHanoi(n - 1, source, auxiliary, destination);

    // Step 2: Move the nth disk from source to destination peg
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Step 3: Move the n-1 disks from auxiliary peg to destination peg
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n > 0)
    {
        printf("\nSequence of moves:\n");
        // 'A' is Source, 'C' is Destination, 'B' is Auxiliary
        towerOfHanoi(n, 'A', 'C', 'B');
    }
    else
    {
        printf("Number of disks must be greater than 0.\n");
    }

    return 0;
}
