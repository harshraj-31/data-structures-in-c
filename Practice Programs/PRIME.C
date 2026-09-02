#include <stdio.h>      // Used for printf() and scanf()
#include <conio.h>      // Used for clrscr() and getch()
#include <math.h>       // Used for sqrt()


// This variable counts how many times the program
// checks divisibility.
// We use it to compare the efficiency of different methods.

int step = 0;


// ===========================================================
// METHOD 1: CHECK DIVISORS UP TO n/2
// ===========================================================
// In this method, we check whether n is divisible by
// any number from 2 up to n/2.
//
// Example:
// For n = 11, we check:
// 2, 3, 4, 5
//
// If any number divides n completely, it is not prime.
// ===========================================================

int Prime2()
{
    int n = 11;
    int i;
    int isPrime = 1;

    step = 0;       // Reset step counter


    // Check possible divisors from 2 to n/2.
    for(i = 2; i <= n / 2; i++, step++)
    {
        // If remainder is 0, n is divisible by i.
        if(n % i == 0)
        {
            isPrime = 0;        // Number is not prime
            break;
        }
    }


    // Display whether 11 is prime or not.
    printf("\nPrime2: %d is %s",
           n,
           isPrime ? "Prime" : "Not Prime");

    printf("\nDivide by n/2 took %d steps.\n", step);

    return isPrime;
}


// ===========================================================
// METHOD 2: CHECK USING i*i < n
// ===========================================================
// Instead of checking up to n/2, we check only up to
// approximately the square root of n.
//
// This reduces the number of checks considerably.
//
// Here we find all prime numbers from 2 to 100.
// ===========================================================

int Prime3()
{
    int n, i, isPrime;

    step = 0;       // Reset step counter


    printf("\nPrime numbers using i*i < n:\n");


    // Check every number from 2 to 100.
    for(n = 2; n <= 100; n++)
    {
        // Assume the number is prime initially.
        isPrime = 1;


        // Check possible divisors.
        //
        // i*i < n means we don't need to check
        // all the way up to n/2.

        for(i = 2; i * i < n; i++, step++)
        {
            if(n % i == 0)
            {
                isPrime = 0;    // Divisor found
                break;
            }
        }


        // If no divisor was found, print the number.
        if(isPrime)
            printf("%d ", n);
    }


    printf("\nSquare method took %d steps.\n", step);

    return 0;
}


// ===========================================================
// METHOD 3: CHECK USING sqrt(n)
// ===========================================================
// This method directly uses sqrt() to find the square root
// of the number.
//
// Instead of checking divisors up to n/2,
// we only check up to sqrt(n).
//
// Example:
// sqrt(100) = 10
//
// So for 100, we only need to check possible divisors
// up to 10.
// ===========================================================

int Prime4()
{
    int n, i, isPrime;

    step = 0;       // Reset step counter


    printf("\nPrime numbers using sqrt(n):\n");


    // Check every number from 2 to 100.
    for(n = 2; n <= 100; n++)
    {
        // Initially assume the number is prime.
        isPrime = 1;


        // Check divisors only up to sqrt(n).
        for(i = 2; i <= sqrt(n); i++, step++)
        {
            if(n % i == 0)
            {
                isPrime = 0;    // Divisor found
                break;
            }
        }


        // Print the number if it is prime.
        if(isPrime)
            printf("%d ", n);
    }


    printf("\nSqrt method took %d steps.\n", step);

    return 0;
}


// ===========================================================
// METHOD 4: OPTIMIZED METHOD
// ===========================================================
// This method improves the sqrt method even further.
//
// We already know that:
// - 2 is the only even prime number.
// - Every other even number is NOT prime.
//
// Therefore, after checking 2, we only check ODD numbers.
//
// We also check only odd divisors:
// 3, 5, 7, 9, ...
//
// This reduces the number of unnecessary checks.
// ===========================================================

int Prime5()
{
    int n, i, isPrime;

    step = 0;       // Reset step counter


    printf("\nPrime numbers using optimized odd check:\n");


    // 2 is the only even prime number,
    // so we print it separately.
    printf("2 ");


    // Start from 3 and check only odd numbers.
    //
    // n += 2 means:
    // 3, 5, 7, 9, 11, ...

    for(n = 3; n <= 100; n += 2)
    {
        // Initially assume the number is prime.
        isPrime = 1;


        // Check only odd divisors up to sqrt(n).
        //
        // i += 2 means:
        // 3, 5, 7, 9, ...

        for(i = 3; i <= sqrt(n); i += 2, step++)
        {
            if(n % i == 0)
            {
                isPrime = 0;    // Divisor found
                break;
            }
        }


        // Print the number if it is prime.
        if(isPrime)
            printf("%d ", n);
    }


    printf("\nOptimized sqrt method took %d steps.\n", step);

    return 0;
}


// ===========================================================
//                         MAIN FUNCTION
// ===========================================================

int main()
{
    int ch;

    clrscr();       // Clears the screen


    // -------------------------------------------------------
    // DISPLAY MENU
    // -------------------------------------------------------

    printf("\nPrime Number Comparison Methods");

    printf("\n1. Divide till n/2");
    printf("\n2. Using i*i < n");
    printf("\n3. Using sqrt(n)");
    printf("\n4. Using sqrt(n) & odd numbers");


    // Ask the user which method they want to execute.
    printf("\nEnter your choice: ");
    scanf("%d", &ch);


    // -------------------------------------------------------
    // SELECT METHOD USING switch
    // -------------------------------------------------------

    switch(ch)
    {
        case 1:
            Prime2();
            break;

        case 2:
            Prime3();
            break;

        case 3:
            Prime4();
            break;

        case 4:
            Prime5();
            break;

        default:
            printf("\nInvalid choice");
    }


    getch();        // Wait for a key press

    return 0;       // End the program
}
