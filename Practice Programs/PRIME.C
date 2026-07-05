#include <stdio.h>
#include <conio.h>
#include <math.h>

int step = 0;

/* Method 1: Divide till n/2 */
int Prime2()
{
    int n = 11, i, isPrime = 1;
    step = 0;

    for (i = 2; i <= n / 2; i++, step++)
    {
        if (n % i == 0)
        {
            isPrime = 0;
            break;
        }
    }

    printf("\nPrime2: %d is %s", n, isPrime ? "Prime" : "Not Prime");
    printf("\nDivide by n/2 took %d steps.\n", step);

    return isPrime;
}

/* Method 2: Using i*i < n */
int Prime3()
{
    int n, i, isPrime;
    step = 0;

    printf("\nPrime numbers using i*i < n:\n");

    for (n = 2; n <= 100; n++)
    {
        isPrime = 1;
        for (i = 2; i * i < n; i++, step++)
        {
            if (n % i == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if (isPrime)
            printf("%d ", n);
    }

    printf("\nSquare method took %d steps.\n", step);
    return 0;
}

/* Method 3: Using sqrt(n) */
int Prime4()
{
    int n, i, isPrime;
    step = 0;

    printf("\nPrime numbers using sqrt(n):\n");

    for (n = 2; n <= 100; n++)
    {
        isPrime = 1;
        for (i = 2; i <= sqrt(n); i++, step++)
        {
            if (n % i == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if (isPrime)
            printf("%d ", n);
    }

    printf("\nSqrt method took %d steps.\n", step);
    return 0;
}

/* Method 4: Optimized (odd numbers only) */
int Prime5()
{
    int n, i, isPrime;
    step = 0;

    printf("\nPrime numbers using optimized odd check:\n");
    printf("2 ");

    for (n = 3; n <= 100; n += 2)
    {
        isPrime = 1;

        for (i = 3; i <= sqrt(n); i += 2, step++)
        {
            if (n % i == 0)
            {
                isPrime = 0;
                break;
            }
        }

        if (isPrime)
            printf("%d ", n);
    }

    printf("\nOptimized sqrt method took %d steps.\n", step);
    return 0;
}

int main()
{
    int ch;

    clrscr();

    printf("\nPrime Number Comparison Methods");
    printf("\n1. Divide till n/2");
    printf("\n2. Using i*i < n");
    printf("\n3. Using sqrt(n)");
    printf("\n4. using sqrt(n) & odd numbers");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
        case 1: Prime2(); break;
        case 2: Prime3(); break;
        case 3: Prime4(); break;
        case 4: Prime5(); break;
        default: printf("\nInvalid choice");
    }

    getch();
    return 0;
}
