#include <stdio.h>

int main()
{
    int num, binary[32], i = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    if (num == 0)
    {
        printf("Binary: 0");
        return 0;
    }

    while (num > 0)
    {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }

    printf("Binary: ");

    while (i > 0)
    {
        i--;
        printf("%d", binary[i]);
    }

    return 0;
}
