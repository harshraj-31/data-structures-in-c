
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char);
char pop();
int precedence(char);
void main()
{
    char infix[MAX], postfix[MAX]="";
    char ch;
    int i, k = 0;

    clrscr();

    printf("ENTER THE EXPRESSION: ");
    gets(infix);


    for (i = 0; infix[i] != '\0'; i++)
    {
	ch = infix[i];

	if (isalnum(ch))
        {
	    postfix[k++] = ch;
	}
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
	    while (stack[top] != '(')
	    {
		postfix[k++] = pop();
	    }
	    pop();   // remove '('
	}
	else
	{
	    while (top != -1 && precedence(stack[top]) >= precedence(ch))
	    {
		postfix[k++] = pop();
	    }

	    push(ch);
	}
    }

    while (top != -1)
    {
	postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("POSTFIX EXPRESSION: %s", postfix);
    getch();
}

void push(char x)
{
    if (top == MAX - 1)
    {
        printf("STACK OVERFLOW");
    }
    else
    {
        stack[++top] = x;
    }
}
char pop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int precedence(char x)
{
    if (x=='^')
	return 3;

    else if (x == '*' || x == '/')
	return 2;

    else if(x == '+' || x == '-')
	return 1;

    else
        return 0;
}
