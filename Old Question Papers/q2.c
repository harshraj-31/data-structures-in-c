// Menu driven stack program

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

// Stack array and top pointer
int stack[MAX];
int top = -1;

// Add an element to the stack
void push(int value)
{
    if(top == MAX - 1)
    {
        printf("\nStack overflow");
    }
    else
    {
        stack[++top] = value;
        printf("\n%d pushed into stack",value);
    }
}

// Remove the top element
void pop()
{
    if(top == -1)
    {
        printf("\nStack Underflow, no elements to POP");
    }
    else
    {
        printf("\n%d popped from the stack",stack[top--]);
    }
}

// Show the top element
void peep()
{
    if(top == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("Top Element is %d",stack[top]);
    }
}

// Display all stack elements
void display()
{
    int i;

    if(top == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        // Start from top and move towards bottom
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

int main()
{
    int value, ch = -1;

    // Keep showing the menu until exit
    while(ch != 0)
    {
        printf("\nSTACK MENU");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Peep");
        printf("\n4.Display");
        printf("\n0.Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            printf("\nEnter the value: ");
            scanf("%d",&value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            peep();
            break;

        case 4:
            display();
            break;

        case 0:
            printf("\nExiting..");
            exit(0);

        default:
            printf("\nInvalid choice, try again!");
            break;
        }
    }

    return 0;
}
