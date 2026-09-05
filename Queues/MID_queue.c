#include <stdio.h>

#define MAX 5

int no[MAX];
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void peek();
void display();

int main()
{
    int choice;

    do
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n0. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 0:
                return 0;

            default:
                printf("\nInvalid choice, try again");
        }

    } while (choice != 0);

    return 0;
}

void enqueue()
{
    int val;

    if (rear == MAX - 1)
    {
        printf("\nQueue is FULL/Overflow");
        return;
    }

    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }

    printf("\nEnter a number: ");
    scanf("%d", &val);

    no[rear] = val;
}

void dequeue()
{
    int val;

    if (front == -1 || front > rear)
    {
        printf("\nQueue Underflow! Nothing to delete.");
        return;
    }

    val = no[front];
    printf("\nElement deleted: %d", val);

    front++;

    if (front > rear)
    {
        front = rear = -1;
    }
}

void peek()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        printf("\nPeek: %d", no[front]);
    }
}

void display()
{
    int i;

    if (front == -1 || front > rear)
    {
        printf("\nQueue is empty");
        return;
    }

    printf("\nQueue elements: ");

    for (i = front; i <= rear; i++)
    {
        printf("%d ", no[i]);
    }
}
