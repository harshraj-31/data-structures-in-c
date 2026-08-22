#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Queue array and front/rear positions
int queue[MAX];
int front = -1, rear = -1;

// Insert an element into the queue
void insert()
{
    int val;

    // Check if the queue is full
    if(rear == MAX - 1)
    {
        printf("\nQueue Overflow\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &val);

        // Set front when inserting the first element
        if(front == -1)
            front = 0;

        rear++;
        queue[rear] = val;

        printf("Inserted successfully\n");
    }

    printf("FRONT = %d , REAR = %d\n", front, rear);
}

// Delete an element from the queue
void delete()
{
    // Check if the queue is empty
    if(front == -1 || front > rear)
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);

        // Move front to the next element
        front++;
    }

    // Reset front and rear when queue becomes empty
    if(front > rear)
    {
        front = rear = -1;
    }

    printf("FRONT = %d , REAR = %d\n", front, rear);
}

// Display all queue elements
void display()
{
    int i;

    if(front == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("Queue elements: ");

        // Display elements from front to rear
        for(i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }

    printf("\nFRONT = %d , REAR = %d\n", front, rear);
}

// Main menu
int main()
{
    int choice;

    // Keep displaying the menu until the user exits
    while(1)
    {
        printf("\n--- SIMPLE QUEUE MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
