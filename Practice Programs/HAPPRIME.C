#include <stdio.h>      // Used for printf() and scanf()


// ===========================================================
//                 CHECK PRIME NUMBER
// ===========================================================
// This function checks whether a number is prime.
//
// Returns:
// 1 -> Number is prime
// 0 -> Number is not prime
// ===========================================================

int checkPrime(int number)
{
    // Numbers less than or equal to 1 are not prime.
    if(number <= 1)
        return 0;


    // 2 and 3 are prime numbers.
    if(number <= 3)
        return 1;


    // If the number is divisible by 2 or 3,
    // then it is not a prime number.
    if(number % 2 == 0 || number % 3 == 0)
        return 0;


    // Check possible factors up to √number.
    //
    // Prime factors greater than 3 can be in the form:
    // 6k - 1 or 6k + 1
    //
    // Therefore, we check i and i + 2.
    for(int i = 5; i * i <= number; i = i + 6)
    {
        if(number % i == 0 || number % (i + 2) == 0)
            return 0;       // Factor found -> not prime
    }


    // No factor was found, so the number is prime.
    return 1;
}


// ===========================================================
//              FIND SUM OF SQUARES OF DIGITS
// ===========================================================
// This function takes each digit of a number,
// squares it, and adds all the squared values.
//
// Example:
// number = 19
//
// 1² + 9²
// = 1 + 81
// = 82
// ===========================================================

int squareDigitSum(int number)
{
    int lastDigit;
    int total = 0;


    // Continue until all digits have been processed.
    while(number > 0)
    {
        // Get the last digit.
        // Example: 19 % 10 = 9
        lastDigit = number % 10;


        // Square the digit and add it to total.
        total = total + lastDigit * lastDigit;


        // Remove the last digit.
        // Example: 19 / 10 = 1
        number = number / 10;
    }


    return total;
}


// ===========================================================
//                  CHECK HAPPY NUMBER
// ===========================================================
// A Happy Number is a number that eventually becomes 1
// when we repeatedly replace it with the sum of the
// squares of its digits.
//
// Example:
// 19
// ↓
// 1² + 9² = 82
// ↓
// 8² + 2² = 68
// ↓
// 6² + 8² = 100
// ↓
// 1² + 0² + 0² = 1
//
// Therefore, 19 is a Happy Number.
//
// If the process reaches 4, it will enter a cycle,
// which means the number is NOT happy.
// ===========================================================

int checkHappy(int number)
{
    // Keep calculating the square-digit sum
    // until we reach either 1 or 4.

    while(number != 1 && number != 4)
    {
        number = squareDigitSum(number);
    }


    // Reaching 1 means the number is happy.
    if(number == 1)
        return 1;

    // Reaching 4 means the number is not happy.
    else
        return 0;
}


// ===========================================================
//                         MAIN FUNCTION
// ===========================================================

int main()
{
    int number;


    // -------------------------------------------------------
    // TAKE NUMBER FROM USER
    // -------------------------------------------------------

    printf("Enter number: ");
    scanf("%d", &number);


    // -------------------------------------------------------
    // CHECK BOTH CONDITIONS
    // -------------------------------------------------------
    // A Happy Prime Number must satisfy BOTH conditions:
    //
    // 1. It must be a prime number.
    // 2. It must be a happy number.
    //
    // && means BOTH conditions must be true.

    if(checkPrime(number) && checkHappy(number))
    {
        printf("Happy Prime Number\n");
    }
    else
    {
        printf("Not a Happy Prime Number\n");
    }


    return 0;     // End the program successfully
}
