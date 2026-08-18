#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start;
struct node *start2;
struct node *start3;

/* DELETE LAST */
void del_end()
{
    struct node *ptr;

    if(start == NULL)
    {
        printf("\nList is empty");
        return;
    }

    // Only one node
    if(start->next == NULL)
    {
        free(start);
        start = NULL;
        return;
    }

    ptr = start;

    // Move to second-last node
    while(ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }

    free(ptr->next);
    ptr->next = NULL;
}


/* SEARCH */
void search()
{
    struct node *ptr;
    int d, cnt = 1;

    printf("Enter value to search: ");
    scanf("%d", &d);

    ptr = start;

    while(ptr != NULL)
    {
        if(ptr->data == d)
        {
            printf("\n%d found at position %d\n", d, cnt);
            return;
        }

        ptr = ptr->next;
        cnt++;
    }

    printf("\nNumber not found in list\n");
}


/* COUNT */
void count()
{
    struct node *ptr;
    int cnt = 0;

    ptr = start;

    // Count every node
    while(ptr != NULL)
    {
        cnt++;
        ptr = ptr->next;
    }

    printf("\nTotal Nodes in list: %d", cnt);
}


/* DELETE SPECIFIC NODE */
void del_node()
{
    struct node *ptr, *temp;
    int d;

    if(start == NULL)
    {
        printf("\nList is empty");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &d);

    // If first node has the value
    if(start->data == d)
    {
        temp = start;
        start = start->next;
        free(temp);

        printf("\nNode deleted");
        return;
    }

    ptr = start;

    // Find the node before the required node
    while(ptr->next != NULL && ptr->next->data != d)
    {
        ptr = ptr->next;
    }

    if(ptr->next == NULL)
    {
        printf("\nNumber not found in list");
        return;
    }

    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);

    printf("\nNode deleted");
}


/* DELETE FIRST */
void del_start()
{
    struct node *temp;

    if(start == NULL)
    {
        printf("\nList is empty");
        return;
    }

    temp = start;
    start = start->next;

    free(temp);
}


/* INSERT AT END */
void ins_end()
{
    struct node *newnode, *ptr;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nInput value: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(start == NULL)
    {
        start = newnode;
        return;
    }

    ptr = start;

    // Move to last node
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = newnode;
}


/* INSERT IN BETWEEN */
void ins_bet()
{
    struct node *newnode, *ptr;
    int d;

    if(start == NULL)
    {
        printf("\nList is empty");
        return;
    }

    printf("Enter value after which to insert: ");
    scanf("%d", &d);

    ptr = start;

    while(ptr != NULL && ptr->data != d)
    {
        ptr = ptr->next;
    }

    if(ptr == NULL)
    {
        printf("\n%d not found", d);
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nInput value: ");
    scanf("%d", &newnode->data);

    // Insert new node after ptr
    newnode->next = ptr->next;
    ptr->next = newnode;
}


/* INSERT AT START */
void ins_start()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nInput value: ");
    scanf("%d", &newnode->data);

    newnode->next = start;
    start = newnode;
}


/* CREATE */
void create()
{
    struct node *newnode, *ptr;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nInput value: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(start == NULL)
    {
        start = newnode;
    }
    else
    {
        ptr = start;

        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = newnode;
    }
}


/* DISPLAY */
void display()
{
    struct node *ptr;

    if(start == NULL)
    {
        printf("\nList is empty");
        return;
    }

    ptr = start;

    while(ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}


/* DISPLAY VALUES DIVISIBLE BY 7 */
void div_seven()
{
    struct node *ptr;

    ptr = start;

    while(ptr != NULL)
    {
        if(ptr->data % 7 == 0)
        {
            printf("%d\t", ptr->data);
        }

        ptr = ptr->next;
    }
}


/* COPY LINKED LIST */
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

    printf("\nList copied successfully");
}


/* DISPLAY COPIED LIST */
void dis_copy()
{
    struct node *ptr;

    if(start2 == NULL)
    {
        printf("\nCopied list is empty");
        return;
    }

    ptr = start2;

    while(ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}


/* MERGE TWO LISTS */
void merge()
{
    struct node *ptr1, *ptr2;
    struct node *newnode, *temp;

    ptr1 = start;
    ptr2 = start2;
    start3 = NULL;
    temp = NULL;

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

        ptr2 = ptr2->next;
    }

    printf("\nMerged Successfully!\n");

    temp = start3;

    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}


/* REVERSE */
void rev()
{
    struct node *current, *next, *prev;

    current = start;
    prev = NULL;

    // Reverse the links one by one
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }

    start = prev;

    printf("\nReversed Successfully!");
}


void main()
{
    int ch = 0;

    start = NULL;
    start2 = NULL;
    start3 = NULL;

    clrscr();

    do
    {
        printf("\n\n1. Create");
        printf("\n2. Display");
        printf("\n3. Insert @ Start");
        printf("\n4. Insert @ End");
        printf("\n5. Insert in Between");
        printf("\n6. Delete Start");
        printf("\n7. Delete End");
        printf("\n8. Delete Specific Node");
        printf("\n9. Count Total Nodes");
        printf("\n10. Search Node");
        printf("\n11. Divisible by 7");
        printf("\n12. Copy Linked List");
        printf("\n13. Display Copy");
        printf("\n14. Reverse Linked List");
        printf("\n15. Merge Linked Lists");
        printf("\n0. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                ins_start();
                break;

            case 4:
                ins_end();
                break;

            case 5:
                ins_bet();
                break;

            case 6:
                del_start();
                break;

            case 7:
                del_end();
                break;

            case 8:
                del_node();
                break;

            case 9:
                count();
                break;

            case 10:
                search();
                break;

            case 11:
                div_seven();
                break;

            case 12:
                copy_ll();
                break;

            case 13:
                dis_copy();
                break;

            case 14:
                rev();
                break;

            case 15:
                merge();
                break;

            case 0:
                exit(0);

            default:
                printf("\nEnter appropriate choice");
        }

    } while(1);
}
