#include <stdio.h>
#include <conio.h>

#define MAX 20

int stack[MAX];
int top = -1;

// Push function
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = val;
    }
}

// Pop function
int pop() {
    if (top == -1) {
        return -1;  // Empty stack
    } else {
        return stack[top--];
    }
}

void main() {
    int num, digit, rev = 0;
    clrscr();

    printf("Enter a number: ");
    scanf("%d", &num);

    // Push digits into stack
    while (num > 0) {
        digit = num % 10;
        push(digit);
        num = num / 10;
    }

    // Pop digits to form reversed number
    while (top != -1) {
        digit = pop();
        rev = rev * 10 + digit;
    }

    printf("Reversed number: %d\n", rev);

    getch();
}
