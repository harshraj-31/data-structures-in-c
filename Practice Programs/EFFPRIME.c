#include <stdio.h>      // Used for printf() and scanf()


// ===========================================================
//                  CHECK PRIME NUMBER
// ===========================================================
// This function checks whether a number is prime.
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


    // Any number divisible by 2 or 3 is not prime.
    // This also quickly handles even numbers.
    if(n % 2 == 0 || n % 3 == 0)
        return 0;


    // -------------------------------------------------------
    // CHECK POSSIBLE FACTORS
    // -------------------------------------------------------
    // After removing multiples of 2 and 3,
    // prime numbers greater than 3 can only be of the form:
    //
    // 6k - 1  or  6k + 1
    //
    // Example:
    // 5  -> 6(1) - 1
    // 7  -> 6(1) + 1
    // 11 -> 6(2) - 1
    // 13 -> 6(2) + 1
    //
    // So instead of checking every number,
    // we only check possible factors.
    //
    // i * i <= n means we only check up to √n.
    // If n has a factor larger than √n,
    // it must also have a smaller factor.

    for(int i = 5; i * i <= n; i += 6)
    {
        // Check both numbers:
        // i     -> 6k - 1
        // i + 2 -> 6k + 1

        if(n % i == 0 || n % (i + 2) == 0)
            return 0;       // Factor found -> not prime
    }


    // No factors were found.
    // Therefore, the number is prime.

    return 1;
}


int main()
{
    int num;


    // -------------------------------------------------------
    // TAKE INPUT FROM USER
    // -------------------------------------------------------

    printf("Enter a number: ");
    scanf("%d", &num);


    // -------------------------------------------------------
    // CHECK WHETHER THE NUMBER IS PRIME
    // -------------------------------------------------------

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
