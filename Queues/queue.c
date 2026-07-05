#include<stdio.h>
#define MAX 5
int no[MAX];
int front = -1, rear = -1;

void enqueue();
void dequeue();
void peek();
void display();

void main()
{
    int choice;

    do
    {
        printf("\n1.Enqueue ");
        printf("\n2.Dequeue ");
        printf("\n3.Peek ");
        printf("\n4.Display ");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            enqueue(); break;
        
        case 2:
            dequeue(); break;

        case 3:
            peek(); break;

        case 4:
            display(); break;


        case 0:
            return;
            break;

        default:
            printf("invalid choice, try again");
        }
    } while (choice != 0);
}

void enqueue()
{
    int val;
    if(rear == MAX-1)
    {
        printf("Queue is FULL/Overflow");
        return;
    }
    //first element 
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    printf("\np1.Input a number: ");
    scanf("%d",&val);
    no[rear] = val;
}

void dequeue()
{
    // 1. Check if the queue is empty
    if (front == -1 || front > rear)
    {
        printf("\nQueue Underflow! Nothing to delete.");
    }
    else
    {
        int val = no[front];
        printf("\nElement deleted: %d", val);
        front = front + 1;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void peek()
{
    if(front == -1 || front > rear)
    {
        printf("\n Queue is Empty");
    }
    else
    {
        printf("\n Peek: %d",no[front]);
    }
}

void display()
{
    int i;
    if(front == -1 || front > rear)
    {
        printf("Queue is empty");
        return;
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("\n%d",no[i]);
        }
        
    }
}