#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of stack

// Global stack array and top pointer
int stack[MAX];
int top = -1; // Initialize top to -1 (empty stack)

// Function to push an element onto the stack
void push(int value)
{
    if (top == MAX - 1) // Check if stack is full
    {
        printf("Stack Overflow! Cannot push %d\n", value);
    }
    else
    {
        stack[++top] = value; // Increment top and insert value
        printf("%d pushed onto stack\n", value);
    }
}

// Function to pop an element from the stack
void pop()
{
    if (top == -1) // Check if stack is empty
    {
        printf("Stack Underflow! No elements to pop\n");
    }
    else
    {
        printf("%d popped from stack\n", stack[top--]); // Print and decrement top
    }
}

// Function to peep (view top element without removing it)
void peep()
{
    if (top == -1) // Check if stack is empty
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nTop element is %d\n", stack[top]);
    }
}

// Function to count total elements in stack
void count()
{
    printf("Total elements in stack: %d\n", top + 1);
}

// Function to display all stack elements from top to bottom
void display()
{
    if (top == -1) // Check if stack is empty
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) // Traverse from top to bottom
        {
            printf("%d\n", stack[i]);
        }
    }
}

// Main menu-driven stack program
int main()
{
    int choice, value;

    while (1) // Infinite loop for menu
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Count\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch statement to handle menu choices
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
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
