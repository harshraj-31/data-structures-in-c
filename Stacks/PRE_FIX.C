#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    if (top == -1)
        return -1;
    return stack[top--];
}

int priority(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

void reverse(char exp[])
{
    int i, j;
    char temp;
    int len = strlen(exp);

    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }

    for (i = 0; i < len; i++)
    {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, k = 0;
    char x;

    top = -1;   
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (isdigit(infix[i]) || isalpha(infix[i]))
        {
            postfix[k++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((x = pop()) != '(')
                postfix[k++] = x;
        }
        else
        {
            while (top != -1 && priority(stack[top]) >= priority(infix[i]))
                postfix[k++] = pop();

            push(infix[i]);
        }
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

int main()
{
    char infix[50], postfix[50];
    clrscr();
    printf("ENTER THE EXPRESION ");
    scanf("%s", infix);

    reverse(infix);
    infixToPostfix(infix, postfix);
    reverse(postfix);

    printf("Prefix Expression: %s\n", postfix);
    getch();
    return 0;
}