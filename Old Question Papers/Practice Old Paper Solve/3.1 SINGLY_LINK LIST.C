#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

// CREATE (Insert at end)
void create()
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
    printf("Node added successfully\n");
}

// DISPLAY
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

// INSERT AT FIRST
void insertFirst()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    printf("Inserted at first successfully\n");
}

// DELETE LAST
void deleteLast()
{
    struct node *temp, *prev;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    // Only one node
    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Last node deleted\n");
        return;
    }
    temp = head;
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
   prev->next = NULL;
    free(temp);
    printf("Last node deleted\n");
}

// MAIN MENU
int main()
{
    int choice;
    while(1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert First\n");
        printf("4. Delete Last\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insertFirst(); break;
            case 4: deleteLast(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}