/*
 * Factorial
 * Starter template
 */

#include <stdio.h>

int main()
{
    int n, i;
    long int fact = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Factorial is not defined for negative numbers.");
        return 0;
    }

    for (i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    printf("Factorial of %d = %ld", n, fact);

    return 0;
}
