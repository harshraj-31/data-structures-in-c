#include <stdio.h>      // Used for printf() and scanf()


// ===========================================================
//                  CHECK PRIME NUMBER
// ===========================================================
// This function checks whether the given number is prime.
//
// Returns:
// 1 -> Number is prime
// 0 -> Number is not prime
// ===========================================================

int isPrime(int n)
{
    // Numbers less than or equal to 1 are not prime.
    if(n <= 1)
        return 0;


    // 2 and 3 are prime numbers.
    if(n <= 3)
        return 1;


    // If the number is divisible by 2 or 3,
    // it is not a prime number.
    if(n % 2 == 0 || n % 3 == 0)
        return 0;


    // Check possible factors of n.
    // We only need to check up to √n.
    //
    // Numbers greater than 3 that can be prime
    // are usually of the form 6k - 1 or 6k + 1.
    //
    // So we check:
    // i     -> 6k - 1
    // i + 2 -> 6k + 1

    for(int i = 5; i * i <= n; i += 6)
    {
        if(n % i == 0 || n % (i + 2) == 0)
        {
            return 0;       // Divisor found -> not prime
        }
    }


    // No divisor was found, so the number is prime.
    return 1;
}


// ===========================================================
//                         MAIN FUNCTION
// ===========================================================

int main()
{
    int num;


    // Ask the user to enter a number.
    printf("Enter a number: ");
    scanf("%d", &num);


    // Call isPrime() to check the number.
    //
    // If it returns 1, the number is prime.
    // Otherwise, it is not prime.

    if(isPrime(num))
    {
        printf("%d is a Prime Number\n", num);
    }
    else
    {
        printf("%d is NOT a Prime Number\n", num);
    }


    return 0;       // End the program successfully
}
