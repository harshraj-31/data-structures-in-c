#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Stack array and top position
int stack[MAX];
int top = -1;

// Function declarations
void push();
void pop();
void peep();
void count();
void display();
void reverse();
int menu();

int main()
{
    int ch;

    // Keep displaying the menu until the user exits
    while(1)
    {
        ch = menu();

        switch(ch)
        {
            case 1:
                push();
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
                reverse();
                break;

            case 7:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("\nINVALID CHOICE\n");
        }
    }

    return 0;
}

// Menu function
int menu()
{
    int choice;

    printf("\n\n\tSTACK PROGRAM MENU\n");
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. PEEP\n");
    printf("4. COUNT\n");
    printf("5. DISPLAY\n");
    printf("6. REVERSE STACK\n");
    printf("7. EXIT\n");

    printf("\nENTER YOUR CHOICE: ");
    scanf("%d", &choice);

    return choice;
}

// Add an element to the stack
void push()
{
    int val;

    // Check if the stack is full
    if(top == MAX - 1)
    {
        printf("\nSTACK IS FULL (Overflow)\n");
    }
    else
    {
        printf("ENTER VALUE TO PUSH: ");
        scanf("%d", &val);

        top++;
        stack[top] = val;

        printf("DATA PUSHED SUCCESSFULLY\n");
    }
}

// Remove the top element from the stack
void pop()
{
    // Check if the stack is empty
    if(top == -1)
    {
        printf("\nSTACK IS EMPTY (Underflow)\n");
    }
    else
    {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

// Display the top element without removing it
void peep()
{
    if(top == -1)
    {
        printf("\nSTACK IS EMPTY\n");
    }
    else
    {
        printf("Top element: %d\n", stack[top]);
    }
}

// Count the number of elements
void count()
{
    printf("Number of elements in stack: %d\n", top + 1);
}

// Display all stack elements
void display()
{
    int i;

    if(top == -1)
    {
        printf("\nSTACK IS EMPTY\n");
    }
    else
    {
        printf("Stack elements are:\n");

        // Display from top to bottom
        for(i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

// Reverse the stack
void reverse()
{
    int i, temp;

    if(top == -1)
    {
        printf("\nSTACK IS EMPTY\n");
        return;
    }

    // Swap elements from both ends
    for(i = 0; i <= top / 2; i++)
    {
        temp = stack[i];
        stack[i] = stack[top - i];
        stack[top - i] = temp;
    }

    printf("\nSTACK REVERSED SUCCESSFULLY\n");

    // Display the reversed stack
    printf("Reversed Stack:\n");

    for(i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}
