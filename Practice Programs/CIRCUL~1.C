#include <stdio.h>      // Used for printf() and scanf()
#include <conio.h>      // Used for clrscr() and getch()


// ===========================================================
//                 FUNCTION TO CHECK PRIME
// ===========================================================
// This function checks whether a given number is prime.
//
// Returns:
// 1 -> Number is prime
// 0 -> Number is not prime
// ===========================================================

int isPrime(int n)
{
    int i;

    // Numbers less than 2 are not prime.
    if(n < 2)
        return 0;

    // Check whether n is divisible by any number
    // from 2 up to n/2.
    for(i = 2; i <= n/2; i++)
    {
        if(n % i == 0)
            return 0;       // Divisible -> not a prime number
    }

    return 1;               // No divisor found -> prime number
}


int main()
{
    clrscr();       // Clears the screen (Turbo C)

    int num, temp, digit, count = 0;
    int pow = 1, rotate, i;


    // -------------------------------------------------------
    // TAKE NUMBER FROM USER
    // -------------------------------------------------------

    printf("Enter a number: ");
    scanf("%d", &num);


    // Keep a copy of the original number.
    // We will use temp for calculations.

    temp = num;


    // -------------------------------------------------------
    // COUNT THE NUMBER OF DIGITS
    // -------------------------------------------------------
    // Example:
    // num = 197
    //
    // 197 / 10 = 19
    // 19  / 10 = 1
    // 1   / 10 = 0
    //
    // Therefore, the number has 3 digits.

    while(temp > 0)
    {
        count++;
        temp = temp / 10;
    }


    // -------------------------------------------------------
    // CALCULATE POWER OF 10
    // -------------------------------------------------------
    // We need 10^(number of digits - 1).
    //
    // For a 3-digit number:
    // pow = 10 * 10 = 100
    //
    // This is used when rotating the digits.

    for(i = 1; i < count; i++)
        pow = pow * 10;


    // Restore the original number.

    temp = num;


    // -------------------------------------------------------
    // CHECK ALL ROTATIONS
    // -------------------------------------------------------
    // A circular prime is a number where ALL rotations
    // of its digits are also prime.
    //
    // Example:
    //
    // 197 -> Prime
    // 971 -> Prime
    // 719 -> Prime
    //
    // Therefore, 197 is a circular prime.

    for(i = 0; i < count; i++)
    {
        // Check whether the current rotation is prime.

        if(!isPrime(temp))
        {
            printf("Not a Circular Prime");

            getch();
            return 0;
        }


        // ---------------------------------------------------
        // ROTATE THE LAST DIGIT TO THE FRONT
        // ---------------------------------------------------
        //
        // Example:
        //
        // temp = 197
        //
        // digit = 197 % 10
        //       = 7
        //
        // temp / 10 = 19
        //
        // rotate = (7 * 100) + 19
        //        = 719
        //
        // So:
        // 197 -> 719

        digit = temp % 10;

        rotate = (digit * pow) + (temp / 10);

        temp = rotate;
    }


    // If every rotation passed the prime check,
    // the number is a circular prime.

    printf("Circular Prime Number");


    getch();        // Wait for a key press
    return 0;
}
