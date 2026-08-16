/*
 * Josephus Problem
 * Starter template
 */

#include <stdio.h>

int main()
{
    printf("Josephus Problem\n");
    return 0;
}#include <stdio.h>
#include <conio.h>

// Recursive function to find the survivor
// n = total people, k = elimination step
int josephus(int n, int k) {
    // Base case: If there is only 1 person left, they survive
    if (n == 1) {
        return 1;
    }
    
    // Recursive step: Find the survivor in a smaller circle (n-1)
    // Shift the position to match the original circle of size n
    return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main() {
    int n, k, survivor;

    clrscr();

    printf("Enter the total number of people (n): ");
    scanf("%d", &n);

    printf("Enter the elimination step (k): ");
    scanf("%d", &k);

    // Call the recursive function
    survivor = josephus(n, k);

    printf("\nThe last person surviving is at position: %d\n", survivor);

    getch();
    return 0;
}
