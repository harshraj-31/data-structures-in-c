#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct node
{
    int data;
    struct node *next;   // Stores address of next node
};

// Start points to the first node of the list
struct node *start = NULL;
struct node *start2;
struct node *start3;

// Function declarations
void create();
void display();
void insatstart();
void insatlast();
void insafternode();
void delsatstart();
void delatlast();
void deleteNode();
void count();
void search();
void reverse();
void sort();
void copy_ll();
void dis_copy();
void merge();

int main()
{
    int ch;

    // Menu loop
    do
    {
        printf("\n1.CREATE");
        printf("\n2.Display");
        printf("\n3.Insert at start");
        printf("\n4.Insert at end");
        printf("\n5.Insert between");
        printf("\n6.Delete at Start");
        printf("\n7.Delete at End");
        printf("\n8.Delete specific node");
        printf("\n9.Count");
        printf("\n10.Search");
        printf("\n11.Reverse the list");
        printf("\n12.Sort the list");
        printf("\n13.Copy list");
        printf("\n14.Display copied list");
        printf("\n15.Merge list");
        printf("\n0.Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insatstart(); break;
            case 4: insatlast(); break;
            case 5: insafternode(); break;
            case 6: delsatstart(); break;
            case 7: delatlast(); break;
            case 8: deleteNode(); break;
            case 9: count(); break;
            case 10: search(); break;
            case 11: reverse(); break;
            case 12: sort(); break;
            case 13: copy_ll(); break;
            case 14: dis_copy(); break;
            case 15: merge(); break;
            case 0: printf("Exiting..."); break;
            default: printf("Invalid choice, try again.");
        }

    } while(ch != 0);

    return 0;
}

// Create a new node and add it at the end
void create()
{
    struct node *newnode, *ptr;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the value: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

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
        return;
    }

    ptr = start;

    printf("\nLinked List:\n");

    while(ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL");
}

// Insert a node at the beginning
void insatstart()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the value: ");
    scanf("%d", &newnode->data);

    newnode->next = start;
    start = newnode;

    printf("\nNode inserted at start");
}

// Insert a node at the end
void insatlast()
{
    struct node *newnode, *ptr;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the value: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(start == NULL)
    {
        start = newnode;
        return;
    }

    ptr = start;

    // Move to the last node
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = newnode;

    printf("\nNode inserted at end");
}

// Insert a node after a given value
void insafternode()
{
    int srchno;
    struct node *newnode, *ptr;

    printf("\nEnter value after which to insert: ");
    scanf("%d", &srchno);

    ptr = start;

    // Search the value
    while(ptr != NULL && ptr->data != srchno)
    {
        ptr = ptr->next;
    }

    if(ptr != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("\nEnter new value: ");
        scanf("%d", &newnode->data);

        newnode->next = ptr->next;
        ptr->next = newnode;

        printf("\nNode inserted");
    }
    else
    {
        printf("\nValue not found");
    }
}

// Delete the first node
void delsatstart()
{
    struct node *ptr;

    if(start == NULL)
    {
        printf("\nList is empty");
        return;
    }

    ptr = start;
    start = start->next;

    free(ptr);
}

// Delete the last node
void delatlast()
{
    struct node *ptr, *p;

    if(start == NULL)
    {
        printf("\nList is empty");
        return;
    }

    if(start->next == NULL)
    {
        free(start);
        start = NULL;
        return;
    }

    p = start;

    // Move to second last node
    while(p->next->next != NULL)
    {
        p = p->next;
    }

    ptr = p->next;
    p->next = NULL;

    free(ptr);
}

// Delete a specific node by value
void deleteNode()
{
    int srchno;
    struct node *ptr, *temp;

    if(start == NULL)
    {
        printf("\nList is empty");
        return;
    }

    printf("\nEnter value to delete: ");
    scanf("%d", &srchno);

    // Delete first node
    if(start->data == srchno)
    {
        temp = start;
        start = start->next;
        free(temp);

        printf("\nNode deleted");
        return;
    }

    ptr = start;

    // Find previous node
    while(ptr->next != NULL && ptr->next->data != srchno)
    {
        ptr = ptr->next;
    }

    if(ptr->next == NULL)
    {
        printf("\nValue not found");
        return;
    }

    temp = ptr->next;
    ptr->next = temp->next;

    free(temp);

    printf("\nNode deleted");
}

// Count total nodes
void count()
{
    int count = 0;
    struct node *p;

    p = start;

    while(p != NULL)
    {
        count++;
        p = p->next;
    }

    printf("\nTotal nodes: %d", count);
}

// Search a value in the list
void search()
{
    int key;
    struct node *p;

    if(start == NULL)
    {
        printf("\nList is empty");
        return;
    }

    printf("\nEnter value to search: ");
    scanf("%d", &key);

    p = start;

    while(p != NULL && p->data != key)
    {
        p = p->next;
    }

    if(p != NULL)
    {
        printf("\n%d found", key);
    }
    else
    {
        printf("\nNumber not found");
    }
}

// Reverse the linked list
void reverse()
{
    struct node *curr, *next = NULL, *prev = NULL;

    curr = start;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    start = prev;

    printf("\nList reversed");
}

// Sort the list in descending order
void sort()
{
    struct node *i, *j;
    int temp;

    for(i = start; i != NULL; i = i->next)
    {
        for(j = start; j != NULL; j = j->next)
        {
            if(i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("\nList sorted");
}

// Copy the linked list
void copy_ll()
{
    struct node *ptr, *newnode, *temp;

    start2 = NULL;
    ptr = start;

    while(ptr != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->data = ptr->data;
        newnode->next = NULL;

        if(start2 == NULL)
        {
            start2 = newnode;
            temp = start2;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        ptr = ptr->next;
    }

    printf("\nList copied");
}

// Display copied list
void dis_copy()
{
    struct node *ptr;

    ptr = start2;

    while(ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL");
}

// Merge original list and copied list
void merge()
{
    struct node *ptr1, *ptr2, *newnode, *temp;

    ptr1 = start;
    ptr2 = start2;
    start3 = NULL;

    // Copy first list
    while(ptr1 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->data = ptr1->data;
        newnode->next = NULL;

        if(start3 == NULL)
        {
            start3 = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        ptr1 = ptr1->next;
    }

    // Copy second list
    while(ptr2 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->data = ptr2->data;
        newnode->next = NULL;

        temp->next = newnode;
        temp = newnode;

        ptr2 = ptr2->next;
    }

    printf("\nMerged list:\n");

    temp = start3;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");
}
