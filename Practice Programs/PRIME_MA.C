#include <stdio.h>      // Used for printf() and scanf()
#include <conio.h>      // Used for clrscr() and getch()
#include <math.h>       // Used for sqrt()


// Function declarations
// These tell the compiler about the functions
// before they are used in main().

int prime_2();
int prime_3();
int prime_5();


int main()
{
    int choice;

    clrscr();       // Clears the screen


    // -------------------------------------------------------
    // DISPLAY MENU
    // -------------------------------------------------------

    printf("\nPrime 1");
    printf("\nPrime 2");
    printf("\nPrime 3");
    printf("\nPrime 4");
    printf("\nPrime 5");

    printf("\nEnter the number: ");
    scanf("%d", &choice);


    // -------------------------------------------------------
    // SELECT PRIME METHOD
    // -------------------------------------------------------
    // switch is used to execute the method selected
    // by the user.

    switch(choice)
    {
        case 2:
            prime_2();      // Use n/2 method
            break;

        case 3:
            prime_3();      // Use square-root method
            break;

        case 5:
            prime_5();      // Use optimized odd-number method
            break;

        default:
            printf("\nInvalid choice");
    }


    getch();        // Wait for a key press

    return 0;
}


// ===========================================================
//             PRIME METHOD 3 : i*i <= n
// ===========================================================
// Instead of checking divisors up to n/2,
// we only check up to the square root of n.
//
// Example:
// For n = 100:
// √100 = 10
//
// So we only need to check possible divisors up to 10.
// This makes the method faster than the n/2 method.
// ===========================================================

int prime_3()
{
    int n, i, isprime, step = 0;

    printf("\nPrime numbers:\n");


    // Check every number from 2 to 100.
    for(n = 2; n <= 100; n++)
    {
        // Initially assume the number is prime.
        isprime = 1;


        // Check possible divisors up to √n.
        for(i = 2; i * i <= n; i++)
        {
            step++;     // Count how many divisibility checks are made

            // If n is completely divisible by i,
            // then n is not prime.
            if(n % i == 0)
            {
                isprime = 0;
                break;
            }
        }


        // If no divisor was found, print the number.
        if(isprime == 1)
            printf("%d\t", n);
    }


    printf("\nSquare method took %d steps", step);

    return 0;
}


// ===========================================================
//          PRIME METHOD 5 : sqrt + ODD CHECK
// ===========================================================
// This is an optimized version of the square-root method.
//
// We already know that 2 is the only even prime number.
// Therefore, every even number greater than 2 is not prime.
//
// After checking even numbers, we only test odd divisors:
// 3, 5, 7, 9, ...
//
// This reduces unnecessary calculations.
// ===========================================================

int prime_5()
{
    int n, i, isprime, step = 0;

    printf("\nPrime numbers:\n");


    // Check every number from 2 to 100.
    for(n = 2; n <= 100; n++)
    {
        // Initially assume the number is prime.
        isprime = 1;


        // If n is even and greater than 2,
        // it cannot be a prime number.

        if(n > 2 && n % 2 == 0)
            isprime = 0;


        // Check only odd divisors up to √n.
        //
        // i += 2 means:
        // 3, 5, 7, 9, 11, ...

        for(i = 3; i <= sqrt(n); i += 2)
        {
            step++;     // Count the number of checks

            // If n is divisible by i,
            // then n is not prime.

            if(n % i == 0)
            {
                isprime = 0;
                break;
            }
        }


        // Print the number if it is prime.
        if(isprime == 1)
            printf("%d\t", n);
    }


    printf("\n%d checks taken", step);

    return 0;
}


// ===========================================================
//              PRIME METHOD 2 : n/2 LOGIC
// ===========================================================
// This is the simplest method among the three.
//
// For every number n, we check divisors from 2 up to n/2.
//
// Example:
// n = 10
//
// We check:
// 2, 3, 4, 5
//
// If any number divides n completely,
// then n is not prime.
//
// This method works correctly but performs more checks
// compared to the square-root methods.
// ===========================================================

int prime_2()
{
    int n, i, isprime, step = 0;

    printf("\nPrime numbers:\n");


    // Check every number from 2 to 100.
    for(n = 2; n <= 100; n++)
    {
        // Initially assume the number is prime.
        isprime = 1;


        // Check divisors from 2 to n/2.
        for(i = 2; i <= n / 2; i++)
        {
            step++;     // Count the divisibility check

            // If n is divisible by i,
            // then n is not prime.

            if(n % i == 0)
            {
                isprime = 0;
                break;
            }
        }


        // If no divisor was found, print the number.
        if(isprime == 1)
            printf("%d\t", n);
    }


    printf("\n%d checks taken", step);

    return 0;
}
