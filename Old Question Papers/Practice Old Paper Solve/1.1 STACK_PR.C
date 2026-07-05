#include <stdio.h>
#include <stdlib.h>

#define MAX 5

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

// MENU FUNCTION
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

// PUSH FUNCTION
void push()
{
    int val;

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

// POP FUNCTION
void pop()
{
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

// PEEP FUNCTION
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

// COUNT FUNCTION
void count()
{
    printf("Number of elements in stack: %d\n", top + 1);
}

// DISPLAY FUNCTION
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
        for(i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

// REVERSE FUNCTION
void reverse()
{
    int i, temp;

    if(top == -1)
    {
        printf("\nSTACK IS EMPTY\n");
        return;
    }

    for(i = 0; i <= top/2; i++)
    {
        temp = stack[i];
        stack[i] = stack[top - i];
        stack[top - i] = temp;
    }

    printf("\nSTACK REVERSED SUCCESSFULLY\n");

    printf("Reversed Stack:\n");
    for(i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}