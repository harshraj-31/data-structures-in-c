#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node
{
    int data;
    struct node *next;
};

// Head points to the first node
struct node *head = NULL;

// Insert a new node at the end
void insert()
{
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    // If the list is empty, new node becomes the first node
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        // Move to the last node
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("Node inserted successfully\n");
}

// Count the total number of nodes
void countNodes()
{
    int count = 0;
    struct node *temp = head;

    // Traverse the list and count each node
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Total nodes = %d\n", count);
}

// Search for a particular value
void searchNode()
{
    int key, pos = 1, found = 0;
    struct node *temp = head;

    printf("Enter value to search: ");
    scanf("%d", &key);

    // Traverse the list and compare each node's data
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

    // Display message if the value was not found
    if(found == 0)
    {
        printf("Element not found\n");
    }
}

// Display all nodes
void display()
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");

    // Traverse from first node to last node
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

    // Keep showing the menu until the user chooses Exit
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
            case 1:
                insert();
                break;

            case 2:
                countNodes();
                break;

            case 3:
                searchNode();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
