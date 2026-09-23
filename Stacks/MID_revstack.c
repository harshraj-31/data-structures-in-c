#include <stdio.h>
#include <conio.h>

#define MAX 20

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = val;
}

int pop() {
    if (top == -1)
        return -1; 
    
    return stack[top--];
}

int main() {
    int num, digit, rev = 0, multiplier = 1;
    
    clrscr();

    printf("Enter a number: ");
    scanf("%d", &num);

    // Push digits into stack (extracts right-to-left)
    while (num > 0) {
        digit = num % 10;
        push(digit);
        num = num / 10;
    }

    // Pop digits and reconstruct in reversed order
    while (top != -1) {
        digit = pop();
        rev = rev + (digit * multiplier);
        multiplier *= 10;
    }

    printf("Reversed number: %d\n", rev);

    getch();
    return 0;
}
