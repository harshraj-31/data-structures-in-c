#include <stdio.h>

int Stack[10]; 
int top = -1; // -1 means the bucket starts empty

// --- PUSH: Add digit to the stack ---
void push(int digit) {
    // ++top adds 1 to top FIRST, then we use that new index to store the digit
    Stack[++top] = digit; 
}

// --- POP: Remove digit from the stack ---
int pop() {
    // myStack[top--] uses the current top index to get the value, 
    // and THEN subtracts 1 from top
    return Stack[top--]; 
}

int main() {
    int inputNumber, temp;
    int reversedResult = 0;
    int multiplier = 1;

    printf("Enter a number: ");
    scanf("%d", &inputNumber);

    temp = inputNumber;

    // Phase 1: Break the number apart and push into stack
    while (temp > 0) {
        int lastDigit = temp % 10; // Grab the last digit
        push(lastDigit);           // Push it onto the stack
        temp = temp / 10;          // Remove that digit from temp
    }

    // Phase 2: Pop from stack and build the reversed number
    while (top != -1) {
        int poppedDigit = pop();               // Get the top digit
        reversedResult += poppedDigit * multiplier; // Place it in its new spot
        multiplier *= 10;                      // Move place value (1, 10, 100...)
    }

    printf("Reversed: %d\n", reversedResult);

    return 0;
}