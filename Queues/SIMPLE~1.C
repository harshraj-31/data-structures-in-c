#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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
    int ch;

    clrscr();

    do
    {
        printf("\n1. ENQUEUE");
        printf("\n2. DEQUEUE");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n0. EXIT");

        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &ch);

        switch (ch)
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
                exit(0);

            default:
                printf("\nINVALID CHOICE");
        }

    } while (ch != 0);

    getch();
    return 0;
}

void enqueue()
{
    int val;

    if (rear == MAX - 1)
    {
        printf("\nQUEUE IS FULL / OVERFLOW");
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

    printf("\nENTER VALUE: ");
    scanf("%d", &val);

    no[rear] = val;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("\nQUEUE IS EMPTY / UNDERFLOW");
        return;
    }

    printf("\nDELETING: %d", no[front]);

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
        printf("\nQUEUE IS EMPTY");
    }
    else
    {
        printf("\nPEEK: %d", no[front]);
    }
}

void display()
{
    int i;

    if (front == -1 || front > rear)
    {
        printf("\nQUEUE IS EMPTY");
        return;
    }

    printf("\nQUEUE ELEMENTS:");

    for (i = front; i <= rear; i++)
    {
        printf(" %d", no[i]);
    }
}
