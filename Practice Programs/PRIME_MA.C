#include <stdio.h>
#include <conio.h>
#include <math.h>

int prime_2();
int prime_3();
int prime_5();

int main()
{
    int choice;
    clrscr();

    printf("\nprime 1");
    printf("\nprime 2");
    printf("\nprime 3");
    printf("\nprime 4");
    printf("\nprime 5");
    printf("\nenter the number: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 2:
            prime_2();
            break;

        case 3:
            prime_3();
            break;

        case 5:
            prime_5();
            break;

        default:
            printf("\ninvalid choice");
    }

    getch();
    return 0;
}

/* prime method 3 : i*i < n */
int prime_3()
{
    int n, i, isprime, step = 0;

    printf("\nprime numbers:\n");

    for (n = 2; n <= 100; n++)
    {
        isprime = 1;

        for (i = 2; i * i <= n; i++)
        {
            step++;
            if (n % i == 0)
            {
                isprime = 0;
                break;
            }
        }

        if (isprime == 1)
            printf("%d\t", n);
    }

    printf("\nsquare method taken %d steps", step);
    return 0;
}

/* prime method 5 : sqrt + odd check */
int prime_5()
{
    int n, i, isprime, step = 0;

    printf("\nprime numbers:\n");

    for (n = 2; n <= 100; n++)
    {
        isprime = 1;

        if (n > 2 && n % 2 == 0)
            isprime = 0;

        for (i = 3; i <= sqrt(n); i += 2)
        {
            step++;
            if (n % i == 0)
            {
                isprime = 0;
                break;
            }
        }

        if (isprime == 1)
            printf("%d\t", n);
    }

    printf("\n%d taken time", step);
    return 0;
}

/* prime method 2 : n/2 logic */
int prime_2()
{
    int n, i, isprime, step = 0;

    printf("\nprime numbers:\n");

    for (n = 2; n <= 100; n++)
    {
        isprime = 1;

        for (i = 2; i <= n / 2; i++)
        {
            step++;
            if (n % i == 0)
            {
                isprime = 0;
                break;
            }
        }

        if (isprime == 1)
            printf("%d\t", n);
    }

    printf("\n%d taken time", step);
    return 0;
}
