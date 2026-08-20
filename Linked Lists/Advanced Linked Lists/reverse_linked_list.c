/*
 * Reverse Linked List
 * Author: Harshrajsinh Zala
 * Description: Reverse singly linked list.
 */

#include <stdio.h>
#include <stdlib.h>

// Basic node structure
struct node
{
    int data;
    struct node *next;
};

// Reverse the linked list
struct node *reverse(struct node *start)
{
    struct node *prev = NULL;
    struct node *curr = start;
    struct node *next;

    // Change each node's next pointer
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// Display the linked list
void display(struct node *start)
{
    struct node *ptr = start;

    while(ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL");
}

int main()
{
    struct node *start = NULL;
    struct node *n1, *n2, *n3, *n4;

    // Create some nodes
    n1 = (struct node *)malloc(sizeof(struct node));
    n2 = (struct node *)malloc(sizeof(struct node));
    n3 = (struct node *)malloc(sizeof(struct node));
    n4 = (struct node *)malloc(sizeof(struct node));

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;
    n4->data = 40;

    // Link the nodes
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    start = n1;

    printf("Before Reverse:\n");
    display(start);

    // Reverse the list
    start = reverse(start);

    printf("\n\nAfter Reverse:\n");
    display(start);

    return 0;
}
