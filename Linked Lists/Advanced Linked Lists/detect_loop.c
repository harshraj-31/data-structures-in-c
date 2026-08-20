/*
 * Detect Loop
 * Author: Harshrajsinh Zala
 * Description: Floyd cycle detection.
 */

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node
{
    int data;
    struct node *next;
};

// Check if the linked list contains a loop
int detectLoop(struct node *start)
{
    struct node *slow = start;
    struct node *fast = start;

    // Slow moves one step, fast moves two steps
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        // If they meet, a loop exists
        if(slow == fast)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    struct node *start;
    struct node *n1;
    struct node *n2;
    struct node *n3;

    // Create some nodes
    n1 = (struct node *)malloc(sizeof(struct node));
    n2 = (struct node *)malloc(sizeof(struct node));
    n3 = (struct node *)malloc(sizeof(struct node));

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;

    start = n1;

    // Link the nodes
    n1->next = n2;
    n2->next = n3;

    // Create a loop: 30 -> 20
    n3->next = n2;

    // Check for loop
    if(detectLoop(start))
    {
        printf("Loop detected in the linked list.");
    }
    else
    {
        printf("No loop found.");
    }

    return 0;
}
