#include <stdio.h>

#define MAX 20

int stack[MAX];
int top = -1;

void push(int val)
{
    stack[++top] = val;
}

int pop()
{
    return stack[top--];
}

void main()
{
    int num, digit;

    printf("Enter a number: ");
    scanf("%d",&num);

    while(num > 0)
    {
        digit = num % 10;
        push(digit);
        num = num / 10;
    }

    printf("Reversed number: ");

    while(top != -1)
    {
        printf("%d", pop());
    }
}