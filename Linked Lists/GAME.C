#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, k, i;
    struct node *start = NULL;
    struct node *newnode, *ptr, *temp;

    clrscr();

    printf("ENTER THE N NUMBER => ");
    scanf("%d", &n);

    printf("ENTER THE K VALUE => ");
    scanf("%d", &k);

    // Create circular linked list
    for(i = 1; i <= n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        newnode->data = i;
        newnode->next = NULL;

        if(start == NULL)
        {
            start = newnode;
            ptr = newnode;
        }
        else
        {
            ptr->next = newnode;
            ptr = newnode;
        }
    }

    // Connect last node back to first
    ptr->next = start;

    ptr = start;

    // Remove every kth node
    while(ptr->next != ptr)
    {
        for(i = 1; i < k - 1; i++)
        {
            ptr = ptr->next;
        }

        temp = ptr->next;
        ptr->next = temp->next;

        printf("Removed: %d\n", temp->data);

        free(temp);
        ptr = ptr->next;
    }

    printf("\nWinner: %d", ptr->data);

    getch();
    return 0;
}
