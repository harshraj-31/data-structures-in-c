#include <stdio.h>
#include <conio.h>

#define MAX 5

char stack[MAX];
int top = -1;

void push(char ch)
{
    if(top == MAX-1)
        printf("Stack Overflow");
    else
        stack[++top] = ch;
}


char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

void main()
{
    char expr[100], ch;
    int i, flag = 1;

    clrscr();

    printf("Enter Expression: ");
    gets(expr);

    for(i = 0; expr[i] != '\0'; i++)
    {
        /* Opening brackets */
        if(expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
        {
            push(expr[i]);
        }

        /* Closing brackets */
        else if(expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            ch = pop();

            if((ch == '(' && expr[i] != ')') ||
               (ch == '{' && expr[i] != '}') ||
               (ch == '[' && expr[i] != ']'))
            {
                flag = 0;
                break;
            }
        }
    }


    if(flag == 1 && top == -1)
	printf("\n IT IS VALID");
    else
	printf("\nIT IS NOT VALID");

    getch();
}