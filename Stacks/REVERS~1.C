#include <stdio.h>
#define MAX 5
int stack[MAX];
int top = -1;
void push(int value)
{
    if(top == MAX - 1)
    {
	printf("Stack Overflow\n");
    }
    else
    {
	top++;
	stack[top] = value;
    }
}
void pop()
{
    if(top == -1)
    {
	printf("Stack Underflow\n");
    }
    else
    {
	printf("%d ", stack[top]);
	top--;
    }
}
int main()
{
    int i, value;
    clrscr();
    printf("Enter %d stack values:\n", MAX);
    for(i = 0; i < MAX; i++)
    {
	scanf("%d", &value);
	push(value);
    }
    printf("\nReverse Stack Values are:\n");
    for(i = 0; i < MAX; i++)
    {
	pop();
    }
	getch();
    return 0;
}
