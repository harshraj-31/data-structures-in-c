#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};

struct node *front = NULL;


// Insert element according to its priority.
void enqueue()
{
    struct node *newnode, *ptr;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter value: ");
    scanf("%d", &newnode->data);

    printf("Enter priority: ");
    scanf("%d", &newnode->priority);

    newnode->next = NULL;

    // Higher priority number is served first.
    if(front == NULL || newnode->priority > front->priority)
    {
        newnode->next = front;
        front = newnode;
    }
    else
    {
        ptr = front;

        while(ptr->next != NULL &&
              ptr->next->priority >= newnode->priority)
        {
            ptr = ptr->next;
        }

        newnode->next = ptr->next;
        ptr->next = newnode;
    }
}


// Delete the element with the highest priority.
void dequeue()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("\nPriority Queue is empty");
        return;
    }

    temp = front;

    printf("\nDeleted value: %d", temp->data);
    printf("\nPriority: %d", temp->priority);

    front = front->next;

    free(temp);
}


// Display the priority queue.
void display()
{
    struct node *ptr;

    if(front == NULL)
    {
        printf("\nPriority Queue is empty");
        return;
    }

    ptr = front;

    printf("\n\nValue\tPriority\n");

    while(ptr != NULL)
    {
        printf("%d\t%d\n", ptr->data, ptr->priority);
        ptr = ptr->next;
    }
}


int main()
{
    int choice;

    clrscr();

    while(1)
    {
        printf("\n\n===== PRIORITY QUEUE =====");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                getch();
                return 0;

            default:
                printf("\nInvalid choice");
        }
    }
}
