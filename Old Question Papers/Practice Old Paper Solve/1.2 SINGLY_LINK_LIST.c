#include <stdio.h>
#include <stdlib.h>
// Node structure
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

// Function to insert node at end (for testing)
void insert()
{
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Node inserted successfully\n");
}

// Count nodes
void countNodes()
{
    int count = 0;
    struct node *temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Total nodes = %d\n", count);
}

// Search node
void searchNode()
{
    int key, pos = 1, found = 0;
    struct node *temp = head;

    printf("Enter value to search: ");
    scanf("%d", &key);

    while(temp != NULL)
    {
        if(temp->data == key)
        {
            printf("Element found at position %d\n", pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if(found == 0)
    {
        printf("Element not found\n");
    }
}

// Display list
void display()
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main menu
int main()
{
    int choice;

    while(1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Insert Node\n");
        printf("2. Count Nodes\n");
        printf("3. Search Node\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: insert(); break;
            case 2: countNodes(); break;
            case 3: searchNode(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}