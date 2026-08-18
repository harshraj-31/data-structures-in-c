#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL;
struct node *newnode, *ptr, *temp;

// Function declarations
void create();
void insertstart();
void insertend();
void deletestart();
void deleteend();
void display();

// Main function
void main()
{
    int choice;

    clrscr();

    do
    {
        printf("\n\n===== DOUBLY LINKED LIST MENU =====\n");
        printf("1. CREATE NODE (AT END)\n");
        printf("2. INSERT AT START\n");
        printf("3. INSERT AT END\n");
        printf("4. DELETE FROM START\n");
        printf("5. DELETE FROM END\n");
        printf("6. DISPLAY\n");
        printf("0. EXIT\n");

        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create();
                break;

            case 2:
                insertstart();
                break;

            case 3:
                insertend();
                break;

            case 4:
                deletestart();
                break;

            case 5:
                deleteend();
                break;

            case 6:
                display();
                break;

            case 0:
                printf("EXITING...");
                break;

            default:
                printf("INVALID CHOICE");
        }

    } while(choice != 0);

    getch();
}

// Create a node at the end
void create()
{
    insertend();
}

// Insert a node at the beginning
void insertstart()
{
    int data;

    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("OVERFLOW");
        return;
    }

    printf("ENTER DATA: ");
    scanf("%d", &data);

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = start;

    // Connect the old first node with new node
    if(start != NULL)
        start->prev = newnode;

    start = newnode;
}

// Insert a node at the end
void insertend()
{
    int data;

    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("OVERFLOW");
        return;
    }

    printf("ENTER DATA: ");
    scanf("%d", &data);

    newnode->data = data;
    newnode->next = NULL;

    // If list is empty, new node becomes first node
    if(start == NULL)
    {
        newnode->prev = NULL;
        start = newnode;
    }
    else
    {
        ptr = start;

        // Move to the last node
        while(ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = newnode;
        newnode->prev = ptr;
    }
}

// Delete the first node
void deletestart()
{
    if(start == NULL)
    {
        printf("LIST IS EMPTY");
        return;
    }

    temp = start;
    start = start->next;

    // Remove previous link from new first node
    if(start != NULL)
        start->prev = NULL;

    printf("DELETED ELEMENT: %d", temp->data);

    free(temp);
}

// Delete the last node
void deleteend()
{
    if(start == NULL)
    {
        printf("LIST IS EMPTY");
        return;
    }

    ptr = start;

    // Move to the last node
    while(ptr->next != NULL)
        ptr = ptr->next;

    if(ptr->prev == NULL)
    {
        // Only one node exists
        start = NULL;
    }
    else
    {
        // Remove the last node
        ptr->prev->next = NULL;
    }

    printf("DELETED ELEMENT: %d", ptr->data);

    free(ptr);
}

// Display list in both directions
void display()
{
    if(start == NULL)
    {
        printf("LIST IS EMPTY");
        return;
    }

    ptr = start;

    printf("\nFORWARD: ");

    // Move from first to last
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);

        if(ptr->next == NULL)
            break;

        ptr = ptr->next;
    }

    printf("\nBACKWARD: ");

    // Move from last to first
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
}
