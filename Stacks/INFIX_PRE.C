#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>

#define MAX 100

char prefix[MAX];
int stack[MAX];
int top = -1;

void push();
int pop();

void main()
{
    int i, op1, op2, result = 0;

    clrscr();
    printf("ENTER THE PREFIX EXPRESSION: ");
    gets(prefix);
    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        if (isdigit(prefix[i]))
        {
            push(prefix[i] - '0');
        }
        else
        {
            op1 = pop();
            op2 = pop();

            switch (prefix[i])
            {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '%': result = op1 % op2; break;
                case '^': result = pow(op1, op2); break;
            }
            push(result);
        }
    }

    printf("RESULT = %d", pop());
    getch();
}

/* PUSH OPERATION */
void push(int x)
{
    stack[++top] = x;
}


/* POP OPERATION */
int pop()
{
    return stack[top--];
}
