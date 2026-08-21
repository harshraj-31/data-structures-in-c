// Menu driven program for linked list

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node
{
    int data;
    struct node *next;
};

// Start points to the first node
struct node *start = NULL;

// Function declarations
void create();
void display();
void insatlast();
void deleteNode();

int main()
{
    int ch = -1;

    // Keep showing the menu until user exits
    while(ch != 0)
    {
        printf("\n1.Create");
        printf("\n2.Display");
        printf("\n3.Insert at last");
        printf("\n4.Delete at specific position: ");
        printf("\n0.EXIT");

        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            create();
            break;

        case 2:
            display();
            break;

        case 3:
            insatlast();
            break;

        case 4:
            deleteNode();
            break;

        case 0:
            printf("\nExitingg...");
            exit(0);
            break;

        default:
            printf("\nInvalid choice");
            break;
        }
    }

    return 0;
}

// Create a new node and add it to the list
void create()
{
    struct node *newnode, *ptr;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the new node data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    // If list is empty, new node becomes the first node
    if(start == NULL)
    {
        start = newnode;
    }
    else
    {
        ptr = start;

        // Move to the last node
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = newnode;
    }
}

// Display all nodes
void display()
{
    struct node *ptr;

    if(start == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        ptr = start;

        // Traverse the list and print each node
        while(ptr != NULL)
        {
            printf("%d ->", ptr->data);
            ptr = ptr->next;
        }

        printf("NULL");
    }
}

// Insert a new node at the end
void insatlast()
{
    struct node *newnode, *ptr;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the new node data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(start == NULL)
    {
        start = newnode;
    }
    else
    {
        ptr = start;

        // Go to the last node
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = newnode;

        printf("Node inserted at last");
    }
}

// Delete a node using its value
void deleteNode()
{
    struct node *ptr, *temp;
    int srchno;

    if(start == NULL)
    {
        printf("\nList is empty");
        return;
    }

    printf("Enter the search no: ");
    scanf("%d", &srchno);

    // Delete the first node if it matches
    if(start->data == srchno)
    {
        temp = start;
        start = start->next;

        free(temp);

        printf("\nNode deleted");
        return;
    }

    ptr = start;

    // Find the node before the node to delete
    while(ptr->next != NULL && ptr->next->data != srchno)
    {
        ptr = ptr->next;
    }

    if(ptr->next == NULL)
    {
        printf("\nNot found in list");
        return;
    }

    temp = ptr->next;
    ptr->next = temp->next;

    free(temp);

    printf("\nNode Deleted");
}
