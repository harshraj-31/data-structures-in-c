// menu driven program link list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void create();
void display();
void insatlast();
void deleteNode();
int main()
{
    int ch = -1;
    while(ch!=0)
    {
        printf("\n1.Create");
        printf("\n2.Display");
        printf("\n3.Insert at last");
        printf("\n4.Delete at specific position: ");
        printf("\n0.EXIT");
        printf("\nENter your choice : ");
        scanf("%d",&ch);
        switch (ch)
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
void insatlast()
{
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the new node data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        printf("Node inserted at last");
    }
}
void deleteNode()
{
    struct node *ptr, *temp;
    int srchno;
    if (start == NULL)
    {
        printf("\nList is empty");
    }
    printf("Enter the search no: ");
    scanf("%d", &srchno);

    if (start->data == srchno)
    {
        temp = start;
        start = start->next;
        free(temp);
        printf("\nnode deleted");
        return;
    }

    ptr = start;
    while (ptr->next != NULL && ptr->next->data != srchno)
    {
        ptr = ptr->next;
    }
    if (ptr->next == NULL)
    {
        printf("\nNot found in list");
        return;
    }

    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    printf("\nNode Deleted");
}