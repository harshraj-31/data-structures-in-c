#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

/* PUSH operation */
void push()
{
    struct node *newnode;
    
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Stack Overflow (Memory not available)\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &newnode->data); 

    newnode->next = top;
    top = newnode;

    printf("Element pushed successfully\n");
}


/* POP operation */
void pop()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack Underflow (Stack is empty)\n");
        return;
    }

    temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->next;
    free(temp);
}


/* PEEK operation */
void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element: %d\n", top->data);
    }
}


/* DISPLAY operation */
void display()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    temp = top;
    printf("Stack elements:\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

/* MAIN function */
int main()
{
    int choice;

    do
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting program\n");
            break;
        default:
            printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}
