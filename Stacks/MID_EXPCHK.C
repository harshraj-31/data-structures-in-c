#include <stdio.h>
#define MAX 10
int top = -1;
int stack[MAX];
char exp[100];

void push(char ch)
{
	if (top == MAX - 1)
	{
		printf("\nStack OverFlow");
	}
	else
	{
		stack[++top] = ch;
	}
}


char pop()
{
	if (top == -1)
	{
		printf("\nStack underflow");
		return '9';
	}
	else
	{
		return stack[top--];
	}
}


int main()
{
	int i, ch, flag = 1;
	clrscr();
	printf("Enter Expression: ");
	flushall();
	gets(exp);

	for (i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
		{
			push(exp[i]);
		}
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			ch = pop(); // ch stores popped < '(' , '[', '{' > expression from stack
			
			// if its invalid expression then flag =0
			if (ch == '9')
				flag = 0;
			else if (ch == '(' && exp[i] != ')') 
				flag = 0;

			else if (ch == '[' && exp[i] != ']')
				flag = 0;

			else if (ch == '{' && exp[i] != '}')
				flag = 0;
		}
	}
	//At the end if flaf == 1 AND stack is empty then then valied expression
	if (flag == 1 && top == -1)
	{
		printf("\n%s is valid Expression", exp);
	}
	else
	{
		printf("\n%s is not a valid expression", exp);
	}
	getch();
}