// Menu driven program for counting nodes and copying a linked list

#include <stdio.h>
#include <stdlib.h>

// Basic node structure
struct node
{
    int data;
    struct node *next;
};

// Start of the original and copied lists
struct node *start = NULL;
struct node *copyStart = NULL;

// Create a copy of the linked list
void copyList()
{
    struct node *ptr = start;
    struct node *newnode;
    struct node *last = NULL;

    if (start == NULL)
    {
        printf("\nOriginal list is empty");
        return;
    }

    copyStart = NULL;

    // Copy each node one by one
    while (ptr != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->data = ptr->data;
        newnode->next = NULL;

        // Add the first node to the copied list
        if (copyStart == NULL)
        {
            copyStart = newnode;
            last = newnode;
        }
        else
        {
            last->next = newnode;
            last = newnode;
        }

        ptr = ptr->next;
    }

    printf("\nLinked list copied successfully");
}

// Create a new node at the end
void create()
{
    struct node *newnode, *ptr;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the new node data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (start == NULL)
    {
        start = newnode;
        printf("\nNode inserted");
    }
    else
    {
        ptr = start;

        // Move to the last node
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = newnode;
    }
}

// Display the original list
void display()
{
    struct node *ptr;

    if (start == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        ptr = start;

        while (ptr != NULL)
        {
            printf("%d ->", ptr->data);
            ptr = ptr->next;
        }

        printf("NULL");
    }
}

// Display the copied list
void displayCopy()
{
    struct node *ptr;

    if (copyStart == NULL)
    {
        printf("\nNo copy of a list found");
        return;
    }
    else
    {
        printf("Copied Linked List: ");
        printf("\n____________________________\n");

        ptr = copyStart;

        while (ptr != NULL)
        {
            printf("%d ->", ptr->data);
            ptr = ptr->next;
        }

        printf("NULL");
    }
}

// Count total nodes in the original list
void count()
{
    struct node *ptr;
    int count = 0;

    if (start == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        ptr = start;

        // Traverse the list and count each node
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->next;
        }

        printf("Total no of nodes: %d", count);
    }
}

int main()
{
    int ch = -1;

    // Keep showing the menu until exit
    while (ch != 0)
    {
        printf("\n1.Create");
        printf("\n2.Display");
        printf("\n3.Count the nodes");
        printf("\n4.Copy link list");
        printf("\n5.Display copied link list");
        printf("\n0.EXIT");

        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create();
            break;

        case 2:
            display();
            break;

        case 3:
            count();
            break;

        case 4:
            copyList();
            break;

        case 5:
            displayCopy();
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
