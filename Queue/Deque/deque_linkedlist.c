#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;


// Insert an element at the front.
void insertFront()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter value: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = front;

    if(front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        front->prev = newnode;
        front = newnode;
    }
}


// Insert an element at the rear.
void insertRear()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter value: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    newnode->prev = rear;

    if(rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}


// Delete an element from the front.
void deleteFront()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("\nDeque is empty");
        return;
    }

    temp = front;
    printf("\nDeleted: %d", temp->data);

    front = front->next;

    if(front == NULL)
    {
        rear = NULL;
    }
    else
    {
        front->prev = NULL;
    }

    free(temp);
}


// Delete an element from the rear.
void deleteRear()
{
    struct node *temp;

    if(rear == NULL)
    {
        printf("\nDeque is empty");
        return;
    }

    temp = rear;
    printf("\nDeleted: %d", temp->data);

    rear = rear->prev;

    if(rear == NULL)
    {
        front = NULL;
    }
    else
    {
        rear->next = NULL;
    }

    free(temp);
}


// Display elements from front to rear.
void display()
{
    struct node *ptr;

    if(front == NULL)
    {
        printf("\nDeque is empty");
        return;
    }

    ptr = front;

    printf("\nDeque: ");

    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}


int main()
{
    int choice;

    clrscr();

    while(1)
    {
        printf("\n\n===== DEQUE USING LINKED LIST =====");
        printf("\n1. Insert Front");
        printf("\n2. Insert Rear");
        printf("\n3. Delete Front");
        printf("\n4. Delete Rear");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insertFront();
                break;

            case 2:
                insertRear();
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                getch();
                return 0;

            default:
                printf("\nInvalid choice");
        }
    }
}
