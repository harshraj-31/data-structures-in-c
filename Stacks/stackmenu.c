#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of stack

int stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(int value)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow! Cannot push %d\n", value);
    }
    else
    {
        stack[++top] = value;
        printf("%d pushed onto stack\n", value);
    }
}

// Function to pop an element from the stack
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! No elements to pop\n");
    }
    else
    {
        printf("%d popped from stack\n", stack[top--]);
    }
}

// Function to peep (view top element)
void peep()
{
    if (top == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nTop element is %d\n", stack[top]);
    }
}

// Function to count elements in stack
void count()
{
    printf("Total elements in stack: %d\n", top + 1);
}

// Function to display stack elements
void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

void rev()
{
    int i;
    for(i=0;i <=top ;i++)
    {
        printf("\n%d",stack[i]);
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Count\n");
        printf("5. Display\n");
        printf("6.Print Reverse Stack");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            count();
            break;
        case 5:
            display();
            break;

        case 6:
            rev();
            break;
        case 0:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
