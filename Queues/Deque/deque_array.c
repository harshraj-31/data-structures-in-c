#include <stdio.h>
#include <conio.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;


// Insert an element at the front.
void insertFront()
{
    int val;

    if((front == 0 && rear == MAX - 1) ||
       (front == rear + 1))
    {
        printf("\nDeque is full");
        return;
    }

    printf("\nEnter value: ");
    scanf("%d", &val);

    if(front == -1)
    {
        front = rear = 0;
    }
    else if(front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }

    deque[front] = val;
}


// Insert an element at the rear.
void insertRear()
{
    int val;

    if((front == 0 && rear == MAX - 1) ||
       (front == rear + 1))
    {
        printf("\nDeque is full");
        return;
    }

    printf("\nEnter value: ");
    scanf("%d", &val);

    if(front == -1)
    {
        front = rear = 0;
    }
    else if(rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = val;
}


// Delete an element from the front.
void deleteFront()
{
    int val;

    if(front == -1)
    {
        printf("\nDeque is empty");
        return;
    }

    val = deque[front];
    printf("\nDeleted: %d", val);

    if(front == rear)
    {
        front = rear = -1;
    }
    else if(front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}


// Delete an element from the rear.
void deleteRear()
{
    int val;

    if(front == -1)
    {
        printf("\nDeque is empty");
        return;
    }

    val = deque[rear];
    printf("\nDeleted: %d", val);

    if(front == rear)
    {
        front = rear = -1;
    }
    else if(rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }
}


// Display elements from front to rear.
void display()
{
    int i;

    if(front == -1)
    {
        printf("\nDeque is empty");
        return;
    }

    printf("\nDeque: ");

    if(front <= rear)
    {
        for(i = front; i <= rear; i++)
            printf("%d ", deque[i]);
    }
    else
    {
        for(i = front; i < MAX; i++)
            printf("%d ", deque[i]);

        for(i = 0; i <= rear; i++)
            printf("%d ", deque[i]);
    }
}


int main()
{
    int choice;

    clrscr();

    while(1)
    {
        printf("\n\n===== DEQUE USING ARRAY =====");
        printf("\n1. Insert Front");
        printf("\n2. Insert Rear");
        printf("\n3. Delete Front");
        printf("\n4. Delete Rear");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insertFront();
                break;

            case 2:
                insertRear();
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                getch();
                return 0;

            default:
                printf("\nInvalid choice");
        }
    }
}
