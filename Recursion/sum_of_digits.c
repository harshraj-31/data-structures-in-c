#include <stdio.h>

int main()
{
    int num, originalNum, remainder, sum = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num;

    // Handle negative numbers
    if (num < 0)
    {
        num = -num;
    }

    while (num > 0)
    {
        remainder = num % 10;
        sum = sum + remainder;
        num = num / 10;
    }

    printf("Sum of digits of %d is %d\n", originalNum, sum);

    return 0;
}
