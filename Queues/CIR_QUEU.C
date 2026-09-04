#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert();
void delete();
void display();
void peek();
void menu();

int main()
{
    clrscr();
    menu();
    getch();
    return 0;
}

void menu()
{
    int choice;

    while (1)
    {
        printf("\n1. INSERT");
        printf("\n2. DELETE");
        printf("\n3. DISPLAY");
        printf("\n4. PEEK");
        printf("\n0. EXIT");

        printf("\nENTER THE CHOICE: ");
        scanf("%d", &choice);

        switch (choice)
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
                peek();
                break;

            case 0:
                exit(0);

            default:
                printf("\nINVALID CHOICE");
        }
    }
}

void insert()
{
    int num;

    if (rear == MAX - 1)
    {
        printf("\nQUEUE OVERFLOW");
        return;
    }

    printf("ENTER THE VALUE: ");
    scanf("%d", &num);

    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }

    queue[rear] = num;
}

void delete()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQUEUE UNDERFLOW");
        return;
    }

    printf("\nDELETED ELEMENT: %d", queue[front]);
    front++;

    if (front > rear)
    {
        front = rear = -1;
    }
}

void display()
{
    int i;

    if (front == -1 && rear == -1)
    {
        printf("\nQUEUE IS EMPTY");
        return;
    }

    printf("\nQUEUE ELEMENTS: ");

    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQUEUE IS EMPTY");
        return;
    }

    printf("\nFRONT ELEMENT: %d", queue[front]);
}
