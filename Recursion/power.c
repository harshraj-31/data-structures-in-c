#include <stdio.h>

int main()
{
    int base, exp, i;
    long long result = 1;

    printf("Enter base: ");
    scanf("%d", &base);

    printf("Enter exponent: ");
    scanf("%d", &exp);

    for (i = 1; i <= exp; i++)
    {
        result = result * base;
    }

    printf("%d to the power of %d is %lld\n", base, exp, result);

    return 0;
}
