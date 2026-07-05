// 3.Write a menu driven program to penform the following operations on singly linked list using user-defined functions:
// a) Count total nodes
// b) Create a copy of the linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *copyStart = NULL;   // head of copied list

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

    while (ptr != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = ptr->data;
        newnode->next = NULL;

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
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}
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

void displayCopy()
{
    struct node *ptr;
    if (copyStart == NULL)
    {
        printf("\n No copy of a list found");
        return;
    }
    else
    printf("Copied Link list: ");
    printf("\n____________________________\n");
    {
        ptr = copyStart;
        while (ptr != NULL)
        {
            printf("%d ->", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL");
    }
}


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
    while (ch != 0)
    {
        printf("\n1.Create");
        printf("\n2.Display");
        printf("\n3.Count the nodes");
        printf("\n4.Copy link list");
        printf("\n5.Display copied link list");
        printf("\n0.EXIT");
        printf("\nENter your choice : ");
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
            exit(0);
            printf("\nExitingg...");
            break;

        default:
            printf("\nInvalid choice");
            break;
        }
    }
    return 0;
}