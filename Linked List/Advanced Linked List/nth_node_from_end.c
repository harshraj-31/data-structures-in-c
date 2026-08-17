/*
 * Nth Node From End
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head, *temp, *fast, *slow;
    int n, i;

    // Create a simple linked list
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;

    head->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->data = 20;

    head->next->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->next->data = 30;

    head->next->next->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->next->next->data = 40;

    head->next->next->next->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->next->next->next->data = 50;

    head->next->next->next->next->next = NULL;

    printf("Enter n: ");
    scanf("%d", &n);

    // Move fast pointer n positions ahead
    fast = head;

    for(i = 0; i < n; i++)
    {
        if(fast == NULL)
        {
            printf("Invalid position");
            return 0;
        }

        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    slow = head;

    while(fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    printf("%dth Node From End: %d", n, slow->data);

    return 0;
}
