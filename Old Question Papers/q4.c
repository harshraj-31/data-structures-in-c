#include <stdio.h>

int Stack[10];
int top = -1;

// Add a digit to the stack
void push(int digit)
{
    Stack[++top] = digit;
}

// Remove and return the top digit
int pop()
{
    return Stack[top--];
}

int main()
{
    int inputNumber, temp;
    int reversedResult = 0;
    int multiplier = 1;

    printf("Enter a number: ");
    scanf("%d", &inputNumber);

    temp = inputNumber;

    // Break the number into digits and push them
    while(temp > 0)
    {
        int lastDigit = temp % 10;

        push(lastDigit);

        temp = temp / 10;
    }

    // Pop the digits and build the reversed number
    while(top != -1)
    {
        int poppedDigit = pop();

        reversedResult += poppedDigit * multiplier;

        multiplier *= 10;
    }

    printf("Reversed: %d\n", reversedResult);

    return 0;
}
