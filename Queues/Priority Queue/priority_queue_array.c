/*
 * Priority Queue
 * Author: Harshrajsinh Zala
 * Description: Array implementation.
 */

#include <stdio.h>
#include <conio.h>

#define MAX 5

int queue[MAX];
int priority[MAX];
int size = 0;

void enqueue()
{
    int data, p, i;

    if (size == MAX)
    {
        printf("\nPriority Queue Overflow!");
        return;
    }

    printf("\nEnter data: ");
    scanf("%d", &data);

    printf("Enter priority: ");
    scanf("%d", &p);

    i = size - 1;

    // Shift lower-priority elements to the right.
    while (i >= 0 && priority[i] < p)
    {
        queue[i + 1] = queue[i];
        priority[i + 1] = priority[i];
        i--;
    }

    queue[i + 1] = data;
    priority[i + 1] = p;
    size++;

    printf("\nElement inserted successfully.");
}

void dequeue()
{
    int i;

    if (size == 0)
    {
        printf("\nPriority Queue Underflow!");
        return;
    }

    printf("\nDeleted element: %d", queue[0]);

    for (i = 0; i < size - 1; i++)
    {
        queue[i] = queue[i + 1];
        priority[i] = priority[i + 1];
    }

    size--;
}

void peek()
{
    if (size == 0)
    {
        printf("\nPriority Queue is empty!");
        return;
    }

    printf("\nHighest priority element: %d", queue[0]);
    printf("\nPriority: %d", priority[0]);
}

void display()
{
    int i;

    if (size == 0)
    {
        printf("\nPriority Queue is empty!");
        return;
    }

    printf("\nData\tPriority\n");

    for (i = 0; i < size; i++)
    {
        printf("%d\t%d\n", queue[i], priority[i]);
    }
}

int main()
{
    int choice;

    clrscr();

    do
    {
        printf("\n\n--- Priority Queue ---");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
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

            case 5:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid choice!");
        }

    } while (choice != 5);

    getch();
    return 0;
}
