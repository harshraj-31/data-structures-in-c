#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// INSERT (ENQUEUE)
void insert()
{
    int val;
    if(rear == MAX - 1)
    {
        printf("\nQueue Overflow\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &val);

        if(front == -1)
            front = 0;
        rear++;
        queue[rear] = val;
       printf("Inserted successfully\n");
    }

    printf("FRONT = %d , REAR = %d\n", front, rear);
}

// DELETE (DEQUEUE)
void delete()
{
    if(front == -1 || front > rear)
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
    // Reset queue when empty
    if(front > rear)
    {
        front = rear = -1;
    }
    printf("FRONT = %d , REAR = %d\n", front, rear);
}

// DISPLAY
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
        for(i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    printf("\nFRONT = %d , REAR = %d\n", front, rear);
}

// MAIN MENU
int main()
{
    int choice;
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
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}