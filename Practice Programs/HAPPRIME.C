#include <stdio.h>

/* check if number is prime */
int checkPrime(int number) {

    if (number <= 1)
        return 0; // not prime

    if (number <= 3)
        return 1; // prime

    if (number % 2 == 0 || number % 3 == 0)
        return 0; // not prime

    for (int i = 5; i * i <= number; i = i + 6) {
        if (number % i == 0 || number % (i + 2) == 0)
            return 0; // not prime
    }
    return 1; //Prime
}


// find sum of squares of digits 
int squareDigitSum(int number) {
    int lastDigit, total = 0;

    while (number > 0) {
        lastDigit = number % 10;
        total = total + lastDigit * lastDigit;
        number = number / 10;
    }
    return total;
}


// check if number is happy 
int checkHappy(int number) {
    while (number != 1 && number != 4)
    {
        number = squareDigitSum(number);
    }

    if (number == 1)
        return 1;
    else
        return 0;
}

int main() {
    int number;
    printf("Enter number: ");
    scanf("%d", &number);

    if (checkPrime(number) && checkHappy(number))
        printf("Happy Prime Number\n");
    else
        printf("Not a Happy Prime Number\n");
    return 0;
}
