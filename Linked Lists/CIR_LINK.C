/*
 * Remove Loop
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
    struct Node *head, *temp;
    struct Node *slow, *fast;

    // Create linked list
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;

    head->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->data = 20;

    head->next->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->next->data = 30;

    head->next->next->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->next->next->data = 40;

    head->next->next->next->next = NULL;

    // Create a loop: 40 -> 20
    head->next->next->next->next = head->next;

    slow = head;
    fast = head;

    // Detect the loop
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            break;
        }
    }

    // If a loop is found, find its starting point
    if(slow == fast)
    {
        slow = head;

        while(slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the loop
        fast->next = NULL;

        printf("Loop Removed Successfully");
    }
    else
    {
        printf("No Loop Found");
    }

    return 0;
}
